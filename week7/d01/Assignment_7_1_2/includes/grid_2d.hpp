#ifndef GRID_2D
#define GRID_2D

#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <vector>

namespace Grid
{
    struct Point_2D
    {
        int32_t x;
        int32_t y;
    };
    
    struct Size_2D
    {
        int32_t width;
        int32_t height;
    };

    /*
    **  Custom container to hold 2D grid. Implemented with vector as the
    **  underlying container
    */
    template <typename T>
    class Grid_2D
    {
        public:
            using value_type        = T;
            using reference         = T&;
            using storage_type      = typename std::vector<T>;
            using const_reference   = typename storage_type::const_reference;
            using iterator          = typename storage_type::iterator;
            using const_iterator    = typename storage_type::const_iterator;
            using difference_type   = typename storage_type::difference_type;
            using size_type         = typename storage_type::size_type;


            Grid_2D() = default;
            Grid_2D(int width_, int height_);
            Grid_2D(int width_, int height_, std::vector<T> vals);
            T& at(int pos);
            T& at(int x, int y);
            T& operator()(int pos);
            T& operator()(int x, int y);
            T& operator[](int pos);
            T& front() { return grid.front(); }
            T& back() { return grid.back(); }
            iterator begin() { return grid.begin(); }
            iterator end() { return grid.end(); }
            const T& cfront() const { return grid.front(); }
            const T& cback() const { return grid.back(); }
            const const_iterator cbegin() const { return grid.begin(); }
            const const_iterator cend() const { return grid.end(); }
            
            void resize(int width_, int height_);
            void print_grid();
            int32_t size_1D() { return size1D; }
            Size_2D size_2D() { return size2D; }

        private:
            int32_t         width;
            int32_t         height;
            int32_t         position1D {0};
            Point_2D        position2D {0, 0};
            int32_t         size1D;
            Size_2D         size2D;
            storage_type    grid;
    };


    template <typename T>
    Grid_2D<T>::Grid_2D(int width_, int height_)
    {
        width = width_;
        height = height_;
        grid.reserve(width * height);
        size1D = width * height;
        size2D.width = width;
        size2D.height = height;
    }

    template <typename T>
    Grid_2D<T>::Grid_2D(int width_, int height_, std::vector<T> vals)
    {
        width = width_;
        height = height_;
        grid.reserve(width * height);
        grid = vals;
        size1D = vals.size();
        size2D.width = width;
        size2D.height = height;
    }

    template <typename T>
    T& Grid_2D<T>::at(int pos)
    {
        if (pos < 0 || pos >= size1D)
            throw std::out_of_range("Out of range");
        return grid[pos];
    }

    template <typename T>
    T& Grid_2D<T>::at(int x, int y)
    {
        int pos = x + width * y;
        if (pos < 0 || pos >= size1D)
            throw std::out_of_range("Out of range");
        return grid[pos];
    }

    template <typename T>
    T& Grid_2D<T>::operator()(int pos)
    {
        if (pos < 0 || pos >= size1D)
            throw std::out_of_range("Out of range");
        return grid[pos];
    }

    template <typename T>
    T& Grid_2D<T>::operator()(int x, int y)
    {
        int pos = x + width * y;
        if (pos < 0 || pos >= size1D)
            throw std::out_of_range("Out of range");
        return grid[pos];
    }

    template <typename T>
    T& Grid_2D<T>::operator[](int pos)
    {
        if (pos < 0 || pos >= size1D)
            throw std::out_of_range("Out of range");
        return grid[pos];
    }

    template <typename T>
    void Grid_2D<T>::resize(int width_, int height_)
    {
        if (width_ <= 0 || height_ <= 0)
            throw std::invalid_argument("Width and height must be over 0");
            
        storage_type new_grid(width_ * height_);
        int w = std::min(width, width_);
        int h = std::min(height, height_);

        for (int i = 0; i < w * h; i++)
        {
            new_grid[(i / w) * width_ + (i % w)] = grid[(i / w) * width + (i % w)];
        }
        width = width_;
        height = height_;
        size1D = width * height;
        size2D.height = height;
        size2D.width = width;
        grid = std::move(new_grid);
    }
    
    template <typename T>
    void Grid_2D<T>::print_grid()
    {
        for (int i = 0; i < size1D; ++i)
        {
            if ((i % width) == 0 && i != 0)
                std::cout << '\n';
            std::cout << grid[i];
        }
        std::cout << '\n';
    }
}
#endif

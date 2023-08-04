#ifndef HEAP_ARRAY_HPP
#define HEAP_ARRAY_HPP

#include <cstdlib>
#include <stdexcept>

namespace oma
{
    template <typename T, size_t Size>
    class Heap_array
    {
        public:
            using value_type = T;
            using reference = T&;
            using const_reference = const T&;
            using iterator = T*;
            using const_iterator = const T*;
            using size_type = size_t;

            Heap_array() { ptr = new T[Size] {}; }
            Heap_array(std::initializer_list<T> initList);
            Heap_array(const Heap_array& other);
            Heap_array(Heap_array&& other);
            Heap_array& operator=(Heap_array& other);
            Heap_array& operator=(Heap_array&& other);
            T& operator[](size_t index);
            const T& operator[](size_t index) const;
            ~Heap_array() { delete[] ptr; }
            iterator begin() { return ptr; }
            iterator end() { return ptr + Size; }
            const_iterator cbegin() const { return ptr; }
            const_iterator cend() const { return ptr + Size; }
            /* Returns the number of elements in the Heap_array.*/
            size_type size() { return Size; }
            size_type max_size() { return SIZE_MAX; }
            void swap(Heap_array& other);
            inline static void swap(Heap_array& a, Heap_array& b);
            bool operator==(const Heap_array& other);
            bool operator!=(const Heap_array& other);

        private:
            T* ptr { nullptr };
    };

    template <typename T, size_t Size>
    Heap_array<T, Size>::Heap_array(const Heap_array& other)
    {
        ptr = new T[Size] {};
        std::copy(other.ptr, other.ptr + Size, ptr);
    }

    template <typename T, size_t Size>
    Heap_array<T, Size>::Heap_array(Heap_array&& other)
    {
        if (ptr != other.ptr)
        {
            delete[] ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
    }

    template <typename T, size_t Size>
    Heap_array<T, Size>& Heap_array<T, Size>::operator=(Heap_array& other)
    {
        this->swap(other);
        return *this;
    }

    template <typename T, size_t Size>
    Heap_array<T, Size>& Heap_array<T, Size>::operator=(Heap_array&& other)
    {
        if (ptr != other.ptr)
        {
            delete[] ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    template <typename T, size_t Size>
    T& Heap_array<T, Size>::operator[](size_t index)
    {
        if (index >= Size)
            throw std::out_of_range("Index out of range");
        return ptr[index];
    }

    template <typename T, size_t Size>
    const T& Heap_array<T, Size>::operator[](size_t index) const
    {
        if (index >= Size)
            throw std::out_of_range("Index out of range");
        return ptr[index];
    }

    /*
    *   Swaps the contents of two Heap_arrays.
    */
    template <typename T, size_t Size>
    void Heap_array<T, Size>::swap(Heap_array& other)
    {
        T* temp = ptr;
        ptr = other.ptr;
        other.ptr = temp;
    }

    /*
    *   Swaps the contents of two Heap_arrays.
    */
    template <typename T, size_t Size>
    void Heap_array<T, Size>::swap(Heap_array& a, Heap_array& b)
    {
        a.swap(b);
    }

    template <typename T, size_t Size>
    bool Heap_array<T, Size>::operator==(const Heap_array& other)
    {
        for (size_t i = 0; i < Size; i++)
        {
            if (ptr[i] != other.ptr[i])
                return false;
        }
        return true;
    }

    template <typename T, size_t Size>
    bool Heap_array<T, Size>::operator!=(const Heap_array& other)
    {
        return !(*this == other);
    }

    template <typename T, size_t Size>
    Heap_array<T, Size>::Heap_array(std::initializer_list<T> list)
    {
        if (list.size() != Size)
            throw std::invalid_argument("Initializer list size must match Heap_array size");

        ptr = new T[Size];
        std::copy(list.begin(), list.end(), ptr);
    }

}

#endif

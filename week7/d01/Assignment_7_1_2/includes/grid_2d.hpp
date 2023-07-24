#ifndef GRID_2D
#define GRID_2D

namespace Grid {
    template <typename T, typename Container>
    class Grid_2d {
        public:
            T value_type = typename T::Container::value_type;
        private:        
    };
}

#endif

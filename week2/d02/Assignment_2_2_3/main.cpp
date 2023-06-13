#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using Matrix = std::vector<std::vector<char>>;

void clear_cin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

struct Cell
{
    char    obstacle { 'O' };
    char    free { ' ' };
    char    player { 'A' };

    char random()
    {
        std::random_device rd{};
        std::seed_seq ss{
			static_cast<std::seed_seq::result_type>
            (std::chrono::steady_clock::now().time_since_epoch().count()),
			rd(), rd(), rd(), rd(), rd(), rd(), rd() };
        std::mt19937 mt {ss};
        std::uniform_int_distribution distr{1, 5};
        int res = distr(mt);
        if(res == 1)
            return obstacle;
        return free;
    }
} cell;

struct Player
{
    int row { 0 };
    int col { 0 };
    int points { 0 };
};

void init_board(Matrix& map)
{
    for (int i = 0; i < 10; ++i)
    {
        std::vector<char> row {};
        for (int j = 0; j < 10; ++j)
        {
            if (i == 0 && j == 0)
            {
                row.push_back(cell.player);
                continue ;
            }
            row.push_back(cell.random());
        }
        map.push_back(row);
    }
}

void draw_map(Matrix& map, Player& player){
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (i == player.row && j == player.col)
                std::cout << cell.player;
            else
                std::cout << map[i][j];
        }
        std::cout << '\n';
    }
}

void print_options()
{
    std::cout << "\nw) Move north\n";
    std::cout << "a) Move west\n";
    std::cout << "s) Move south\n";
    std::cout << "d) Move east\n";
    std::cout << "q) Quit\n";
}

bool check_north(Matrix& map, Player& player){
    if (player.row != 0)
    {
        if (map[player.row - 1][player.col] != cell.obstacle)
            return true;
    }
    return false;
}

bool check_west(Matrix& map, Player &player){
    if (player.col != 0)
    {
        if (map[player.row][player.col - 1] != cell.obstacle)
            return true;
    }
    return false;
}

bool check_south(Matrix& map, Player& player){
    if (player.row != 9)
    {
        if (map[player.row + 1][player.col] != cell.obstacle)
            return true;
    }
    return false;
}

bool check_east(Matrix& map, Player& player){
    if (player.col != 9)
    {
        if (map[player.row][player.col + 1] != cell.obstacle)
            return true;
    }
    return false;
}

void move_player(char dir, Matrix& map, Player& player)
{
    if (dir == 'w')
    {
        if (check_north(map, player))
        {
            std::cout << "\nPlayer moves north!\n";
            map[player.row][player.row] = cell.free;
            player.row -= 1;
        }
        else
            std::cout << "\nPlayer can't move north!\n";
    }
    else if (dir == 'a')
    {
        if (check_west(map, player))
        {
            std::cout << "\nPlayer moves west!\n";
            map[player.row][player.row] = cell.free;
            player.col -= 1;
        }
        else
            std::cout << "\nPlayer can't move west!\n";
    }
    else if (dir == 's')
    {
        if (check_south(map, player))
        {
            std::cout << "\nPlayer moves south!\n";
            map[player.row][player.row] = cell.free;
            player.row += 1;
        }
        else
            std::cout << "\nPlayer can't move south!\n";
    }
    else if (dir == 'd')
    {
        if (check_east(map, player))
        {
            std::cout << "\nPlayer moves east!\n";
            map[player.row][player.row] = cell.free;
            player.col += 1;
        }
        else
            std::cout << "\nPlayer can't move east!\n";
    }
}

int main()
{
    Matrix map {};

    Player player {};

    init_board(map);
    
    while (true)
    {
        draw_map(map, player);
        print_options();
        char option {};
        std::cin >> option;
        clear_cin();
        if (option == 'q')
        {
            return 0;
        }
        else if (option == 'w' || option == 'a'
            || option == 's' || option == 'd')
        {
            move_player(option, map, player);
        }
        else
        {
            std::cout << "Invalid option!\n";
            continue ;
        }
        
    }
    
}

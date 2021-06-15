#include <iostream>
#include <string>
#include <map>
#include <utility>
#include "Direction.hpp"
namespace ariel
{
    class Board
    {
    private:
        std::map<std::pair<unsigned, unsigned>, char> board;
        unsigned int maxRow;
        unsigned int maxCol;
        unsigned int minRow;
        unsigned int minCol;
        void update_limits(unsigned r, unsigned c, unsigned messlen, Direction d);

    public:
        Board();
        void post(unsigned int row, unsigned int column, Direction d, std::string message);
        std::string read(unsigned int row, unsigned int column, Direction d, unsigned int length);
        void show();
    };

}
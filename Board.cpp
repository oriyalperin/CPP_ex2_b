#include <iostream>
#include <string>
#include <map> 
#include <utility>
#include "Board.hpp"
#include "Direction.hpp"
using namespace std;
using namespace ariel;
const char no='_';

Board::Board()
{
    minRow=minCol=UINT32_MAX;
    maxRow=maxCol=0;
}

void Board::update_limits(unsigned r,unsigned c,unsigned messlen,Direction d)
{
    unsigned h=0;
    unsigned v=0;
    if(d==Direction::Horizontal)
        {
            h=messlen;
        }
    else
        {
            v=messlen;
        }
    if(r+v>maxRow)
    {
        maxRow=r+v;
    }
    if(r<minRow)
    {
        minRow=r;
    }   
    if(c+h>maxCol)
    {
        maxCol=c+h;
    }
    if(c<minCol)
    {
        minCol=c;
    }
}
void Board::post(unsigned int row, unsigned int column, Direction d, string message )
{
    
    unsigned length= message.length();
    update_limits(row,column,length,d);
    if(d==Direction::Horizontal)
    { 
        for(unsigned i=column;i<column+length;i++)
        {
           board[{row,i}]=message.at(i-column);
        }
    }
    else
    {
         for(unsigned i=row;i<row+length;i++)
        {
            board[{i,column}]=message.at(i-row);
        }
    }
}

string Board::read(unsigned int row, unsigned int column, Direction d, unsigned int length)
{
    string message;
    if(d==Direction::Horizontal)
    { 
        for(unsigned i=column;i<column+length;i++)
        { 
            char curr=no;
            try
            {
                curr = board.at({row,i});
            }
            catch(exception out_of_range){}            
            message+=curr;
        }
    }
    else
    {
         for(unsigned i=row;i<row+length;i++)
        { 
            char curr=no;
            try
            {
                curr = board.at({i,column});
            }
            catch(exception out_of_range){}   
            message+=curr;
            
        }     
    }
    return message;
}

void Board::show()
{
    if(board.empty())
        {
            throw out_of_range("the board is empty");
        }
    for (unsigned i=minRow;i<=maxRow;i++)
    {
        cout <<read(i,minCol,Direction::Horizontal,maxCol-minCol) << endl;  
    }
}

Board::~Board()
{
    board.clear();
    //delete &board;
}

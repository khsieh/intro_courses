/**
 * Name: Kevin Hsieh
 * Section: 021
 * Lab: 10
 * Course: CS 10 Fall 2012
 *
 * @author Adam Koehler
 * @date November 29, 2012 
 * @brief Simple percolation example using 2D vectors and grid from input file.
 */
/*
 *        Requires grid file as input (input redirection).
 *        Grid file looks similar to:
 *        xxxSxxxxxxxxxxxxxxx
 *        x                 x
 *        xxxxxxx xxxxxxxxxxx
 *        x                 x
 *        xxxxxxxxxxxxxxGxxxx
 *
 *        Spaces represent empty grid blocks.  Init in EMPTY state.
 *        S represents the starting grid block(s). Init in COLOR state.
 *        G represents the goal grid block. More than one can exist.
 *        Any non-space (x here) is considered a wall. Init in WALL state.
 */

#include <iostream>
#include <vector>

using namespace std;

// Provided functions
void animationPause();
void readGrid(vector <vector <int> > & , vector <vector <bool> > &);
void printGrid(const vector <vector <int> > &);
bool percComplete(const vector <vector <int> > &, 
                  const vector <vector <bool> > &);

// States for grid spots
const int EMPTY = 0;
const int WALL = 1;
const int COLOR = 2;
const int TO_BE_COLORED = 3;




/**
 * @brief percolates the fluid from grid blocks with fluid in them
 * @param grid the current grid filled with current states
 */
void perc(vector <vector <int> > &grid)
{
    // TODO: Implement the function per the lab specification
    int gridSize = grid.size();
    int rowSize;
    
    for(int i = 0; i < gridSize; ++i)
    {
        rowSize = grid.at(i).size();
        
        for(int r = 0; r < rowSize; ++r)
            if(grid.at(i).at(r) == COLOR)
            {
                //Down       
                if( i != gridSize - 1 && grid.at(i + 1).at(r) == EMPTY) 
                    grid.at(i + 1).at(r) = TO_BE_COLORED;
                //Up
                if( i != 0 && grid.at(i - 1).at(r) == EMPTY) 
                    grid.at(i - 1).at(r) = TO_BE_COLORED;
                //Right
                if( r != rowSize -1 && grid.at(i).at(r + 1) == EMPTY) 
                    grid.at(i).at(r + 1) = TO_BE_COLORED;
                //Left
                if( r != 0 && grid.at(i).at(r - 1) == EMPTY) 
                    grid.at(i).at(r - 1) = TO_BE_COLORED;
                    
                    
                //Down Right
                //if( r != rowSize -1 && i != gridSize - 1 && grid.at(i + 1).at(r + 1) == EMPTY) 
                    //grid.at(i + 1).at(r + 1) = TO_BE_COLORED;
                //Up Right
                //if( i != 0 && r != rowSize -1 && grid.at(i - 1).at(r + 1) == EMPTY) 
                    //grid.at(i - 1).at(r + 1) = TO_BE_COLORED;
                
                //Down Left
                //if( r != 0 && i != gridSize - 1 && grid.at(i + 1).at(r - 1) == EMPTY) 
                    //grid.at(i + 1).at(r - 1) = TO_BE_COLORED;
                //Up Left
                //if( i != 0 && r != 0 && grid.at(i - 1).at(r -1) == EMPTY) 
                    //grid.at(i - 1).at(r - 1) = TO_BE_COLORED;
            }
    }
    
    
    int rowSize2;
        
    for(int p = 0; p < gridSize; ++p)
    {
        rowSize2 = grid.at(p).size();
            
        for(int l = 0; l < rowSize2; ++l)
            {
                if(grid.at(p).at(l) == TO_BE_COLORED)
                {
                    grid.at(p).at(l) = COLOR;
                }
                    
            }
    }
    
}





// DO NOT edit existing code, your task is only to implement the perc func
int main()
{
    // 2D vectors to store states of grid and whether it is a goal cell
    vector <vector <int> > grid;
    vector <vector <bool> > goals;
   
    // Read in the grid from input
    readGrid(grid, goals);

    // Print initial grid
    printGrid(grid);

    // Run the simulation
    do
    {
        // Animation
        animationPause();

        // Percolate
        perc(grid);

        // Print updated grid
        printGrid(grid);
    }while(!percComplete(grid, goals));

    return 0;
}

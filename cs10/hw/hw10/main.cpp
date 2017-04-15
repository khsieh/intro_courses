// Course: CS 10 fall 2012
//
// First Name:Kevin
// Last Name: Hsieh
// Login id: khsie003
// email address: khsie003@ucr.edu
//
// Lecture Section: 001
// Lab Section: 021
// TA: Zhe Wu
//
// Assignment: assgn10
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ================================================================

#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

void getGrid(vector<vector<char> > &grid)
{
    vector<char> row;
    string line;
    do
    {
        getline(cin, line);
        if(line.empty()) break;
        int lineSize = line.size();
        for(int i = 0; i < lineSize; ++i)
        {
            if(isalpha(line.at(i)))
                row.push_back(line.at(i));
        }
        grid.push_back(row);
        row.clear();
    } while("TARDIS" == "TARDIS");
}

void printGrid(vector<vector<char> > &grid)
{
    int gridSize = grid.size();
    for(int i = 0; i < gridSize; ++i)
    {
        int rowSize = grid.at(i).size();
        for(int j = 0; j < rowSize; j++)
        {
            cout << grid.at(i).at(j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void getList(vector <string>& list)
{
    string word;
    while(cin >> word)
    {
        int wordSize = word.size();
        for(int i = 0; i < wordSize; ++i)
        {
            word.at(i) = toupper(word.at(i));
        }
        list.push_back(word);
    }
}

void printList(vector <string> list)
{
    int listSize = list.size();
    for(int r = 0; r < listSize; ++r)
        {
            cout << list.at(r) << endl;
        }
}

void printFoundList(const vector<string> &foundList)
{
    int foundListSize = foundList.size();
    for(int i = 0; i < foundListSize; ++i)
    cout << foundList.at(i) << endl;
}

void checkLeft (const vector <vector <char> > &grid, string curWord, vector <string> &foundList)
{
    int gridSize = grid.size();
    int rowSize;
    int curWordSize = curWord.size();
    string foundWord = "";
    
    for(int x = 0; x < gridSize; ++x) //
    {
        rowSize = grid.at(x).size();
        for(int y = rowSize-1; y >= 0 && y < rowSize; --y) //
            {
                if(curWord.at(0) == grid.at(x).at(y) && curWordSize <= y) //
                {
                    for(int i = 0; i < curWordSize; ++i)
                    {
                        if (i <= y && curWord.at(i) == grid.at(x).at(y - i)) //
                            {
                                foundWord.push_back(curWord.at(i));
                                if(curWord == foundWord)
                                {
                                    foundList.push_back(foundWord);
                                }
                            }
                            else break;
                    }
                    foundWord.clear();
                }
            }
    }
}

void checkRight (const vector <vector <char> > &grid, string curWord, vector <string> &foundList)
{
    int gridSize = grid.size();
    int rowSize;
    int curWordSize = curWord.size();
    string foundWord = "";
    
    for(int x = 0; x < gridSize; ++x) //
    {
        rowSize = grid.at(x).size();
        for(int y = 0; y < rowSize; ++y) //
            {
                if(curWord.at(0) == grid.at(x).at(y) && curWordSize <= (rowSize-y)) //
                {
                    for(int i = 0; i < curWordSize; ++i)
                    {
                        if (curWord.at(i) == grid.at(x).at(y+i)) //
                            {
                                foundWord.push_back(curWord.at(i));
                                
                                if(curWord == foundWord)
                                {
                                    foundList.push_back(foundWord);
                                }
                            }
                    }
                    foundWord.clear();
                }
            }
    }
    
    
}

void checkUp (const vector <vector <char> > &grid, string curWord, vector <string> &foundList)
{
    int gridSize = grid.size();
    int rowSize;
    int curWordSize = curWord.size();
    string foundWord = "";
    
    for(int x = gridSize -1; x < gridSize && x >= 0; --x)
    {
        rowSize = grid.at(x).size();
        for(int y = 0; y < rowSize; ++y)
            {
                if(curWord.at(0) == grid.at(x).at(y) && curWordSize <= gridSize )
                {
                    for(int i = 0; i < curWordSize; ++i)
                    {
                        if (i <= x && curWord.at(i) == grid.at(x - i).at(y))
                            {
                                foundWord.push_back(curWord.at(i));                        
                                if(curWord == foundWord)
                                {
                                    foundList.push_back(foundWord);
                                }
                            }
                    }
                    foundWord.clear();
                }
            }
    }
}

void checkDown (const vector <vector <char> > &grid, string curWord, vector <string> &foundList)
{
    int gridSize = grid.size();
    int rowSize;
    int curWordSize = curWord.size();
    string foundWord = "";
    
    for(int x = 0; x < gridSize && x >= 0 ; ++x)
    {
        rowSize = grid.at(x).size();
        for(int y = 0; y < rowSize; ++y)
            {
                if(curWord.at(0) == grid.at(x).at(y) && curWordSize <= (gridSize - x))
                {
                    for(int i = 0; i < curWordSize; ++i)
                    {
                        if (curWord.at(i) == grid.at(x + i).at(y))
                            {
                                foundWord.push_back(curWord.at(i));
                                
                                if(curWord == foundWord)
                                {
                                    foundList.push_back(foundWord);
                                }
                            }
                    }
                    foundWord.clear();
                }
            }
    }
}

void checkDownRight (const vector <vector <char> > &grid, string curWord, vector <string> &foundList)
{
    int gridSize = grid.size();
    int rowSize;
    int curWordSize = curWord.size();
    string foundWord = "";
    
    for(int x = 0; x < gridSize ; ++x)
    {
        rowSize = grid.at(x).size();
        for(int y = 0; y < rowSize; ++y)
            {
                if(curWord.at(0) == grid.at(x).at(y) 
                    && curWordSize - 1  <= (gridSize - x +1)
                    && curWordSize - 1  <=  (gridSize - y +1))
                {
                    for(int i = 0; i < curWordSize && x + i < gridSize && y - i < gridSize; ++i)
                    {
                        if (curWord.at(i) == grid.at(x + i).at(y + i))
                            {
                                foundWord.push_back(curWord.at(i));
                                
                                if(curWord == foundWord)
                                {
                                    foundList.push_back(foundWord);
                                }
                            }
                    }
                    foundWord.clear();
                }
            }
    }
}

void checkDownLeft (const vector <vector <char> > &grid, string curWord, vector <string> &foundList)
{
    int gridSize = grid.size();
    int rowSize;
    int curWordSize = curWord.size();
    string foundWord = "";
    
    for(int x = 0; x < gridSize && x >= 0 ; ++x)
    {
        rowSize = grid.at(x).size();
        for(int y = rowSize-1; y >= 0 && y < rowSize; --y)
            {
                if(curWord.at(0) == grid.at(x).at(y) 
                    && curWordSize - 1  <= (gridSize - x +1)
                    && curWordSize - 1  <=  (y))
                {
                    for(int i = 0; i < curWordSize && x + i < gridSize && y - i > 0; ++i)
                    {
                        if (curWord.at(i) == grid.at(x + i).at(y - i))
                            {
                                foundWord.push_back(curWord.at(i));
                                
                                if(curWord == foundWord)
                                {
                                    foundList.push_back(foundWord);
                                }
                            }
                    }
                    foundWord.clear();
                }
            }
    }
}

void checkUpRight (const vector <vector <char> > &grid, string curWord, vector <string> &foundList)
{
    int gridSize = grid.size();
    int rowSize;
    int curWordSize = curWord.size();
    string foundWord = "";
    
    for(int x = gridSize -1; x < gridSize && x >= 0; --x)
    {
        rowSize = grid.at(x).size();
        for(int y = 0; y < rowSize; ++y)
            {
                if(curWord.at(0) == grid.at(x).at(y) 
                    && curWordSize - 1  <= (x)
                    && curWordSize - 1  <=  (gridSize - y +1))
                {
                    for(int i = 0; i < curWordSize && x + i > 0 && y - i < rowSize; ++i)
                    {
                        if (curWord.at(i) == grid.at(x - i).at(y + i))
                            {
                                foundWord.push_back(curWord.at(i));
                                
                                if(curWord == foundWord)
                                {
                                    foundList.push_back(foundWord);
                                }
                            }
                    }
                    foundWord.clear();
                }
            }
    }
}

void checkUpLeft (const vector <vector <char> > &grid, string curWord, vector <string> &foundList)
{
    int gridSize = grid.size();
    int rowSize;
    int curWordSize = curWord.size();
    string foundWord = "";
    
    for(int x = gridSize -1; x < gridSize && x >= 0; --x)
    {
        rowSize = grid.at(x).size();
        for(int y = rowSize-1; y >= 0 && y < rowSize; --y)
            {
                if(curWord.at(0) == grid.at(x).at(y) 
                    && curWordSize - 1  <= (x)
                    && curWordSize - 1  <= (y))
                {
                    for(int i = 0; i < curWordSize && x + i >= 0 && y - i >= 0; ++i)
                    {
                        if (curWord.at(i) == grid.at(x - i).at(y - i))
                            {
                                foundWord.push_back(curWord.at(i));
                                
                                if(curWord == foundWord)
                                {
                                    foundList.push_back(foundWord);
                                }
                            }
                    }
                    foundWord.clear();
                }
            }
    }
}

int main()
{
    vector <vector <char> > grid;
    vector <string> list;
    vector <string> foundList;
    
    string curWord = "DOCTOR";
    
    int listSize = list.size();
    
    getGrid(grid);
    getList(list);
    
    //printGrid(grid);
    //printList(list);
    
    
    while("POND" == "POND")
    {
        listSize = list.size();
        for(int l = 0; l < listSize; ++l)
            {
                curWord = list.at(l);
            
                checkUp(grid, curWord, foundList); 
                            
                checkDown(grid, curWord, foundList);
                        
                checkRight(grid, curWord, foundList);
                        
                checkLeft(grid, curWord, foundList);
                
                checkDownRight(grid, curWord, foundList);
                
                checkDownLeft(grid, curWord, foundList); 
                
                checkUpRight(grid, curWord, foundList); 
                
                checkUpLeft(grid, curWord, foundList);
            }
        break;
    }
    
    sort (foundList.begin(), foundList.end());
    printFoundList(foundList);
    
    return 0;
}

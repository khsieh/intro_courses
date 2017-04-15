//Course: CS10 <fall,2012>
//
//First Name: Kevin
//Last Name: Hsieh
//Course username:khsie003
//Email address:khsie003@ucr.edu
//
//Lecture Section: 001
//Lab Section: 021
//TA:Zhe Wu
//
//Assignment: Assignment9
//
//I hereby certify that the code in this file
//is ENTIRELY my own original work.
//
//=================================================================

#include <vector>
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;


const bool CLEAR_SCREEN = true;


/**
    @brief Utilizes an escape character sequence to clear the screen
*/
void clearScreen()
{
	cout << endl;

	if (CLEAR_SCREEN)
	{
		cout << "\033c" << endl;
    }

    cout << endl;
}


/** 
 *  @brief Draws the provided tic-tac-toe board to the screen
 *  @param board is the tic-tac-toe board that should be drawn
 */
void drawBoard(const vector<char> &board)
{
    clearScreen();
    for (int i=0; i<9; i+=3)
    {
        cout << "  " << board.at(i) << "  |  " << board.at(i+1) << "  |  "
             << board.at(i+2) << "  " << endl;
        if (i < 6)
            cout << "-----|-----|-----" << endl;
    }
    cout << endl;
}


/**
 *  @brief Converts character position to appropriate vector index for board
 *
 *      For example, 'a' is converted to 0, 'd' is converted to 3, etc.
 *
 *  @param position the character to be converted to a vector index
 *  @return the integer index in the vector, should be 0 to (vector size - 1)
 */
int convertPosition(char position)
{
    int positionInt;
    if(position == 'a') positionInt = 0;
    else if (position == 'b') positionInt = 1;
    else if (position == 'c') positionInt = 2;
    else if (position == 'd') positionInt = 3;
    else if (position == 'e') positionInt = 4;
    else if (position == 'f') positionInt = 5;
    else if (position == 'g') positionInt = 6;
    else if (position == 'h') positionInt = 7;
    else if (position == 'i') positionInt = 8;
    else positionInt = -1;
    
    return positionInt; 
}


/**
 *  @brief Predicate function to determine if a spot in board is available.
 *  @param board the current tic-tac-toe board 
 *  @param position is an index into vector to check if available
 *  @return true if position's state is available (not marked) AND is in bounds
 */
bool validPlacement(const vector<char> &board, int position)
{
    if(board.at(position) != 'O' && board.at(position) != 'X' 
       && position >= 0 && position <= 8)
    return true;
    
    else return false;
}


/**
 *  @brief Acquires a play from the user as to where to put her mark
 *
 *      Utilizes convertPosition and validPlacement functions to convert the
 *      user input and then determine if the converted input is a valid play.
 *
 *  @param board the current tic-tac-toe board 
 *  @return an integer index in board vector of a chosen available board spot
 */
int getPlay(const vector<char> &board)
{
    char play;
    int playint;
    
    while("TARDIS" == "TARDIS")
    {
        cout << "Please choose a position: " << endl;
        cin >> play;
    
        playint = convertPosition(play);
    
        if(playint != -1 && validPlacement(board, playint)) 
        {
            return playint;
        }
        
    }
}


/**
 *  @brief Predicate function to determine if the game has been won
 *
 *  Winning conditions in tic-tac-toe require three marks from same 
 *  player in a single row, column or diagonal.
 *
 *  @param board the current tic-tac-toe board 
 *  @return true if the game has been won, false otherwise
 */
bool gameWon(const vector<char> &board)
{
    if(board.at(0) == board.at(1) && board.at(0) == board.at(2))
        return true;
    else if(board.at(3) == board.at(4) && board.at(3) == board.at(5))
        return true;
    else if(board.at(6) == board.at(7) && board.at(6) == board.at(8))
        return true;
    else if(board.at(0) == board.at(3) && board.at(0) == board.at(6))
        return true;    
    else if(board.at(1) == board.at(4) && board.at(1) == board.at(7))
        return true;
    else if(board.at(2) == board.at(5) && board.at(2) == board.at(8))
        return true;
    else if(board.at(0) == board.at(4) && board.at(0) == board.at(8))
        return true;
    else if(board.at(2) == board.at(4) && board.at(2) == board.at(6))
        return true;
    else
        return false;
}


/**
 *  @brief Predicate function to determine if the board is full
 *  @param board the current tic-tac-toe board 
 *  @return true if the board is full (no cell is available)
 */
bool boardFull(const vector<char> &board)
{
    if(board.at(0) != 'a' && board.at(1) != 'b' && board.at(2) != 'c' &&
       board.at(3) != 'd' && board.at(4) != 'e' && board.at(5) != 'f' &&
       board.at(6) != 'g' && board.at(7) != 'h' && board.at(8) != 'i' )
       return true;
    else if((board.at(0) == 'X' || board.at(0) == 'O') 
         && (board.at(1) == 'X' || board.at(1) == 'O')
         && (board.at(2) == 'X' || board.at(2) == 'O')
         && (board.at(3) == 'X' || board.at(3) == 'O')
         && (board.at(4) == 'X' || board.at(4) == 'O')
         && (board.at(5) == 'X' || board.at(5) == 'O')
         && (board.at(6) == 'X' || board.at(6) == 'O')
         && (board.at(7) == 'X' || board.at(7) == 'O')
         && (board.at(8) == 'X' || board.at(8) == 'O'))
         return true;
    else
        return false;
}


// Global constants for player representation
const int PLAYER1 = 0;
const int PLAYER2 = 1;

int main()
{
    // use the following variables to store the tic-tac-toe board 
    vector<char> board(9);

    // the current position to play, acquired from player
    // is a valid tic-tac-toe board index 
    int cur_play;

    // whose turn it currently is, changes at end of a turn
    int turn = PLAYER1;
     

    // Initialize board to empty (places 'a' through 'i' in board)
    
    
    char spot = 'a';
    int boardsize = board.size();
    for (int n = 0; n < boardsize; n++)
    {
        board.at(n) = spot;
        spot++;
    }
    
    // Display empty board
    
    drawBoard(board);
    
    bool player1win = false;
    bool player2win = false;
    
    // keep performing turns until game over

    while( gameWon(board) == false && boardFull(board) == false )
    {
    // Get a play

        // Update proper board spot with current player's marking
        if(turn == 0)
        {
            cur_play = getPlay(board);
            board.at(cur_play) = 'X';
            
            drawBoard(board);
            
            if(gameWon(board))
            {
                cout << "Player 1 (X's) wins!" << endl;
                break;
            }
            
            if (boardFull(board) && player1win == false)
            {
                cout << "No one wins" << endl;
                break;
            }
        
            turn = PLAYER2;
            
        }
    
    if(turn == 1)
        {
        // Switch the turn to the other player
            cur_play = getPlay(board);
            board.at(cur_play) = 'O';

        // Output the updated board
                        
            drawBoard(board);
            
            if(gameWon(board))
            {
                cout << "Plater 2 (O's) wins!" << endl;
                break;
            }
            
            if (boardFull(board) && player2win == false)
            {
                cout << "No one wins" << endl;
                break;
            }
                
                
            turn = PLAYER1;
            
        }
          
    
    }
    // TODO: Game Over - Output who won, if someone did.
    
    
    
    // Output must be one of these 3 options (exactly like these)
         // "Player 1 (X's) wins!"
         // "Player 2 (O's) wins!"
         // "No one wins"
       
    return 0;
}

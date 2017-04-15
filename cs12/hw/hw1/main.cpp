// Course: CS 12 <winter 2013>
//
// First Name:Kevin
// Last Name: Hsieh
// Login id: khsie003
// email address: khsie003@ucr.edu
//
// Lecture Section: 001
// Lab Section: 23
// TA: Mike Izbicki
//
// Assignment: assgn1
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ================================================================

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

/**
 * calculate the magic number by using the the formula
 * 2^n - 1
 * returns the magic number
 */ 
double powers_of_2(int& n)
{
    double magic_number = pow(2.0,n) - 1;
    return magic_number;
}

/**
 * determine the action of the computer by checking gamemode
 * if naive take random valid number of marbles
 * if smart use powers of 2 strategy
 */
void computer_play(int& total_marble, string game_mode)
{
    int take_marble = 101;
    srand(time(NULL));
    
    cout << "Total Marble: " << total_marble << endl;
    
    //naive mode
    if(game_mode == "naive" || game_mode == "n")
    {
        take_marble = 1 + rand() % (total_marble/2);
        total_marble = total_marble - take_marble;
        cout << "Computer takes " << take_marble << " marbles." << endl;
    }
    
    //smart mode
    else
    {
        int n = 0;
        double magic_number;
        
        //find the number n and check if take_marble is valid
        while(take_marble > total_marble/2)
        {
            magic_number = powers_of_2(n);
            //cout << " magic num is " << magic_number << endl;
            
            take_marble = total_marble - static_cast<int>(magic_number);
            //cout << " take marble is " << take_marble << endl;
            n++;
        }
        
        if(total_marble == magic_number)
        {
            take_marble = 1 + rand() % (total_marble/2);
        }
        
        total_marble = total_marble - take_marble;
        
        cout << "Computer takes " << take_marble << " marbles." << endl << endl;
    }
}

/**
 * ask user to remove marble and check if it is a valid number
 * remove if valid, ask again if not
 */
void user_play(int& total_marbles)
{
    int take_marble;
    
    cout << "Total marbles: "<< total_marbles << endl
         << "How many would you like to remove? ";
    cin  >> take_marble;
    cout << endl;
    
    //check if user input is valid
    while(take_marble > (total_marbles/2) || take_marble < 1)
    {
        cout << "Invalid input, please enter another number: ";
        cin >> take_marble;
    }
    
    total_marbles = total_marbles - take_marble;
}

/**
 * checks for if total_marble reaches 1, if so, check for who's turn is it
 * and then determine winner accordingly 
 */ 
void determine_win(double total_marble, char play_turn, bool& win)
{
    if(total_marble == 1)
    {
        win = true;
        if(play_turn == 'c')
        {
            cout << "Total Marble: " << total_marble << endl << endl
                 << "You Took The Last Marble" << endl
                 << "The Computer Beat You! T_T" << endl << endl;
        }
        else if (play_turn == 'u')
        {
            cout << "Total Marble: " << total_marble << endl << endl
                 << "The Computer Took The Last Marble" << endl 
                 << "CONGRATULATIONS! YOU WON!" << endl << endl;
        }
    }
}

int main()
{
    //srand(time(NULL));
    
    int total_marble;
    int start_first;
    char play_turn;
    string game_mode;
    string play_game = "y";
    bool win;
    
    
    while(play_game == "y" || play_game == "yes")
    {
        start_first = rand() % (2);
        //cout << start_first << endl;
        total_marble = 10 + rand() % (91);
        
        win = false;
        
        cout << "Welcome to the Game of Nim!" << endl
             << "Choose a game mode: naive(n) or smart(s) ";
        cin  >> game_mode;
        cout << "\nGAME START!" << endl << endl;
        
        //computer starts first
        if(start_first == 0)
        {
            cout << "The computer starts first!" << endl;
            while(total_marble > 0)
            {
                //let computer play and check for win
                computer_play(total_marble,game_mode);
                play_turn = 'c';
                determine_win(total_marble,play_turn,win);
                if(win) break;
                
                //let user play and check for win
                user_play(total_marble);
                play_turn = 'u';
                determine_win(total_marble,play_turn,win);
                if(win) break;
            }
        }
        
        //user starts first
        else
        {
            cout << "You start first!" << endl;
            while(total_marble > 0)
            {
                //let user play and check for win
                user_play(total_marble);
                play_turn = 'u';
                determine_win(total_marble,play_turn,win);
                if(win) break;
                
                //let computer paly and check for win
                computer_play(total_marble,game_mode);
                play_turn = 'c';
                determine_win(total_marble,play_turn,win);
                if(win) break;
            }
        }
        //ask user if continue playing The game of Nim
        cout << "play again? yes(y) or no(n)  ";
        cin  >> play_game;
        
        //if start a new game, clear screen for better interface
        if(play_game == "yes" || play_game == "y")
        {
            cout << "\033c";
        }
    }
    
    //if user did not continue game, output message and end program
    cout << "\nThank you for playing! :D" << endl << endl;
    
    return 0;
}

//course : CS10 <fall,12>
//
//First name: Kevin
//Last name: Hsieh
//Course username: khsie003
//email address: khsie003@ucr.edu
//
//Lecture section: 001
// Lab section: 021
//TA: Zhe Wu
//
//Assignment: assignment 8
//
//I hereby certify that the code in this file
//is ENTIRELY my own original work
//
//===========================================================================

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstddef>
#include <cstdlib>

using namespace std;

//monster takse all bananas and oranges
void monsterRoom(string monsterName, int& banana, int& orange)
{
    banana = 0;
    orange = 0;
    cout << "WATCH OUT!!" << endl
         << monsterName 
         << " attacks you and steals all of your bananas and oranges."
         << endl << endl;
}

//genie gives two additional bananas and one additional orange
void genieRoom(int& banana, int& orange)
{
    banana += 2;
    orange += 1;
    cout << "!!POOF!!" << endl
         << "A genie pops out and grants you 2 bananas and 1 orange."
         << endl << endl;
         
}

//cout a picture of R2-D2
void drawPicture()
{
    cout << "       _--~~--_" << endl;
    cout << "     /~/_|  |_\\~\\" << endl;
    cout << "    |____________|" << endl;
    cout << "    |[][][][][][]|" << endl;
    cout << "  __| __         |__" << endl;
    cout << " |  ||. |   ==   |  |" << endl;
    cout << "(|  ||__|   ==   |  |)" << endl;
    cout << " |  |[] []  ==   |  |" << endl;
    cout << " |  |____________|  |" << endl;
    cout << " /__\\            /__\\" << endl;
    cout << "  ~~              ~~" << endl;
    cout << endl;
}

//cout statment and use drawPicture function
void pictureRoom()
{
    cout << "You found a picture!" << endl << endl;
    drawPicture();
}

int main()
{
    int banana = 5;
    int orange = 3;
    int DoorSetUp;
    
    string monsterName;
    string player;
    
    bool Exit = false;
    bool checkDirection = false;
    char direction = ' ';
    
    srand(500);
    DoorSetUp = rand() % (2);
        
    
    cout << "Please enter your name: " << endl;
    cin >> player;
    cout << "Name your scariest monster: " << endl;
    cin >> monsterName;
        
    while(Exit == false)
    {
        
        cout << player << ", you are in a room with 4 doors." << endl
             << "You are carrying " 
             << banana << " bananas and " << orange << " oranges." 
             << endl << endl;
        cout << "Pick a door to enter by typing the direction"
             << " it is in (N/E/S/W): " << endl;
        cin >> direction;
        
        while (checkDirection == false)
            {
                if(direction == 'N' || direction == 'S' ||
                   direction == 'W' || direction == 'E')
                   {
                        checkDirection = true;
                    }
                else if(direction != 'N' || direction != 'S' ||
                   direction != 'W' || direction != 'E')
                    {
                        cout << "Pick a door to enter by typing the direction"
                             << " it is in (N/E/S/W): " <<endl;
                        cin >> direction;
                        checkDirection = false;
                    }
            }
        
    //
    //      Alignment 0       Alignment 1
    //N:    Monster           Exit
    //S:    Genie             Monster
    //E:    Picture           Genie
    //W:    Exit              Picture
    //
    
    if(DoorSetUp == 0)
    {
        if(direction == 'N') monsterRoom(monsterName, banana, orange);
        if(direction == 'S') genieRoom(banana, orange);
        if(direction == 'E') pictureRoom();
        if(direction == 'W') 
            {
                cout << "You found the exit!" << endl;
                cout << "Your score is " << banana + orange
                     << " (" << banana
                     << " bananas and "
                     << orange
                     << " oranges).";
                cout << endl << "Bye bye!!!" << endl;
                Exit = true;
            }
    }
    
    if(DoorSetUp == 1)
    {
        if(direction == 'S') monsterRoom(monsterName, banana, orange);
        if(direction == 'E') genieRoom(banana, orange);
        if(direction == 'W') pictureRoom();
        if(direction == 'N') 
            {
                cout << "You found the exit!" << endl;
                cout << "Your score is " << banana + orange
                     << " (" << banana
                     << " bananas and "
                     << orange
                     << " oranges).";
                cout << endl << "Bye bye!!!" << endl;
                Exit = true;
            }
    }
    
    DoorSetUp = rand( ) % 2;
    checkDirection = false;
    
    }
    
    return 0;
}

// Course: CS 10 fall quarter 2012
//
// First Name: Kevin
// Last Name: Hsieh
// Course username: CS-10
// Email address: khsie003@ucr.edu 
//
// Lecture Section: 001
// Lab Section: 021
// TA: Zhe Wu
//
// Assignment: assignment7
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================

#include <iostream>
#include "assn.h"
#include <string>

/**
@brief Puts dashes in place of alphabetic characters in phrase.
@param phrase the phrase to be solved
@return the phrase with all alphabetic characters converted to dashes
*/

string setupUnsolvedPhrase (string phrase)
{
    int size = phrase.size();
    string unsolved;
    for (int i = 0; i < size; i++) 
    {        
        if(isalpha(phrase.at(i)))
        phrase.at(i)= '-';
    }
    unsolved = phrase;
    return unsolved;
}

/**
@brief Replaces the dashes with the guessed character.
@param phrase the phrase to be solved
@param unsolved the phrase with dashes fo rall unsolvedc haracters
@param guess the char containing the current guessed character
@return the new unsolved string with dashes replaced by new guess
*/

string updateUnsolvedPhrase(string phrase, string unsolved, char guess)
{
    
    for(unsigned int i = 0; i < phrase.size(); i++)
    if (guess == phrase.at(i))
    unsolved.at(i) = guess;
    return unsolved;
}

/**
@brief Gets valid guess as input.
A guess is taken as input as a character. It is valid if
1)it is an alphabetic character and
2)the character has not already been guessed
@param prevGuesses the string containing all characters guessed so far
@return a valid guess and only a valid guessas a character
*/

char getNewGuess(string prevGuesses)
{
    char newGuess;
    bool notUsed;
    int i = prevGuesses.size();
    
    while(1 == 1)
    {
        notUsed = true;
        cin >> newGuess;
        for(int a = 0; a < i ; a++)
            {
            if(newGuess == prevGuesses.at(a)) notUsed = false;
            }
    
        if(isalpha(newGuess) && notUsed)
            {
            return newGuess;
            }
    
    cout << "Invalid guess! Please re-enter a guess: " << endl;
    }
}


int main ()
{
    string phrase;
    string unsolved;
    string prevGuesses = "";
    int guessCount = 7;
    
    cout << "Enter a phrase: " << endl;
    getline(cin, phrase);
    
    clearScreen();
    
    cout << endl;
    unsolved = setupUnsolvedPhrase(phrase);
    cout << "Phrase: " << unsolved << endl;
    char newGuess = ' ';
    
    while(unsolved != phrase)
    {
        string solving = unsolved;
        cout << endl << "Enter a guess: " << endl;
        newGuess = getNewGuess(prevGuesses);
        
        unsolved = updateUnsolvedPhrase(phrase, unsolved,newGuess);

        if (solving == unsolved) guessCount--;
        
        
        prevGuesses += newGuess;
        
        clearScreen();
        cout << endl;
        cout << "Phrase: " << unsolved << endl << endl;
        cout << "Guessed so far: " << prevGuesses << endl;
        cout << "Wrong guesses left: " << guessCount << endl;
    
        if(unsolved == phrase)
        {
            cout << endl << "Congratulations!!" << endl;
            break;
        }
    
        if (guessCount == 0 && unsolved != phrase)
        {
            cout << endl << "You lost!" << endl;
            break;
        }
    
    }
    
    return 0;
}

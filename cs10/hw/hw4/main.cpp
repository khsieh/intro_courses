//course : CS 10 Fall Quarter 2012
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
//Assignment: Assignment 4
//
//I hereby certify that the code in this file
//is ENTIRELY my own original work
//
//===========================================================================

#include <iostream>
#include "assn.h"
#include <iomanip>

using namespace std;

int main ()
{
    string word;
    double index;
    index = 0;
    
    int wordSum;
    wordSum = 0;
    
    int sentence;
    sentence = 0;
    
    int syllable;
    syllable = 0;
    
    int a = 0;
    int i;
    int skips;
    int c;
    
    
    while(cin >> word)
    {
        wordSum++;
        c = syllable;
        a = word.size();
        
        for(i = 0; i < a; i++)
        {
            if(is_vowel( word.at(i) ) )
            {
                syllable++;
                skips = 0;
                for(int b = i + 1; b < a && is_vowel(word.at(b)); b++) 
                {
                    skips++;
                }
                i += skips;
            }
         } 
        
        if( c == syllable)
        {
            syllable++;
        }
        
        int w = word.size() - 1;
        
        if ( word.at(w) == '!' || word.at(w) == '?' || word.at(w) == '.' 
            || word.at(w) == ':' || word.at(w) == ';')
            {
                sentence++;
            }
        
    }
    
    
    cout << "Words: " << wordSum << endl 
         << "Syllables: " << syllable << endl 
         << "Sentences: " << sentence << endl;
    
    index = static_cast<double>( 206.835 - 84.6 * syllable / 
        wordSum - 1.105 * wordSum /
        sentence);
    index = index + 0.5;
    index = static_cast<int>(index);
    
    cout << "Legibility Index: " << index << endl;
    
    return 0;
}

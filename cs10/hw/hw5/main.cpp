//course : CS 10 Fall Quarter 2012
//
//First name: Kevin
//Last name: Hsieh
//Course username: khsie003
//email address: khsie003@ucr.edu
//
//Lecture section: 001
//Lab section: 021
//TA: Zhe Wu
//
//Assignment: Assignment 5
//
//I hereby certify that the code in this file
//is ENTIRELY my own original work
//
//===========================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>


using namespace std;


int main ()
{
    int r;
    int rollnum = 1;
    int score = 0;
    int a = 1;
    int b = 6;
    int round = 0;
    
    int s0 = 0;
    int s20 = 0;
    int s21 = 0;
    int s22 = 0;
    int s23 = 0;
    int s24 = 0;
    int s25 = 0;
    
    double maxround = 0;
    
    double prob0 = 0;
    double prob20 = 0;
    double prob21 = 0;
    double prob22 = 0;
    double prob23 = 0;
    double prob24 = 0;
    double prob25 = 0;
    
        
    cout << "Hold-at-20 turn simulations?" << endl;
    cin >> maxround;
    cout << endl;
    cout << fixed << setprecision(6); 
    
    srand(1000);
    
    while(round != maxround)
    { score = 0;
        
        do
        {
        
        // min + rand() % (max - min + 1)
        r = a + rand() % (b - a + 1);
        
        score = r + score;
        
        
        if(r == 1) 
        {
            score = 0;
            break;
        }
        
    //cout << "Roll " << rollnum << ": " << r << endl;
        rollnum++;
        }
        while (score < 20);

    
    //cout << "Total score: " << score << endl;
    
    if(score == 0) {s0++;}
    if(score == 20) {s20++;}
    if(score == 21) {s21++;}
    if(score == 22) {s22++;}
    if(score == 23) {s23++;}
    if(score == 24) {s24++;}
    if(score == 25) {s25++;}
    
    round++;
    
    }
    
    
    if(s0 != 0) 
    {prob0 = static_cast<double>(s0 / maxround);}
    if(s20 != 0) 
    {prob20 = static_cast<double>(s20 / maxround);}
    if(s21 != 0) 
    {prob21 = static_cast<double>(s21 / maxround);}
    if(s22 != 0) 
    {prob22 = static_cast<double>(s22 / maxround);}
    if(s23 != 0) 
    {prob23 = static_cast<double>(s23 / maxround);}
    if(s24 != 0) 
    {prob24 = static_cast<double>(s24 / maxround);}
    if(s25 != 0) 
    {prob25 = static_cast<double>(s25 / maxround);}
    
    cout << "score\tEstimated Probability" << endl;
    cout << "0\t"  << prob0 << endl;
    cout << "20\t" << prob20 << endl;
    cout << "21\t" << prob21 << endl;
    cout << "22\t" << prob22 << endl;
    cout << "23\t" << prob23 << endl;
    cout << "24\t" << prob24 << endl;
    cout << "25\t" << prob25 << endl;
    
    
    return 0;
}

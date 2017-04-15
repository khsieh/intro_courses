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
// Assignment: assignment6
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================

#include <iostream>
#include <iomanip>
#include "assn.h"

using namespace std;

int main()
{
    //the current tax rate
    const double TAX = .075;
	string itemFTW;
    
    string transActionNum;
    string cashierNum;
    string itemBought;
    string item;
    
    double Price = 0;
    double TotalPrice = 0;
    double C0Price = 0;
    double C1Price = 0;
    double C2Price = 0;
    
    double C0LargestSale = 0;
    double C1LargestSale = 0;
    double C2LargestSale = 0;
    
    int C0Count = 0;
    int C1Count = 0;
    int C2Count = 0;
    
    int C0FTWCount = 0;
    int C1FTWCount = 0;
    int C2FTWCount = 0;
    
    int pos = 0;
    //input item for the week
    cin >> itemFTW;
    //input one line of transaction
   while(cin >> transActionNum >> cashierNum >> itemBought)
    {
        if(cashierNum == "0") C0Count++; //cashier0 count
        if(cashierNum == "1") C1Count++; //cashier1 count
        if(cashierNum == "2") C2Count++; //cashier2 count
       
        pos = itemBought.find(',');
        TotalPrice = 0;
        
        //going through each line of itemBought
        
        while(pos != -1)
        {
        
        pos = itemBought.find(','); 
        item = itemBought.substr(0,pos);
        
        //check if item is Taxed
        
        if(isTaxed(item) == true) 
        Price = getItemPrice(item ) + getItemPrice(item) * TAX;
        else Price = getItemPrice(item);
        
        //add up total price of each transaction line
        
        TotalPrice = TotalPrice + Price;
        
        //check for item for the week sales
        //add to each cahsier count for item for the week
        
        if(item == itemFTW)
            {
            if(cashierNum == "0") C0FTWCount++;
            if(cashierNum == "1") C1FTWCount++;
            if(cashierNum == "2") C2FTWCount++;
            }
        
        itemBought = itemBought.substr(pos + 1);
        
        }
        
        //assign total price to each cashier after each line of transaction        
        if(cashierNum == "0") 
        C0Price = C0Price + TotalPrice;
        if(cashierNum == "1") 
        C1Price = C1Price + TotalPrice;
        if(cashierNum == "2") 
        C2Price = C2Price + TotalPrice;
        
        //assign single largest sale to each cashier
        if(cashierNum == "0" && C0LargestSale < TotalPrice) 
        C0LargestSale = TotalPrice;
        if(cashierNum == "1" && C1LargestSale < TotalPrice) 
        C1LargestSale = TotalPrice;
        if(cashierNum == "2" && C2LargestSale < TotalPrice) 
        C2LargestSale = TotalPrice;
        
    }
        
    cout << fixed << setprecision(2); 
    
    //Sale of the Week
    string SOTW;
    SOTW = determineWinner(C0LargestSale,C1LargestSale,C2LargestSale);
    //Item of item Week
    string IOTW;
    IOTW = determineWinner(C0FTWCount,C1FTWCount,C2FTWCount);
    //Best Total Sale
    string BTS;
    BTS = determineWinner(C0Price,C1Price,C2Price);
    
    //out put result
    cout << "item of the week: " << itemFTW << endl
         << "Largest Single Sale Seller: " 
         << getCashierName(SOTW) 
         << endl
         << "Best Item Of The Week Seller:" 
         << getCashierName(IOTW) 
         << endl
         << "Best At Total Sales: " 
         << getCashierName(BTS) 
         << endl
         << endl
         << "Individual\t\t" 
         << getCashierName("0") 
         << "\t" 
         << getCashierName("1") 
         << "\t" 
         << getCashierName("2")
         << endl
         << "Total Sales\t\t" 
         << C0Price << "\t" 
         << C1Price << "\t" 
         << C2Price<< endl
         << "Largest Single Sale\t" 
         << C0LargestSale << "\t" 
         << C1LargestSale << "\t" 
         << C2LargestSale << endl
         << "Item Of Week Sales\t" 
         << C0FTWCount << "\t" 
         << C1FTWCount << "\t" 
         << C2FTWCount << endl;
        
	return 0;
}

// Course: CS 12 <winter,13>
//
// First Name: Kevin
// Last Name:  Hsieh
// Login id: khsie003
// email address: khsie003@ucr.edu
//
// Lecture Section: 001
// Lab Section: 023
// TA:Mike Izbicki
//
// Assignment: assn5
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ================================================================

#include <iostream>
#include "intlist.h"

using namespace std;


void test0(IntList& list)
{
    cout << "IntList: ";
    list.print();
    cout << "Check select_sorted | sorted: 1 && size: 0" << endl;
    list.select_sort();
    cout << "IntList: ";
    list.print();
    cout <<"Size: " << list.size() << endl;
    cout << "Sorted: " << list.is_sorted() << endl;
    cout << "==========================================================="
         << endl;
}

void test1(IntList& list)
{
    cout << "IntList: ";
    list.print();
    cout << "Push Front | push_front(5) | 5" << endl;
    list.push_front(5);
    cout << "IntList: ";
    list.print();
    cout <<"Size: " << list.size() << endl;
    cout << "Sorted: " << list.is_sorted() << endl;
    cout << "==========================================================="
         << endl;
}

void test2(IntList& list)
{
    cout << "IntList: ";
    list.print();
    cout << "Push Back: push_back(3) | 5 5 3" << endl;
    list.push_back(3);
    cout << "IntList: ";
    list.print();
    cout <<"Size: " << list.size() << endl;
    cout << "Sorted: " << list.is_sorted() << endl;
    cout << "==========================================================="
         << endl;
}

void test3(IntList& list)
{
    cout << "IntList: ";
    list.print();
    cout << "Pop front: pop_front() | 5 3 " << endl;
    list.pop_front();
    cout << "IntList: ";
    list.print();
    cout <<"Size: " << list.size() << endl;
    cout << "Sorted: " << list.is_sorted() << endl;
    cout << "==========================================================="
         << endl;
}

void test4(IntList& list)
{
    cout << "IntList: ";
    list.print();
    cout << "Insert Sorted: inster_sorted(2) | 2 3 5" << endl;
    list.insert_sorted(2);
    cout << "IntList: ";
    list.print();
    cout <<"Size: " << list.size() << endl;
    cout << "Sorted: " << list.is_sorted() << endl;
    cout << "==========================================================="
         << endl;
}
void test5(IntList& list)
{
    cout << "IntList: ";
    list.print();
    cout << "Insert Sorted: inster_sorted(6) | 2 3 5 6" << endl;
    list.insert_sorted(6);
    cout << "IntList: ";
    list.print();
    cout <<"Size: " << list.size() << endl;
    cout << "Sorted: " << list.is_sorted() << endl;
    cout << "==========================================================="
         << endl;
}
void test6(IntList& list)
{
    cout << "IntList: ";
    list.print();
    cout << "Insert Sorted: inster_sorted(4) | 2 3 4 5 6" << endl;
    list.insert_sorted(4);
    cout << "IntList: ";
    list.print();
    cout <<"Size: " << list.size() << endl;
    cout << "Sorted: " << list.is_sorted() << endl;
    cout << "==========================================================="
         << endl;
}
void test7(IntList& list)
{
    cout << "IntList: ";
    list.print();
    cout << "remove duplicates: remove duplicates |" << endl;
    list.remove_duplicates();
    cout << "IntList: ";
    list.print();
    cout <<"Size: " << list.size() << endl;
    cout << "Sorted: " << list.is_sorted() << endl;
    cout << "==========================================================="
         << endl;
}

int main()
{
    cout << "IntList: ";
    IntList list;
    cout << "\033c";
    
    cout << "====================TEST HARNESS!=========================="
         << endl;
    //select sorted
    test0(list);
    
    //=====push front=====//
    test1(list);
    test1(list);
    
    //=====push back=====//
    test2(list);
    
    //=====pop front====//
    test3(list);
    
    //slect sorted
    list.select_sort();
    cout << "sorted" << endl
         << "==========================================================="
         << endl;
    //===========insert sorted================//
    if(list.is_sorted())
    {
        test4(list);
        test5(list);
        test6(list);
    }
    
    //=======remove duplicates 1=====//
    cout << "sorted" << endl;
    list.insert_sorted(3);
    list.insert_sorted(5);
    //list.print();
    test7(list);
    
    //=======remove duplicates 2=====//
    IntList list2 = list;
    cout << "not sorted" << endl;
    list2.push_front(6);
    //list2.push_back(5);
    //list2.print();
    test7(list2);
    
    //=======remove duplicates 3=====//
    IntList list3;
    cout << "more than two duplicates" << endl;
    list3.push_back(5);
    list3.push_back(6);
    list3.push_back(1);
    list3.push_back(6);
    list3.push_back(3);
    list3.push_back(6);
    list3.push_back(7);
    
    test7(list3);
    
    //=======remove duplicates 4=====//
    IntList list4;
    cout << "more than 2 right next to each other" << endl;
    list4.push_back(5);
    list4.push_back(6);
    list4.push_back(6);
    list4.push_back(6);
    list4.push_back(6);
    list4.push_back(6);
    list4.push_back(7);
    
    test7(list4);
    
    return 0;
}

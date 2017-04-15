#include <iostream>
#include <vector>

using namespace std;


//Doubles the capacity of the array. Called by push_back function when needed
void extend(string* & str_array, unsigned& cap, unsigned& str_l)
{
    (cap *= 2);
    
    string* temp = str_array;
    str_array = new string[cap];

    for(unsigned i = 0; i < (cap / 2); ++i)
    {
        str_array[i] = temp[i];
    }
    
    delete [] temp;
}


/* Gets a string and a dynamic string array, 
 * and adds the string to the end of the array. 
 * If the capacity of the array is reached, 
 * it calls the extend function to double the capacity. 
 */ 
void push_back( string& str, string* & str_array, unsigned& str_l, unsigned& cap)
{
    if(str_l == cap)
        extend(str_array, cap, str_l); //double the cap
    str_array[str_l] = str;
    ++str_l;
}

//computes and returns the average size of strings in the array.
double average_size( string* str_array, unsigned cap)
{
    double avg;
    
    for(unsigned p = 0; p < cap; ++p)
    {
        avg += str_array[p].size();
    }
    
    avg = avg / cap;
    
    return avg;    
}

//Prints all strings in the array, on one line, separated by spaces. 
void print( string* str_array, unsigned int cap)
{
    for(unsigned p(0); p < cap; ++p)
    {
        cout << str_array[p] << " ";
    }
}

int main()
{
    unsigned int str_l = 0;
    unsigned int cap = 3;
    string* str_array = new string[3];
    
    bool done = false;
    string str;
    
    cout << "\033c";
    
    cout << "Enter strings ('.' to exit): " << endl;   
    
    while(!done)
    {
             
        cin >> str;
        if(str == ".")
            done = true;
        else if(str.at(str.size() - 1) == '.')
        {
            push_back(str,str_array,str_l,cap);
            done = true;
        }
        else
            push_back(str,str_array,str_l,cap);
        //cout << str_l << " " << cap << endl;
        
    }
    
    cout << "average char in each string: " << average_size(str_array,str_l)
         << endl;
    
    print(str_array, cap);
    cout << endl;
    //cout << endl << cap << " " << str_l << endl;
    
    return 0;
}

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;


int rand_gen( int max, int min)
{
    int range = max - min;
    if (range < 0) range = -range;
    range += 1;
    return max + (rand() % range);
}

void generate_data_set(vector <int> &v, unsigned n)
{
    srand(time(0));
    
    int max = 100000;
    int min = -100000;
    
    for(unsigned i = 0; i < n; ++i)
        v.push_back(rand_gen(max, min));
    
}

/**Helper**/

unsigned find_min(unsigned from, unsigned to, const vector <int> &v)
{
    unsigned min = from;
    //~ if(to == from || from == v.size()-1)
        //~ return min;
        
    for(unsigned i = from; i <= to; ++i)
    {
        if(v.at(i) < v.at(min))
            min = i;
    }
    return min;
}

void swap(unsigned from, unsigned to, vector <int> &v)
{
    int temp = v.at(from);
    v.at(from) = v.at(to);
    v.at(to) = temp;
}

void print_vec(const vector<int> &v)
{
    for(unsigned i = 0; i < v.size(); ++i)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
}

/** Selection Sort **/

void selection_sort(vector <int> &v, unsigned from, unsigned to)
{
    //~ unsigned index;
    //~ for(unsigned i = from; i <= to; ++i)
    //~ {
        //~ cout << "stuff" ;
        //~ index = find_min(i, to, v);
        //~ cout << index;
        //~ swap(index, i, v);
        //~ print_vec(v);
    //~ }
    
    unsigned index = find_min(from, to, v);
    swap(index, from, v);
    if(from == to)
        return;
    return selection_sort(v,from + 1, to);
}

/** Bubble Sort **/
void bubble_sort(vector <int> &v, unsigned from, unsigned to)
{
    unsigned index = from + 1;
    for(unsigned i = from; i < to; i++)
    {
        if(v.at(index) < v.at(i))
            swap(i, index, v);
        index++;
    }
    
    if(to == from)
        return;
    return bubble_sort(v,from, to - 1);
}

/** Optimize Bubble Sort **/
//same as bubble sort
void opBubble_sort (vector <int> &v, unsigned from, unsigned to)
{
    unsigned index = from + 1;
    for(unsigned i = from; i < to; i++)
    {
        if(v.at(index) < v.at(i))
            swap(i, index, v);
        index++;
    }
    
    if(to == from)
        return;
    return bubble_sort(v,from, to - 1);
}

/** Insertion Sort**/
void insert_sort(vector <int> &v, unsigned from, unsigned to)
{
    unsigned i = from + 1;
    //~ cout << "stuff";
    do
    {
        //~ cout << "Stuff";
        int current = v.at(i);
        unsigned j = i;
        while(j != 0 && v.at(j-1) > current)
        {
            v.at(j) = v.at(j-1);
            j = j-1;
        }
        v.at(j) = current;
        ++i;
    } while(i <= to);
}

/**===========MAIN===========**/
int main()
{

    clock_t start;
    clock_t end;
    double dif;
    char action, print_char;
    bool to_print;
    vector <int> v;
    unsigned n = 0;
    
    cout << "Enter the number for the size of dataset: ";
    cin  >> n;
    generate_data_set(v,n);
    cout << "\nDo you want to output the data set to console (y/n): ";
    cin  >> print_char;
    if(print_char == 'y' || print_char == 'Y')
        to_print = true;
    else 
        to_print = false;
    cout << "\nWhich sorting algorithm do you wish to test?" << endl;
    cout << "Selection(s), Bubble(b), Optimized Bubble(o), Insertion(i)";
    cin  >> action;
    
    //Selection
    if(action == 's' || action == 'S')
    {
        cout << "Selection Sort: " << endl;
        
        if(to_print)
        {
            cout << "Before:\t";
            print_vec(v);
        }
        
        start = clock();
        selection_sort(v,0,v.size()-1);
        end = clock();
        
        if (to_print)
        {
            cout << "After:\t";
            print_vec(v);            
        }
    }
    
    //Bubble
    else if(action == 'b' || action == 'B')
    {
        cout << "Bubble Sort: " << endl;
        
        if(to_print)
        {
            cout << "Before:\t";
            print_vec(v);
        }
        
        start = clock();
        bubble_sort(v,0,v.size()-1);
        end = clock();
        
        if (to_print)
        {
            cout << "After:\t";
            print_vec(v);            
        }
    }
    
    //Optimized Bubble
    else if(action == 'o' || action == 'O')
    {
        cout << "Optimize Bubble Sort: " << endl;
        
        if(to_print)
        {
            cout << "Before:\t";
            print_vec(v);
        }
        
        start = clock();
        opBubble_sort(v,0,v.size()-1);
        end = clock();
        
        if (to_print)
        {
            cout << "After:\t";
            print_vec(v);            
        }
    }
    
    //Insertion sort
    else if (action == 'i' || action == 'I')
    {
        cout << "Insertion Sort: " << endl;
        
        if(to_print)
        {
            cout << "Before:\t";
            print_vec(v);
        }
        
        start = clock();
        insert_sort(v,0,v.size()-1);
        end = clock();
        
        if (to_print)
        {
            cout << "After:\t";
            print_vec(v);            
        }
    }
    
    dif = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    cout << fixed << setprecision(3);
    cout << "\nThe loop took " << dif << " seconds\n";
    cout << endl;

    return 0;
}


#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <algorithm> // for the built in sort funciton.

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
/**==================ASSIGNMENT 7=====================**/

int search_index(int i, const vector <int>& v, unsigned from, unsigned to)
{
    if(from != to)
    {
        if(i == v.at(from))
            return from;
        else
            return search_index(i, v, from + 1, to);
    }
    
    else
    {
        if(i == v.at(from))
            return from;
        else
            return -1;
    }
}

//HELPER
vector <int> merge(vector <int> &v1, vector <int> &v2)
{
    vector <int> result;
    
    //~ cout << "WAHTTT??\n";
    while(v1.size() > 0 && v2.size() > 0)
    {
        //~ cout << "HELLO??\n";
        //~ if (v1.size() > 0 && v2.size() > 0)
        //~ {
        if (v1.at(0) <= v2.at(0))
        {
            //~ cout << "dskjf;kadf\n";
            result.push_back(v1.at(0));
            v1.erase(v1.begin());
        }
        else if( v2.at(0) < v1.at(0))
        {
            result.push_back(v2.at(0));
            v2.erase(v2.begin());
        }
    }
            
        //~ }
        
    if (v1.size() > 0 && v2.size() == 0)
    {
        for (unsigned i = 0; i < v1.size(); i++)
        {
            result.push_back(v1.at(i));
            //~ v1.erase(v1.begin());
        }
       
    }
    
    else if (v2.size() > 0 && v1.size() == 0)
    {
        for(unsigned i = 0; i < v2.size(); i++)
        {
            result.push_back(v2.at(i));
            //~ v2.erase(v2.begin());
        }
    }    
    //~ }
    
    return result;
}

vector <int> merge_sort(vector <int> &v)
{    
    if (v.size() <= 1)
        return v;
        
    vector <int> result;
    vector <int> lhv, rhv;
    unsigned mid = v.size() / 2;
    
    for(unsigned i = 0; i < mid; ++i)
    {
        //~ cout <<"Seg Fault??\n";
        lhv.push_back(v.at(i));
        //~ cout << lhv.at() << endl;
    }
    
    for (unsigned x = mid; x < v.size(); ++x)
    {
        //~ cout << "Here??\n";
        rhv.push_back(v.at(x));
        //~ cout << rhv.at(x) << endl;
    }
    
    //~ if(lhv.size() > 1)
    lhv = merge_sort(lhv);
    //~ if(rhv.size() > 1)
    rhv = merge_sort(rhv);
    
    return merge(lhv, rhv);
    
}


/**===========MAIN===========**/
int main()
{

    clock_t start;
    clock_t end;
    double dif;
    char action, print_char, search_char;
    bool to_print, to_search;
    int search_num;
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
    cout << "Selection(s), Bubble(b), Optimized Bubble(o), "
         << "Insertion(i), Merge(m)";
    cin  >> action;
    
    //Selection
    if(action == 's' || action == 'S')
    {
        cout << "\nSelection Sort: " << endl;
        
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
        cout << "\nBubble Sort: " << endl;
        
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
        cout << "\nOptimize Bubble Sort: " << endl;
        
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
        cout << "\nInsertion Sort: " << endl;
        
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
    
    else if (action == 'm' || action == 'M')
    {
        cout << "\nMerge Sort: " << endl;
        
        if(to_print)
        {
            cout << "Before:\t";
            print_vec(v);
        }
        
        start = clock();
        merge_sort(v);
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
    
    //~ ========================================================
    cout << "Search for a number(y/n): ";
    cin  >> search_char;
    if(search_char == 'y' || search_char == 'Y')
    {
        to_search = true;
        cout << "Enter the number you wish to search for: ";
        cin  >> search_num;
    }
    else 
        to_search = false;
    
    if(to_search)
    {
        
        int index_found = search_index(search_num, v, 0, v.size() -1);
        
        if(index_found >= 0)
            cout << "The number you wish to seach for was not in the list\n";
        else
            cout << "The nubmer you wish to find is at " << index_found
                 << " index\n";
    }
    
    //~ =====================================================

    return 0;
}


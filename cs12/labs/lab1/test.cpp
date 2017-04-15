#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
          
using namespace std;

bool is_inside(float x, float y, float R)
   {
       float z = 0;
       z = (x * x) + ( y * y);
       z = pow(z,1/2);
       
       if(z <= R) return true;
       else return false;
              
   }
   
bool throw_dart(int s)
   {
         int x, y;
         int a = (s/-2);
         int b = (s/2);
         float r = (s/2);
         // assign x and y to two random numbers between -s/2 and s/2
         // see the previous exersice to see an example.
         
         srand(time(NULL));
         
         x = a + rand() % (b - a +1);
         y = a + rand() % (b - a +1);
         
         //Call the is_inside function and return its output. 
         //You do not have to cast x,y to floats, it is done automatically.
         return is_inside(x,y,r);
         
   }

int main()
{
    double total_marble = 55;
    double n;
    n = log(total_marble) / log(2);
    n= n - 0.5;
    setprecision (1);
    cout << n;
    
    return 0;
}

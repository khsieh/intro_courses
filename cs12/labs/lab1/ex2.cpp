// This program implements the Monte Carlo Method for estimating the value of PI.
           
   #include <iostream>
   #include <cstdlib>
   #include <ctime>
   #include <cmath>
           
   using namespace std;
           
   // given the coordinates of a point (x,y) computes if the point is inside the circle 
   // centered at origin with radius R. Returns 'true' if it is inside, 'false' otherwise.
   bool is_inside(float x, float y, float R)
   {
       float z2 = 0;
       z2 = pow(x,2) + pow(y,2);
       
       if(z2 < pow(R,2)) return true;
       else return false;
              
   }
   // given the side,s, of a square that is centered at origin, 
   // choses a random coordinates inside the square, and calls is_inside function 
   // to test if the point is inside the circle or not.
   bool throw_dart(int s)
   {
         int x, y;
         // assign x and y to two random numbers between -s/2 and s/2
         // see the previous exersice to see an example.
         
         //rand() % (s+1) - (s/2)
         x = rand() % (s+1) - (s/2);
         y = rand() % (s+1) - (s/2);
         
         //Call the is_inside function and return its output. 
         //You do not have to cast x,y to floats, it is done automatically.
         return is_inside(x,y,s/2);
         
   }
   
   int main()
   {
         int side = 1000; // this is the side of the square and is also our resolution. 
         int tries;  // this is the number of tries.
         
         srand(time(NULL));
   
         //Ask the user for the number of tries using cout.
         cout << "Enter the number of tries: " << endl;
                  
         //Get the users input using cin.
         cin >> tries;         
         
         int in_count = 0; //counter to track number of throws that fall inside
        
          for(int i = 0; i < tries; i++)
         {
           //throw a dart using throw_dart method and increment the counter depending on its output.
           if(throw_dart(side))
           {
               in_count++;
           }
                        
         }
   
         //Compute and display the estimated value of PI. Make sure you are not doing integer division.
         
         float pi;
         pi = 4 * static_cast<float> (in_count)/(tries);
         cout << "Estimated value of PI = " << pi << endl;
         
         return 0;
   }

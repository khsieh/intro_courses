#include <iostream>
#include "music.h"
#include "tune.h"

using namespace std;

/**
 * create a few Tune objects to use later on;
 * Music_collection A;
 * add a few tunes to A;
 * Music_collection B(A); 
 * change a Tune in B using set_tune function;
 * Music_collection C;
 * C = B; 
 * add a Tune to B; 
 * change a Tune in C using set_tune function;
 * print A,B,C; 
**/

int main()
{
    Tune t1("Notes'n'Words");
    Tune t2("The Beginning");
    Tune t3("C.H.A.O.S.M.Y.T.H.");
    Tune t4("Silent World");
    Tune t5("Riot");
    Tune t6("Pierce");
    
    Music_collection album1;
    album1.add_tune(t1);
    album1.add_tune(t2);
    album1.add_tune(t3);
    album1.add_tune(t4);
    
    Music_collection album2(album1);
    album2.set_tune(3,t5);
    
    Music_collection album3;
    album3 = album2;
    
    album2.add_tune(t6);
    album3.set_tune(1,t4);
    
    cout << "Album1:\n" << album1 << endl 
         << "Ablum2:\n" << album2 << endl 
         << "Album3:\n" << album3 << endl;
    
    return 0;
}

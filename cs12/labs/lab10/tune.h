#ifndef _TUNE_H_
#define _TUNE_H_

#include <string>

using namespace std;

class Tune
{
    private:
        string title;

    public:
        Tune();
        Tune( string n );  
        string get_title();
};

#endif

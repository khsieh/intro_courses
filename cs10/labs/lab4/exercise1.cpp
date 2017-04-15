#include <iostream>
using namespace std;

int main()
{
    string word;
    int i=0;
    
    
    cout << "Enter your word: ";
    cin >> word;
    bool founde = false;
    bool foundx = false;
    int a= word.size();
    while (i < a)
        {
        word.at(i);
        if (word.at(i)=='e' && !founde)
            {cout << "your word, " << word 
                  << " contains the character 'e'." << endl;
             founde = true;}
        if (word.at(i)=='x' && !foundx)
            {cout<< "your word, " << word
                 << " contains the character 'x'." << endl;
             foundx = true;}
        i+=1;
        }
    return 0;
}

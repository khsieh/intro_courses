#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> sentence;
    string word;
    char letter;
    string part;
    
    cout << "Enter words (ente done to quit):" << endl;
    
    while (cin >> word)
    {
        if(word == "done") break;
        sentence.push_back(word);
    }
    
    cout << "Enter a letter: " << endl;
    cin >> letter;
        
    for(int i = sentence.size() - 1; i >= 0; i--)
    {
        
        part = sentence.at(i);
        if(part.at(0) == letter)
        cout << part << endl;
    }
     
    
    return 0;
}

#include <stdio.h>

void str_cat(char* buff1, char* buff2)
{
    int index = 0;
    unsigned z;
    for(z = 0; buff1[z] != '\0' && z < 40; ++z)
    {
        index++;
    }
    
    //printf("%i",index);
    
    int index2 = 0;
    unsigned y;
    for(y = 0; buff2[y] != '\0' && y < 40; ++y)
    {
        index2++;
    }
    
    //printf("%i",index2);
    
    unsigned x;
    int pos;
    for(pos = index, x = 0; x < index2 + 1 && x < 40; ++x, ++pos)
    {
        buff1[pos] = buff2[x];
    }
}

void str_rev(char* buff)
{
    int index2 = 0;
    unsigned y;
    for(y = 0; buff[y] != '\0' && y < 40; ++y)
    {
        index2++;
    }
    
    printf("%i", index2);
    
    int pos;
    char temp;
    unsigned x;
    for(x = index2 - 1 , pos = 0; x > index2/2; --x, ++pos)
    {
        temp = buff[pos];
        buff[pos] = buff[x];
        buff[x] = temp;
    }
    
    buff[index2] = '\0';
    
}


int main()
{
    
    char buff1[40], buff2[40];
    
    scanf("%s %s", buff1, buff2);
    str_cat(buff1, buff2);
    printf("buff1 = %s\n", buff1);
    str_rev(buff2);
    printf("buff2 = %s\n", buff2);
    
    
    //string s;
    //cout << "\nEnter a word: ";
    //cin >> s;	
    //char arr0[20];
    //strcpy( arr0, s.c_str() ); // this "extracts" a cstring from a string object, and copies it to the array

    //char arr1[20];
    //cout << "\nEnter another word: ";
    //cin >> arr1; 

    //char arr2[20] = "helloworld"; // string literals are created and stored as cstrings

    //cout << arr0 << '\n' << arr1 << '\n' << arr2 << endl;
    

    return 0;
}

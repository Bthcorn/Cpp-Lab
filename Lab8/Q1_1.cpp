#include <iostream>
#include <cstring>
using namespace std;

void mystery1(char *, const char *);
void mystery2(char *, const char *);

int main()
{
    char string1[80];
    char string2[80];
    cout << "Enter two strings: ";
    cin >> string1 >> string2;

    mystery1(string1, string2);
    cout << "Concatenated string: " << string1 << endl;

    if(strlen(string1) >= strlen(string2)){
        mystery2(string1, string2);
    }else{
        cout << "substring shouldn't be longer than string\n";
        exit(1);
    }
    // mystery2(string1, string2); check in case of string2 is longer than string1
}

void mystery1(char *s1, const char *s2)
{
    size_t maxSize = 80; 
    const auto originalPtr = s1;
    while (*s1 != '\0')
    {
        ++s1;
    }
    char *tempPtr = s1;
    const char *tempPtr2 = s2;
    while (*tempPtr2 != '\0')
    {
        ++tempPtr; 
        ++tempPtr2;
        
    }
    
    if (abs((originalPtr - tempPtr) + 1) > maxSize)
    {
        cout << "Insufficient space in string1 to concatenate string2.\n"; 
        exit(1); 
    }
    else
    {
        for (; (*s1 = *s2); ++s1, ++s2)
        {
            *s1 = *s2;
        }
    }
}

void mystery2(char *s1, const char *s2){
    size_t count = 0; 
    while(*s1 != '\0'){
        if(*s1 == *s2){
            ++count; 
            s2++; 
        }else{
            count = 0; 
        }
        ++s1; 
    }

    if(count == strlen(s2) || s1 == s1){
        cout << "Is string2 a substring of string1: Yes"<< endl;
    }else{  
        cout << "Is string2 a substring of string1: No"<< endl;
    }

}
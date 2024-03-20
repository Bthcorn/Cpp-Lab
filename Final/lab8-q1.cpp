#include <iostream>
#include <cstring>
#include <algorithm>
#include <iterator>

struct Count {
    unsigned int vowels;
    unsigned int length;
};

void Concatenate(char *s1, const char *s2)
{
    int length = 0;

    while (*s1 != '\0')
    {
        ++length;
        ++s1;
    }

    while (*s2 != '\0')
    {
        if (length >= 80)
        {
            std::cout << "Error: Insufficient space for concatenation.";
            exit(1);
        }
        *s1 = *s2;
        ++s2;
        ++s1;
        ++length;
    }
    *s1 = '\0';
}

bool isSubStr(const char *s1, const char *s2)
{
    const char *p1_advance;
    const char *p2;

    for (; *s1; ++s1)
    {
        p1_advance = s1;
        p2 = s2;
        while (*p1_advance == *p2)
        {
            ++p1_advance;
            ++p2;
        }

        if (*p2 == '\0')
        {
            return true;
        }
    }

    return false;
}

Count CountString(const char* s1) 
{
    Count result;
    unsigned int l = 0; // It is required to assign value to be zero first
    unsigned int v = 0;

    for (; *s1 != '\0'; ++s1)
    {  
        if (*s1 == 'a' || *s1 == 'e' || *s1 == 'i' || *s1 == 'o' || *s1 == 'u' || 
            *s1 == 'A' || *s1 == 'E' || *s1 == 'I' || *s1 == 'O' || *s1 == 'U')
        {
            ++v;
        }
        ++l;
    }
    result.length = l;
    result.vowels = v;

    return result;
}

void reverseString(char* str)
{
    int length = std::strlen(str);
    for (int i = 0; i < length / 2; ++i) 
    {
       std::swap(str[i], str[length - i - 1]);
    }

}


int main()
{
    char string1[80];
    char string2[80];

    std::cout << "Enter two strings: ";
    std::cin >> string1 >> string2;
    // Concatenate(string1, string2);
    // std::cout << "Concatenated: " << string1 << '\n';
    std::cout << "Is string 2 is substring of string 1: " << (isSubStr(string1, string2) ? "Yes" : "No") << '\n';
    
    Count result;
    result = CountString(string1);
    std::cout << "Length of string 1: " << result.length << '\n';
    std::cout << "Number of vowels of string 1: " << result.vowels << '\n'; 
    
    reverseString(string1);
    std::cout << "Reversed string 1: " << string1 << '\n'; 
}

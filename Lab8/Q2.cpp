#include <iostream>
#include <cstring>
#include <algorithm>
#include <iterator>
using namespace std;

int mystery3(const char *, unsigned int& n); // prototype
void reverseString(char *);

int main()
{
    char string1[80];
    cout << "Enter a string: ";

    cin >> string1;
    if (strlen(string1) > 80)
    {
        cout << "Error: Input exceeds the maximum allowed string length." << endl;
        return 1;
    }
    unsigned int vowelCount;
    cout << "Length of the string: " << mystery3(string1, vowelCount) << endl;
    cout << "Vowel count: " << vowelCount << endl;
    reverseString(string1);
    cout << "Reversed string: " << string1 << endl;
}

// Calculates the length of a string
int mystery3(const char *s, unsigned int& n)
{
    unsigned int x;
    for (x = 0, n = 0; *s != '\0'; ++s)
    {
        ++x;

        if (*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u' || 
            *s == 'A' || *s == 'E' || *s == 'I' || *s == 'O' || *s == 'U')
        {
            ++n;
        }
    }
    return x;
}

void reverseString(char *s)
{
    char *begin = s;
    char *end = s + strlen(s) - 1;
    cout << *end << endl;
    char temp;
    while (begin < end)
    {
        temp = *begin;
        *begin = *end;
        *end = temp;
        ++begin;
        --end;
    }
    // std::reverse(s, s + strlen(s));
}
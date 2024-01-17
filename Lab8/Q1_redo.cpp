#include <iostream>
#include <cstring>

using namespace std;

void mystery1(char *, const char *);
bool mystery2(const char *, const char *);

int main()
{
    char string1[80];
    char string2[80];
    cout << "Enter two strings: ";
    cin >> string1 >> string2;
    cout << "Is string2 a substring of string1" << " ";
    if (mystery2(string1, string2))
    {
        cout << "Yes!" << endl;
    }
    else
    {
        cout << "No!" << endl;
    }
    mystery1(string1, string2);
    cout << string1 << endl;
} // end main

void mystery1(char *s1, const char *s2)
{
    int length = 0;
    while (*s1 != '\0')
    {
        length++;
        s1++;
    }

    while (*s2 != '\0')
    {
        if (length >= 80)
        {
            cout << "Insufficient space in string1 to concatenate string2.\n";
            exit(1);
        }
        *s1 = *s2;
        s1++;
        s2++;
        length++;
    }

    *s1 = '\0';
}

bool mystery2(const char *s1, const char *s2)
{
    // If s2 is an empty string, it is considered a substring of any string.
    if (*s2 == '\0') {
        return true;
    }

    while (*s1 != '\0') {

        while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0') {
            ++s1;
            ++s2;
        }

        if (*s2 == '\0') {
            // s2 is a substring of s1
            return true;
        }

        ++s1;
    }

    // s2 is not a substring of s1
    return false;
}

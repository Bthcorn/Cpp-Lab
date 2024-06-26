#include <iostream>
#include <cstring>

std::size_t string_length(const char *s)
{
    std::size_t n = 0;
    while (*s != '\0')
    {
        ++s;
        ++n;
    }
    return n;
}

void string_copy(char* d, const char *s)
{
    // char *p = d;
    while ((*d = *s) != '\0')
    {
        ++d;
        ++s;
    }
    *d = '\0';
    // return d;
}

char* string_duplicate(const char *s)
{
    std::size_t n = string_length(s);
    char* result = new char[n + 1];
    string_copy(result, s);
    return result;
}
char* string_concatenate(const char *first, const char *second)
{
    std::size_t first_len = string_length(first);
    std::size_t second_len = string_length(second);
    char* result = new char[first_len + second_len + 1];
    string_copy(result, first);
    string_copy(result + first_len, second); // move the recent pointer char* to the last len of first
    return result;
}

int main()
{
    char *s = string_concatenate("Hello, ", "World!");
    char *t = string_duplicate(s);
    std::cout << t << '\n';
    delete[] s;
    delete[] t;
}

// #include <iostream>
// #include <cstring> // for strcpy and strcat

// char* str_concat(const char* str1, const char* str2) {
//     size_t len1 = strlen(str1);
//     size_t len2 = strlen(str2);
    
//     char* result = new char[len1 + len2 + 1]; // +1 for null terminator
    
//     strcpy(result, str1);
//     strcat(result, str2);
    
//     return result;
// }

// int main() {
//     const char* str1 = "Hello, ";
//     const char* str2 = "world!";
    
//     char* concatenated = str_concat(str1, str2);
//     std::cout << concatenated << std::endl;
    
//     delete[] concatenated; // Remember to free the allocated memory
//     return 0;
// }
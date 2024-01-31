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
bool check (char* haystack, char* needle, int index)
{
    for (int i = index, j = 0; j < strlen(needle); i++, j++)
    {
        if (haystack[i] != needle[j]) return false;
    }
    return true;
}


int strStr(char* haystack, char* needle) {
    bool loo;
    for (int i = 0; i < strlen(haystack); i++)
    {
        if (haystack[i] == needle[0])
        {
            loo = check (haystack, needle, i);
        }
        if (loo)
        {
            return i;
        }
    }
    return -1;
}

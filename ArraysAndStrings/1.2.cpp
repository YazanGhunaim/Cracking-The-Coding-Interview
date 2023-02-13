#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int cmp(const char *a, const char *b)
{
    return (*b < *a) - (*a < *b);
}

char *stringToCharArray(string str)
{
    char *result = new char[str.length() + 1];
    result[str.length()] = '\0';
    for (std::string::size_type i = 0; i < str.length(); ++i)
    {
        result[i] = str[i];
    }
    return result;
}

bool permutation(string str1, string str2)
{
    if (str1.size() != str2.size())
    {
        cout << "strings arent permuations of each other." << endl;
        return false;
    }
    char *charArrayOne = stringToCharArray(str1);
    char *charArrayTwo = stringToCharArray(str2);
    qsort(charArrayOne, str1.length(), sizeof(charArrayOne[0]), (int (*)(const void *, const void *))cmp);
    qsort(charArrayTwo, str1.length(), sizeof(charArrayTwo[0]), (int (*)(const void *, const void *))cmp);

    for (std::string::size_type i = 0; i < str1.length(); ++i)
    {
        if (charArrayOne[i] != charArrayTwo[i])
        {
            cout << "Not permutations." << endl;
            return false;
        }
    }
    cout << "permutations." << endl;

    delete charArrayOne;
    delete charArrayTwo;
    return true;
}

/*
without using extra memory.
*/
bool permutationTwo(string str1, string str2)
{
    if (str1.length() != str2.length())
    {
        return false;
    }
    int charSet[256];
    memset(charSet, 0, sizeof(charSet));
    for (std::string::size_type i = 0; i < str1.length(); ++i)
    {
        charSet[(unsigned char)str1[i]]++;
    }
    for (std::string::size_type i = 0; i < str2.length(); ++i)
    {
        charSet[(unsigned char)str2[i]]--;
        if (charSet[(unsigned char)str2[i]] < 0)
        {
            cout << "Not permutations." << endl;
            return false;
        }
    }
    cout << "permutations." << endl;
    return true;
}

int main()
{
    string one("dog");
    string two("ogd");
    permutation(one, two);
    permutationTwo(one, two);
    return 0;
}

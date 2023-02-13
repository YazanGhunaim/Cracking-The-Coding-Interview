#include <iostream>
#include <string>

using namespace std;

bool palindromePermutation(string str)
{
    int charSet[128];
    memset(charSet, 0, sizeof(charSet));
    for (std::string::size_type i = 0; i < str.length(); ++i)
    {
        if (str[i] != ' ')
        {
            charSet[(unsigned char)tolower(str[i])]++;
        }
    }
    int result = 0;
    for (std::string::size_type i = 0; i < str.length(); ++i)
    {
        if (str[i] != ' ')
        {
            result += charSet[(unsigned char)tolower(str[i])] % 2;
        }
    }
    return result <= 1;
}

int main()
{
    string str1("Tact Coa");
    string str2("racecar");

    if (palindromePermutation(str1))
    {
        cout << str1 << " is a permutation of a palindrome." << endl;
    }
    if (palindromePermutation(str2))
    {
        cout << str2 << " is a permutation of a palindrome." << endl;
    }
    return 0;
}

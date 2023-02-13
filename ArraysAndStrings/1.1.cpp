#include <iostream>
#include <string>
using namespace std;
/*
implement an algorigthm to determine if a string
has all unique characters without using an additional data structure
*/

// ASCII 128
// Extended ASCII 256
namespace str
{
    string test1("Hello");
    string test2("Hey Bro");

    void uniqueCharacters(string test)
    {
        if (test.length() > 128)
        {
            cout << "string " << test << " has duplicate characters." << endl;
        }
        //--//
        bool charSet[128];
        memset(charSet, false, sizeof(charSet));
        int unique = 1;
        for (std::string::size_type i = 0; i < test.length(); ++i)
        {
            int val = test[i];
            if (charSet[val])
            {
                cout << "string " << test << " has duplicate characters." << endl;
                unique = 0;
                break;
            }
            charSet[val] = true;
        }
        if (unique)
            cout << "string " << test << " has unique characters." << endl;
    }
}

/*
reducing space usage by a factor of 8 by using a bit vector
*/
bool isUniqueChars(string str)
{
    int checker = 0;
    for (std::string::size_type i = 0; i < str.length(); ++i)
    {
        int val = str[i] - 'a';
        // (1 << val) creatrs a value with only the valueth bit set to one
        if (checker & (1 << val) > 0)
        {
            return false;
        }
        // sets valueth bit of checker equal to 1
        checker |= (1 << val);
    }
    return true;
}

int main()
{
    /*
    Time Complexity: O(min(c,n))
    Space Complexity: O(c)
    */
    cout << str::test1 << endl;
    str::uniqueCharacters(str::test1);
    cout << str::test2 << endl;
    str::uniqueCharacters(str::test2);
    return 0;
}

/*
If We are allowed to modify the string we can sort it using nlogn time and linearly check.
However may take extra space.
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str("Mr John Smith   ");
    int length = str.length();
    int spaces = 0;

    // Remove trailing spaces
    for (int i = length - 1; i >= 0; --i)
    {
        if (str[i] == ' ')
        {
            length--;
        }
        else
        {
            break;
        }
    }

    // Count spaces
    for (int i = 0; i < length; ++i)
    {
        if (str[i] == ' ')
        {
            spaces++;
        }
    }

    int newLength = length + spaces * 2;
    str.resize(newLength);

    for (int i = length - 1, j = newLength - 1; i >= 0; --i)
    {
        if (str[i] == ' ')
        {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        }
        else
        {
            str[j--] = str[i];
        }
    }

    cout << str;
    return 0;
}
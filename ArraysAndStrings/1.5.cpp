#include <iostream>
#include <string>

using namespace std;

bool contains(string str, char character)
{
    for (std::string::size_type i = 0; i < str.length(); ++i)
    {
        if (str[i] == character)
            return true;
    }
    return false;
}
bool oneAway(string str1, string str2)
{
    int length = str1.length();
    if (str2.length() > str1.length() + 1)
        return false;

    int containsVal = 0;
    for (std::string::size_type i = 0; i < str2.length(); ++i)
    {
        if (contains(str1, str2[i]) == true)
        {
            containsVal++;
        }
    }
    if (containsVal + 1 == length)
    {
        cout << "true" << endl;
        return true;
    }
    cout << "false" << endl;
    return false;
}

int main()
{
    oneAway("pale","ple");
    oneAway("pales","pale");
    oneAway("pale","bale");
    oneAway("pale","bake");
    return 0;
}

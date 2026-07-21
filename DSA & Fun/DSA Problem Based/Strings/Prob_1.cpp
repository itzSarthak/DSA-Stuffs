//  Leetcode 125
//  Valid Palindrome

#include <iostream>
using namespace std;

// Function to convert uppercase to lowercase
char lower(char ch)
{
    if(ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')
        return ch;

    else
    {
        char temp;
        temp = ch - 'A' + 'a';
        // here we are finding the difference
        // then adding to the first lowercase character .
        return temp;
    }
}

// checking weather a string is Palindrome !
bool palindrome(string str)
{
    int s = 0,e = str.size() - 1;
    while(s < e)
    {
        if(str[s] != str[e])
            return false;

        s++;
        e--;
    }
    return true;
}

int main()
{
    return 0;
}
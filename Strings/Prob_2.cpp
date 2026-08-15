// Leetcode 151
// Revese word in a string
#include <bits/stdc++.h>
using namespace std;

// Program to reverse a word
void reverse(string &str)
{
    int s = 0,e = str.size() - 1;
    while(s <= e)
        swap(str[s++],str[e--]);

}

string reverseWords(string s)
{
        // "the sky is blue"
        string prev = "";
        string res = "";
        
        // for trailing spaces
        int i = s.size() - 1;
        while(i>=0 && s[i] == ' ') i--;
   

        for(;i>=0;i--)
        {
            if(s[i] == ' ')
            {
                reverse(prev);
                res.append(prev);
                res.push_back(' ');
                prev = "";
                
                while(i>=0 && s[i] == ' ') i--;
                
                // for leading spaces
                if(i == -1)
                {
                    res.pop_back();
                    return res;
                }
                i++;
            }
            else
                prev.push_back(s[i]);
        }
        
        
        /*
            the sky is blue"   - - > simple 
            "the   sky   is blue" - - > more than one space in between two word
            "the sky is blue   " - - > traling spaces
            "   the sky  is  blue  " - - > leading spaces
        */

        reverse(prev);
        res+=prev;
        return res;
}

int main()
{
    string str = "  sarthak   rai is the name  ";
    string res = reverseWords(str);

    cout<<res<<endl;
    return 0;
}
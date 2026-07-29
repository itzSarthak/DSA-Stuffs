#include<bits/stdc++.h>
using namespace std;

// this we solving using LIS std method **

bool compare(string &s1,string& s2)
{
    if(s1.size() != s2.size() + 1)
        return false;

    int i = 0,j = 0;
    while(i < s1.size())
    {
        if(j < s1.size() && s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }

    if(i == s1.size() && j == s2.size())
        return true;

    return false;
}
int longestStrChain(vector<string>& words)
{
    int n = words.size();
    vector<int>dp(n,1);
    int ans = 1;

    // here we also need to sort the words[] ac to length
    // sort(words.begin(),words.end(),comp); using comparator we can do **

    for(int idx = 0; idx < n; idx++)
    {
        for(int prev_idx = 0; prev_idx < idx; prev_idx++)
        {
            // here we compare those two strings if they are in chain **
            if(compare(words[idx],words[prev_idx]) && 1 + dp[prev_idx] > dp[idx] )
                dp[idx] = 1 + dp[prev_idx];
        }

        ans = max(ans,dp[idx]);
    }
    return ans;
}  
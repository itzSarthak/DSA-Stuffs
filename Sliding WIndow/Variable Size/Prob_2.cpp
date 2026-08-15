// Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/


/*
#include <bits/stdc++.h>
using namespace std;


    // This problem is very similar to Count Occurance of Anagrams.
    string minWindow(string s, string t) 
    {
        int i=0,j=0;
        string res = "";
        int curr_len = INT_MAX;
            
        unordered_map<char,int>m;        
        for(int it=0;it<t.size();it++)
            m[t[it]]++;
            
        int count = m.size();
            
        while(j < s.size())
        {            
            if(m.find(s[j]) != m.end())
            {
                    m[s[j]]--;

                    if(m[s[j]] == 0)
                        count--;
            }               
            if(count == 0)
            {
                while(count == 0)
                {
                    if(curr_len > j-i+1)
                    {
                        curr_len = j-i+1;
                        res = "";
                        res.append(s,i,curr_len);
                    }
                    if(m.find(s[i]) != m.end())
                    {
                        m[s[i]]++;
                        if(m[s[i]] == 1)
                            count++;
                    }
                    i++;
                }
            }
            j++;
        }          
            if(curr_len == INT_MAX)
                res = "";
            
            return res;
    }

*/
// Count Occurance of Anagrams
// https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

#include <bits/stdc++.h>
using namespace std;

int search(string pat, string txt)
{
        map<char,int>m;   
        for(int i=0;i<pat.size();i++)
            m[pat[i]]++;

        //      ** map has been created
        //      ** this map stores the occurance of every charcters of pat which we 
        //      ** need to find in txt !!
        
        int i=0,j=0;
        int k = pat.size();
        int count = m.size(),ans = 0;
        
        //      ** count stores the no of distinct characters in txt.
        //      ** without count we need to iterate the map for answer.
        
        while(j < txt.size())
        {
            //      ** calculation part
            if(m.find(txt[j]) != m.end())
            {
                m[txt[j]]--;
                
                if(m[txt[j]] == 0)
                    count--;
            }
            

            if(j-i+1 == k)
            {
                //      ** calculating the ans 
                if(count == 0)
                    ans++;
                
                //      ** sliding the window
                if(m.find(txt[i]) != m.end())
                {
                    //      ** deleting the calculation for i
                    //      ** opposite of what we have done for j in calculation part.
                    m[txt[i]]++;
                    if(m[txt[i]] == 1)
                        count++;
                }
                i++;
            }
            j++;
        }
        return ans;
}

/*
    ** In every window our map doesn't represnt occurance of each
    ** and every characters but in first window.

    ** but with the help of our map we can check for anagram in each window.
*/
int main()
{
    cout<<search("aaba","aabaabaa")<<endl;
}


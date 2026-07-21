// First negative integer in every window of size k
// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include<bits/stdc++.h>
using namespace std;

vector<int> first_neg(vector<int>arr,int k)
{
    deque<int>d;
    vector<int>res;

    int i=0,j=0;
    while(j < arr.size())
    {
        // ** comparison part
        if(arr[j] < 0)
            d.push_back(arr[j]);

        if(j-i+1 == k)
        {
            if(d.empty())           // ** if no negative element is there
                res.push_back(0);

            else
            {
                res.push_back(d.front());
                if(arr[i] == d.front())
                    d.pop_front();

            }
            i++;
        }
        j++;
    }

    return res;
}

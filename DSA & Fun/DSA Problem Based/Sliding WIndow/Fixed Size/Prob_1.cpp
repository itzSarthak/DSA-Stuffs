
// Maximum sum subarray of size k
// https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

#include<bits/stdc++.h>
using namespace std;
int max_sum(vector<int>arr,int k)
{
    // k : window size
    // j - i + 1 : window size

    int i=0,j=0;
    int sum = 0;
    int ans = INT_MIN;

    while(j < arr.size())
    {
        sum+=arr[j];            // --> calculation part
        if(j-i+1 == k)
        {
            ans=max(ans,sum);   // --> find ans from calculations.
            sum-=arr[i++];      // --> delete calculation for ith element.
                                // --> Slide the window.
        }
        j++;
    }

    return ans;
}

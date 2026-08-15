// sliding window maximum
// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

#include <bits/stdc++.h>
using namespace std;

    vector<int>maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int>res;
        deque<int>dq;
        dq.push_front(INT_MIN);
        
        int i=0,j=0;
        while(j < nums.size())
        {
            // ** calculation
            while(dq.size() > 0 && dq.back() < nums[j])
                dq.pop_back();
            
            dq.push_back(nums[j]);
            //  ** while pushing nums[j] we need to remove all
            //  ** elements leeser than nums[j], bcz they are not needed anymore.
           
            if(j-i+1 == k)
            {
                res.push_back(dq.front());
                
                if(nums[i] == dq.front())
                    dq.pop_front();
                
                i++;
            }
            j++;
        }
        return res;
    }
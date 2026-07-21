
// check if rotated and sorted array
/*
    bool check(vector<int>& nums)
    {
        ** In rotated & sorted array (non decreasing) ther exist an 'i'
        ** S.T. A[i] > A[(i+1)%size]

        int count = 0;     
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] > nums[(i+1)%nums.size()])
                count++;
        }

        if(count == 1 || count == 0)
            return true;

        ** for single element array 
        ** we should give true always.

        return false;
    }
*/
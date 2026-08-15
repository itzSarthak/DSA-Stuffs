
// Search in Rotated Sorted Array II
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

/*
        **first_half            second_half

            mid                     target              - ->    s = mid + 1;
            target                  mid                 - ->    e = mid - 1;
            mid/target              --                  - ->    in these two cases we need to compare
             --                     mid/target          - ->    target with A[mid] also.


    bool search(vector<int>& nums, int target)
    {
        int s = 0,e = nums.size() - 1;
        int mid = s + (e-s)/2;
        
        while(s <= e)
        {
            if(nums[mid] == target || nums[s] == target || nums[e] == target)
                return true;
            
            if(nums[mid] == nums[e])        ** cases for duplicates
                e--;
            
            else if(nums[mid] > nums[e])    ** mid lie in first half
            {
                if(target < nums[e])
                    s = mid + 1;
                else
                {
                    if(target > nums[mid])
                        s = mid + 1;
                    else
                        e = mid-1;
                }
            }
            else                            ** mid lie in second half
            {
                if(target > nums[e])
                    e = mid-1;
                else
                {
                    if(target < nums[mid])
                        e = mid - 1;
                    else
                        s = mid+1;
                    
                }
            }
            
            mid = s + (e-s)/2;
        }
        return false;             
    }
*/

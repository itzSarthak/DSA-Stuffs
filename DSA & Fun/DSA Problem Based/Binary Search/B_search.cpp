
/*
    ** What is Binary Search ?
    ** How it Works ?
    ** Code (iterative Implementation)

    bool binary_search(int arr[],int n,int target)
    {
        int mid = s + (e-s)/2;

        while(s <= e)
        {
            if(A[mid] == target)
                return true;

            else if(A[mid] > target)
                e = mid - 1;
            
            else
                s = mid + 1;

            mid = s + (e-s)/2;
        }

        return false;
    }

    ** Time Complexity
        * Best Case : O(1)
        * Worst Case : O(log(n))
        * Avg Case : O(log(n))
*/


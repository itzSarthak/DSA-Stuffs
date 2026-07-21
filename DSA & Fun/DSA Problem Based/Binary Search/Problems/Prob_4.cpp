#include <bits/stdc++.h>
using namespace std;

    // Find square root of a number.
    // idea : figure out the search space .


// Integer part of sqrt(n) .
int sqrt(int n)
{
    int s=0,e=n;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s <= e)
    {
        if ( mid * mid > n)
            e=mid-1;
        else if( mid * mid < n)
        {
            ans=mid;
            s = mid + 1;
        }
        else
            return mid;

        mid = s + (e-s)/2;
    }
    return ans;
}

// decimal part of sqrt(n) .
    // here we are adding 0.1 to integer part
    // every time if it is lesser than the final ans.

double final_ans(int n,int prec,int temp_ans)
{
    double ans = temp_ans;
    double factor = 1;

    for(int i=0;i<prec;i++)
    {
        factor/=10;
        for(double j=ans;j*j < n;j+=factor)
            ans=j;
    }

    return ans;
}

int main()
{
    int n = 65;
    std::cout<<final_ans(n,3,sqrt(n));
    return 0;
}
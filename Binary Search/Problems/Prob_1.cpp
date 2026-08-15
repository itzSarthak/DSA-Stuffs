//😍😂😊
// First & Last Occurance in Sorted Array using Binary Search

#include <bits/stdc++.h>
using namespace std;

int first_occ(int arr[],int n,int key)
{
    int s=0,e=n-1;
    int mid=(s+e)/2;
    int ans=-1;
    while(s <= e)
    {
        if(arr[mid] == key)
        {
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid] > key)
            e=mid-1;
        
        else
            s=mid+1;

        mid=s+(e-s)/2;
    }
    return ans;
}

int last_occ(int arr[],int n,int key)
{
    int s=0,e=n-1;
    int mid=(s+e)/2;
    int ans=-1;
    while(s <= e)
    {
        if(arr[mid] == key)
        {
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid] > key)
            e=mid-1;
        
        else
            s=mid+1;

        mid=s+(e-s)/2;
    }
    return ans;
}

// total no of occurance = last_occ - first_occ + 1

// Peak Index in Mountain Array

#include <bits/stdc++.h>
using namespace std;

int peak_index(int arr[],int n)
{
    int start=0,end=n-1;
    int mid=(start+end)/2;

    while(start <= end)
    {
        if(arr[mid] < arr[mid+1])
            start = mid + 1;
        else
            end = mid;


        mid = start + (end - start)/2;
    }
    return -1;
}

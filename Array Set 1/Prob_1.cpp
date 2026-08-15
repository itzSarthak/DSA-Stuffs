
// Reverse the Array completely .
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>arr = {2,5,6,9,13};
    // rotating with the help of two pointer

    int s = 0,e = arr.size() - 1;
    while(s < e)
    {
        swap(arr[s],arr[e]);
        s++;
        e--;
    }

    return 0;
}
// Print all subsequences
#include <bits/stdc++.h>
using namespace std;

int no_calls = 0;
void print(int id,vector<int>&ds,int arr[],int n)
{
    no_calls++;
    if(id == n)
    {
        for(auto i:ds)
            cout<<i<<" ";

        if(ds.empty())
            cout<<"NULL"<<endl;
        cout<<endl;
        return;
    }

    // for any index id,we have only two options.

    // ** step 1
        //taking and moving to next id (opt1)
    ds.push_back(arr[id]);
    print(id+1,ds,arr,n);

    // ** step 2
        // not taking and moving to next id (opt2)
    ds.pop_back();
    print(id+1,ds,arr,n);

    // ** Trace the code and ENJOY 😁😁😉
}
     
/*      Time Complexity 
        ** No. of Function Call Happening ?  - - > 2^(n+1) - 1
        ** How about the Time Complexity ?  - - > O(2^n)
*/

int main()
{
    int arr[] = {3,1,2};
    vector<int>ds;
    print(0,ds,arr,3);

    cout<<"Interestingly !"<<endl;
    cout<<"No. of function call: "<<no_calls<<endl;

    cout<<"\n\n\n"<<endl;
    return 0;
}
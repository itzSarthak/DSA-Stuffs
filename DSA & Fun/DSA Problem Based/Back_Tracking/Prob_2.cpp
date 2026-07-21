
#include <bits/stdc++.h>
using namespace std;

/*
    ** 1.   Print all subsequences having sum K
    ** 2.   Print any subsequences having sum K
    ** 3.   Count no. of subsequences having sum K
*/

// prob_1
void print(int id,vector<int>&ds,int s,int sum,int arr[],int n)
{
    if(id == n)
    {
        if(s == sum)
        {
            for(auto i:ds)
                cout<<i<<" ";  

                cout<<endl;          
        }
        return;
    }
    
    s+=arr[id];
    ds.push_back(arr[id]);
    print(id+1,ds,s,sum,arr,n);

    s-=arr[id];
    ds.pop_back();
    print(id+1,ds,s,sum,arr,n);

}

// prob_2
bool print_any(int id,vector<int>&ds,int s,int sum,int arr[],int n)
{
    if(id == n)
    {
        if(s == sum)
        {
            for(auto i:ds)
                cout<<i<<" ";  

                return true;          
        }
        return false;
    }

    s+=arr[id];
    ds.push_back(arr[id]);
    if(print_any(id+1,ds,s,sum,arr,n)) return true;
    // we can avoid the below two lines if we found the subsequence in the above call
    

    s-=arr[id];
    ds.pop_back();
    if(print_any(id+1,ds,s,sum,arr,n)) return true;
    // similarly we can avoid the below line if we found the subsequence in the above call

    return false;
}

// prob_3
int count_sbsq(int id,int s,int sum,int arr[],int n)
{
    if(id == n)
    {
        if(s == sum)
            return 1;

        return 0;     
    } 
    s+=arr[id];
    int l = count_sbsq(id+1,s,sum,arr,n);

    s-=arr[id];
    int r = count_sbsq(id+1,s,sum,arr,n);

    return l + r;
}

int main()
{
    int arr[] ={1,2,1,3};
    int n = 4;
    int sum = 3;
    vector<int>ds;
    cout<<count_sbsq(0,0,sum,arr,n);
}

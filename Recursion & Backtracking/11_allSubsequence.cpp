#include<bits/stdc++.h>

using namespace std;

void subseque(int ind, vector<int>&ds, int arr[], int n){
    if(ind==n){
        for(auto it: ds){
            cout<<it<<" ";
        }
        if(ds.size()==0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }
    ds.push_back(arr[ind]);
    // Take or Pick, This element is added to Subsequence
    subseque(ind+1, ds, arr, n);
    ds.pop_back();
    // Don't Take or Not Pick, This element is not added to Subsequence
    subseque(ind+1, ds, arr, n);
}

int main()
{

    int arr[]={3, 1, 2};
    int n=3;
    vector<int>ds;
    subseque(0, ds, arr, n);
    return 0;
}
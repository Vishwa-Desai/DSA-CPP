#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void subset(vector<int> arr,int l,int r,vector<int> &ans1,int sum=0)
    {
        if(l>r){
            ans1.push_back(sum);
            return;
        }
        subset(arr,l+1,r,ans1,sum+arr[l]);
        subset(arr,l+1,r,ans1,sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans1;
        subset(arr,0,N-1,ans1);
        sort(ans1.begin(),ans1.end());
        return ans1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
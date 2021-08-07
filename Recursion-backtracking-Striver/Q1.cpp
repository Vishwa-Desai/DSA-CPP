//Q : Print all permutations of an array .
//Approach : 1
//Time limit exceeded at Leetcode.
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void recurPermute(vector<int> &ds,vector<int> &nums,vector<vector<int>> &ans,int freq[])
    {
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){{
            if(!freq[i])
            {
                ds.push_back(nums[i]);
                freq[i]=1;
                recurPermute(ds,nums,ans,freq);
                freq[i]=0;
                ds.pop_back(); //doubt
            }
        }}
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int N=nums.size();
        int freq[N]; 
        for(int i=0;i<N;i++)
        {
            freq[i]=0;
        }
        recurPermute(ds,nums,ans,freq);
        return ans;
    }
};
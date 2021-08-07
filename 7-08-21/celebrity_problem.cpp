class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> s;
        int ans;
        for(int i=0;i<n;i++)
        {
            s.push(i);
        }
        while(s.size()>=2)
        {
            int i=s.top();
            s.pop();
            int j=s.top();
            s.pop();
            if(M[i][j]==1)
            {
                //if i knows j ,i is not a celebrity
                s.push(j);
            }
            else
            {
                //if j knows i ,j is not a celebrity
                s.push(i);
            }
        }
        int pot=s.top();
        s.pop();
        ans=pot;
        for(int i=0;i<n;i++)
        {
            if(i!=pot)
            {
                if(M[i][pot]==0 || M[pot][i]==1)
                {
                    ans=-1;
                    break;
                }
            }
        }
        return ans;
    }
};
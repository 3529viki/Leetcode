//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    vector<vector<int>> dp;
    int func(int wt[],int val[],int rem_w, int n , int index){
        //base case
        if(index >= n)
        return 0;
        
        if(rem_w <= 0){
        return 0;
        }
        
        if(dp[index][rem_w] != -1)
            return dp[index][rem_w];
        
        
       // recursive case
       
       //pick kr rhe hai
       int op1=INT_MIN;
       
       if(wt[index] <= rem_w){
           
       op1= val[index] + func( wt, val, rem_w - wt[index],  n ,  index + 1);
       }
       
       //pick nahi kr rhe
      int op2 = func( wt , val, rem_w , n , index+1);
      
      return dp[index][rem_w]= max(op1 , op2);
       
    }
    
       int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        this->dp=dp;
        return func( wt, val, W, n , 0);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
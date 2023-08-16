//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
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
           
       op1= val[index] + func( wt, val, rem_w - wt[index],  n ,  index);
       }
       
       //pick nahi kr rhe
      int op2 = func( wt , val, rem_w , n , index+1);
      
      return dp[index][rem_w]= max(op1 , op2);
       
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
         vector<vector<int>>dp(N+1,vector<int>(W+1,-1));
        this->dp=dp;
        return func( wt, val, W, N , 0);
      
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
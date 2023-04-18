class Solution{   
public:
    vector<vector<int>> dp(101,vector<int>(101,-1));
    bool sumpossible(vector<int>arr,int n, int sum){
        if(n==0){
            if (sum==0) return true;
            else return false;
        }
        if(dp[n][sum] != -1) return dp[n][sum];
        
        dp[n][sum] = sumpossible(arr,n-1,sum) || sumpossible(arr,n-1,sum-arr[n-1]);
        return dp[n][sum];
    }

    bool isSubsetSum(vector<int>arr, int sum){
        return sumpossible(arr,arr.size(),sum);
    }
};
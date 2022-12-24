class Solution
{
public:
    const int M = 1e9 + 7;
    //     int ans(int n,vector<int>&dp){
    //         if(n==0)
    //             return 1;
    //         if(n==1)
    //             return 1;
    //         if(n==2)
    //             return 2;

    //         if(dp[n]!=-1)   return dp[n];
    //         return dp[n]=((2*1LL*dp[n-1])%M+dp[n-3])%M;
    //     }
    int numTilings(int n)
    {
        if (n == 1)
            return 1;
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = ((2 * 1LL * dp[i - 1]) % M + dp[i - 3] % M) % M;
        }
        return dp[n];
    }
};
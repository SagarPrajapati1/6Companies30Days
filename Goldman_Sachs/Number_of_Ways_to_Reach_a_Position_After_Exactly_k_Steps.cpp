class Solution {
public:
    long long mod = 1e9 + 7;
    int dp[3005][1005];

    int solve(int st, int et, int k){
        
        // basse case
        if(k == 0) {
            if(st == et) return 1;
            else return 0;
        }

        // if solution is exist
        if(dp[st + 1000][k] != -1) return dp[st+1000][k];

        // for count ways

        long long cnt = 0;

        // recursive calls for left and right

        cnt = (cnt % mod + solve(st-1, et, k-1) % mod) % mod; // for left
        cnt = (cnt % mod + solve(st+1, et, k-1) % mod) % mod; // for right

        return dp[st + 1000][k] = cnt;

    }

    int numberOfWays(int startPos, int endPos, int k) {
       
        memset(dp, -1, sizeof(dp));
        return solve(startPos, endPos, k);
    }
};

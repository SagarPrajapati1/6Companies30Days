class Solution {
public:

    bool recur(string s, vector<string>& wordDict, unordered_set<string> &mp, int i, int j, vector<vector<int>> &dp){
        if(i==s.size()-1 || j==s.size()-1){
            string str = s.substr(j, i-j+1);
            if(mp.find(str) != mp.end()){
                return true;
            }
            else{
                return false;
            }
        }

        if(dp[i][j] != -1) return dp[i][j];

        string str = s.substr(j, i-j+1);
        if(mp.find(str) != mp.end()){
            return dp[i][j] = recur(s, wordDict, mp, i+1, i+1, dp) || recur(s, wordDict, mp, i+1, j, dp);
        }
        else{
            return dp[i][j] = recur(s, wordDict, mp, i+1, j, dp);
        }
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> mp;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        for(auto word: wordDict){
            mp.insert(word);
        }

        return recur(s, wordDict, mp, 0, 0, dp);
    }
};

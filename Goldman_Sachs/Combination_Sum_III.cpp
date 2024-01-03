class Solution {
public:

    void solve(int i, int k, int sumTillNow, int n, vector<int> &subSet, vector<vector<int>>& ans ) {
        // base case
        if(sumTillNow > n) return;

        if(k == 0) {
            if(sumTillNow == n) {
              // it is one of the possible solution so store it and just return and go for another solution
                ans.push_back(subSet);
                return;
            }
        }
      
        if(i == 10) return;

        // recursive case
      
        //pick element
        subSet.push_back(i);
      
        solve(i+1, k-1, sumTillNow+i, n, subSet, ans);
      
        subSet.pop_back();

        //not pick element
        solve(i+1, k, sumTillNow, n, subSet, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        vector<int> subSet;

        solve(1, k, 0, n, subSet, ans);

        return ans;
    }
};

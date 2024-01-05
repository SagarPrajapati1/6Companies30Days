class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++) {
            vector<int> v;
            int cnt = 0;
            for(int j = i; j < nums.size(); j++) {
                if(nums[j] % p == 0) cnt++;

                v.push_back(nums[j]);
                if(cnt > k) break;
                ans.insert(v);
            }
        }
        return ans.size();
    }
};

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        int tc = k;

        vector<int> ans;
        int j = 0;
        while(tc > 0){
            ans.push_back(nums[j]);
            j++;
            tc--;
        }

        for(int i = j; i < n; i++) {
            int miniEle = min_element(ans.begin(), ans.end()) - ans.begin();


            if(ans[miniEle] < nums[i]) {
                ans.erase(ans.begin() + miniEle);
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

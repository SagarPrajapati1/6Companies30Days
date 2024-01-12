class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; j++) {

                int var = -1;
                int f = 1;
                for(int k = 0; k < n; k++) {
                    if(k >= i && k <= j) continue;
                    if(var >= nums[k]) {
                        f = 0;
                        break;
                    }
                    var = nums[k];
                }
                cnt += f;
            }
        }
        return cnt;
    }
};

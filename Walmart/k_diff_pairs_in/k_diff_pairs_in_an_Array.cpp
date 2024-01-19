class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        // O(n^2) time 
        // int n = nums.size(); 
        // int cnt = 0;
        
        // set<pair<int, int>> st;
        // for(int i = 0; i < n; i++) {
        //     for(int j = i+1; j < n; j++) {
        //         if(abs(nums[i] - nums[j]) == k) {
        //             st.insert({min(nums[i], nums[j]), max(nums[i], nums[j])});
        //         }
        //     }
        // }
        // return st.size();

        // O(n) and O(n)
        // unordered_map<int, int> count;

        // store the count of each digit
        // for(int i : nums) count[i]++;

        // int ans = 0;
        // for(auto it : count) {
        //     // check if k is 0 
        //     if(k == 0) {
        //         // checkl if count of it is greater than 1 than ans++
        //         if(it.second > 1) ans++;
        //     }
        //     else if(count.find(it.first + k) != count.end()) ans++;
        // }
        // return ans;

        // O(n logn) and O(1)

        sort(nums.begin(), nums.end());

        int ans = 0;
        int i = 0; int j = 1;
        while(i < nums.size() && j < nums.size()) {
            
            if(i == j || nums[j] - nums[i] < k) j++;
            else {
                if(nums[j] - nums[i] == k){
                    
                    ans++;
                    j++;

                    for(; j < nums.size(); j++){
                        if(nums[j] != nums[j-1]) break;
                    }

                    if(j == nums.size()) return ans;
                    j--;
                }
                i++;

                while(i < j && nums[i] == nums[i-1]) i++;
            }
        }
        return ans;

    }
};

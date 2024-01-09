class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // 1st approach
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // int med = nums[n/2]; // find median

        // int steps = 0l;
        // for(int i = 0; i < n; i++){
        //     steps += abs(nums[i] - med);
        // }
        // return steps;

        // 2nd appraoch
        // int steps = 0;

        // int n = nums.size();

        // sort(nums.begin(), nums.end());

        // for(int i = 0; i < n/2; i++){
        //     steps += nums[n-i-1] - nums[i];
        // }        

        // return steps;

        // 3rd approach

        int n = nums.size();
        int steps = 0;
        nth_element(nums.begin(), nums.begin()+ (n/2), nums.end());


        int med = nums[n/2];

        for(int i = 0; i < n; i++){
            steps += abs(nums[i] - med);
        }
        return steps;
        
    }
};

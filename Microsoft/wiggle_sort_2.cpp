class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        // step 1 sort the array
        sort(nums.begin(), nums.end());

        int i = nums.size()-1;
        int j = 1;

        int n = nums.size();

        vector<int> v(n, 0);

        
            while(j < n){
                v[j] = nums[i];
                j += 2;
                i--;
            }

            j = 0;
            while(j < n){
                v[j] = nums[i];
                j+= 2;
                i--;
            }
            

        for(int i = 0; i < n; i++){
            nums[i] = v[i];
        }
    }
};

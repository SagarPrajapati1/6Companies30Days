class Solution {
public:
    vector <int> v;
    vector<vector<int>> temp;

    int area (vector<int> & arr){
        return (arr[2] - arr[0] + 1) * (arr[3] - arr[1] + 1);
    }
    Solution(vector<vector<int>>& rects) {
        temp = rects;
        int total = 0;
        for(auto it : temp){
            total += area(it);
            v.push_back(total);
        }
    }
    
    vector<int> pick() {

        int rd = rand() % v.back();

        int index = upper_bound(v.begin(), v.end(), rd) - v.begin();

        auto it = temp[index];

        int x = rand() % (it[2] - it[0] + 1) + it[0];
        int y = rand() % (it[3] - it[1] + 1) + it[1];

        return {x,y};
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

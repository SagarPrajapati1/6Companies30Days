class Solution {
public:
    static bool comp(const vector<int>& v1, const vector<int>& v2){
        if(v1[0] == v2[0]) return v1[1] > v2[1];
        return v1[0] < v2[0];
    }

    int maxEnvelopes(vector<vector<int>>& e) {
         sort(e.begin(), e.end(), comp);

         // now use binary search as LIS

         vector<int> temp;
         int cnt = 1;
         temp.push_back(e[0][1]);
         for(int i = 0; i < e.size(); i++){
             if(temp.back() < e[i][1]) {
                 temp.push_back(e[i][1]);
                 cnt++;
             }
             else {
                int idx = lower_bound(temp.begin(), temp.end(), e[i][1])- temp.begin();
                temp[idx] = e[i][1];
             }
         }
         return cnt++;
    }
};

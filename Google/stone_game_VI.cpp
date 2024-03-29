class Solution {
public:
    int stoneGameVI(vector<int>& aV, vector<int>& bV) {
        int a = 0, b = 0, sz = aV.size();
        vector<int> idx(sz);
        iota(begin(idx), end(idx), 0);
        sort(begin(idx), end(idx), [&](int i, int j) {
            return aV[i] + bV[i] > aV[j] + bV[j];
        });
        for (int i = 0; i < sz; ++i) {
            a += i % 2 ? 0 : aV[idx[i]];
            b += i % 2 ? bV[idx[i]] : 0;
        }
        return a == b ? 0 : a > b ? 1 : -1;
    }
};

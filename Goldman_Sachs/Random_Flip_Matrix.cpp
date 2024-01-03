class Solution {
    int m, n;
    set<pair<int, int> > st;
public:
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        st.clear();
    }
    
    vector<int> flip() {
        int row = rand() % m;
        int col = rand() % n;

        while(st.count({row, col}) > 0) {
            row = rand() % m;
            col = rand() % n;
        }
        st.insert({row, col});
        return {row, col};
    }
    
    void reset() {
        st.clear();
    }
};

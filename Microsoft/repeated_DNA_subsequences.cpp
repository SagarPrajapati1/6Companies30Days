class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
         unordered_map<int, int> m;
        vector<string> r;
        for (int t = 0, i = 0; i < s.size(); i++)
            if (m[t = t << 3 & 0x3FFFFFFF | s[i] & 7]++ == 1)
                r.push_back(s.substr(i - 9, 10));
        return r;
    }
};

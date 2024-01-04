class Solution {
    void solve(int ind, string digits, string &temp, vector<string> &ans, string mapping[]) {
        // base case
        if(ind >= digits.length()) {
            ans.push_back(temp);
            return;
        }


        // solve  the problem
        // find out the index for mapping 
        int idx  = digits[ind] - '0';

        // get the string at that index

        string str = mapping[idx];

        // iterate a over the mapping and call recursion
        for(int i = 0; i < str.length(); i++) {
            //store the possible ans
            temp.push_back(str[i]);
            cout << " before " << temp  << " " << str << endl;
            solve(ind+1, digits, temp, ans, mapping);
            // undo the previous operation
            
            temp.pop_back();
            cout << "after " << temp << " " << str <<endl;
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        if(digits.length() == 0) return{};
           
        string temp;
        vector<string> ans;
        solve(0, digits, temp, ans, mapping);
        return ans;


    }
};

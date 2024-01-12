class Solution {
public:
        
    // int result = 0;
    // bool check(string& s){
    //     int i = 0;
    //     int j = s.length() - 1;
 
    //     while (i < j) {
    //         if (s[i] != s[j]) return false;
    //         i++;
    //         j--;
    //     }
 
    //     return true;
    // }

    string reverseStr(string str){
        reverse(str.begin(), str.end());
        return str;
    }
void solve(string &s, string &str1, string &str2, int i, int &res) {
    // if (i >= s.length()) {
    //     if(check(str1) && check(str2) ) {
    //         result = max(result, (int)str1.length() * (int)str2.length());
            
    //     }
    //     return;
    // }

        if(i >= s.length()) {
            string revStr1 = reverseStr(str1);
            string revStr2 = reverseStr(str2);
            if(str1 == revStr1 && str2 == revStr2) 
                res = max(res, (int)str1.length() * (int)str2.length());
            return;
        }
        str1.push_back(s[i]);
        solve(s, str1, str2, i+1, res);
        str1.pop_back();

        str2.push_back(s[i]);
        solve(s, str1, str2, i+1, res);
        str2.pop_back();

        solve(s, str1, str2, i+1, res);

}
    int maxProduct(string s) {
        string str1 = "", str2 = "";

        int result = 0;
        solve(s, str1, str2, 0, result);
        return result;
    }
};

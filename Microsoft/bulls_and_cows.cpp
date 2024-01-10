class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> smp;
        unordered_map<char, int> gmp;

        int n = secret.size();

        int A = 0;
        int B = 0;

        for(int i = 0; i < n; i++){

            char s = secret[i], g = guess[i];

            if(s == g) A++;
            else {
                (smp[g] > 0) ? smp[g]--, B++: gmp[g]++;
                (gmp[s] > 0) ? gmp[s]--, B++: smp[s]++;
            }
        }

        return to_string(A)+"A" + to_string(B)+"B";
    }
};

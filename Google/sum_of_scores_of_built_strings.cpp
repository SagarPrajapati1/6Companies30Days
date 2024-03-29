class Solution {
public:
    #define FastRead        ios_base::sync_with_stdio(0);cin.tie(0)
    #define ULL             unsigned long long
    #define LL              long long
    #define eps             1e-9
    #define inf             0x3f3f3f3f
    #define INF             2e18
    #define all(a)          a.begin(),a.end()
    #define Unique(a)       sort(all(a)),a.erase(unique(all(a)),a.end())

    #define Cube(a) ((a)*(a)*(a))
    #define Sqr(a)  ((a)*(a))
    const int N = 2000006;
    ULL hs = 3797;
    ULL F[100005], H[100005];
    
    ULL seg(int x, int y) {
        return H[y] - H[x - 1] * F[y - x + 1];
    }
    
    long long sumScores(string s) {
        F[0] = 1; for (int i = 1; i <= 100000; i++) F[i] = F[i - 1] * hs;
        for (int i = 1; i <= s.size(); i++) H[i] = H[i - 1] * hs + s[i - 1];
        
        int len = s.size();
        LL res = len;
        
        for (int i = 2; i <= len; i++) {
            int low = 0, high = (len - i + 1), reach = 0;
            while(low <= high) {
                int mid = (low + high) >> 1;
                if (seg(1, 1 + mid - 1) == seg(i, i + mid - 1)) {
                    reach = mid;
                    low = mid + 1;
                } else high = mid - 1;
            }
            res += reach;
        }
        
        return res;
    }
};

class Solution {
public:
    long gcd(long a, long b) {
        if(a %b == 0) return b;
        else return gcd(b, a % b);
    }


    void BinarySearch(long low, long high, long var, long *ans, int d1, int d2, int cnt1, int cnt2) {
        if(low <= high) {
            long mid = (low + high) / 2;

            long varA = mid - mid/d1;
            long varB = mid - mid / d2;

            long varC = mid - mid/d1 - mid/d2 + mid / var;

            if(varA >= cnt1 && varB >= cnt2 && (varA + varB - varC) >= cnt1+ cnt2) {
                *ans = mid;
                BinarySearch(low, mid-1, var, ans, d1, d2, cnt1, cnt2);
            } 
            else {
                BinarySearch(mid + 1, high, var, ans, d1, d2, cnt1, cnt2);
            }
        }
    }

    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        
        // find the gcd of divisors

        long g = gcd(min(divisor1, divisor2), max(divisor1, divisor2));

        long var = ((long)(divisor1)* (long)(divisor2)) / g;

        long ans = 10000000000;

        BinarySearch(2, 10000000000, var, (&ans), divisor1, divisor2, uniqueCnt1, uniqueCnt2);
        return ans;  
    }
};

class Solution {
public:
    int helper(int n,int k){
        if(n==1)
            return 0;
        return (helper(n-1,k) + k) % n;
    }
    int findTheWinner(int n, int k) {
        
        // list<int> q;
        // for(int i = 1; i <= n; i++) q.push_back(i);

        // while(q.size() != 1){
        //     int i = 1;
        //     while(i < k) {
        //         int temp = q.front();
        //         q.pop_front();
        //         q.push_back(temp);
        //         i++;
        //     }
        //     q.pop_front();
        // }
        // return q.front();


        // int ans = 0;
        // for(int i = 1; i <= n; i++) {
        //     ans = (ans+k)%i;
        // }

        // return ans + 1;

        return helper(n,k)+1;
    }
};

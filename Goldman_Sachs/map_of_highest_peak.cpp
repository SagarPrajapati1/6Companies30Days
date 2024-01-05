class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
       

        queue<pair<int, int>> p;
        int row = isWater.size();
        int col = isWater[0].size();
         vector<vector<int> > ans(row, vector<int>(col, INT_MAX));
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(isWater[i][j] == 1) {
                    p.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        while(!p.empty()) {
            int f = p.front().first;
            int b = p.front().second;
            p.pop();
            
            int x[] = {0,0,-1,1};
            int y[] = {-1,1,0,0};
            for(int i = 0; i < 4; i++) {
 

                int idx = f+x[i];
                int idy = b+y[i];

              if(idx >= 0 && idx < row && idy >= 0 && idy < col && ans[idx][idy] > 1 + ans[f][b]) {
                    ans[idx][idy] = 1+ans[f][b];
                    p.push({idx, idy});
                }
            }

        }
        return ans;

    }
};

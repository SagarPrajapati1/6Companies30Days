class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img)
    {
        vector<vector<int>> ans = img;
        int row = img.size();
        int col = img[0].size();

        for(int r = 0; r < row; r++) {
            for(int c = 0; c < col; c++) {

                int temp = 0; int cnt = 0;

                for(int i = max(r-1, 0); i < min(r+2, row); i++){
                    for(int j = max(c-1, 0); j < min(c+2, col); j++){
                        temp += img[i][j];
                        cnt++;
                    }

                    ans[r][c] = temp / cnt;
                }
            }
        }
        return ans;
    }
};

int ans;
class helper{
    public:
    int minVal;
    int maxVal;
    bool flag = true;
    int sum;

    helper(){
        flag = true;
        maxVal = INT_MIN;
        minVal = INT_MAX;
        sum = 0;
    }
};


class Solution {
    public:
    helper solve(TreeNode* root) {
        if(root == nullptr) return helper();
    

        helper obj;
        helper left = solve(root -> left);
        helper right = solve(root -> right);


        if(left.flag == true && right.flag == true && root -> val > left.maxVal && root -> val < right.minVal) {
            obj.flag = true;
            obj.sum = left.sum + right.sum + root -> val;
            obj.minVal = min(root -> val, left.minVal);
            obj.maxVal = max(root -> val, right.maxVal);
        }
        else {
            obj.flag = false;
            obj.sum = max(left.sum, right.sum);
        }
        ans = max(ans, obj.sum);
        return obj;
    }

    int maxSumBST(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};

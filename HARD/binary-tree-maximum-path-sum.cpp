/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0x80000000;
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        maxPathSumDown(root);
        return ans;
    }
    int maxPathSumDown(TreeNode* root)
    {
        if(!root) return 0;
        int leftDown=maxPathSumDown(root->left);
        int rightDown=maxPathSumDown(root->right);
        int temp=root->val+max(0,max(leftDown,rightDown));
        ans=max(ans,temp);
        ans=max(ans,root->val+max(0,leftDown+rightDown));
        return temp;
    }
};

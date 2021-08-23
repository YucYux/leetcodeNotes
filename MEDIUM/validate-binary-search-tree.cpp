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
    int now=0x80000000;
    bool ans=1;
    bool started=0;
    bool isValidBST(TreeNode* root) {
        func(root);
        return ans;
    }
    inline void func(TreeNode* root)
    {   
        if(!ans) return;
        if(root->left)
            func(root->left);
        if(started&&root->val<=now)
        {
            ans=0;
            return;
        }
        started=1;
        now=root->val;
        if(root->right)
            func(root->right);
    }
};

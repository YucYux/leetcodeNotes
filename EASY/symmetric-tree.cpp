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
    bool isSymmetric(TreeNode* root) {
        if(!root) return 1;
        if(root->left&&root->right) return isSymmetricTwo(root->left,root->right);
        if((!root->left)&&(!root->right)) return 1;
        return 0;
    }
    bool isSymmetricTwo(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL&&root2==NULL) return 1;
        if(root1->val!=root2->val) return 0;
        if(((bool)(root1->left))!=((bool)(root2->right))) return 0;
        if(((bool)(root1->right))!=((bool)(root2->left))) return 0;
        if(root1->left&&root1->left->val!=root2->right->val) return 0;
        if(root1->right&&root1->right->val!=root2->left->val) return 0;
        return isSymmetricTwo(root1->left,root2->right)&&isSymmetricTwo(root1->right,root2->left);
    }
};

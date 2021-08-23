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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> res;
        vector<vector<TreeNode*>> vec;
        vector<TreeNode*> temp;
        vec.emplace_back(temp);
        vec.emplace_back(temp);
        int use=0;
        vec[use].emplace_back(root);
        while(vec[use].empty()!=1)
        {
            for(int i=0;i<vec[use].size();i++)
            {
                if(vec[use][i]->left)
                    vec[use^1].emplace_back(vec[use][i]->left);
                if(vec[use][i]->right)
                    vec[use^1].emplace_back(vec[use][i]->right);
                res.emplace_back(vec[use][i]->val);
            }
            ans.emplace_back(res);
            res.clear();
            vec[use].clear();
            use=use^1;
        }
        return ans;
    }
};

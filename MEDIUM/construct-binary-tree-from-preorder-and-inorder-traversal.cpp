/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int* pre;
    int* in;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre=&preorder[0];
        in=&inorder[0];
        return buildTreeRange(0,preorder.size()-1,0,preorder.size()-1);
    }
    TreeNode* buildTreeRange(int ps,int pe,int is,int ie)
    {
        TreeNode* temp=new TreeNode(pre[ps]);
        if(ps==pe) return temp;
        int mid=0;
        for(int i=is;i<=ie;i++)
        {
            if(in[i]==pre[ps])
            {
                mid=i;
                break;
            }
        }
        if(mid!=is)
            temp->left=buildTreeRange(ps+1,ps+mid-is,is,mid-1);
        if(mid!=ie)
            temp->right=buildTreeRange(ps+mid-is+1,pe,mid+1,ie);
        return temp;
    }
};

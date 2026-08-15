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
int ans=0;
int answer(TreeNode* root)
    { 
        if(root==NULL) return 0;
        int left=answer(root->left);
        int right=answer(root->right);
        ans=max(ans,abs(left-right));
        return 1+max(left,right);

    }
    bool isBalanced(TreeNode* root) {
        answer(root);
        if(ans<=1) return true;
        else return false;    }
};

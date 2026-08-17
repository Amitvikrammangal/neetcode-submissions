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
    void answer(TreeNode* root,int x,int &count)
    {
         if(root==NULL) return;


         if(root->val>=x)
         count++;
            x=max(x,root->val);
         answer(root->left,x,count);
         answer(root->right,x,count);
    }
    int goodNodes(TreeNode* root) {
        int x=root->val;
        int count=0;
        answer(root,x,count);
        return count;
    }
};

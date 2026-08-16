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
     TreeNode* answer( TreeNode* root,int value)
     {
         if(root==NULL)
         {
             return new TreeNode(value);
         }
         else if(root->val<value)
         { 
            root->right= answer(root->right,value);
         }
         else
         { 
            root->left= answer(root->left,value);
         }
         return root;
     }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return answer(root,val);
    }
};
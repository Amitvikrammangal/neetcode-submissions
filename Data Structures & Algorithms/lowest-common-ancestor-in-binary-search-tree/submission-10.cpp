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
       TreeNode* answer(TreeNode* root,TreeNode* p,TreeNode* q)
      {
        if(root==NULL)
        {
             return NULL;
        }
        if(root->val>p->val && root->val>q->val)
        { 
            return answer(root->left,p,q);
        }
        else if((root->val>=p->val && root->val<=q->val) || (root->val>=q->val && root->val<=p->val))
        {
             return root;
        }
        else 
        {
           return answer(root->right,p,q);
        }
        return NULL;
      }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return answer(root,p,q);
    }
};

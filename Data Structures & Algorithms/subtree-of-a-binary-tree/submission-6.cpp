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
  bool answer(TreeNode* p,TreeNode* q)
  {
      if(p==NULL && q==NULL) return true;
      if(p==NULL || q==NULL) return false;
      if((p->val) !=(q->val))
    {
        return false;
    }
     
    return answer(p->left,q->left) && answer(p->right,q->right);
  }
    bool search(TreeNode* root,TreeNode* subroot)
    {
        if(root==NULL) return false;
         if(root->val==subroot->val)
         {
             if(answer(root,subroot)) return true;
         }
         return search(root->left,subroot) ||  search(root->right,subroot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
         return search(root,subroot);
    }
};

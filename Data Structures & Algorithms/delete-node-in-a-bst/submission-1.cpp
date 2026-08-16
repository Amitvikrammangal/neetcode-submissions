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
    TreeNode* getorder(TreeNode* root)
    {
         while(root!=NULL && root->left!=NULL)
         {
             root=root->left;
         }
         return root; 
    }
    TreeNode* answer(TreeNode* root,int key)
    {
         if(root==NULL)
         {
             return NULL;
         }
         if(root->val>key)
         {
             root->left = answer(root->left, key);
         }
         else if(root->val<key)
         {
            root->right=answer(root->right,key);
         }
         else
         {
             if(root->left==NULL && root->right==NULL) 
             {
                 delete root;
                 return NULL;
             }
             else if(root->left==NULL)
             { 
                TreeNode* temp=root->right;
                delete root;
                return temp;
             }
             else if(root->right==NULL)
             {
                 TreeNode* temp=root->left;
                 delete root;
                 return temp;
             }
             else
             {
                 TreeNode* IS=getorder(root->right);
                 root->val=IS->val;
                 root->right=answer(root->right,IS->val);
             }
         }
         return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return answer(root,key);
    }
};
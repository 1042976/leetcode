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
    //Time O(N), Space O(1)
    // TreeNode* insertIntoBST(TreeNode* root, int val) {
    //     TreeNode *cur = root;
    //     TreeNode *newNode = new TreeNode(val);
    //     if(root == nullptr){
    //         return newNode;
    //     }
    //     while(true){
    //         if(cur->val < val){
    //             if(cur->right == nullptr){
    //                 cur->right = newNode;
    //                 return root;
    //             }else{
    //                cur = cur->right; 
    //             }
    //         }else{
    //             if(cur->left == nullptr){
    //                 cur->left = newNode;
    //                 return root;
    //             }else{
    //                 cur = cur->left;
    //             }
    //         }
    //     }
    //     return root;
    // }
    
    //Time O(N), Space O(N)
    TreeNode* insertIntoBST(TreeNode* root, int val){
        if(root == nullptr){
            return new TreeNode(val);
        }
        if(root->val < val){
            root->right = insertIntoBST(root->right, val);
        }else{
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
};

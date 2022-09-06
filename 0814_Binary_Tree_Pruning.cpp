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
    // TreeNode* dfs(TreeNode* parent, TreeNode* cur){
    //     if(cur->left != nullptr){
    //         dfs(cur, cur->left);
    //     }
    //     if(cur->right != nullptr){
    //         dfs(cur, cur->right);
    //     }
    //     if(cur->val == 0 && cur->left == nullptr && cur->right == nullptr){
    //         if(parent != nullptr){
    //            cur == parent->left? parent->left = nullptr : parent->right = nullptr; 
    //         }
    //         delete(cur);
    //         cur = nullptr;
    //     }
    //     return cur;
    // }
    // //Time O(N), Space O(N)
    // TreeNode* pruneTree(TreeNode* root) {
    //     return dfs(nullptr, root);
    // }
    
    //Time O(N), Space O(N)
    TreeNode* pruneTree(TreeNode* root){
        if(root == nullptr){
            return nullptr;
        }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->val == 0 && root->left == nullptr && root->right == nullptr){
            delete(root);
            root = nullptr;
        }
        return root;
    }
};

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
    // Iterative Time O(N), Space O(N)
    // TreeNode* invertTree(TreeNode* root) {
    //     if(root == nullptr){
    //         return nullptr;
    //     }
    //     queue<TreeNode*> Q;
    //     Q.emplace(root);
    //     while(!Q.empty()){
    //         TreeNode* cur = Q.front();
    //         Q.pop();
    //         swap(cur->left, cur->right);
    //         if(cur->left !=nullptr){
    //             Q.emplace(cur->left);
    //         }
    //         if(cur->right != nullptr){
    //             Q.emplace(cur->right);
    //         }
    //     }
    //     return root;
        
    // }

    // Recursive Time O(N), Space O(logN)
    TreeNode* invertTree(TreeNode* root){
        if(root == nullptr){
            return nullptr;
        }
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};

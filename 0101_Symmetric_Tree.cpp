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
    //Time O(N), Space O(N)
    // bool dfs(TreeNode* a, TreeNode* b){
    //     if(a == nullptr || b == nullptr){
    //         return a == nullptr && b == nullptr;
    //     }
    //     if(a->val != b->val){
    //         return false;
    //     }
    //     return dfs(a->left, b->right) && dfs(a->right, b->left);
    // }
    // bool isSymmetric(TreeNode* root) {
    //     return dfs(root->left, root->right);
    // }
    
    //Time O(N), Space O(N)
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return false;
        }
        queue<TreeNode*> A, B;
        A.emplace(root->left);
        B.emplace(root->right);
        while(!A.empty()){
            TreeNode* a = A.front();
            TreeNode* b = B.front();
            A.pop();
            B.pop();
            if(a == nullptr || b == nullptr){
                if(a == nullptr && b == nullptr){
                    continue;
                }else{
                    return false;
                }
            }
            if(a->val != b->val){
                return false;
            }
            A.emplace(a->left);
            A.emplace(a->right);
            B.emplace(b->right);
            B.emplace(b->left);
        }
        return true;
    }
};

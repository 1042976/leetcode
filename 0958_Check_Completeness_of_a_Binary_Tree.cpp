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
    //bfs. Time O(N), Space O(N)
    // bool isCompleteTree(TreeNode* root) {
    //     queue<TreeNode*> Q;
    //     Q.emplace(root);
    //     int numOfNodes = 1;
    //     while(!Q.empty()){
    //         int size = Q.size();
    //         bool shouldNotHaveChild = false;
    //         for(int i = 0; i < size; ++i){
    //             TreeNode* cur = Q.front();
    //             Q.pop();
    //             if(shouldNotHaveChild){
    //                 if(cur->left != nullptr || cur->right != nullptr){
    //                     return false;
    //                 }
    //             }else{
    //                 if(cur->left == nullptr){
    //                     shouldNotHaveChild = true;
    //                     if(cur->right != nullptr){
    //                         return false;
    //                     }
    //                 }else{
    //                     Q.emplace(cur->left);
    //                 }
    //                 if(cur->right == nullptr){
    //                     shouldNotHaveChild = true;
    //                 }else{
    //                     Q.emplace(cur->right);
    //                 }
    //             }
    //         }
    //         if(!Q.empty() && size < numOfNodes){
    //             return false;
    //         }
    //         numOfNodes <<= 1;
    //     }
    //     return true;
    // }
    
    //bfs. Time O(N), Space O(N)
    // bool isCompleteTree(TreeNode* root){
    //     queue<TreeNode*> Q;
    //     Q.emplace(root);
    //     while(!Q.empty()){
    //         TreeNode* cur = Q.front();
    //         Q.pop();
    //         if(cur != nullptr){
    //             Q.emplace(cur->left);
    //             Q.emplace(cur->right);
    //         }else{
    //             break;
    //         }
    //     }
    //     while(!Q.empty()){
    //         TreeNode* cur = Q.front();
    //         if(cur != nullptr){
    //             return false;
    //         }
    //         Q.pop();
    //     }
    //     return true;
    // }
    
    int dfs(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int l = dfs(root->left), r = dfs(root->right);
        bool state = (l&(l+1)) == 0 && (l-1)/2 <= r && r <= l 
            || (r&(r+1)) == 0 && r <= l && l < 2*r+1;
        return state? l+r+1 : -1;
    }
    //Time O(N), Space O(H)
    bool isCompleteTree(TreeNode* root){
        return dfs(root) >= 0;
    }
};

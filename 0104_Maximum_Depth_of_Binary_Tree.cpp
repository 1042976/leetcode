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
    // int maxDepth(TreeNode* root) {
    //     queue<TreeNode*> Q;
    //     if(root != nullptr){
    //        Q.emplace(root); 
    //     }
    //     int depth = 0;
    //     while(!Q.empty()){
    //         ++depth;
    //         int sizeOfDepth = Q.size();
    //         while(sizeOfDepth--){
    //             TreeNode* cur = Q.front();
    //             Q.pop();
    //             if(cur->left != nullptr){
    //                 Q.emplace(cur->left);
    //             }
    //             if(cur->right != nullptr){
    //                 Q.emplace(cur->right);
    //             }
    //         }
    //     }
    //     return depth;
    // }
    
    //Time O(N), Space O(N)
    int maxDepth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return 1+max(maxDepth(root->left), maxDepth(root->right));;
    }
};

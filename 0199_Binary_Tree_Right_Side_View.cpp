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
    //Time O(n), Space O(n), bfs
    // vector<int> rightSideView(TreeNode* root) {
    //     if(root == nullptr){
    //         return vector<int>();
    //     }
    //     vector<int> res;
    //     queue<TreeNode*> Q;
    //     Q.emplace(root);
    //     int sizeOfLevel = 1;
    //     while(!Q.empty()){
    //         while(sizeOfLevel--){
    //             TreeNode* cur = Q.front();
    //             Q.pop();
    //             if(sizeOfLevel == 0){
    //                 res.emplace_back(cur->val);
    //             }
    //             if(cur->left != nullptr){
    //                 Q.emplace(cur->left);
    //             }
    //             if(cur->right != nullptr){
    //                 Q.emplace(cur->right);
    //             }
    //         }
    //         sizeOfLevel = Q.size();
    //     }
    //     return res;
    // }
    vector<int> res;
    void dfs(TreeNode* node, int level){
        if(node == nullptr){
            return;
        }
        if(res.size() < level){
            res.emplace_back(node->val);
        }
        dfs(node->right, level+1);
        dfs(node->left, level+1);
    }
    //Time O(n), Space O(n)
    vector<int> rightSideView(TreeNode* root){
        dfs(root, 1);
        return res;
    }
};

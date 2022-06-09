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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root == nullptr){
            return res;
        }
        queue<TreeNode*> Q;
        Q.emplace(root);
        while(!Q.empty()){
            int sizeOfLevel = Q.size();
            res.emplace_back(vector<int>());
            while(sizeOfLevel--){
                TreeNode* cur = Q.front();
                Q.pop();
                res.back().emplace_back(cur->val);
                if(cur->left != nullptr){
                    Q.emplace(cur->left);
                }
                if(cur->right != nullptr){
                    Q.emplace(cur->right);
                }
            }
        }
        return res;
    }
    
    // vector<vector<int> > res;
    // void dfs(TreeNode* cur, int level){
    //     if(cur == nullptr){
    //         return;
    //     }
    //     if(res.size() == level){
    //         res.emplace_back(vector<int>());
    //     }
    //     res[level].emplace_back(cur->val);
    //     dfs(cur->left, level+1);
    //     dfs(cur->right, level+1);
    // }
    // //Time O(N), Space O(N)
    // vector<vector<int>> levelOrder(TreeNode* root){
    //     dfs(root, 0);
    //     return res;
    // }
};

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
    // vector<int> largestValues(TreeNode* root) {
    //     if(root == nullptr){
    //         return vector<int>();
    //     }
    //     vector<int> res;
    //     queue<TreeNode*> Q;
    //     Q.emplace(root);
    //     while(!Q.empty()){
    //         int size = Q.size();
    //         int maxVal = INT_MIN;
    //         while(size > 0){
    //             TreeNode* cur = Q.front();
    //             Q.pop();
    //             maxVal = max(maxVal, cur->val);
    //             --size;
    //             if(cur->left != nullptr){
    //                 Q.emplace(cur->left);
    //             }
    //             if(cur->right != nullptr){
    //                 Q.emplace(cur->right);
    //             }
    //         }
    //         res.emplace_back(maxVal);
    //     }
    //     return res;    
    // }
    
    //dfs. Time O(N), Space O(H)
    vector<int> res;
    void dfs(TreeNode* root, int level){
        if(root == nullptr){
            return;
        }
        if(res.size() > level){
            res[level] = max(res[level], root->val);
        }else{
            res.emplace_back(root->val);
        }
        ++level;
        dfs(root->left, level);
        dfs(root->right, level);
    }
    vector<int> largestValues(TreeNode* root){
        dfs(root, 0);
        return res;
    }
};

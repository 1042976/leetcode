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
    //bfs Time O(nlogn) Space O(n)
    // vector<vector<int>> verticalOrder(TreeNode* root) {
    //     vector<vector<int> > res;
    //     if(root == nullptr){
    //         return res;
    //     }
    //     map<int, vector<int> > hashMap;
    //     queue<pair<TreeNode*, int> > Q;
    //     Q.emplace(make_pair(root, 0));
    //     while(!Q.empty()){
    //         auto [cur, column] = Q.front();
    //         Q.pop();
    //         hashMap[column].emplace_back(cur->val);
    //        if(cur->left != nullptr){
    //             Q.emplace(make_pair(cur->left, column-1));
    //         }       
    //         if(cur->right != nullptr){
    //             Q.emplace(make_pair(cur->right, column+1));
    //         }
    //     }
    //     for(auto [column, arr] : hashMap){
    //         res.emplace_back(arr);
    //     }
    //     return res;
    // }
    
    
    //bfs, Time O(n) Space O(n)
    vector<vector<int>> verticalOrder(TreeNode* root){
        vector<vector<int> > res;
        if(root == nullptr){
            return res;
        }
        queue<pair<TreeNode*, int> > Q;
        Q.emplace(make_pair(root, 0));
        unordered_map<int, vector<int> > hashMap;
        int minColumn = INT_MAX, maxColumn = INT_MIN;
        while(!Q.empty()){
            auto [cur, column] = Q.front();
            Q.pop();
            minColumn = min(minColumn, column);
            maxColumn = max(maxColumn, column);
            hashMap[column].emplace_back(cur->val);
            if(cur->left != nullptr){
                Q.emplace(make_pair(cur->left, column-1));
            }
            if(cur->right != nullptr){
                Q.emplace(make_pair(cur->right, column+1));
            }
        }
        res.resize(maxColumn-minColumn+1);
        for(const auto &[column, arr] : hashMap){
            res[column-minColumn] = arr;
        }
        return res;
    }
};

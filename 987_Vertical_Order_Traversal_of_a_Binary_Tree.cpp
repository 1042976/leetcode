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
    //bfs Time O(n*log(n/k)), Space O(n)
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int minColumn = INT_MAX;
        unordered_map<int, vector<pair<int, int> > > hashMap; //column, [row, val]
        queue<pair<TreeNode*, int> > Q;
        int row = 0;
        int sizeOfLevel = 1;
        Q.emplace(make_pair(root, 0));
        while(!Q.empty()){
            while(sizeOfLevel--){
                auto [cur, column] = Q.front();
                Q.pop();
                hashMap[column].emplace_back(make_pair(row, cur->val));
                minColumn = min(minColumn, column);
                if(cur->left != nullptr){
                    Q.emplace(make_pair(cur->left, column-1));
                }
                if(cur->right != nullptr){
                    Q.emplace(make_pair(cur->right, column+1));      
                }
            }
            ++row;
            sizeOfLevel = Q.size();
        }
        vector<vector<int> > res(hashMap.size());
        for(auto &[column, arr] : hashMap){
            sort(arr.begin(), arr.end(), [](const pair<int, int> &a, const pair<int, int> &b)->bool{
                if(a.first == b.first){
                    return a.second < b.second;
                }else{
                    return a.first < b.first;
                }
            });
            int idx = column-minColumn;
            res[idx].resize(arr.size());
            for(int i = 0; i < arr.size(); ++i){
                res[idx][i] = arr[i].second;
            }
        }
        return res;
    }
};

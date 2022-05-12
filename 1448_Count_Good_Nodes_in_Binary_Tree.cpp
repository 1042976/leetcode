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
    // int count;
    // void dfs(TreeNode* cur, int maxVal){
    //     if(cur->val >= maxVal){
    //         ++count;
    //         maxVal = cur->val;
    //     }
    //     if(cur->left != nullptr){
    //         dfs(cur->left, maxVal);
    //     }
    //     if(cur->right != nullptr){
    //         dfs(cur->right, maxVal);
    //     }
    // }
    // //Time O(n) Space O(n)
    // int goodNodes(TreeNode* root) {
    //     count = 0;
    //     if(root == nullptr){
    //         return 0;
    //     }
    //     dfs(root, INT_MIN);
    //     return count;
    // }
    
    //Time O(n) Space O(n)
    // int goodNodes(TreeNode* root){
    //     if(root == nullptr){
    //         return 0;
    //     }
    //     int count = 0;
    //     stack<pair<TreeNode*, int> > st;
    //     st.emplace(make_pair(root, INT_MIN));
    //     while(!st.empty()){
    //         auto [cur, maxVal] = st.top();
    //         st.pop();
    //         if(cur->val >= maxVal){
    //             ++count;
    //             maxVal = cur->val;
    //         }
    //         if(cur->left != nullptr){
    //             st.emplace(make_pair(cur->left, maxVal));
    //         }
    //         if(cur->right != nullptr){
    //             st.emplace(make_pair(cur->right, maxVal));
    //         }
    //     }
    //     return count;
    // }
    
    
    //Time O(n), Space O(n)
    int goodNodes(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int count = 0;
        queue<pair<TreeNode*, int> > Q;
        Q.emplace(make_pair(root, INT_MIN));
        while(!Q.empty()){
            auto [cur, maxVal] = Q.front();
            Q.pop();
            if(cur->val >= maxVal){
                ++count;
                maxVal = cur->val;
            }
            if(cur->left != nullptr){
                Q.emplace(make_pair(cur->left, maxVal));
            }
            if(cur->right != nullptr){
                Q.emplace(make_pair(cur->right, maxVal));
            }
        }
        return count;
    }
};

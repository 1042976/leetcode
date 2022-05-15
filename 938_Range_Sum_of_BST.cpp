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
    //Time O(n), Space O(n)
    // int rangeSumBST(TreeNode* root, int low, int high) {
    //     int res = 0;
    //     if(root == nullptr){
    //         return res;
    //     }
    //     queue<TreeNode*> Q;
    //     Q.emplace(root);
    //     while(!Q.empty()){
    //         TreeNode* cur = Q.front();
    //         Q.pop();
    //         if(cur->val >= low && cur->val <= high){
    //             res += cur->val;
    //         }
    //         if(cur->val > low && cur->left != nullptr){
    //             Q.emplace(cur->left);
    //         }
    //         if(cur->val < high && cur->right != nullptr){
    //             Q.emplace(cur->right);
    //         }
    //     }
    //     return res;
    // }
    
    //Time O(n), Space O(n)
    int rangeSumBST(TreeNode* root, int low, int high){
        int res = 0;
        if(root == nullptr){
            return res;
        }
        stack<TreeNode*> st;
        st.emplace(root);
        while(!st.empty()){
            TreeNode* cur = st.top();
            st.pop();
            if(cur->val >= low && cur->val <= high){
                res += cur->val;
            }
            if(cur->val < high && cur->right != nullptr){
                st.emplace(cur->right);
            }
            if(cur->val > low && cur->left != nullptr){
                st.emplace(cur->left);
            }
        }
        return res;
    }
};

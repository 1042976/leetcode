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
    // vector<int> res;
    // void inorder(TreeNode* root){
    //     if(root == nullptr){
    //         return;
    //     }
    //     inorder(root->left);
    //     res.emplace_back(root->val);
    //     inorder(root->right);
    // }
    // //Time O(N), Space O(N)
    // vector<int> inorderTraversal(TreeNode* root) {
    //     inorder(root);
    //     return res;
    // }
    
    //Time O(N), Space O(N)
    // vector<int> inorderTraversal(TreeNode* root){
    //     vector<int> res;
    //     stack<TreeNode*> st;
    //     while(true){
    //         while(root != nullptr){
    //             st.emplace(root);
    //             root = root->left;
    //         }
    //         if(st.empty()){
    //             break;
    //         }
    //         root = st.top();
    //         st.pop();
    //         res.emplace_back(root->val);
    //         root = root->right;
    //     }
    //     return res;
    // }
    
    //Time O(N), Space O(1)
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        while(root != nullptr){
            TreeNode* left = root->left;
            if(left == nullptr){
                res.emplace_back(root->val);
                root = root->right;
            }else{
                TreeNode* pre = left;
                while(pre->right != nullptr){
                    pre = pre->right;
                }
                pre->right = root;
                root->left = nullptr;
                root = left;
            }
        }
        return res;
    }
};

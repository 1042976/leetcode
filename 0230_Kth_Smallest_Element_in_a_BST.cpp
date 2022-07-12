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
//     int val = -1;
//     void inorder(TreeNode* root, int& k){
//         if(root == nullptr || k <= 0){
//             return;
//         }
//         inorder(root->left, k);
//         if(--k == 0){
//             val = root->val;
//             return;
//         }
//         inorder(root->right, k);
          
//     }
//     //Time O(H+k) Space O(H)
//     int kthSmallest(TreeNode* root, int k) {
//         inorder(root, k);
//         return val;
//     }
    
    //Time O(H+k), Space O(H)
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while(true){
            while(root != nullptr){
                st.emplace(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if(--k == 0){
                return root->val;
            }
            root = root->right;
        }
        return 0;
    }
};

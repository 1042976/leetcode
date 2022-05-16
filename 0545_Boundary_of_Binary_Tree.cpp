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
    //T-O(n), S-O(logn)
    // vector<int> boundaryOfBinaryTree(TreeNode* root) {
//         vector<int> res;
//         //root
//         if(root == nullptr){
//             return res;
//         }
//         res.emplace_back(root->val);
//         //left boundary
//         if(root->left != nullptr){
//             res.emplace_back(root->left->val);
//             TreeNode* cur = root->left;
//             while(cur != nullptr){
//                 if(cur->left != nullptr){
//                     res.emplace_back(cur->left->val);
//                     cur = cur->left;
//                 }else if(cur->right != nullptr){
//                     res.emplace_back(cur->right->val);
//                     cur = cur->right;
//                 }else{
//                     res.pop_back();
//                     break;
//                 }            
//             }
//         }
        
//         //leaf
//         if(root->left != nullptr || root->right != nullptr){
//             stack<TreeNode*> st;
//             st.emplace(root);
//             while(!st.empty()){
//                 TreeNode* cur = st.top();
//                 st.pop();
//                 if(cur->left == nullptr && cur->right == nullptr){
//                     res.emplace_back(cur->val);
//                 }else{
//                     if(cur->right != nullptr){
//                         st.emplace(cur->right);
//                     }
//                     if(cur->left != nullptr){
//                         st.emplace(cur->left);
//                     }
//                 }
//             }
//         }

        
//         //right boundary
//         int sizeOfRightBoundary = 0;
//         if(root->right != nullptr){
//             res.emplace_back(root->right->val);
//             TreeNode* cur = root->right;
//             while(cur != nullptr){
//                 if(cur->right != nullptr){
//                     res.emplace_back(cur->right->val);
//                     ++sizeOfRightBoundary;
//                     cur = cur->right;
//                 }else if(cur->left != nullptr){
//                     res.emplace_back(cur->left->val);
//                     ++sizeOfRightBoundary;
//                     cur = cur->left;
//                 }else{
//                     res.pop_back();
//                     break;
//                 }
//             }
//         }
        
//         //reverse right boundary
//         reverse(res.end()-sizeOfRightBoundary, res.end());
//         return res;
//     }
    //T-O(n), S-O(logn)
    int ROOT_NODE, LEFT_B_NODE, RIGHT_B_NODE, OTHER_NODE;
    void preOrder(vector<int>& res, TreeNode* node, int status){
        if(node == nullptr){
            return;
        }
        if(status == ROOT_NODE){
            res.emplace_back(node->val);
            preOrder(res, node->left, LEFT_B_NODE);
            preOrder(res, node->right, RIGHT_B_NODE);
        }else if(status == LEFT_B_NODE){
            res.emplace_back(node->val);
            if(node->left != nullptr){
                preOrder(res, node->left, LEFT_B_NODE);
                preOrder(res, node->right, OTHER_NODE);
            }else if(node->right != nullptr){
                preOrder(res, node->right, LEFT_B_NODE);
            }
        }else if(status == RIGHT_B_NODE){
            if(node->right != nullptr){
                preOrder(res, node->left, OTHER_NODE);
                preOrder(res, node->right, RIGHT_B_NODE);
            }else if(node->left != nullptr){
                preOrder(res, node->left, RIGHT_B_NODE);
            }
            res.emplace_back(node->val);
        }else{
            if(node->left == nullptr && node->right == nullptr){
                res.emplace_back(node->val);
            }else{
                preOrder(res, node->left, OTHER_NODE);
                preOrder(res, node->right, OTHER_NODE);
            }
        }
        
    }
        
    vector<int> boundaryOfBinaryTree(TreeNode* root){
        ROOT_NODE = 0;
        LEFT_B_NODE = 1;
        RIGHT_B_NODE = 2;
        OTHER_NODE = 3;
        vector<int> res;
        preOrder(res, root, 0);
        return res;
    }
};

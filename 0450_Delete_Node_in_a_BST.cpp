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
//     TreeNode* insert(TreeNode* a, TreeNode* b){
//         if(b == nullptr){
//             return a;
//         }
//         TreeNode* root = a;
//         while(a != nullptr){
//             if(a->val > b->val){
//                 if(a->left == nullptr){
//                     a->left = b;
//                     return root;
//                 }
//                 a = a->left;
//             }else{
//                 if(a->right == nullptr){
//                     a->right = b;
//                     return root;
//                 }
//                 a = a->right;
//             }
//         }
//         return root;
//     }
//     TreeNode* deleteNode(TreeNode* root){
//         TreeNode* newRoot = nullptr;
//         if(root->right != nullptr){
//             newRoot = insert(root->right, root->left);
//         }else if(root->left != nullptr){
//             newRoot = insert(root->left, root->right);
//         }
//         delete(root);
//         return newRoot;
//     }
//     //Time O(N), Space O(1)
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if(root == nullptr){
//             return nullptr;
//         }
//         if(root->val == key){
//             return deleteNode(root);
//         }
        
//         TreeNode *cur = root;
//         while(cur != nullptr){
//             if(cur->val > key){
//                 if(cur->left != nullptr && cur->left->val == key){
//                     cur->left = deleteNode(cur->left);
//                 }
//                 cur = cur->left;
//             }else{
//                 if(cur->right != nullptr && cur->right->val == key){
//                     cur->right = deleteNode(cur->right);
//                 }
//                 cur = cur->right;
//             }
//         }
//         return root;
//     }
    TreeNode* predecessor(TreeNode* root){
        root = root->right;
        while(root->left != nullptr){
            root = root->left;
        }
        return root;
    }
    TreeNode* successor(TreeNode* root){
        root = root->left;
        while(root->right != nullptr){
            root = root->right;
        }
        return root;
    }
    
    //Time O(N), Space O(N)
    TreeNode* deleteNode(TreeNode* root, int key){
        if(root == nullptr){
            return nullptr;
        }
        if(root->val > key){
            root->left =  deleteNode(root->left, key);
        }else if(root->val < key){
            root->right =  deleteNode(root->right, key);
        }else{
            if(root->left == nullptr && root->right == nullptr){
                delete(root);
                return nullptr;
            }else if(root->right != nullptr){
                TreeNode* p = predecessor(root);
                swap(root->val, p->val);
                root->right = deleteNode(root->right, p->val);
            }else{
                TreeNode* s = successor(root);
                swap(root->val, s->val);
                root->left =  deleteNode(root->left, s->val);
            }
        }
        return root;
    }
};

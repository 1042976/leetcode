/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //Time O(n), Space O(n)
//     TreeNode *previous, *inorderSuccessorNode;
//     void inorder(TreeNode* cur, TreeNode* p){
//         if(cur == nullptr){
//             return;
//         }
//         inorder(cur->left, p);
//         if(inorderSuccessorNode != nullptr){
//             return;
//         }
//         if(previous == p){
//             inorderSuccessorNode = cur;
//             return;
//         }
//         previous = cur;
//         inorder(cur->right, p);
        
//     }
//     TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
//         if(p->right != nullptr){
//             TreeNode* leftmost = p->right;
//             while(leftmost->left != nullptr){
//                 leftmost = leftmost->left;
//             }
//             return leftmost;
//         }else{
//             inorder(root, p);
//             return inorderSuccessorNode;
//         }
//     }
    //Time O(n), Space O(1)
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
        TreeNode *cur = root, *successor = nullptr;
        while(cur != nullptr){
            if(cur->val <= p->val){
                cur = cur->right;
            }else{
                successor = cur;
                cur = cur->left;
            }
        }
        return successor;
    }
    
};

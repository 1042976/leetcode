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
//     int sum = 0;
//     void dfs(int val, TreeNode* root){
//         val = val*10 + root->val;
//         if(root->left == nullptr && root->right == nullptr){
//             sum += val;
//             return;
//         }
//         if(root->left != nullptr){
//            dfs(val, root->left); 
//         }
//         if(root->right != nullptr){
//            dfs(val, root->right); 
//         }
//     }
//     //Time O(N), Space O(H)
//     int sumNumbers(TreeNode* root) {
//         if(root == nullptr){
//             return 0;
//         }
//         dfs(0, root);
//         return sum;
//     }
    
    //Time O(N), Space O(N)
    // int sumNumbers(TreeNode* root){
    //     if(root == nullptr){
    //         return 0;
    //     }
    //     int sum = 0;
    //     queue<pair<int, TreeNode*> > Q;
    //     Q.emplace(make_pair(0, root));
    //     while(!Q.empty()){
    //         auto [val, node] = Q.front();
    //         Q.pop();
    //         val = val*10 + node->val;
    //         if(node->left == nullptr && node->right == nullptr){
    //             sum += val;
    //         }else{
    //             if(node->left != nullptr){
    //                 Q.emplace(make_pair(val, node->left));
    //             }
    //             if(node->right != nullptr){
    //                 Q.emplace(make_pair(val, node->right));
    //             }
    //         }
    //     }
    //     return sum;
    // }
    
    //Time O(N), Space O(1)
    int sumNumbers(TreeNode* root){
        int sum = 0;
        int curVal = 0;
        while(root != nullptr){
            if(root->left != nullptr){
                TreeNode* predecessor = root->left;
                int depth = 1;
                while(predecessor->right != nullptr && predecessor->right != root){
                    predecessor = predecessor->right;
                    ++depth;
                }
                if(predecessor->right == nullptr){
                    curVal = curVal*10 + root->val;
                    predecessor->right = root;
                    root = root->left;
                }else{
                    if(predecessor->left == nullptr){
                       sum += curVal; 
                    }
                    while(depth--){
                        curVal /= 10;
                    }
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }else{
                curVal = curVal*10 + root->val;
                if(root->right == nullptr){
                    sum += curVal;
                }
                root = root->right;
            }
        }
        return sum;
    }
};

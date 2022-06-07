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
    //Time O(N), Space O(N)
    // bool check(TreeNode* node, int minVal, int maxVal){
    //     if(node->val == INT_MAX && node->right != nullptr){
    //         return false;
    //     }else if(node->val == INT_MIN && node->left != nullptr){
    //         return false;
    //     }else if(node->val >= minVal && node->val <= maxVal){
    //         return (node->left == nullptr || check(node->left, minVal, node->val-1)) && 
    //             (node->right == nullptr || check(node->right, node->val+1, maxVal));
    //     }else{
    //         return false;
    //     }
    // }
    // bool isValidBST(TreeNode* root) {
    //     return check(root, INT_MIN, INT_MAX);
    // }
    
    //Time O(N), Space O(N)
    // bool isValidBST(TreeNode* root){
    //     stack<pair<TreeNode*, pair<int, int> > > st;
    //     st.emplace(make_pair(root, make_pair(INT_MIN, INT_MAX)));
    //     while(!st.empty()){
    //         auto [node, vals] = st.top();
    //         int minVal = vals.first;
    //         int maxVal = vals.second;
    //         st.pop();
    //         if(node->val == INT_MAX && node->right != nullptr){
    //             return false;
    //         }
    //         if(node->val == INT_MIN && node->left != nullptr){
    //             return false;
    //         }
    //         if(node->val >= minVal && node->val <= maxVal){
    //             if(node->left != nullptr){
    //                 st.emplace(make_pair(node->left, make_pair(minVal, node->val-1)));
    //             }
    //             if(node->right != nullptr){
    //                 st.emplace(make_pair(node->right, make_pair(node->val+1, maxVal)));
    //             }
    //         }else{
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    
    
    //Time O(N), Space O(N)
    // bool check(TreeNode* node, TreeNode* low, TreeNode* high){
    //     if(node == nullptr){
    //         return true;
    //     }
    //     if(low != nullptr){
    //         if(node->val <= low->val){
    //             return false;
    //         }
    //     }
    //     if(high != nullptr){
    //         if(node->val >= high->val){
    //             return false;
    //         }
    //     }
    //     return check(node->left, low, node) && check(node->right, node, high);
    // }
    // bool isValidBST(TreeNode* root){
    //    return check(root, nullptr, nullptr);
    // }
    
    //Time O(N), Space O(N)
    // bool isValidBST(TreeNode* root){
    //     stack<TreeNode*> stA;
    //     stack<pair<TreeNode*, TreeNode*> > stB;
    //     stA.emplace(root);
    //     stB.emplace(make_pair(nullptr, nullptr));
    //     while(!stA.empty()){
    //         TreeNode* node = stA.top();
    //         stA.pop();
    //         auto [low, high] = stB.top();
    //         stB.pop();
    //         if(node == nullptr){
    //             continue;
    //         }
    //         if(low != nullptr && node->val <= low->val){
    //             return false;
    //         }
    //         if(high != nullptr && node->val >= high->val){
    //             return false;
    //         }
    //         stA.emplace(node->left);
    //         stB.emplace(make_pair(low, node));
    //         stA.emplace(node->right);
    //         stB.emplace(make_pair(node, high));
    //     }
    //     return true;
    // }
    
    // TreeNode* prev = nullptr;
    // bool inOrder(TreeNode* node){
    //     if(node == nullptr){
    //         return true;
    //     }
    //     if(!inOrder(node->left)){
    //         return false;
    //     }
    //     if(prev != nullptr && prev->val >= node->val){
    //         return false;
    //     }
    //     prev = node;
    //     return inOrder(node->right);
    // }
    // //Time O(N), Space O(N)
    // bool isValidBST(TreeNode* root){
    //     return inOrder(root);
    // }
    
    //Time O(N), Space O(N)
    bool isValidBST(TreeNode* root){
        TreeNode* prev = nullptr;
        stack<TreeNode*> st;
        while(!st.empty() || root != nullptr){
            while(root != nullptr){
                st.emplace(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if(prev != nullptr && prev->val >= root->val){
                return false;
            }
            prev = root;
            root = root->right;
        }
        return true;
    }
};

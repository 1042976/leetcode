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
    // TreeNode* getLinkedList(TreeNode* node){
    //     if(node == nullptr){
    //         return node;
    //     }
    //     TreeNode* leftEnd = getLinkedList(node->left);
    //     TreeNode* right = node->right;
    //     node->right = node->left;
    //     node->left = nullptr;
    //     if(leftEnd == nullptr){
    //         leftEnd = node;
    //     }
    //     TreeNode* rightEnd = getLinkedList(right);
    //     leftEnd->right = right;
    //     if(rightEnd == nullptr){
    //         rightEnd = leftEnd;
    //     }
    //     return rightEnd;
    // }
    // // Time O(N), Space O(H)
    // void flatten(TreeNode* root) {
    //     getLinkedList(root);
    // }

    // enum State{
    //     WHITE,
    //     GRAY
    // };
    // // Time O(N), Space O(H)
    // void flatten(TreeNode* root){
    //     if(root == nullptr){
    //         return;
    //     }
    //     stack<pair<TreeNode*, State> > st;
    //     st.emplace(make_pair(root, WHITE));
    //     TreeNode* tail = nullptr;
    //     while(!st.empty()){
    //         TreeNode* cur = st.top().first; 
    //         State state = st.top().second;
    //         if(cur->left == nullptr && cur->right == nullptr){
    //             st.pop();
    //             tail = cur;
    //             continue;
    //         }
    //         if(state == WHITE){
    //             if(cur->left != nullptr){
    //                 st.top().second = GRAY;
    //                 st.emplace(make_pair(cur->left, WHITE));
    //             }else{
    //                 st.pop();
    //                 if(cur->right != nullptr){
    //                     st.emplace(make_pair(cur->right, WHITE));
    //                 }
    //             }
    //         }else{
    //             st.pop();
    //             TreeNode* right = cur->right;
    //             if(tail != nullptr){    
    //                 cur->right = cur->left;
    //                 cur->left = nullptr;    
    //                 tail->right = right;
    //             }
    //             if(right != nullptr){
    //                 st.emplace(make_pair(right, WHITE));
    //             }
                
    //         } 
    //     }
    // }

    // Iterative. Time O(N), Space O(1)
    void flatten(TreeNode* root){
        TreeNode* cur = root;
        while(cur != nullptr){
            if(cur->left == nullptr){
                cur = cur->right;
                continue;
            }
            TreeNode* rightMost = cur->left;
            while(rightMost->right != nullptr){
                rightMost = rightMost->right;
            }
            rightMost->right = cur->right;
            cur->right = cur->left;
            cur->left = nullptr;
            cur = cur->right;
        }
    }
};

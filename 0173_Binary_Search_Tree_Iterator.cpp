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
class BSTIterator {
public:
    stack<TreeNode*> st;
    //Time O(H), Space O(H)
    BSTIterator(TreeNode* root) {
        while(root != nullptr){
            st.emplace(root);
            root = root->left;
        }
    }
    
    //Time O(1), Space O(1)
    int next() {
        TreeNode* root = st.top();
        st.pop();
        int val = root->val;
        root = root->right;
        while(root != nullptr){
            st.emplace(root);
            root = root->left;
        }
        return val;
    }
    
    //Time O(1), Space O(1)
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

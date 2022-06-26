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
    int preorderIdx = 0;
    unordered_map<int, int> hashMap;
    TreeNode* buildHelper(vector<int>& preorder, int l, int r){
        if(l > r){
            return nullptr;
        }
        int rootVal = preorder[preorderIdx++];
        int idx = hashMap[rootVal];
        TreeNode* leftRoot = buildHelper(preorder, l, idx-1);
        TreeNode* rightRoot = buildHelper(preorder, idx+1, r);
        TreeNode* root = new TreeNode(rootVal);
        root->left = leftRoot;
        root->right = rightRoot;
        return root;
    }
    //Time O(N), Space O(N)
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); ++i){
            hashMap[inorder[i]] = i;
        }
        return buildHelper(preorder, 0, inorder.size()-1); 
    }
};

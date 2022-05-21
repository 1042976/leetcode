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
    int diameter;
    int dfs(TreeNode* node){
        if(node == nullptr){
           return 0;
        }
        int depthOfLeft = dfs(node->left);
        int depthOfRight = dfs(node->right);
        diameter = max(diameter, depthOfLeft+depthOfRight);
        return 1+max(depthOfLeft, depthOfRight);
    }
    //Time O(n), Space O(n)
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = INT_MIN;
        dfs(root);
        return diameter;
    }
};

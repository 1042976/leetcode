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
    int maxSum = INT_MIN;   
    int getMaxPathSumStartFrom(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        int b = getMaxPathSumStartFrom(node->left);
        int c = getMaxPathSumStartFrom(node->right);
        if(c <= 0 && b <= 0){
            maxSum = max(node->val, maxSum);
            return node->val;
        }else if(c > 0 && b <= 0){
            maxSum = max(node->val+c, maxSum);
            return node->val+c;
        }else if(c <= 0 && b > 0){
            maxSum = max(node->val+b, maxSum);
            return node->val+b;
        }else{
            maxSum = max(node->val+b+c, maxSum);
            return node->val+max(b,c);
        }
    }
    int maxPathSum(TreeNode* root) {
        getMaxPathSumStartFrom(root);
        return maxSum;
    }
};

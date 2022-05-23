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
    //Time O(n), Space O(1)
    int closestValue(TreeNode* root, double target) {
        int closestVal = root->val;
        double dist = INT_MAX;
        TreeNode* cur = root;
        while(cur != nullptr){
            double d = cur->val-target;
            if(d == 0){
                return cur->val;
            }
            if(dist > abs(d)){
                closestVal = cur->val;
                dist = abs(d);
            }
            if(d > 0){
                cur = cur->left;
            }else{
                cur = cur->right;
            }
        }
        return closestVal;
    }
};

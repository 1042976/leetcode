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
    vector<int> res;
    void getNodes(TreeNode* root, int dist){
        if(root == nullptr){
            return;
        }
        if(dist == 0){
            res.emplace_back(root->val);
        }else{
            --dist;
            getNodes(root->left, dist);
            getNodes(root->right, dist);
        }
    }
    int getDist(TreeNode* root, TreeNode* target, int dist, int k){
        if(root == nullptr){
            return -1;
        }
        if(root == target){
            getNodes(target, k);
            return 0;
        }else{
            ++dist;
            int leftDist = getDist(root->left, target, dist, k);
            if(leftDist >= 0){
                if(leftDist+1 < k){
                    getNodes(root->right, k-leftDist-2);
                }else if(leftDist+1 == k){
                    res.emplace_back(root->val);
                }
                return leftDist+1;
            }
            int rightDist = getDist(root->right, target, dist, k);
            if(rightDist >= 0){
                if(rightDist+1 < k){
                    getNodes(root->left, k-rightDist-2);
                }else if(rightDist+1 == k){
                    res.emplace_back(root->val);
                }
                return rightDist+1;
            } 
            return -1;
        }
    }
    //Time O(N), Space O(H)
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        getDist(root, target, 0, k);
        return res;
    }
};

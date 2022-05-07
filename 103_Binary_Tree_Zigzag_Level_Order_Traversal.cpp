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
    //T-O(n), S-O(logn). bfs
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root == nullptr){
            return res;
        }
        deque<TreeNode*> D;
        bool getValFromLeftToRight = true;
        D.emplace_back(root);
        int sizeOfLevel = 1;
        while(!D.empty()){
            vector<int> arr;
            if(getValFromLeftToRight){
                while(sizeOfLevel > 0){
                    TreeNode* node = D.front();
                    D.pop_front();
                    arr.emplace_back(node->val);
                    if(node->left != nullptr){
                        D.emplace_back(node->left);
                    }
                    if(node->right != nullptr){
                        D.emplace_back(node->right);
                    }
                    --sizeOfLevel;
                }
                getValFromLeftToRight = false;
            }else{
                while(sizeOfLevel > 0){
                    TreeNode* node = D.back();
                    D.pop_back();
                    arr.emplace_back(node->val);
                    if(node->right != nullptr){
                        D.emplace_front(node->right);
                    }
                    if(node->left != nullptr){
                        D.emplace_front(node->left);
                    }
                    --sizeOfLevel;
                }
                getValFromLeftToRight = true;
            }
            sizeOfLevel = D.size();
            res.emplace_back(arr);
        }
        return res;
    }

};

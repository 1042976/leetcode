/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    //T-O(2^n) S-O(2^n), bfs
    string serialize(TreeNode* root) {
        //--->1-->2 3-->null null 4 5--->1#2#3# # #4#5# # #
        queue<TreeNode*> Q;
        string res = "";
        Q.push(root);
        while(!Q.empty()){
            TreeNode* cur = Q.front();
            Q.pop();
            if(cur != nullptr){
                res.append(to_string(cur->val));
                Q.push(cur->left);
                Q.push(cur->right);
            }
            res.push_back('#');
        }
        return res;
    }

    // Decodes your encoded data to tree.
    //T-O(K), S-O(K) 
    TreeNode* deserialize(string data) {
        //#1#2#3# # #4#5# # --->1-->2 3-->null null 4 5
        TreeNode* root = new TreeNode(0);
        int leftIdx = 0;
        int rightIdx = 0;
        if(data[0] == '#'){
            return nullptr;
        }else{
            rightIdx = data.find('#', 0);
            root->val = stoi(data.substr(0, rightIdx));
        }
        ++rightIdx;
        leftIdx = rightIdx;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            TreeNode* cur = Q.front();
            Q.pop();
            rightIdx = data.find('#', rightIdx);
            if(leftIdx != rightIdx){
                cur->left = new TreeNode(stoi(data.substr(leftIdx, rightIdx)));
                Q.push(cur->left);
            }
            ++rightIdx;
            leftIdx = rightIdx;
            rightIdx = data.find('#', rightIdx);
            if(leftIdx != rightIdx){
                cur->right = new TreeNode(stoi(data.substr(leftIdx, rightIdx)));
                Q.push(cur->right);
            }
            ++rightIdx;
            leftIdx = rightIdx;
        }
        return root;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

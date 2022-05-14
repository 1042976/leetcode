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
    //Time O(n), Space O(n)
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     unordered_map<int, TreeNode*> hashMap;
    //     hashMap[root->val] = nullptr;
    //     queue<TreeNode*> Q;
    //     Q.emplace(root);
    //     bool reachP = false, reachQ = false;
    //     while(!Q.empty()){
    //         TreeNode* cur = Q.front();
    //         Q.pop();
    //         if(cur->val == p->val){
    //             reachP = true;
    //         }else if(cur->val == q->val){
    //             reachQ = true;
    //         }
    //         if(reachP && reachQ){
    //             break;
    //         }
    //         if(cur->left != nullptr){
    //             hashMap[cur->left->val] = cur;
    //             Q.emplace(cur->left);
    //         }
    //         if(cur->right != nullptr){
    //             hashMap[cur->right->val] = cur;
    //             Q.emplace(cur->right);
    //         }
    //     }
    //     TreeNode *a = p, *b = q;
    //     while(a->val != b->val){
    //         a = hashMap[a->val] == nullptr? q : hashMap[a->val];
    //         b = hashMap[b->val] == nullptr? p : hashMap[b->val];
    //     }
    //     return a;
    // }
    // TreeNode* lca;
    // bool dfs(TreeNode* cur, TreeNode* p, TreeNode* q){
    //     if(cur == nullptr){
    //         return false;
    //     }
    //     bool mid = cur->val == p->val || cur->val == q->val;
    //     bool left = dfs(cur->left, p, q);
    //     if(mid && left){
    //         lca = cur;
    //         return true;
    //     }
    //     bool right = dfs(cur->right, p, q);
    //     if(mid && right || left&&right){
    //         lca = cur;
    //     }
    //     return mid||left||right;
    // }
    // //Time O(n), Space O(n)
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    //     dfs(root, p, q);
    //     return lca;
    // }
    
    //Time O(n), Space O(n)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        TreeNode* lca = nullptr;
        stack<pair<TreeNode*, int> > st;
        st.emplace(make_pair(root, 2));
        while(!st.empty()){
            auto [parent, state] = st.top();
            if(state > 0){
                if(state == 2){
                    if(parent->val == p->val || parent->val == q->val){
                        if(lca == nullptr){
                            lca = parent;
                        }else{
                            return lca;
                        }
                    }
                }
                --st.top().second;
                if(state == 2 && parent->left != nullptr){
                    st.emplace(make_pair(parent->left, 2));
                }else if(state == 1 && parent->right != nullptr){
                    st.emplace(make_pair(parent->right, 2));
                } 
            }else{
                if(lca == st.top().first){
                    st.pop();
                    lca = st.top().first;
                    continue;
                }
                st.pop();
            }
        }
        return nullptr;
    }
};

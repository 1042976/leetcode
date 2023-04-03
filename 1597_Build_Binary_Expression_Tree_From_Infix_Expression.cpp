/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Node* splitExp(string &s, int j, int left, int right){
    //     Node* root = new Node(s[j]);
    //     root->left = dfs(s, left, j-1);
    //     root->right = dfs(s, j+1, right);
    //     return root;
    // }
    // Node* dfs(string &s, int left, int right){
    //     if(left == right){
    //         return new Node(s[left]);
    //     }else{
    //         int i = right;
    //         int j = -1;
    //         int balance = 0;
    //         while(i >= left){
    //             if(s[i] == ')'){
    //                 ++balance;
    //             }else if(s[i] == '('){
    //                 --balance;
    //             }
    //             if(balance > 0){
    //                 --i;
    //                 continue;
    //             }
    //             if(s[i] == '-' || s[i] == '+'){
    //                 j = i;
    //                 break;
    //             }else if(j == -1 && (s[i] == '*' || s[i] == '/')){
    //                 j = i;
    //             }
    //             --i;
    //         }
    //         if(j == -1){
    //             return dfs(s, left+1, right-1);
    //         }
    //         return splitExp(s, j, left, right);
    //     }
    // }
    // //Time O(N^2), Space O(N)
    // Node* expTree(string s) {
    //     return dfs(s, 0, s.length()-1);
    // }
    
    //Time O(N), Space O(N)
    Node* expTree(string s){
        stack<Node*> st;
        st.emplace(new Node('('));
        s.push_back(')');
        Node* right = st.top();
        for(const auto &c : s){
            if(!isdigit(c)){
                if(c == '*' || c == '/'){
                    st.pop();
                    Node* root = st.top();
                    if(root->val == '*' || root->val == '/'){
                        st.pop();
                        Node* left = st.top();
                        st.pop();
                        root->left = left;
                        root->right = right;
                        st.emplace(root);
                        right = root;
                    }else{
                        st.emplace(right);
                    }
                }else if(c != '('){
                    st.pop();
                    while(st.top()->val != '('){
                        Node* root = st.top();
                        st.pop();
                        Node* left = st.top();
                        st.pop();
                        root->left = left;
                        root->right = right;
                        right = root;
                    }
                    if(c == ')'){
                        st.pop();
                    }
                    st.emplace(right);
                }
            }
            if(c != ')'){
                st.emplace(new Node(c));
                right = st.top();
            }
        }
        return st.top();
    }
};

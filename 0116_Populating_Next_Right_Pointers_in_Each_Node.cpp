/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    //T-O(n), S-O(logn)
    // Node* connect(Node* root) {
    //     queue<Node*> Q;
    //     if(root != nullptr){
    //         Q.emplace(root);
    //     }
    //     while(!Q.empty()){
    //         int sizeOfCurrentLevel = Q.size();
    //         while(sizeOfCurrentLevel--){
    //             Node* cur = Q.front();
    //             Q.pop();
    //             if(sizeOfCurrentLevel == 0){
    //                 cur->next = nullptr;
    //             }else{
    //                 cur->next = Q.front();
    //             }
    //             if(cur->left != nullptr){
    //                 Q.emplace(cur->left);
    //             }
    //             if(cur->right != nullptr){
    //                 Q.emplace(cur->right);
    //             }
    //         }
    //     }
    //     return root;
    // }
    
    //T-O(N), S-O(1)
    Node* connect(Node* root){
        if(root==nullptr){
            return nullptr;
        }
        Node* leftMost = root;
        while(leftMost->left != nullptr){
            Node* cur = leftMost;
            leftMost = leftMost->left;
            while(cur != nullptr){
                cur->left->next = cur->right;
                if(cur->next != nullptr){
                    cur->right->next = cur->next->left;
                    cur = cur->next;
                }else{
                    break;
                }
            }
        }
        return root;
    }
};

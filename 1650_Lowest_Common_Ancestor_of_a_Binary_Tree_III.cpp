/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    //Time O(n) Space O(n)
    // bool findNodeInSubTree(Node* root, Node* target){
    //     if(root == nullptr){
    //         return false;
    //     }
    //     queue<Node*> Q;
    //     Q.emplace(root);
    //     Node* cur = nullptr;
    //     while(!Q.empty()){
    //         cur = Q.front();
    //         Q.pop();
    //         if(cur->val == target -> val){
    //             return true;
    //         }
    //         if(cur->left != nullptr){
    //             Q.emplace(cur->left);
    //         }
    //         if(cur->right != nullptr){
    //             Q.emplace(cur->right);
    //         }
    //     }
    //     return false;
    // }
    // Node* lowestCommonAncestor(Node* p, Node * q) {
    //     bool b = findNodeInSubTree(p, q);
    //     if(b){
    //         return p;
    //     }
    //     Node* parent = p->parent;
    //     Node* child = p;
    //     while(parent != nullptr){
    //         if(parent->val == q->val){
    //             return parent;
    //         }
    //         if(child == parent->left){
    //             b = findNodeInSubTree(parent->right, q);
    //         }else{
    //             b = findNodeInSubTree(parent->left, q);
    //         }
    //         if(b){
    //             return parent;
    //         }else{
    //             child = parent;
    //             parent = parent->parent;
    //         }
    //     }
    //     return nullptr;
    // }
    
    //Time O(n) Space O(1)
    Node* lowestCommonAncestor(Node* p, Node * q){
        Node *a = p, *b = q;
        while(a != b){
            a = a->parent == nullptr? q : a->parent;
            b = b->parent == nullptr? p : b->parent;
        }
        return a;
    }
};

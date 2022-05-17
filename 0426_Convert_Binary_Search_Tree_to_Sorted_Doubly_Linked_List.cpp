/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node *head, *tail;
    void inorder(Node* root){
        if(root == nullptr){
            return;
        }
        inorder(root->left);
        if(tail == nullptr){
            head = root;
        }else{
            tail->right = root;
            root->left = tail;
        }
        tail = root;
        inorder(root->right);
    }
    //Time O(n), Space O(n)
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr){
            return nullptr;
        }
        inorder(root);
        tail->right = head;
        head->left = tail;
        return head;
    }
};

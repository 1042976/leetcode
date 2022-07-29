/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */
int calculate(int leftVal, int rightVal, char op){
    switch(op){
        case '*' : return  leftVal * rightVal; break;   
        case '/' : return leftVal / rightVal; break;
        case '+' : return leftVal + rightVal; break;
        case '-' : return leftVal - rightVal; break;
        default : return -1;
    };
}
class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
    string val;
    Node *left, *right;  
    Node(const string& _val): val(_val), left(nullptr), right(nullptr){}
};

class ExpNode: public Node{
public:
    ExpNode(const string& _val):Node(_val){}
    int evaluate() const{
        if(isdigit(val[0])){
            return stoi(val);
        }
        return calculate(this->left->evaluate(), this->right->evaluate(), val[0]);
    }
    ~ExpNode(){
        delete left;
        delete right;  
    }
};
/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
private:
    Node* root;
public:
    ~TreeBuilder(){
        delete root;
    }
    Node* buildTree(vector<string>& postfix) {
        stack<Node*> st;
        for(const auto &x : postfix){
            Node* node = new ExpNode(x);
            if(!isdigit(x[0])){
                Node* right = st.top();
                st.pop();
                Node* left = st.top();
                st.pop();
                node->left = left;
                node->right = right;
            }
            st.emplace(node);
        }
        root = st.top();
        return root;
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */

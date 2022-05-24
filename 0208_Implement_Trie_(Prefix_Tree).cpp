class Node{
public:
    bool isEnd;
    vector<Node*> arr;
    Node():isEnd(false), arr(26, nullptr){}
    ~Node(){
        for(int i = 0; i < arr.size(); ++i){
            delete arr[i];
        }
    }
    Node* getNode(char c){
        int idx = c-'a';
        return arr[idx];
    }
    
    Node* setNode(char c){
        int idx = c-'a';
        arr[idx] = new Node();
        return arr[idx];
    }
    
};
class Trie {
public:
    Node* root;
    //Time O(1), Space O(1)
    Trie(): root(new Node()){
        
    }
    ~Trie(){
        delete root;
    }
    
    //Time O(n), Space O(n)
    void insert(string word) {
        Node* cur = root;
        for(int i = 0; i < word.length(); ++i){
            if(cur->getNode(word[i]) == nullptr){
                while(i < word.length()){
                    cur = cur->setNode(word[i++]);
                }
                cur->isEnd = true;
                return;                
            }else{
                cur = cur->getNode(word[i]);
            }
        }
        cur->isEnd = true;
    }
    
    //Time O(n), Space O(1)
    bool search(string word) {
        Node* cur = root;
        for(int i = 0; i < word.length(); ++i){
            cur = cur->getNode(word[i]);
            if(cur == nullptr){
                return false;
            }
        }
        return cur->isEnd;
    }
    
    //Time O(n), Space O(1)
    bool startsWith(string prefix) {
        Node* cur = root;
        for(int i = 0; i < prefix.length(); ++i){
            cur = cur->getNode(prefix[i]);
            if(cur == nullptr){
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

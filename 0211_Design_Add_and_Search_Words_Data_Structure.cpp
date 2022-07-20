class Node{
public:
    Node* arr[26];
    bool isEnd = false;
};
class WordDictionary {
public:
    Node* root;
    //Time O(1), Space O(1)
    WordDictionary(): root(new Node()) {
        
    }
    
    //Time O(N), Space O(N)
    void addWord(string word) {
        Node* cur = root;
        for(const auto &letter : word){
            int idx= letter-'a';
            if(cur->arr[idx] == nullptr){
                cur->arr[idx] = new Node();
            }
            cur = cur->arr[idx];
        }
        cur->isEnd = true;
    }
    
    bool search(string &word, int start, Node* cur){
        for(int i = start; i < word.length(); ++i){
            if(word[i] == '.'){
                bool isMatched = false;
                for(int j = 0; j < 26; ++j){
                    if(cur->arr[j] != nullptr){
                        isMatched = search(word, i+1, cur->arr[j]);
                        if(isMatched){
                            return true;
                        }
                    }
                }
                return false;
            }else{
                int idx = word[i]-'a';
                if(cur->arr[idx] != nullptr){
                    cur = cur->arr[idx];
                }else{
                    return false;
                }
            }
        }
        return cur->isEnd;
    }
    //Time O(N), Space O(min(H,M)), N is the total number of node in trie. H is the height of the trie. M is the length of the given word.
    bool search(string word) {
        return search(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

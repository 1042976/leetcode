class Node{
public:
    bool isEnd;
    unordered_map<char, Node*> hashMap;
    Node():isEnd(false){}
    ~Node(){
        auto it = hashMap.begin();
        while(it != hashMap.end()){
            delete it->second;
            ++it;
        }
    }
    
    Node* getNode(char c){
        if(hashMap.find(c) != hashMap.end()){
            return hashMap[c];
        }else{
            return nullptr;
        }
    }
};
class Trie{
public:
    Node* root;
    Trie():root(new Node()){}
    ~Trie(){
        delete root;
    }
    void insert(const string &word){
        Node* cur = root;
        for(int i = 0; i < word.length(); ++i){
            if(cur->getNode(word[i]) == nullptr){
                cur->hashMap[word[i]] = new Node();
                cur = cur->hashMap[word[i]];
                for(int j = i+1; j < word.length(); ++j){
                    cur->hashMap[word[j]] = new Node();
                    cur = cur->hashMap[word[j]];
                }
                break;
            }else{
                cur = cur->hashMap[word[i]];
            }
        }
        cur->isEnd = true;
    }
};
class Solution {
public:
    vector<string> res;
    Trie trie;
    void dfs(string &s, int i, Node* cur, string sentence){
        cur = cur->getNode(s[i]);
        if(cur == nullptr){
            return;
        }
        sentence.push_back(s[i]);
        if(i == s.length()-1){
            if(cur->isEnd){
                res.emplace_back(sentence);
            }
            return;
        }
        if(cur->isEnd){
            dfs(s, i+1, trie.root, sentence+" ");
        }
        dfs(s, i+1, cur, sentence);
    }
    
    //Time O(M+(2^N)*N) Space O(M+N)
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        //create Trie
        for(const auto &word : wordDict){
            trie.insert(word);
        }
        
        //get sentences
        dfs(s, 0, trie.root, "");
        return res;
    }
};

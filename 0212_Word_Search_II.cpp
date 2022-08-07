// class Node{
// public:
//     vector<Node*> arr;
//     Node():arr(26,nullptr){}
//     ~Node(){
//         for(int i = 0; i < arr.size(); ++i){
//             delete arr[i];
//         }
//     }
//     void insertNode(char c){
//         if(arr[c-'a'] == nullptr){
//             arr[c-'a'] = new Node();
//         }
//     }
    
//     Node* getNode(char c){
//         return arr[c-'a'];
//     }
// };
// class Trie{
// public:
//     Node* root;
//     Trie():root(new Node()){}
//     ~Trie(){
//         delete root;
//     }
//     bool search(const string &word){
//         Node* cur = root;
//         for(int i = 0; i < word.length(); ++i){
//             cur = cur->getNode(word[i]);
//             if(cur == nullptr){
//                 return false;
//             }
//         }
//         return true;
//     }
// };
// class Solution {
// public:
//     Trie trie;
//     vector<string> res;
//     vector<vector<bool> > memo;
//     int offsets[4][2] = {{1,0},{-1,0},{0,1}, {0,-1}};
//     int m, n;
//     void backtrack(vector<vector<char> > &board, int i, int j, Node* parent, int wordLen){
//         if(wordLen == 0){
//             return;
//         }
        
//         memo[i][j] = true;
//         parent->insertNode(board[i][j]);
//         parent = parent->getNode(board[i][j]);
//         for(const auto &offset : offsets){
//             int newI = i + offset[0];
//             int newJ = j + offset[1];
//             if(newI >= 0 && newI < m & newJ >= 0 && newJ < n && memo[newI][newJ] == false){
//                 backtrack(board, newI, newJ, parent, wordLen-1);
//             }
//         }
//         memo[i][j] = false;
//     }
//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         int maxWordLen = INT_MIN;
//         m = board.size(), n = board[0].size();
//         unordered_set<char> initials;
//         unordered_map<char, int> availableLetters;
//         vector<string> validWords;
        
//         for(int i = 0; i < m; ++i){
//             for(int j = 0; j < n; ++j){
//                 ++availableLetters[board[i][j]];
//             }
//         }
//         for(const auto &word : words){
//             unordered_map<char, int> letters = availableLetters;
//             bool isValid = true;
//             for(int i = 0; i < word.length(); ++i){
//                 --letters[word[i]];
//                 if(letters[word[i]] < 0){
//                     isValid = false;
//                     break;                    
//                 }
//             }
//             if(isValid){
//                 validWords.emplace_back(word);
//                 maxWordLen = max((int)word.length(), maxWordLen);
//                 initials.insert(word[0]);
//             }
//         }        
//         maxWordLen = min(maxWordLen, m*n);
//         for(int i = 0; i < m; ++i){
//             for(int j = 0; j < n; ++j){
//                 if(initials.find(board[i][j]) != initials.end()){
//                     memo = vector<vector<bool> >(vector<vector<bool> >(m, vector<bool>(n, false)));
//                     backtrack(board, i, j, trie.root, maxWordLen);
//                 }
//             }
//         }
//         for(const auto &word : validWords){
//             if(trie.search(word)){
//                 res.emplace_back(word);
//             }
//         }   
            
//         return res;
//     }
    
// };



class Node{
public:
    unordered_map<char, Node*> hashMap;
    bool isEnd;
    Node():isEnd(false){}
    ~Node(){
        for(auto &[letter, child] : hashMap){
            delete child;
        }
    }
    void insertNode(char c){
        if(hashMap.find(c) == hashMap.end()){
            hashMap[c] = new Node();
        }
    }
    
    Node* getNode(char c){
        return hashMap[c];
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
            if(cur->hashMap.count(word[i]) == 0){
                cur->hashMap[word[i]] = new Node();
            }
            cur = cur->getNode(word[i]);
        }
        cur->isEnd = true;
    }
};

class Solution {
public:
    Trie trie;
    vector<string> res;
    vector<vector<bool> > memo;
    int offsets[4][2] = {{1,0},{-1,0},{0,1}, {0,-1}};
    int m, n;
    void backtrack(vector<vector<char> > &board, int i, int j, Node* parent, string str){
        char letter = board[i][j];
        if(parent->hashMap.count(letter) == 0){
            return;
        }
        Node* child = parent->hashMap[letter]; 
        str.push_back(letter);
        memo[i][j] = true;
        for(const auto &offset : offsets){
            int newI = i + offset[0];
            int newJ = j + offset[1];
            if(newI >= 0 && newI < m & newJ >= 0 && newJ < n && memo[newI][newJ] == false){
                backtrack(board, newI, newJ, child, str);
            }
        }
        if(child->isEnd){
            res.emplace_back(str);
            child->isEnd = false;
        }
        if(child->hashMap.empty()){
            delete child;
            parent->hashMap.erase(letter);
        }
        memo[i][j] = false;
    }
    //Time O(M*4*3^(L-1)), Space O(M+N)
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(const auto &word : words){
            trie.insert(word);
        }
        m = board.size();
        n = board[0].size();
        memo = vector<vector<bool> >(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                backtrack(board, i, j, trie.root, "");
            }
        }
        return res;
    }
    
};

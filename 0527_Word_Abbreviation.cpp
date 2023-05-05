class Solution {
public:
    class TrieNode{
    public:
        TrieNode* arr[26];
        int count;
        TrieNode():count(0){
            memset(arr, 0, sizeof(arr));
        }
        ~TrieNode(){
            for(size_t i = 0; i < 26; ++i){
                delete arr[i];
            }
        }

    };
    class Trie{
    public:
        TrieNode* root;
        Trie(): root(new TrieNode()){}
        ~Trie(){
            delete root;
        }
        void add(const string& word){
            TrieNode* cur = root;
            for(size_t i = 1; i < word.length()-1; ++i){
                size_t charIdx = word[i]-'a';
                if(cur->arr[charIdx] == nullptr){
                    cur->arr[charIdx] = new TrieNode();
                }
                ++(cur->count);
                cur = cur->arr[charIdx];
            }
        }

        int findOne(const string& word){
            TrieNode* cur = root;
            size_t depth = 1;
            for(size_t i = 1; i < word.length()-1; ++i){
                size_t charIdx = word[i]-'a';
                if(cur->count == 1){
                    break;
                }
                cur = cur->arr[charIdx];
                ++depth;
            }
            return depth;
        }
    };
    // Time O(N), Space O(N), N is the the total number of characters in the input.
    vector<string> wordsAbbreviation(vector<string>& words) {
        vector<string> res(words.size());
        unordered_map<string, vector<size_t> > hashMap;
        for(size_t i = 0; i < words.size(); ++i){
            if(words[i].length() <= 2){
                res[i] = words[i];
            }else{
                hashMap[to_string(words[i].length())+words[i][0]+words[i].back()].emplace_back(i);
            }
        }
        for(const auto& group : hashMap){
            Trie trie;
            for(const auto& idx : group.second){
                trie.add(words[idx]);
            }
            for(const auto& idx : group.second){
                int prefixLen = trie.findOne(words[idx]);
                if(prefixLen >= words[idx].length()-2){
                    res[idx] = words[idx];
                }else{
                    res[idx] = words[idx].substr(0, prefixLen)+to_string(words[idx].length()-prefixLen-1)+words[idx].back();
                }
            }
        }
        return res;
    }
};

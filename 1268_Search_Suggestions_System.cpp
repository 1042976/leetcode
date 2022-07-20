class Solution {
public:
    // int lower_binary_search(vector<string>& products, int left, int right, int i, char target){
    //     while(left < right){
    //         int mid = left + ((right-left)>>1);
    //         if(products[mid][i] < target){
    //             left = mid+1;
    //         }else{
    //             right = mid;
    //         }
    //     }
    //     return left;
    // }
    // int upper_binary_search(vector<string>& products, int left, int right, int i, char target){
    //     while(left < right){
    //         int mid = left + ((right-left)>>1);
    //         if(products[mid][i] <= target){
    //             left = mid+1;
    //         }else{
    //             right = mid;
    //         }
    //     }
    //     return left;
    // }
    // //Time O((M+N)logM), Space O(logM)
    // vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    //     vector<vector<string> > res(searchWord.length());
    //     int curIdx = 0;
    //     sort(products.begin(), products.end());
    //     int left = 0, right = products.size();
    //     for(int i = 0; i < searchWord.length(); ++i){
    //         left = lower_binary_search(products, left, right, i, searchWord[i]);
    //         right = upper_binary_search(products, left, right, i, searchWord[i]);
    //         if(left == products.size()){
    //             break;
    //         }
    //         for(int i = left; i < min(right, left+3); ++i){
    //             res[curIdx].emplace_back(products[i]);
    //         }
    //         ++curIdx;
    //     }
    //     return res;
    // }
    class Node{
    public:
        Node* arr[26];
        bool isEnd;
    };
    class Trie{
    private:
        Node *root, *start;
    public:
        Trie():root(new Node()), start(root){}
        void insert(const string &word){
            Node* cur = root;
            for(const auto &c : word){
                int idx = c-'a';
                if(cur->arr[idx] == nullptr){
                    cur->arr[idx] = new Node();
                }
                cur = cur->arr[idx];
            }
            cur->isEnd = true;
        }
        void getThreeWords(Node* node, string& word, vector<string>& words){
            if(words.size() == 3){
                return;
            }
            if(node->isEnd){
                words.emplace_back(word);
            }
            bool hasChild = false;
            for(int i = 0; i < 26; ++i){
                if(node->arr[i] != nullptr){
                    hasChild = true;
                    word.push_back('a'+i);
                    getThreeWords(node->arr[i], word, words);
                    word.pop_back();
                }
            }
        }
        vector<string> getWordsWithPrefix(string& prefix){
            Node* cur = start;
            int idx = prefix.back()-'a';
            if(cur->arr[idx] == nullptr){
                return vector<string>();
            }else{
                cur = cur->arr[idx];
            }
            start = cur;
            vector<string> words;
            getThreeWords(cur, prefix, words);
            return words;
        }
    };
    
    //Time O(M+L), Space O(N), M is the total number of character in products. L is the length of searchWord. N is the total number of nodes in trie.
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord){
        Trie trie;
        for(const auto &x : products){
            trie.insert(x);
        }
        string prefix = "";
        vector<vector<string> > res(searchWord.size());
        int curIdx = 0;
        for(const auto &x : searchWord){
            prefix.push_back(x);
            res[curIdx] = trie.getWordsWithPrefix(prefix);
            if(res[curIdx++].empty()){
                break;
            }
        }
        return res;
    }
};

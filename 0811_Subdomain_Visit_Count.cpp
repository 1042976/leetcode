class Node{
public:
    int count;
    unordered_map<string, Node*> hashMap;
    Node():count(0){}
    ~Node(){
        auto it = hashMap.begin();
        while(it != hashMap.end()){
            delete it->second;
            ++it;
        }
    }
};
class Trie{
private:
    int getCount(const string& cpdomain){
        int count = 0;
        for(int i = 0; cpdomain[i] != ' '; ++i){
            count = count*10+cpdomain[i]-'0';
        }
        return count;
    }
public:
    Node* root;
    Trie():root(new Node()){}
    ~Trie(){
        delete root;
    }
    void insert(const string& cpdomain){
        int count = getCount(cpdomain);
        int len = cpdomain.length();
        size_t i = len-1;
        size_t j = cpdomain.rfind('.', i);
        Node* cur = root;
        while(j != string::npos){
            string word = cpdomain.substr(j+1, i-j);
            if(cur->hashMap[word] == nullptr){
                cur->hashMap[word] = new Node();
            }
            cur = cur->hashMap[word];
            cur->count += count;
            i = j-1;
            j = cpdomain.rfind('.', i);
            if(j == string::npos){
                j = cpdomain.rfind(' ', i);
            }
        }
    }
};

class Solution {
public:
    void dfs(Node* node, vector<string> &res, string subdomain){
        for(const auto &[word, next] : node->hashMap){
            string countStr = to_string(next->count);
            if(subdomain.empty()){
                res.emplace_back(countStr + " " + word);
            }else{
                res.emplace_back(countStr + " " + word + "." + subdomain);
            }
            dfs(next, res, res.back().substr(countStr.length()+1));
        }
    }
    //Time O(N), Space O(N)
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res;
        Trie trie;
        for(const auto &str: cpdomains){
            trie.insert(str);
        }
        dfs(trie.root, res, "");
        return res;
    }
};

// class Solution {
// public:
//     int getCount(const string& cpdomain){
//         int count = 0;
//         for(int i = 0; cpdomain[i] != ' '; ++i){
//             count = count*10+cpdomain[i]-'0';
//         }
//         return count;
//     }
//     //Time O(N), Space O(N)
//     vector<string> subdomainVisits(vector<string>& cpdomains) {
//         vector<string> res;
//         unordered_map<string, int> hashMap;
//         for(const auto &cpdomain: cpdomains){
//             int count = getCount(cpdomain);
//             vector<string> arr;
//             size_t i = cpdomain.length()-1;
//             size_t j = cpdomain.rfind('.', i);
//             string subdomain = "";
//             while(j != string::npos){
//                 string subdomain = cpdomain.substr(j+1, i-j);
//                 hashMap[subdomain] += count;
//                 j = cpdomain.find_last_of(". ", j-1);
//             }
//         }
//         for(const auto &[subdomain, count] : hashMap){
//             res.emplace_back(to_string(count) + " " + subdomain);
//         }
//         return res;
//     }
// };

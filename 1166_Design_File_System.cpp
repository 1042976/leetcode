class FileSystem {
public:
    FileSystem() {
        
    }
    class TrieNode{
    public:
        int val;
        unordered_map<string, TrieNode*> childMap;
        TrieNode(): val(-1){}
        TrieNode(int _val): val(_val){}
    };
    TrieNode* root = new TrieNode();
    // Time O(T), Space O(1). T is the number of nodes in one of the Trie paths.
    bool createPath(string path, int value) {
        size_t slashIdx = 0;
        TrieNode* cur = root;
        while(slashIdx != string::npos){
            size_t start = slashIdx+1;
            slashIdx = path.find('/', start);
            string fileName = path.substr(start, slashIdx-start);
            auto it = cur->childMap.find(fileName);
            if(it == cur->childMap.end()){
                if(slashIdx != string::npos || fileName.length() == 0){
                    return false;
                }else{
                    TrieNode* next = new TrieNode(value);
                    cur->childMap[fileName] = next;
                    return true;
                }
            }else{
                cur = it->second;
            }

        }
        return false;
    }
    
    // Time O(T), Space O(1).
    int get(string path) {
        size_t slashIdx = 0;
        TrieNode* cur = root;
        while(slashIdx != string::npos){
            size_t start = slashIdx+1;
            slashIdx = path.find('/', start);
            string fileName = path.substr(start, slashIdx-start);
            auto it = cur->childMap.find(fileName);
            if(it == cur->childMap.end()){
                return -1;
            }else{
                cur = it->second;
            }
        }
        return cur->val;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */

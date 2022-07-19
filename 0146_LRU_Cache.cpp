class LRUCache {
public:
    int capacity;
    unordered_map<int, list<pair<int, int> >::iterator> hashMap;
    list<pair<int, int> > values; 
    //Time O(1), Space O(1)
    LRUCache(int capacity): capacity (capacity) {
        
    }
    
    //Time O(1), Space O(1)
    int get(int key) {
        if(hashMap.count(key)){
            auto it = hashMap[key]; 
            values.emplace_back(*it);
            values.erase(it);
            hashMap[key] = (--values.end());
            return hashMap[key]->second;
        }else{
            return -1;
        }
    }
    
    void updateNode(int key, int value){
        auto it = hashMap[key];
        values.erase(it);
        values.emplace_back(make_pair(key, value));
        hashMap[key] = (--values.end());
    }
    void deleteNode(list<pair<int, int> >::iterator it){
        hashMap.erase(it->first);
        values.erase(it);
    }
    void addNode(int key, int value){
        values.emplace_back(make_pair(key, value));
        hashMap[key] = (--values.end());
    }
    //Time O(1), Space O(1)
    void put(int key, int value) {
        if(hashMap.count(key)){
            updateNode(key, value);
        }else{
            if(hashMap.size() == capacity){
                deleteNode(values.begin());
            }
            addNode(key, value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class LRUCache {
public:
    //T-O(1), S-O(capacity)
    unordered_map<int, pair<int, list<int>::iterator> > hashMap;
    list<int> lruList;
    int capacity;
    LRUCache(int capacity):capacity(capacity) {
        
    }
    
    int get(int key) {
        if(hashMap.count(key) == 0){
            return -1;
        }
        setKeyAsLastOne(hashMap[key].second);
        return hashMap[key].first;
    }
    
    void put(int key, int value) {
        if(hashMap.count(key) == 1){
            hashMap[key].first = value;
            setKeyAsLastOne(hashMap[key].second);
        }else{
            if(hashMap.size() == capacity){
                deletelruKey();
            }
            addNewKey(key, value);
        }
    }
    void deletelruKey(){
        hashMap.erase(*lruList.begin());
        lruList.erase(lruList.begin());
    }
    
    void addNewKey(int key, int value){
        hashMap[key].first = value;
        lruList.emplace_back(key);
        hashMap[key].second = --lruList.end();
    }
    
    void setKeyAsLastOne(list<int>::iterator it){
        int key = *it;
        lruList.erase(it);
        lruList.emplace_back(key);
        hashMap[key].second = --lruList.end();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

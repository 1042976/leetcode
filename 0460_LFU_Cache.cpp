class LFUCache {
public:
    typedef list<pair<int, int> > LRULIST; //key, value
    typedef list<pair<int, LRULIST> > LFULIST; //count, lru_list
    int capacity;
    unordered_map<int, pair<LRULIST::iterator, LFULIST::iterator> > hashMap; //key, iterators
    LFULIST LFU_list; //count_keys_pair_list, first pair of the list contains the LFU keys.
    
    LFUCache(int capacity): capacity(capacity) {}
    
    //T-O(1), S-O(1)
    int get(int key) {
        if(hashMap.count(key) == 0){
            return -1;
        }else{
            updateLFU(key);
            return (hashMap[key].first)->second;
        }
    }
    
    //T-O(1), S-O(1)
    void put(int key, int value) {
        if(capacity == 0){
            return;
        }
        if(hashMap.count(key) == 1){
            updateLFU(key);
            //update the value of the key
            (hashMap[key].first)->second = value;
        }else{
            if(hashMap.size() == capacity){
                pop();
            }
            add(key, value);
        }
    }
    //among the LFU keys, pop out the key that is least recently used.
    void pop(){
        auto LFU_list_it = LFU_list.begin();
        hashMap.erase(LFU_list_it->second.begin()->first);
        LFU_list_it->second.erase(LFU_list_it->second.begin());
        if(LFU_list_it->second.empty()){
            LFU_list.erase(LFU_list_it);
        }
    }
  
    void updateLFU(int key){
        //update LFU_list
        auto its = hashMap[key];
        auto LRU_list_it = its.first;
        auto LFU_list_it = its.second;
        int oldCount = LFU_list_it->first;
        int newCount = oldCount+1;
        auto LRUNode = *LRU_list_it;
        LFU_list_it->second.erase(LRU_list_it);
        auto last_LFU_list_it = LFU_list_it;
        ++LFU_list_it;
        if(LFU_list_it == LFU_list.end() || LFU_list_it->first > newCount){
            auto newLRUList = LRULIST{LRUNode};
            auto newLFUNode = make_pair(newCount, newLRUList);
            LFU_list.insert(LFU_list_it, newLFUNode);
            --LFU_list_it;
        }else{
            LFU_list_it->second.emplace_back(LRUNode);
        }
        LRU_list_it = (--LFU_list_it->second.end());
        if(last_LFU_list_it->second.empty()){
            LFU_list.erase(last_LFU_list_it);
        }
        hashMap[key] = make_pair(LRU_list_it, LFU_list_it);
    }
    
    
    void add(int key, int value){
        auto newLRUNode = make_pair(key, value);
        auto LFU_list_it = LFU_list.begin();
        if(LFU_list_it == LFU_list.end() || LFU_list_it->first > 1){
            auto newLRUList = LRULIST{newLRUNode};
            LFU_list.emplace_front(make_pair(1, newLRUList));
            LFU_list_it = LFU_list.begin();
        }else{
            LFU_list_it->second.emplace_back(newLRUNode);
        }
        auto LRU_list_it = (--LFU_list_it->second.end());
        hashMap[key] = make_pair(LRU_list_it, LFU_list_it);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

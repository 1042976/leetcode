class RandomizedSet {
public:
    unordered_map<int, int> hashMap;
    vector<int> arr;
    RandomizedSet() {
        srand(time(0));
    }
    
    //T-O(1)
    bool insert(int val) {
        if(hashMap.count(val)){
            return false;
        }
        hashMap[val] = arr.size();
        arr.emplace_back(val);
        return true;
    }
    
    //T-O(1)
    bool remove(int val) {
        if(hashMap.count(val) == 0){
            return false;
        }
        int lastVal = arr.back();
        swap(arr[hashMap[val]], arr.back());
        hashMap[lastVal] = hashMap[val];
        arr.pop_back();
        hashMap.erase(val);
        return true;
    }
    
    //T-O(1)
    int getRandom() {
        int idx = rand()%arr.size();
        return arr[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

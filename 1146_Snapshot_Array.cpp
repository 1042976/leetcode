// class SnapshotArray {
// public:
//     int len;
//     vector<unordered_map<int, int> > arr;
//     unordered_map<int, int> hashMap;
//     SnapshotArray(int length):len(length) {
//     }
    
//     //Time O(1), Space O(1)
//     void set(int index, int val) {
//         hashMap[index] = val;
//     }
    
//     //Time O(M), Space O(1), M is the number of indices where vals are updated
//     int snap() {
//         arr.emplace_back(hashMap);
//         return arr.size()-1;
//     }
    
//     //Time O(1), Space O(1)
//     int get(int index, int snap_id) {
//         return arr[snap_id].count(index)? arr[snap_id][index] : 0;
//     }
// };


class SnapshotArray {
public:
    int numOfSnaps;
    unordered_map<int, vector<pair<int, int> > > hashMap;
    //Time O(N), Space O(N), N is the length.
    SnapshotArray(int length):numOfSnaps(0){
        for(int i = 0; i < length; ++i){
            hashMap[i].emplace_back(make_pair(0,0));
        }
    }
    
    //Time O(1), Space O(1)
    void set(int index, int val) {
        if(hashMap[index].back().first < numOfSnaps){
            hashMap[index].emplace_back(make_pair(numOfSnaps, val));
        }else{
            hashMap[index].back().second = val;
        }
    }
    
    //Time O(1), Space O(1)
    int snap() {
        return numOfSnaps++;
    }
    
    //Time O(M), Space O(1). M is the number of snaps occur
    int get(int index, int snap_id) {
        int targetIdx = upper_bound(hashMap[index].begin(), hashMap[index].end(), make_pair(snap_id, 0), [](const pair<int, int>& a, pair<int, int>& b){
           return a.first < b.first; 
        }) - hashMap[index].begin() - 1;
        return hashMap[index][targetIdx].second;
    }
};
/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

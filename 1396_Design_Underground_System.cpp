class UndergroundSystem {
public:
    //Space O(P+S^2)
    unordered_map<int, pair<string, int> > hashMapA;
    unordered_map<string, unordered_map<string, vector<int> > > hashMapB;
    UndergroundSystem() {
        
    }
    //Time O(1)
    void checkIn(int id, string stationName, int t) {
        hashMapA[id] = make_pair(stationName, t);
    }
    
    //Time O(1)
    void checkOut(int id, string stationName, int t) {
        int diffT = t-hashMapA[id].second;
        vector<int> &arr = hashMapB[hashMapA[id].first][stationName];
        if(arr.empty()){
            arr = vector<int>(2);
            arr[0] = diffT;
            arr[1] = 1;
        }else{
            arr[0] += diffT;
            ++arr[1];
        }
        hashMapA.erase(id);
    }
    
    //Time O(1)
    double getAverageTime(string startStation, string endStation) {
        vector<int> &arr = hashMapB[startStation][endStation];
        return arr[0]*1.0/arr[1];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

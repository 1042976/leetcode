class Logger {
public:
    // queue<pair<string, int> > Q;
    // unordered_set<string> hashSet;
    // Logger() {
        
    // }
    // // Time O(N), Space O(N)
    // bool shouldPrintMessage(int timestamp, string message) {
    //     while(!Q.empty() && Q.front().second <= timestamp-10){
    //         hashSet.erase(Q.front().first);
    //         Q.pop();
    //     }
    //     if(hashSet.count(message) == 0){
    //         hashSet.insert(message);
    //         Q.emplace(make_pair(message, timestamp));
    //         return true;
    //     }
    //     return false;
    // }

    unordered_map<string, int> hashMap;
    Logger() {
        
    }
    // Time O(1), Space O(M). M is the number of unique messages.
    bool shouldPrintMessage(int timestamp, string message) {
        if(hashMap.count(message) == 0 || timestamp-hashMap[message] >= 10){
            hashMap[message] = timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

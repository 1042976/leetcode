class Solution {
public:
    vector<int> parse(const string &log){
        size_t idx1 = log.find(':');
        size_t idx2 = log.find(':', idx1+1);
        vector<int> res(3);
        res[0] = stoi(log.substr(0, idx1));
        res[1] = (log[idx1+1] == 's'? 0 : 1);
        res[2] = stoi(log.substr(idx2+1));
        return res;
    }
    //Time O(m) Space(k)
    // vector<int> exclusiveTime(int n, vector<string>& logs) {
    //     vector<int> res(n, 0);
    //     int timeInterval = 0;
    //     stack<vector<int> > st;
    //     for(const auto &log : logs){
    //         vector<int> info = parse(log);
    //         if(info[1] == 0){
    //             st.emplace(info);
    //         }else{
    //             vector<int> top = st.top();                    
    //             while(st.top()[0] == -1){
    //                 top = st.top();
    //                 st.pop();
    //                 timeInterval += (top[2]-st.top()[2]+1);
    //                 st.pop();
    //             }
    //             res[info[0]] += info[2]-st.top()[2]+1-timeInterval;
    //             if(st.size()==1){
    //                 st.pop();
    //             }else{
    //                 st.top()[0] = -1;
    //                 info[0] = -1;
    //                 st.emplace(info);
    //             }
    //             timeInterval = 0;
    //         }
    //     }
    //     return res;
    // }
    
    //Time O(m) Space(k)
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<vector<int> > st;
        for(const auto &log : logs){
            vector<int> info = parse(log);
            if(info[1] == 0){
                st.emplace(info);
            }else{     
                int timeInterval = info[2]-st.top()[2]+1;
                res[info[0]] += timeInterval;
                st.pop();
                if(!st.empty()){
                    res[st.top()[0]] -= timeInterval;
                }
            }
        }
        return res;
    }
};

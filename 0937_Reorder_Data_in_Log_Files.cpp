class Solution {
public:
    // int compareStr(const string &a, int start1, int end1, const string &b, int start2, int end2){
    //     while(start1 < end1 && start2 < end2){
    //         if(a[start1] < b[start2]){
    //             return 1;
    //         }else if(a[start1] > b[start2]){
    //             return 0;
    //         }else{
    //             ++start1;
    //             ++start2;
    //         }
    //     }
    //     if(start1 < end1){
    //         return 0;
    //     }
    //     if(start2 < end2){
    //         return 1;
    //     }
    //     return -1;
    // }
    // int findSpace(const string& log, int i){
    //     while(i < log.length() && log[i] != ' '){
    //         ++i;
    //     }
    //     return i;
    // }
    // bool isDigitLog(const string& log){
    //     int i = log.find(' ', 0);
    //     return isdigit(log[i+1]);
    // }
    // int sortDigitLogs(vector<string>& logs){
    //     int i = logs.size()-1, j = i;
    //     while(i >= 0){
    //         while(i >= 0 && !isDigitLog(logs[i])){
    //             --i;
    //         }
    //         while(j > i && isDigitLog(logs[j])){
    //             --j;
    //         }
    //         if(i >= 0){
    //             swap(logs[i--], logs[j--]);
    //         }
    //     }  
    //     return j;
    // }
    // //Time O((MlogM+N)*L), Space O(logM). M is number of letter logs, N is the number of digit logs, L is the average length of each log.
    // vector<string> reorderLogFiles(vector<string>& logs) {
    //     int last = sortDigitLogs(logs);
    //     auto compare = [this](const string &a, const string &b)->bool{
    //         int start1 = findSpace(a, 0)+1, start2 = findSpace(b, 0)+1;
    //         int end1 = 0, end2 = 0;
    //         int idIdx1 = start1, idIdx2 = start2;
    //         do{
    //             end1 = findSpace(a, start1), 
    //             end2 = findSpace(b, start2);
    //             int state = compareStr(a, start1, end1, b, start2, end2);
    //             if(state != -1){
    //                 return state == 1;
    //             }
    //             start1 = end1+1;
    //             start2 = end2+1;
    //         }while(end1 < a.length() && end2 < b.length());
    //         if(end1 < a.length()){
    //             return false;  
    //         }
    //         if(end2 < b.length()){
    //             return true;
    //         }
    //         start1 = 0;
    //         start2 = 0;
    //         int state = compareStr(a, start1, idIdx1, b, start2, idIdx2);
    //         return state != 0;
    //     }; 
    //     sort(logs.begin(), logs.begin()+last+1, compare);
    //     return logs;
    //}

    //Time O(LNlogN), Space O(logN), L is the maximum length of log, N is the size of logs
    vector<string> reorderLogFiles(vector<string>& logs) {
        //int last = sortDigitLogs(logs);
        auto compare = [this](const string &a, const string &b)->bool{
            int i = a.find(' ', 0)+1, j = b.find(' ', 0)+1;
            if(isdigit(a[i])){
                return false;
            }else if(isdigit(b[j])){
                return true;
            }else{
                int state = a.compare(i, a.length()-i, b, j, b.length()-j);
                if(state < 0){
                    return true;
                }else if(state > 0){
                    return false;
                }else{
                    return a.compare(0, i, b, 0, j) < 0;
                }
            }
        }; 
        stable_sort(logs.begin(), logs.end(), compare);
        return logs;
    }
};

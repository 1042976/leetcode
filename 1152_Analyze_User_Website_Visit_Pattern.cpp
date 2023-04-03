class Solution {
public:
    void swapArrays(vector<string>& username, vector<int>& timestamp, vector<string>& website, int i, int j){
        swap(username[i], username[j]);
        swap(timestamp[i], timestamp[j]);
        swap(website[i], website[j]);       
    }
    int partition(vector<string>& username, vector<int>& timestamp, vector<string>& website, int left,int right){
        int pivotPos = left + rand()%(right-left+1);
        swapArrays(username, timestamp, website, pivotPos, right);
        int j = right-1, i = left;
        while(i <= j){
            if(timestamp[i] > timestamp[right]){
                swapArrays(username, timestamp, website, i, j--);
            }else{
                ++i;
            }
        }
        swapArrays(username, timestamp, website, i, right);
        return i;
    }
    void quickSort(vector<string>& username, vector<int>& timestamp, vector<string>& website, int left, int right){
        if(left >= right){
            return;
        }
        int pivotPos = partition(username, timestamp, website, left, right);
        quickSort(username, timestamp, website, left, pivotPos);
        quickSort(username, timestamp, website, pivotPos+1, right);
    }
    vector<string> flatten(const string &tuple){
        vector<string> res;
        size_t first = tuple.find(',', 0);
        res.emplace_back(tuple.substr(0, first));
        size_t second = tuple.find(',', first+1);
        res.emplace_back(tuple.substr(first+1, second-first-1));
        res.emplace_back(tuple.substr(second+1, tuple.length()-second-1));
        return res;
    }
    bool greaterThan(vector<string>& A, vector<string>& B){
        for(int i = 0; i < 3; ++i){
            if(A[i] > B[i]){
                return true;
            }else if(A[i] < B[i]){
                return false;
            }
        }
        return false;
    }
    //Time O(N^3), Space O(N^3)
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n = timestamp.size();
        unordered_map<string, vector<string> > userToWebsites; 
        unordered_map<string, unordered_set<string> > tupleToUsers;
        srand(time(NULL));
        quickSort(username, timestamp, website, 0, n-1);
        for(int i = 0; i < n; ++i){
            userToWebsites[username[i]].emplace_back(website[i]);
        }
        for(const auto &[name, webs] : userToWebsites){
            for(int i = 0; i < webs.size(); ++i){
                for(int j = i+1; j < webs.size(); ++j){
                    for(int k = j+1; k < webs.size(); ++k){
                        string tuple = webs[i]+','+webs[j]+','+webs[k];
                        tupleToUsers[tuple].insert(name);
                    }
                }
            }
        }
        vector<string> bestTuple;
        int maxScore = 0;
        for(const auto &[tuple, users] : tupleToUsers){
            if(users.size() > maxScore){
                bestTuple = flatten(tuple);
                maxScore = users.size();
            }else if(users.size() == maxScore){
                vector<string> curTuple = flatten(tuple);
                if(greaterThan(bestTuple, curTuple)){
                    bestTuple = curTuple;
                }
            }
        }
        return bestTuple;
    }
};

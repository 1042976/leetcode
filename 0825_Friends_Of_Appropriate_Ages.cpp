class Solution {
public:
    //Time O(N), Space O(1)
    // int numFriendRequests(vector<int>& ages) {
    //     int total = 0, numInQueue = 0;
    //     map<int, int> uniqueAges;
    //     queue<pair<int, int> > Q;
    //     for(const auto &x : ages){
    //         ++uniqueAges[x];
    //     }
    //     for(const auto &[age, count] : uniqueAges){
    //         if(age > 14){
    //           total += (count-1)*count;  
    //         }
    //         int val = age*0.5+7;
    //         while(!Q.empty() && val >= Q.front().first){
    //             numInQueue -= Q.front().second;
    //             Q.pop();
    //         }
    //         total += numInQueue*count;
    //         Q.emplace(make_pair(age, count));
    //         numInQueue += count;
    //     }
    //     return total;
    // }
    
    //Time O(N), Space O(1)
    int numFriendRequests(vector<int>& ages){
        int total = 0;
        map<int, int> uniqueAges;
        for(const auto &x : ages){
            ++uniqueAges[x];
        }
        map<int, int>::iterator curIt = uniqueAges.begin(), lastIt = curIt;
        int numOfAges = 0;
        while(curIt != uniqueAges.end()){
            int count = curIt->second;
            int age = curIt->first;
            if(age > 14){
                total += count * (count - 1);
            }
            int val = age*0.5 + 7;
            while(lastIt != curIt && lastIt->first <= val){
                numOfAges -= lastIt->second;
                ++lastIt;
            }
            total += numOfAges*count;
            numOfAges += count;
            ++curIt;
        }
        return total;
    }
};

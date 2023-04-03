class Solution {
public:
    //bfs
    
    // int m, n;
    // string target = "123450";
    // string error = "123540";
    // vector<vector<int> > offsets{{-1,0}, {1,0}, {0,-1}, {0,1}};
    // string toString(vector<vector<int>>& board){
    //     string str = "";
    //     for(int i = 0; i < m; ++i){
    //         for(int j = 0; j < n; ++j){
    //             str.push_back(board[i][j]+'0');
    //         }
    //     }
    //     return str;
    // }
    // tuple<string, int, int> move(tuple<string, int, int>& cur, const vector<int>& offset){
    //     string str;
    //     int depth, zeroPos;
    //     tie(str, depth, zeroPos) = cur;
    //     int row = zeroPos/n, col = zeroPos%n;
    //     int newRow = row+offset[0], newCol = col+offset[1];
    //     if(newRow < 0 || newRow >= m || newCol < 0 || newCol >= n){
    //         return make_tuple("", 0, -1);
    //     }
    //     int otherPos = newRow*n+newCol;
    //     swap(str[otherPos], str[zeroPos]);
    //     return make_tuple(str, depth+1, otherPos);
    // }
        
    //Time O(N*N!), Space O(N*N!), N is the number of cells on the board.
//     int slidingPuzzle(vector<vector<int>>& board) {
//         m = board.size(), n = board[0].size();
        
//         string start = toString(board); 
//         queue<tuple<string, int, int> > Q;
//         Q.push({start, 0, start.find('0')});
        
//         unordered_set<string> visited;
//         visited.insert(start);
        
//         string str; 
//         int depth, zeroPos;
//         while(!Q.empty()){
//             auto cur = Q.front();
//             Q.pop();
//             tie(str, depth, zeroPos) = cur;
//             if(str == error){
//                 return -1;
//             }else if(str == target){
//                 return depth;
//             }else{
//                 for(const auto &offset : offsets){
//                     auto next = move(cur, offset);
//                     tie(str, depth, zeroPos) = next;
//                     if(zeroPos != -1 && visited.count(str) == 0){
//                         Q.emplace(next);
//                         visited.insert(str);
//                     }
//                 }
//             } 
//         }
//         return -1;
//     }
    typedef pair<int, tuple<string, int, int> > State;
    int m, n;
    string target = "123450";
    string error = "123540";
    vector<vector<int> > offsets{{-1,0}, {1,0}, {0,-1}, {0,1}};
    string toString(vector<vector<int>>& board){
        string str = "";
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                str.push_back(board[i][j]+'0');
            }
        }
        return str;
    }
    tuple<string, int, int> move(tuple<string, int, int>& cur, const vector<int>& offset){
        string str;
        int depth, zeroPos;
        tie(str, depth, zeroPos) = cur;
        int row = zeroPos/n, col = zeroPos%n;
        int newRow = row+offset[0], newCol = col+offset[1];
        if(newRow < 0 || newRow >= m || newCol < 0 || newCol >= n){
            return make_tuple("", 0, -1);
        }
        int otherPos = newRow*n+newCol;
        swap(str[otherPos], str[zeroPos]);
        return make_tuple(str, depth+1, otherPos);
    }   
    int getWeight(string& str, int depth){
        int heuristic = 0;
        for(int i = 0; i < str.length(); ++i){
            int a = str[i]-'0';
            int targetPos = str[i]-'0'-1;
            if(targetPos == -1){
                targetPos = 5;
            }
            int curRow = i/n, curCol = i%n;
            int targetRow = targetPos/n, targetCol = targetPos%n;
            heuristic += abs(curRow-targetRow)+abs(curCol-targetCol);
        }
        return depth+heuristic;
    }
        
    //A* approach. Time O(N*N!), Space O(N*N!)
    int slidingPuzzle(vector<vector<int>>& board){
        m = board.size(), n = board[0].size();
        string start = toString(board); 
        
        auto compare = [](const State& a, const State& b)->bool{
            return a.first > b.first;
        };
        priority_queue<State, vector<State>, decltype(compare) > minHeap(compare);
        minHeap.emplace(make_pair(getWeight(start, 0), make_tuple(start, 0, start.find('0'))));
        
        unordered_map<string, int> visited;
        visited[start] = minHeap.top().first;
        
        string str; 
        int depth, zeroPos;
        while(!minHeap.empty()){
            auto [w, cur] = minHeap.top();
            minHeap.pop();
            tie(str, depth, zeroPos) = cur;
            if(str == error){
                return -1;
            }else if(str == target){
                return depth;
            }else{
                for(const auto &offset : offsets){
                    auto next = move(cur, offset);
                    tie(str, depth, zeroPos) = next;
                    w = getWeight(str, depth);
                    if(zeroPos != -1 && (visited.count(str) == 0 || visited[str] > w)){
                        minHeap.emplace(make_pair(w, next));
                        visited[str] = w;
                    }
                }
            } 
        }
        return -1;
    }
};

// class SnakeGame {
// public:
//     int height, width;
//     deque<vector<int> > snake;
//     queue<vector<int> > food;
//     vector<vector<int> > board;

//     // Time O(WH+N), Space O(WH+N), W is the width, H is the height, N is the size of array food; 
//     SnakeGame(int width, int height, vector<vector<int>>& food):height(height), width(width), board(height, vector<int>(width, 0)) {
//         snake.emplace_back(vector<int>{0,0});
//         for(const auto& pos : food){
//             this->food.emplace(pos);
//         }
//     }
    
//     // Time O(1), Space O(1)
//     int move(string direction) {
//         auto& head = snake.front();
//         auto& tail = snake.back();
//         int x = head[0], y = head[1];
//         if(direction == "R"){
//             ++y;
//         }else if(direction == "L"){
//             --y;
//         }else if(direction == "U"){
//             --x;
//         }else{
//             ++x;
//         }
//         if(x < 0 || x == height || y < 0 || y == width || board[x][y] == -1 && (tail[0] != x || tail[1] != y)){
//             return -1;
//         }else if(food.empty() || food.front()[0] != x || food.front()[1] != y){
//             board[tail[0]][tail[1]] = 0;
//             snake.pop_back();
//             // snake.erase(prev(snake.end()));
//         }else{
//             food.pop();
//         }
//         board[x][y] = -1;
//         snake.emplace_front(vector<int>{x,y});
//         return snake.size()-1;  
//     }
// };


class SnakeGame {
public:
    int height, width;
    unordered_set<string> memo;
    deque<vector<int> > snake;
    queue<vector<int> > food;

    // Time O(N), Space O(N). N is the size of array food; 
    SnakeGame(int width, int height, vector<vector<int>>& food):height(height), width(width) {
        snake.emplace_back(vector<int>{0,0});
        memo.insert("0,0");
        for(const auto& pos : food){
            this->food.emplace(pos);
        }
    }
    
    // Time O(1), Space O(1)
    int move(string direction) {
        auto& head = snake.front();
        auto& tail = snake.back();
        int x = head[0], y = head[1];
        if(direction == "R"){
            ++y;
        }else if(direction == "L"){
            --y;
        }else if(direction == "U"){
            --x;
        }else{
            ++x;
        }
        string pos = to_string(x) + ","+to_string(y);
        if(x < 0 || x == height || y < 0 || y == width || memo.count(pos) > 0 && (tail[0] != x || tail[1] != y)){
            return -1;
        }else if(food.empty() || food.front()[0] != x || food.front()[1] != y){
            memo.erase(to_string(tail[0])+","+to_string(tail[1]));
            snake.pop_back();
        }else{
            food.pop();
        }
        snake.emplace_front(vector<int>{x,y});
        memo.insert(pos);
        return snake.size()-1;  
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */

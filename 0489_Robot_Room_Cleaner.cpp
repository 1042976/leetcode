/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

// class Solution {
// public:
//     unordered_set<int> visited;
//     int offsets[4][2] {{-1,0}, {0, 1}, {1, 0}, {0, -1}};
//     void goback(Robot& robot){
//         robot.turnRight();
//         robot.turnRight();
//         robot.move();
//         robot.turnRight();
//         robot.turnRight();        
//     }
//     string toStr(const int& row, const int& col){
//         return to_string(row) + "," + to_string(col);
//     }
//     void backtrack(Robot& robot, int row, int col, int d){
//         visited.insert(row*200+col);
//         robot.clean();
//         for(int i = 0; i < 4; ++i){
//             int newD = (d+i)%4;
//             int newRow = row + offsets[newD][0];
//             int newCol = col + offsets[newD][1];
//             if(visited.count(newRow*200+newCol) == 0 && robot.move()){
//                 backtrack(robot, newRow, newCol, newD);
//                 goback(robot);
//             }
//             robot.turnRight();
//         }
//     }
    
//     //Use hash set. Time O(N-M), Space O(N-M), where N is the total number of cells and M is the number of obstacles
//     void cleanRoom(Robot& robot) {
//         backtrack(robot, 0, 0, 0);
//     }
// };

class Solution {
public:
    bool visited[200][400] {false};
    int offsets[4][2] {{-1,0}, {0, 1}, {1, 0}, {0, -1}};
    void goback(Robot& robot){
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();        
    }
    string toStr(const int& row, const int& col){
        return to_string(row) + "," + to_string(col);
    }
    void backtrack(Robot& robot, int row, int col, int d){
        visited[row][col] = true;
        robot.clean();
        for(int i = 0; i < 4; ++i){
            int newD = (d+i)%4;
            int newRow = row + offsets[newD][0];
            int newCol = col + offsets[newD][1];
            if(!visited[newRow][newCol] && robot.move()){
                backtrack(robot, newRow, newCol, newD);
                goback(robot);
            }
            robot.turnRight();
        }
    }
    
    //Use matrix. Time O(N-M), Space O(1), where N is the total number of cells and M is the number of obstacles
    void cleanRoom(Robot& robot) {
        backtrack(robot, 100, 200, 0);
    }
};

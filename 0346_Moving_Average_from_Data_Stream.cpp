class MovingAverage {
public:
//     int size;
//     double avg;
//     list<int> arr;
//     //Time O(1), Space O(1)
//     MovingAverage(int size): size(size), avg(0){
        
//     }
//     //Time O(1), Space O(n)
//     double next(int val) {
//         int oldSize = arr.size();
//         if(oldSize < size){
//             arr.emplace_back(val);
//             avg = (avg*oldSize+val)/arr.size();
//             return avg;
//         }else{
//             avg = (avg*size-*arr.begin()+val)/size;
//             arr.erase(arr.begin());
//             arr.emplace_back(val);
//         }
//         return avg;
//     }
    
    int n, winSum;
    queue<int> Q;
    MovingAverage(int size):n(size), winSum(0){
        
    }
    //Time O(1), Space O(1)
    double next(int val){
        if(Q.size() == n){
            int a = Q.front();
            Q.pop();
            winSum += (val-a);
            Q.emplace(val);
            return winSum*1.0/n;
        }else{
            winSum += val;
            Q.emplace(val);
            return winSum*1.0/Q.size();
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

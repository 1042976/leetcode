// class MedianFinder {
// public:
//     map<int, int> hashMap;
//     map<int, int>::iterator it;
//     int delta;
//     int total;
//     MedianFinder():it(hashMap.begin()),delta(0), total(0) {
        
//     }
//     //T-O(logn), S-O(1)
//     void addNum(int num) {
//         ++hashMap[num];
//         ++total;
//         if(it == hashMap.end()){
//             it = hashMap.begin();
//             delta = 1;
//             return;
//         }
//         if(num < it->first){
//             if(total%2 == 0){
//                 if(--delta == 0){
//                     --it;
//                     delta = it->second;
//                 }
//             }
//         }else{
//             if(total%2 == 1){
//                 if(++delta > it->second){
//                     ++it;
//                     delta = 1;
//                 }
//             }
//         }
//     }
    
//     //T-O(1), S-O(1)
//     double findMedian() {
//         if(total%2 == 1 || delta < it->second){
//             return it->first;
//         }else{
//             auto next_it = it;
//             ++next_it;
//             return (it->first+next_it->first)/2.0;
//         }

//     }
// };


class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int> > lo;
    priority_queue<int, vector<int>, greater<int> > hi;
    
    MedianFinder() {
        
    }
    //T-O(logn), S-O(1)
    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        if(hi.size() > lo.size()){
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    //T-O(1), S-O(1)
    double findMedian() {
      if(lo.size() > hi.size()){
          return lo.top();
      }else{
          return (lo.top()+hi.top())/2.0;
      }

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

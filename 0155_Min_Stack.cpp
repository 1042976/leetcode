class MinStack {
    stack<int> mainStk;
    stack<pair<int, int> > minStk;
public:
    MinStack() {
        
    }
    
    //Time O(1)
    void push(int val) {
        mainStk.emplace(val);
        if(minStk.empty() || minStk.top().first > val){
            minStk.emplace(make_pair(val, 1));
        }else if(minStk.top().first == val){
            ++minStk.top().second;
        }
    }
    
    //Time O(1)
    void pop() {
        if(minStk.top().first == mainStk.top()){
            if(--minStk.top().second == 0){
                minStk.pop();
            }
        }
        mainStk.pop();
    }
    
    //Time O(1)
    int top() {
        return mainStk.top();
    }
    
    //Time O(1)
    int getMin() {
        return minStk.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class StockSpanner {
public:
    stack<pair<int, int> > st;
    //Time O(1), Space O(1)
    StockSpanner() {
        st.emplace(make_pair(INT_MAX, -1));
    }
    
    //Time O(1), Space O(1)
    int next(int price) {
        int curIdx = st.top().second+1;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        int res = curIdx-st.top().second;
        st.emplace(make_pair(price, curIdx));
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

class SORTracker {
private:
    set<pair<int, string> > data;
    set<pair<int, string> >::iterator it;
public:
    SORTracker(): it(end(data)){
        
    }
    
    //Time O(logN), Space O(1)
    void add(string name, int score) {
        auto it1 = data.insert({-score, name}).first;
        if(it == end(data) || *it1 < *it){
            --it;
        }
    }
    
    //Time O(1), Space O(1)
    string get() {  
        return (it++)->second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */

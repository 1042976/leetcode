class Vector2D {
public:
    vector<vector<int> > &vec;
    int i, j;
    //Time O(1), Space O(1)
    Vector2D(vector<vector<int>>& vec):vec(vec),i(0), j(0) {
        moveToNotEmpty();
    }
    
    //Time O(M/N), Space O(1)
    int next() {
        int val = vec[i][j];
        update();
        return val;
    }
    
    //Time O(1), Space O(1)
    bool hasNext() {
        moveToNotEmpty();
        return i < vec.size();
    }
    
    //Time O(M/N), Space O(1)
    void update(){
        ++j;
        if(j == vec[i].size()){
            j = 0;
            ++i;
            moveToNotEmpty();
        }  
    }
    
    void moveToNotEmpty(){
        while(i < vec.size() && vec[i].empty()){
            ++i;
        }  
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

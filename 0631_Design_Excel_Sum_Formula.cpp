class Excel {
public:
    class Formula{
    public: 
        unordered_map<string, int> cells;
        int val;
        Formula() : val(0){}
        Formula(unordered_map<string, int> _cells, int _val) : cells(_cells), val(_val){}
    };

    vector<vector<Formula> > formulas;
    stack<pair<int, int> > st;
    string toStr(int realRow, int realCol){
        return static_cast<char>(realCol+'A')+to_string(realRow+1);
    }
    pair<int, int> toPoint(const string& colRow){
        return make_pair(stoi(colRow.substr(1))-1, colRow[0]-'A');
    }
    // Time O(HW), Space O(1). H is the height and W is the width.
    Excel(int height, char width) : formulas(height, vector<Formula>(width-'A'+1, Formula())) {
    }
    
    void topologicalSort(int realRow, int realCol){
        string pos = toStr(realRow, realCol);
        for(int i = 0; i < formulas.size(); ++i){
            for(int j = 0; j < formulas[0].size(); ++j){
                if(formulas[i][j].cells.count(pos) > 0){
                    topologicalSort(i, j);
                }
            }
        }
        st.emplace(make_pair(realRow, realCol));
    }
    void update_cells(){
        while(!st.empty()){
            pair<int, int> pos = st.top();
            st.pop();
            if(!formulas[pos.first][pos.second].cells.empty()){
                int sum = 0;
                for(const auto& cell : formulas[pos.first][pos.second].cells){
                    pair<int, int> otherPos = toPoint(cell.first); 
                    sum += formulas[otherPos.first][otherPos.second].val * cell.second;
                }
                formulas[pos.first][pos.second].val = sum;
            }
        }
    }
    // Time O((HW)^2), Space O(HW)
    void set(int row, char column, int val) {
        int realRow = row-1, realCol = column-'A';
        formulas[realRow][realCol].val = val;
        formulas[realRow][realCol].cells.clear();
        topologicalSort(realRow, realCol);
        st.pop();
        update_cells();
    }

    int get(int realRow, int realCol){
        return formulas[realRow][realCol].val;
    }

    // Time O(1), Space O(1)
    int get(int row, char column) {
        return get(row-1, column-'A');
    }
    
    // Time O(HWL+(HW)^2), Space O(HW). L is the size of numbers.
    int sum(int row, char column, vector<string> numbers) {
        cout << formulas.size() << " " << formulas[0].size() << " sum" << endl;
        int res = 0;
        unordered_map<string, int> cells;
        for(const string& str : numbers){
            size_t idxOfColon = str.find(':');
            pair<int, int> pos = toPoint(str);
            if(idxOfColon == string::npos){
                res += get(pos.first, pos.second);
                ++cells[str];
            } else{
                string topLeft = str.substr(0, idxOfColon);
                string bottomRight = str.substr(idxOfColon+1);
                pair<int, int> topLeftPoint = toPoint(topLeft);
                pair<int, int> bottomRightPoint = toPoint(bottomRight);
                for(int h = topLeftPoint.first; h <= bottomRightPoint.first; ++h){
                    for(int w = topLeftPoint.second; w <= bottomRightPoint.second; ++w){
                        res += get(h,w);
                        ++cells[toStr(h, w)];
                    }
                }
            }
        }
        set(row, column, res);
        formulas[row-1][column-'A'].cells = cells;
        return res;
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */

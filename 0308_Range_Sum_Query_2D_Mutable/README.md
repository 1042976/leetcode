### 308.Range Sum Query 2D - Mutable

**In Segment Tree solution, the time and space complexity for each method are:**

constructor  - O(MN) and O(MN)

update - O(logM * logN) and O(1)

sumRegion - O(logM * logN) and O(logN)

The space complexity of the sumRegion could be O(1) but here we define an array to store possible column indices to avoid trying to get the same column indices repeatedly.

This link is helpful to understand the structure of the 2D Segment Tree: https://www.geeksforgeeks.org/two-dimensional-segment-tree-sub-matrix-sum/

**In BIT solution, the time and space complexity for each method are:**

constructor - O(MN) and O(MN)

update - O(logM * logN) and O(1)

sumRegion - O(logM * logN) and O(1)

#### 1.Segment Tree (8ms - 37ms)

```C++
class SegmentTree{
private:
    int m, n;
    vector<vector<int> > matrix;
    vector<int> getColIndices(int col1, int col2){
        vector<int> res;
        while(col1 <= col2){
            if(col1%2){
                res.emplace_back(col1++);
            }
            if(col2%2 == 0){
                res.emplace_back(col2--);
            }
            col1 >>= 1;
            col2 >>= 1;
        }
        return res;
    }
    int sumRowRegion(int row, vector<int> &colIndices){
        int sum = 0;
        for(const auto &col : colIndices){
            sum += matrix[row][col];
        }
        return sum;
    }
public:
    SegmentTree(vector<vector<int> >& _matrix): m(_matrix.size()), n(_matrix[0].size()), matrix(2*m, vector<int>(2*n, 0)){
        //initialize leaves
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                matrix[i+m][j+n] = _matrix[i][j];
            }
            for(int j = n-1; j > 0; --j){
                matrix[i+m][j] = matrix[i+m][2*j] + matrix[i+m][2*j+1];
            }
        }
        //initialize nodes in higher levels
        for(int i = m-1; i > 0; --i){
            for(int j = n; j < 2*n; ++j){
                matrix[i][j] = matrix[2*i][j] + matrix[2*i+1][j];
            }
            for(int j = n-1; j > 0; --j){
                matrix[i][j] = matrix[i][2*j] + matrix[i][2*j+1];
            }
        }
    }
    void update(int row, int col, int val){
        row += m;
        col += n;
        
        //update the leaf
        matrix[row][col] = val;
        for(int j = col>>1; j > 0; j >>= 1){
            matrix[row][j] = matrix[row][2*j]+matrix[row][2*j+1];
        }  
        
        //update the values of nodes in in higher levels
        for(int i = row>>1; i > 0; i >>= 1){
            matrix[i][col] = matrix[2*i][col] + matrix[2*i+1][col];
            for(int j = col>>1; j > 0; j >>= 1){
                matrix[i][j] = matrix[i][2*j] + matrix[i][2*j+1];
            }
        }
    }
      
    int sumRegion(int row1, int col1, int row2, int col2){
        int sum = 0;
        row1 += m;
        row2 += m;
        col1 += n;
        col2 += n;
        vector<int> colIndices = getColIndices(col1, col2);
        while(row1 <= row2){
            if(row1%2){
                sum += sumRowRegion(row1++, colIndices);
            }
            if(row2%2 == 0){
                sum += sumRowRegion(row2--, colIndices);
            }
            row1 >>= 1;
            row2 >>= 1;
        }
        return sum;
    }
};
class NumMatrix {
public:   
    SegmentTree tree;
    
    //Time O(MN), Space O(MN)
    NumMatrix(vector<vector<int>>& matrix):tree(matrix) {}
    
    //Time O(logM * logN), Space O(1)
    void update(int row, int col, int val) {
        tree.update(row, col, val);
    }
    
    //Time O(logM * logN), Space O(logN)
    int sumRegion(int row1, int col1, int row2, int col2) {
        return tree.sumRegion(row1, col1, row2, col2);
    }
};
```

#### 2.Binary Indexed Tree (19ms - 38ms)

```c++
class BIT{
private:
    int m, n;
    vector<vector<int> >& raw;
    vector<vector<int> > matrix;
    int getNext(int idx){
        return idx + (idx & (-idx));
    }
    int getParent(int idx){
        return idx & (idx-1);
    }
    void addValue(int row, int col, int val){
        for(int i = row+1; i <= m; i = getNext(i)){
            for(int j = col+1; j <= n; j = getNext(j)){
                matrix[i][j] += val;               
            }
        }
    }
    int getSum(int row, int col){
        int sum = 0;
        for(int i = row+1; i > 0; i = getParent(i)){
            for(int j = col+1; j > 0; j = getParent(j)){
                sum += matrix[i][j];            
            }
        }
        return sum;
    }
public:
    BIT(vector<vector<int> >& _matrix) : m(_matrix.size()), n(_matrix[0].size()), raw(_matrix), matrix(m+1, vector<int>(n+1, 0)){
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                addValue(i, j, _matrix[i][j]);
            }
        }
    }
    void update(int row, int col, int val){
        addValue(row, col, val-raw[row][col]);
        raw[row][col] = val;
    }
    int sumRegion(int row1, int col1, int row2, int col2){
        return getSum(row2, col2)-getSum(row2, col1-1)-getSum(row1-1, col2)+getSum(row1-1,col1-1);        
    }
};
class NumMatrix {
public:   
    BIT tree;
    //Time O(MN), Space O(MN)
    NumMatrix(vector<vector<int>>& matrix):tree(matrix) {}
    
    //Time O(logM * logN), Space O(1)
    void update(int row, int col, int val) {
        tree.update(row, col, val);
    }
    
    //Time O(logM * logN), Space O(1)
    int sumRegion(int row1, int col1, int row2, int col2) {
        return tree.sumRegion(row1, col1, row2, col2);
    }
};
```


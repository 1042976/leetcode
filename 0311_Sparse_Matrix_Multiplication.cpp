class Solution {
public:
    //Time O(M1*N2*M2), Space O(1)
    // vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
    //     vector<vector<int> > res(mat1.size(), vector<int>(mat2[0].size()));
    //     for(int i = 0; i < res.size(); ++i){
    //         for(int j = 0; j < res[0].size(); ++j){
    //             for(int k = 0; k < mat2.size(); ++k){
    //                 res[i][j] += mat1[i][k]*mat2[k][j];
    //             }
    //         }
    //     }
    //     return res;
    // }
    //Time O(M*K*N), Space O(1), M is the rows of mat1, N is the columns of mat2, K is the rows of mat2
    // vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
    //     vector<vector<int> > res(mat1.size(), vector<int>(mat2[0].size(), 0));
    //     for(int i = 0; i < res.size(); ++i){
    //         for(int k = 0; k < mat2.size(); ++k){
    //             if(mat1[i][k] != 0){
    //                 for(int j = 0; j < res[0].size(); ++j){
    //                    res[i][j] += mat1[i][k]*mat2[k][j]; 
    //                 }                     
    //             }
    //         }
    //     }
    //     return res;
    // }

    // vector<vector<pair<int, int> > > compress(vector<vector<int> >& mat){
    //     vector<vector<pair<int, int> > > sparseMat(mat.size());
    //     for(int i = 0; i < mat.size(); ++i){
    //         for(int j = 0; j < mat[0].size(); ++j){
    //             if(mat[i][j] != 0){
    //                 sparseMat[i].emplace_back(make_pair(j, mat[i][j]));
    //             }
    //         }
    //     }   
    //     return sparseMat;
    // }
    // //Time O(M*K*N), Space O(MK+KN);
    // vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
    //     vector<vector<int> > res(mat1.size(), vector<int>(mat2[0].size(), 0));
    //     auto sparseMat1 = compress(mat1);
    //     auto sparseMat2 = compress(mat2);
    //     for(int row1 = 0; row1 < sparseMat1.size(); ++row1){
    //         for(const auto &[col1, val1] : sparseMat1[row1]){
    //             for(const auto &[col2, val2] : sparseMat2[col1]){
    //                 res[row1][col2] += val1*val2;
    //             }
    //         }
    //     }
    //     return res;
    // }
    class CSR{
    public:
        vector<int> values, cols, numsAsRowIncrease;
        CSR(vector<vector<int> >& mat){
            numsAsRowIncrease.emplace_back(0);
            for(int i = 0; i < mat.size(); ++i){
                for(int j = 0; j < mat[0].size(); ++j){
                    if(mat[i][j] != 0){
                        values.emplace_back(mat[i][j]);
                        cols.emplace_back(j);
                    }
                }
                numsAsRowIncrease.emplace_back(values.size());
            }
        }
    };
    class CSC{
    public:
        vector<int> values, rows, numsAsColumnIncrease;
        CSC(vector<vector<int> >& mat){
            numsAsColumnIncrease.emplace_back(0);
            for(int j = 0; j < mat[0].size(); ++j){
               for(int i = 0; i < mat.size(); ++i){
                   if(mat[i][j] != 0){
                       values.emplace_back(mat[i][j]);
                       rows.emplace_back(i);
                   }
               }
               numsAsColumnIncrease.emplace_back(values.size());
            }
        }
    };
    //Time O(M*K*N), Space O(M*K+K*N)
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2){
        CSR csr(mat1);
        CSC csc(mat2);
        vector<vector<int> > res(mat1.size(), vector<int>(mat2[0].size(), 0));
        for(int i = 0; i < res.size(); ++i){
            for(int j = 0; j < res[0].size(); ++j){
                int mat1RowStart = csr.numsAsRowIncrease[i];
                int mat1RowEnd = csr.numsAsRowIncrease[i+1];
                int mat2ColumnStart = csc.numsAsColumnIncrease[j];
                int mat2ColumnEnd = csc.numsAsColumnIncrease[j+1];
                while(mat1RowStart < mat1RowEnd && mat2ColumnStart < mat2ColumnEnd){
                    if(csr.cols[mat1RowStart] < csc.rows[mat2ColumnStart]){
                        ++mat1RowStart;
                    }else if(csr.cols[mat1RowStart] > csc.rows[mat2ColumnStart]){
                        ++mat2ColumnStart;
                    }else{
                        res[i][j] += csr.values[mat1RowStart] * csc.values[mat2ColumnStart];
                        ++mat1RowStart;
                        ++mat2ColumnStart;
                    }
                }
            }
        }
        return res;
    }
};

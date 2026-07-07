class NumMatrix {
public:
    vector<vector<int>> pfm; // prefix matrix
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        pfm.resize(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pfm[i][j] = matrix[i][j];
                if (i) {
                    pfm[i][j] += pfm[i - 1][j];
                }
                if (j) {
                    pfm[i][j] += pfm[i][j - 1];
                }
                if (i && j) {
                    pfm[i][j] -= pfm[i - 1][j - 1];
                }
            }
        }
        // cout << "--- displaying matrix --- \n";
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << matrix[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "--- displaying pfm --- \n";
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << pfm[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = pfm[row2][col2];
        if (row1) {
            res -= pfm[row1 - 1][col2];
        }
        if (col1) {
            res -= pfm[row2][col1 - 1];
        }
        if (row1 && col1) {
            res += pfm[row1 - 1][col1 - 1];
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
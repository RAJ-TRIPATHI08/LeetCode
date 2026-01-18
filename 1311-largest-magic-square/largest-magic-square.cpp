class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> rowCumSum(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            rowCumSum[i][0] = grid[i][0];
            for(int j = 1; j < n; j++) {
                rowCumSum[i][j] = rowCumSum[i][j-1] + grid[i][j];
            }
        }

        vector<vector<int>> colCumSum(m, vector<int>(n));
        for(int j = 0; j < n; j++) {
            colCumSum[0][j] = grid[0][j];
            for(int i = 1; i < m; i++) {
                colCumSum[i][j] = colCumSum[i-1][j] + grid[i][j];
            }
        }

        for(int side = min(m, n); side >= 2; side--) {
            for(int i = 0; i + side - 1 < m; i++) {
                for(int j = 0; j + side - 1 < n; j++) {

                    int targetSum = rowCumSum[i][j+side-1] - (j > 0 ? rowCumSum[i][j-1] : 0);
                    bool allSame = true;

                    for(int r = i+1; r < i+side; r++) {
                        int rowSum = rowCumSum[r][j+side-1] - (j > 0 ? rowCumSum[r][j-1] : 0);
                        if(rowSum != targetSum) {
                            allSame = false;
                            break;
                        }
                    }

                    if(!allSame) continue;

                    for(int c = j; c < j+side; c++) {
                        int colSum = colCumSum[i+side-1][c] - (i > 0 ? colCumSum[i-1][c] : 0);
                        if(colSum != targetSum) {
                            allSame = false;
                            break;
                        }
                    }

                    if(!allSame) continue;

                    int diag = 0, antiDiag = 0;
                    for(int k = 0; k < side; k++) {
                        diag += grid[i+k][j+k];
                        antiDiag += grid[i+k][j+side-k-1];
                    }

                    if(diag == targetSum && antiDiag == targetSum)
                        return side;
                }
            }
        }

        return 1;
    }
};

class Solution {
public:
    int r, c;

    void shift(int i, int j, vector<vector<int>>& grid)
    {
        while(i < j)
        {
            swap(grid[i/c][i%c], grid[j/c][j%c]);
            i++;
            j--;
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        this->r = grid.size();
        this->c = grid[0].size();
        int n = r*c;
        k = k % n;
        if(k == 0)  
            return grid;

        shift(0, n - 1, grid);
        shift(0, k - 1, grid);
        shift(k, n - 1, grid);
        return grid;
    }
};
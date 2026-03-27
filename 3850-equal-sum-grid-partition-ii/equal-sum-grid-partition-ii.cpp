class Solution {
public:
    typedef long long ll;
    ll total = 0;

    // // We are checking only horizontal cuts
    // // to encounter all possible ways we are reversing transposing so we can check 
    // // vertical cases also


    // bool checkCuts(vector<vector<int>>& grid)
    // {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     ll top = 0;
    //     unordered_set<ll> st;

    //     for(int i = 0; i <= n - 2; i++)
    //     {
    //         for(int j = 0; j < m; j++)
    //         {
    //             st.insert(grid[i][j]);
    //             top += grid[i][j];
    //         }

    //         ll bottom = total - top;
    //         ll diff = top - bottom;

    //         if(diff == 0)   
    //             return true;

    //         // check for connectivities

    //         // Case1: if it is present at top corner left
    //         if(diff == (ll)grid[0][0])
    //             return true;

    //         // Case2: if it is present at top corner right
    //         if(diff == (ll)grid[0][m-1])
    //             return true;

    //         // if only one column
    //         // Case3: if it is present at just above the cutline 
    //         if(diff == (ll)grid[i][0])
    //             return true;

    //         // Case4: if there is multiple rows then there is no issue of connectivity
    //         if(i > 0 && m > 1 && st.count(diff))
    //             return true;
    //     }
    //     return false;
    // }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                total += grid[i][j];
            }
        }

        auto checkCuts = [&](vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            ll top = 0;
            unordered_set<ll> st;

            for(int i = 0; i <= n - 2; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    st.insert(grid[i][j]);
                    top += grid[i][j];
                }

                ll bottom = total - top;
                ll diff = top - bottom;

                if(diff == 0)   
                    return true;

                // check for connectivities

                // Case1: if it is present at top corner left
                if(diff == (ll)grid[0][0])
                    return true;

                // Case2: if it is present at top corner right
                if(diff == (ll)grid[0][m-1])
                    return true;

                // if only one column
                // Case3: if it is present at just above the cutline 
                if(diff == (ll)grid[i][0])
                    return true;

                // Case4: if there is multiple rows then there is no issue of connectivity
                if(i > 0 && m > 1 && st.count(diff))
                    return true;
            }
            return false;
        };

        // horizontal check
        if(checkCuts(grid))
            return true;
        
        // reverse the grid order so we can check top to bottom 
        reverse(begin(grid), end(grid));

        if(checkCuts(grid))
            return true;

        // transform to original grid for vertical check
        reverse(begin(grid), end(grid)); 

        // take transpose of grid to check for verticalCuts using horCuts
        vector<vector<int>> transposeGrid(m, vector<int>(n)); //m*n

        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < m; j++) 
            {
                transposeGrid[j][i] = grid[i][j];
            }
        }

        // left -> right vertical check
        if(checkCuts(transposeGrid))
            return true;
        
        // reverse the grid order so we can check top to bottom 
        // right -> left vertical check
        reverse(begin(transposeGrid), end(transposeGrid));
        if(checkCuts(transposeGrid))
            return true;

        cout << total << endl;
        return false;
    }
};
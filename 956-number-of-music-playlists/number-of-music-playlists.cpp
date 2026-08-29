class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        int mod = 1e9 + 7;
        int dp[101][101];
        memset(dp, -1, sizeof(dp));
        function<int(int, int)> solve = [&](int noOfSongs, int uniqueSongs) -> int {
            if(noOfSongs == goal)
            {
                if(uniqueSongs == n)
                    return 1;
                return 0;
            }

            if(dp[noOfSongs][uniqueSongs] != -1)
                return dp[noOfSongs][uniqueSongs];

            int res = 0;
            long long onlyUniqueSongsLists = 1LL * (n - uniqueSongs) * solve(noOfSongs + 1, uniqueSongs + 1);
            
            long long repeatedSongsLists = 1LL * max(0, uniqueSongs - k) * solve(noOfSongs + 1, uniqueSongs);

            res = (onlyUniqueSongsLists + repeatedSongsLists) % mod;
            return dp[noOfSongs][uniqueSongs] = res;
        };
        return solve(0, 0);
    }
};
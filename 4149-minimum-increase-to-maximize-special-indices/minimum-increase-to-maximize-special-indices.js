class Pair {
    constructor(first, second) {
        this.first = first;
        this.second = second;
    }
}

function minIncrease(nums) {
    let n = nums.length;

    let cost = new Array(n).fill(0);
    let dp = new Array(n).fill(null);

    for (let i = 1; i < n - 1; i++) {
        let m = Math.max(nums[i - 1], nums[i + 1]);
        if (m < nums[i]) continue;
        cost[i] = m + 1 - nums[i];
    }

    function solve(i) {
        if (i >= n - 1)
            return new Pair(0, 0);

        if (dp[i] !== null)
            return dp[i];

        let skip = solve(i + 1);
        let nxt = solve(i + 2);
        let take = new Pair(
            1 + nxt.first,
            cost[i] + nxt.second
        );

        let res;

        if (skip.first > take.first) {
            res = skip;
        } else if (take.first > skip.first) {
            res = take;
        } else {
            if (skip.second > take.second) {
                res = take;
            } else {
                res = skip;
            }
        }

        return dp[i] = res;
    }

    return solve(1).second;
}
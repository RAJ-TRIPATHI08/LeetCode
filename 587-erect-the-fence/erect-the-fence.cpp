class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        int left = 0;

        // find leftmost point (min x, tie-break min y)
        for (int i = 1; i < n; i++) {
            if (trees[i][0] < trees[left][0] ||
               (trees[i][0] == trees[left][0] && trees[i][1] < trees[left][1])) {
                left = i;
            }
        }

        unordered_set<int> hull;
        int curr = left;

        while (true) {

            hull.insert(curr);

            int next = (curr + 1) % n;
            vector<int> collinearPoints;

            for (int i = 0; i < n; i++) {
                if (i == curr) continue;

                int dir = cross(trees[curr], trees[next], trees[i]);

                if (dir < 0) {
                    next = i;
                    collinearPoints.clear();
                }
                else if (dir == 0) {
                    int dist = distance(trees[curr], trees[next], trees[i]);
                    if (dist < 0) {
                        collinearPoints.push_back(next);
                        next = i;
                    } else {
                        collinearPoints.push_back(i);
                    }
                }
            }

            for (int idx : collinearPoints) {
                hull.insert(idx);
            }

            if (next == left) break;

            curr = next;
        }

        vector<vector<int>> ans;
        for (int idx : hull) {
            ans.push_back(trees[idx]);
        }

        return ans;
    }

private:
    // < 0 → CCW (c is to the left of line ab)
    int cross(vector<int>& a, vector<int>& b, vector<int>& c) {
        return (b[0] - a[0]) * (c[1] - a[1]) -
               (b[1] - a[1]) * (c[0] - a[0]);
    }

    // < 0 → b is closer to a than c
    // > 0 → c is closer to a than b
    int distance(vector<int>& a, vector<int>& b, vector<int>& c) {
        int d1 = (b[0] - a[0]) * (b[0] - a[0]) +
                 (b[1] - a[1]) * (b[1] - a[1]);

        int d2 = (c[0] - a[0]) * (c[0] - a[0]) +
                 (c[1] - a[1]) * (c[1] - a[1]);

        return d1 - d2;
    }
};
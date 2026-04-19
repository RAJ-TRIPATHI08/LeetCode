#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct State {
        int index;
        long long value;
        long long prev;
        string expr;
    };

    vector<string> addOperators(string num, int target) {
        vector<string> result;
        int n = num.size();

        stack<State> st;

        // Initial numbers
        for (int i = 0; i < n; i++) {
            if (i > 0 && num[0] == '0') break; // leading zero

            string s = num.substr(0, i + 1);
            long long val = stoll(s);

            st.push({i + 1, val, val, s});
        }

        while (!st.empty()) {
            State cur = st.top();
            st.pop();

            // If reached end
            if (cur.index == n) {
                if (cur.value == target) {
                    result.push_back(cur.expr);
                }
                continue;
            }

            // Try next numbers
            for (int i = cur.index; i < n; i++) {
                if (i > cur.index && num[cur.index] == '0') break;

                string s = num.substr(cur.index, i - cur.index + 1);
                long long val = stoll(s);

                // +
                st.push({i + 1,
                         cur.value + val,
                         val,
                         cur.expr + "+" + s});

                // -
                st.push({i + 1,
                         cur.value - val,
                         -val,
                         cur.expr + "-" + s});

                // *
                st.push({i + 1,
                         cur.value - cur.prev + (cur.prev * val),
                         cur.prev * val,
                         cur.expr + "*" + s});
            }
        }

        return result;
    }
};
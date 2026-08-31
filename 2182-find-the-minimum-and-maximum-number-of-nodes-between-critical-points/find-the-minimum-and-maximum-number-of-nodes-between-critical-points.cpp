class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> vec;

        while(head->next) {
            vec.push_back(head->val);
            head = head->next;
        }
        vec.push_back(head->val);

        if(vec.size() < 3)
            return {-1, -1};

        int first = -1;
        int prev = -1;

        int minDist = INT_MAX;
        int maxDist = -1;

        for(int i = 1; i < vec.size() - 1; i++) {
            
            if((vec[i-1] > vec[i] && vec[i] < vec[i+1]) ||
               (vec[i-1] < vec[i] && vec[i] > vec[i+1])) {
                
                int pos = i + 1;   // your 1-based position

                if(first == -1) {
                    first = pos;
                }
                else {
                    minDist = min(minDist, pos - prev);
                    maxDist = pos - first;
                }

                prev = pos;
            }
        }

        if(minDist == INT_MAX)
            return {-1, -1};

        return {minDist, maxDist};
    }
};
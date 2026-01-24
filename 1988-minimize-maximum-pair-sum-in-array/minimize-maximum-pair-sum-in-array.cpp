class Solution {
public:
    int minPairSum(vector<int>& nums) {
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int n:nums) 
        {
            minHeap.push(n);  maxHeap.push(n);
        }
        int res = -1e9;
        while(!minHeap.empty())
        {
            res = max(res, minHeap.top() + maxHeap.top());
            minHeap.pop();
            maxHeap.pop();
        }
        return res;
    }
};
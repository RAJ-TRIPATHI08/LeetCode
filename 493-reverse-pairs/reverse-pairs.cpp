class Solution {
public:
    int merge(vector<int>& a, int l, int mid, int r)
    {
        int cnt = 0;
        int j = mid + 1;

        for(int i = l; i <= mid; i++) {
            while(j <= r && (long long)a[i] > 2LL * a[j])
                j++;

            cnt += j - (mid + 1);
        }
        vector<int> temp;

        int i = l;
        j = mid + 1;

        while(i <= mid && j <= r)
        {
            if(a[i] <= a[j])
                temp.push_back(a[i++]);
            else
                temp.push_back(a[j++]);
        }

        while(i <= mid)
            temp.push_back(a[i++]);

        while(j <= r)
            temp.push_back(a[j++]);

        for(int i = l; i <= r; i++)
            a[i] = temp[i - l];

        return cnt;
    }

    int mergeSort(vector<int>& a, int l, int r) 
    {
        if(l >= r)
            return 0;

        int mid = (l + r) / 2;

        int cnt = 0;

        cnt += mergeSort(a, l, mid);
        cnt += mergeSort(a, mid + 1, r);

        cnt += merge(a, l, mid, r);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};
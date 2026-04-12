class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        unordered_map<int,vector<int>> m;
        m[0].push_back(-1);

        int count0=0,count1=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') count0++;
            else count1++;
        }

        int sum=0;
        int ans=0;

        for(int i=0;i<n;i++){
            if(s[i]=='1') sum++;
            else sum--;

            if(m.count(sum)){
                ans=max(ans,i-m[sum][0]);
            }

            if(m.count(sum-2)){
                vector<int> arr=m[sum-2];
                for(int j=0;j<arr.size();j++){
                    int len=i-arr[j];
                    int zeros=(len-2)/2;
                    if(count0>zeros){
                        ans=max(ans,len);
                        break;
                    }
                }
            }

            if(m.count(sum+2)){
                vector<int> arr=m[sum+2];
                for(int j=0;j<arr.size();j++){
                    int len=i-arr[j];
                    int ones=(len-2)/2;
                    if(count1>ones){
                        ans=max(ans,len);
                        break;
                    }
                }
            }

            m[sum].push_back(i);
        }

        return ans;
    }
};
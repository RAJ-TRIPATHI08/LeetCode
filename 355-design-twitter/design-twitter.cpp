class Twitter {
public:
    int time = 0;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> posts;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> res;
        for(auto v : posts[userId])
            res.push_back(v);

        for(auto Id : following[userId])
        {
            for(auto v : posts[Id])
            {
                res.push_back(v);
            }
        }
        sort(res.begin(), res.end());
        reverse(begin(res), end(res));  
        vector<int> ans;
        for(auto it : res)
        {
            if(ans.size() >= 10)
                break;
            ans.push_back(it.second);
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId); 
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->following(followerId,followeeId);
 * obj->unfollowing(followerId,followeeId);
 */
class Twitter {
public:
    vector<pair<int, int>> cake; // userid, tweet id
    unordered_map<int, unordered_set<int>> f; 
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        cake.push_back(make_pair(userId, tweetId));
        f[userId].insert(userId);        
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> toret;
        for(int i=cake.size()-1;i>=0;i--){
            if(toret.size()==10){
                return toret;
            }
            if(f[userId].find(cake[i].first)!=f[userId].end()){
                toret.push_back(cake[i].second);
            }

        }return toret;
        
    }
    
    void follow(int followerId, int followeeId) {
        f[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        f[followerId].erase(followeeId);
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
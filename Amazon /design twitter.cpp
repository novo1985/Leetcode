class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        pair<int,int> temp = make_pair(userId, tweetId);
        news_list.push_back(temp);
        user_newsmap[userId].push_front(temp);

        for(const auto& it : user_follow){ // user who follow this poster
            if(it.second.count(userId) == 1){
                user_newsmap[it.first].push_front(temp);
            }
        }
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed
     must be posted by users who the user followed or by the user herself. Tweets must be ordered
      from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        //find the user in the map
        if(user_newsmap.count(userId) == 0) { return res; }
        //int n = user_newsmap[userId].size();
        int n = 1;
        list<pair<int, int>>::iterator it = user_newsmap[userId].begin();
        while(it != user_newsmap[userId].end() && n <= 10){
            res.push_back(it->second);
            it++;
            n++;
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        user_follow[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        //update newslist of followerId
        //list<pair<int, int>>::iterator it = user_newsmap[followerId];
        /*user_newsmap[followerId].remove_if([](list<pair<int, int>>::iterator it)
            { return it->fisrt == followeeId; });*/


        user_follow[followeeId].erase(followeeId);

    }
private:
    // key: userID, val: recent tweet(userID, tweetID)
    unordered_map<int, list<pair<int, int>> > user_newsmap;
    list<pair<int, int>> news_list;//userID and tweetID
    unordered_map<int, set<int>> user_follow;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */



//
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        cnt = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        follow(userId, userId);
        tweets[userId].insert({cnt++, tweetId});
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        map<int, int> top10;
        for (auto it = friends[userId].begin(); it != friends[userId].end(); ++it) {
            int t = *it;
            for (auto a = tweets[t].begin(); a != tweets[t].end(); ++a) {
                top10.insert({a->first, a->second});
                if (top10.size() > 10) top10.erase(top10.begin());
            }
        }
        for (auto it = top10.rbegin(); it != top10.rend(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            friends[followerId].erase(followeeId);
        }
    }

private:
    int cnt;
    unordered_map<int, set<int>> friends;
    unordered_map<int, map<int, int>> tweets;
};
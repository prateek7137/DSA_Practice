class Twitter {
public:
    int time; // Global timestamp counter to order tweets chronologically
    
    Twitter() {
        time = 1; // Initialize timestamp counter starting at 1
    }
    
    map<int, set<pair<int,int>>> tweets; // Maps userId -> set of latest 10 tweets as {timestamp, tweetId}
    unordered_map<int, set<int>> follows;  // Maps userId -> set of userIds they currently follow
    
    void postTweet(int userId, int tweetId) {
        set<pair<int,int>> myTweets = tweets[userId]; // Retrieve the user's current tweets
        if(myTweets.size() == 10){
            myTweets.erase(myTweets.begin()); // Remove the oldest tweet to maintain a max of 10
        }
        myTweets.insert({time, tweetId}); // Insert the new tweet with the current timestamp
        tweets[userId] = myTweets; // Update the user's tweet list in the map
        time++; // Increment the global timestamp for the next tweet
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed; // Will store the final list of up to 10 tweet IDs
        set<int> network = follows[userId]; // Get the set of users the current user follows
        network.insert(userId); // Ensure the user also sees their own tweets
        
        set<pair<int,int>> top10; // Set to keep the top 10 newest tweets across the network sorted
        
        for(int u : network){ // Iterate through the user and all their followees
            set<pair<int,int>> myTweets = tweets[u]; // Get the tweets for the current person in the loop
            for(pair<int,int> t : myTweets){ // Process each of their tweets
                if(top10.size() < 10){
                    top10.insert(t); // If we haven't collected 10 tweets yet, just add it
                }
                else{
                    pair<int,int> oldest = *top10.begin(); // Get the oldest tweet currently in our top 10 set
                    if(t.first > oldest.first){ // If the current tweet being evaluated is newer:
                        top10.erase(top10.begin()); // Remove the oldest tweet from the set
                        top10.insert(t); // Insert the newer tweet
                    }
                }
            }
        }
        
        for(pair<int,int> t : top10){
            feed.push_back(t.second); // Extract just the tweet IDs from our sorted set
        }
        
        reverse(feed.begin(), feed.end()); // Reverse to get descending chronological order (newest first)
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId); // Add the followeeId to the follower's set
    }
    
    void unfollow(int followerId, int followeeId) {
        set<int> network = follows[followerId]; // Retrieve the follower's current set of followees
        if(network.find(followeeId) != network.end()){ // Check if they are actually following the user
            network.erase(network.find(followeeId)); // Remove the followee from the set
            follows[followerId] = network; // Update the map with the modified set
        }
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
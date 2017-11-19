#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() { }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
		posts_.push_back(tweetId);
		int index = posts_.size() - 1;
		auto iter = user_posts_.find(userId);
		if (iter == user_posts_.end()) {
			user_posts_[userId] = vector<int>({index});
		} else {
			iter->second.push_back(index);
		}
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
		auto iter = user_posts_.find(userId);
		if (iter == user_posts_.end()) {
			return {};
		}
		set<int> news_feed_index;
		for (int i = 0; i < iter->second.size(); i++) {
			news_feed_index.insert(iter->second[i]);
		}
		auto it = follows_.find(userId);
		if (it != follows_.end()) {
			for (auto user_id = it->second.begin(); user_id != it->second.end(); user_id++) {
				iter = user_posts_.find(*user_id);
				if (iter != user_posts_.end()) {
					for (int i = 0; i < iter->second.size(); i++) {
						news_feed_index.insert(iter->second[i]);
					}
				}
			}
		}
		vector<int> post_ids;
		int cnt = 0;
		for (set<int>::const_reverse_iterator index = news_feed_index.rbegin(); index != news_feed_index.rend(); index++) {
			post_ids.push_back(posts_[*index]);
			if (++cnt >= 10) {
				break;
			}
		}

		return post_ids;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
		auto iter = follows_.find(followerId);
		if (iter == follows_.end()) {
			follows_[followerId] = unordered_set<int>({followeeId});
		} else {
			follows_[followerId].insert(followeeId);
		}
		auto user_iter = user_posts_.find(followerId);
		if (user_iter == user_posts_.end()) {
			user_posts_[followerId] = vector<int>();
		}
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
		auto iter = follows_.find(followerId);
		if (iter != follows_.end()) {
			iter->second.erase(followeeId);
		}
    }
private:
	vector<int> posts_; // post_id by time line
	unordered_map<int, vector<int>> user_posts_; // <user_id, vector<post_id>>
	unordered_map<int, unordered_set<int>> follows_; // <follower, vector<followee>>
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

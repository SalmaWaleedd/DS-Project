#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class User {
private:
    std::string Name;
    int ID;
    std::vector<std::string> postBody;
    std::vector<std::string> postTopic;
    int total_followers = 0;

public:
    int total_following = 0;
    std::vector<User*> following;

    User();

    void set_PostBody(std::string post_Body);

    void set_ID(int id);

    void set_Name(std::string name);

    void set_PostTopic(std::string post_Topic);

    void set_Following(User* followedUser);

    std::string getName() const;

    int get_followersCount();

    int getId() const;

    User* getUserFollowing(int userNumber);

    bool doYouFollow(User* targetedUser);

    void printUserSuggestion();

    std::string getUserSuggestion();

    void PrintUserData() const;

    string getUserDataAsString() const;

    vector<string> getPostsByKeyword(const string& keyword) const;

    vector<string> gettopicsByKeyword(const string& keyword) const ;
};

class SocialNetwork {
public:
    std::vector<User*> users;
    int TotalUser = 0;

    ~SocialNetwork();

    User* createUser();

    User* getUser(int user_id) const;

    User* getUserWithMostFollowings();

    User* getUserWithMostFollowers();

    void printMutualFollowers(User* user1, User* user2);

    string getMutualFollowers(User* user1, User* user2);

    string searchByKeyword(const string& keyword) const;

    string getAllUsersDataAsString() ;

    vector<User*> getUsersAsVector();
};

#endif // GRAPH_H


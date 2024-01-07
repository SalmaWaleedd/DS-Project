
/*******************************************************************
* File Name: Graph.h
********************************************************************/
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <string>
#define ID_Converter                                                           1

using namespace std;
class User {
private:
     string Name;
    int ID;
     vector< string> postBody;
     vector< string> postTopic;
    int total_followers = 0;

public:
    int total_following = 0;
     vector<User*> following;

    User();

    void set_PostBody( string post_Body);

    void set_ID(int id);

    void set_Name( string name);

    void set_PostTopic( string post_Topic);

    void set_Following(User* followedUser);

    string getName() const;

    int get_followersCount();

    int getId() const;

    User* getUserFollowing(int userNumber);

    bool doYouFollow(User* targetedUser);


     string getUserSuggestion();


    string getUserDataAsString() const;

    vector<string> getPostsByKeyword(const string& keyword) const;

    vector<string> gettopicsByKeyword(const string& keyword) const ;
};

  class SocialNetwork {
public:
     vector<User*> users;
    int TotalUser = 0;

    ~SocialNetwork();
    string getAllUsersDataAsString();
    User* createUser();

    User* getUser(int user_id) const;

    User* getUserWithMostFollowings();

    User* getUserWithMostFollowers();


    string getMutualFollowers(User* user1, User* user2);

    string searchByKeyword(const string keyword) const;
    vector<User*> getUsersAsVector();
};

#endif // GRAPH_H


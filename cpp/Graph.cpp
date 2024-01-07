#include "Graph.h"

// User Class Implementation
User::User() {}

void User::set_PostBody(std::string post_Body) {
    postBody.push_back(post_Body);
}

void User::set_ID(int id) {
    ID = id;
}

void User::set_Name(std::string name) {
    Name = name;
}

void User::set_PostTopic(std::string post_Topic) {
    postTopic.push_back(post_Topic);
}

void User::set_Following(User* followedUser) {
    following.push_back(followedUser);
    followedUser->total_followers++;
    total_following++;
}

std::string User::getName() const {
    return Name;
}

int User::get_followersCount() {
    return total_followers;
}

int User::getId() const {
    return ID;
}

User* User::getUserFollowing(int userNumber) {
    if (total_following > userNumber) {
        return following[userNumber];
    } else {
        std::cout << "Error, You exceed the maximum following users" << std::endl;
        return nullptr;  // Return nullptr to indicate an error condition
    }
}

bool User::doYouFollow(User* targetedUser) {
    for (int i = 0; i < total_following; i++) {
        if (following[i] == targetedUser && targetedUser != this) {
            return true;
        }
    }
    return false;
}

void User::printUserSuggestion() {
    for (int i = 0; i < total_following; i++) {
        for (int j = 0; j < following[i]->total_following; j++) {
            User* suggestedUser = following[i]->getUserFollowing(j);
            if (suggestedUser && !doYouFollow(suggestedUser) && (suggestedUser != this)) {
                suggestedUser->PrintUserData();
            }
        }
    }
}
string User::getUserSuggestion() {
    string UserSuggestion = "";
    for (int i = 0; i < total_following; i++) {
        for (int j = 0; j < following[i]->total_following; j++) {
            User* suggestedUser = following[i]->getUserFollowing(j);
            if (suggestedUser && !doYouFollow(suggestedUser) && (suggestedUser != this)) {

                UserSuggestion = UserSuggestion + suggestedUser->getUserDataAsString();
            }
        }
    }
    return UserSuggestion ;
}

void User::PrintUserData() const {
    std::cout << "User ID: " << ID << std::endl;
    std::cout << "User Name: " << Name << std::endl;

    for (size_t i = 0; i < postBody.size(); ++i) {
        std::cout << "Post " << i + 1 << ": " << postBody[i] << std::endl;
    }

    for (size_t i = 0; i < postTopic.size(); ++i) {
        std::cout << "Topic " << i + 1 << ": " << postTopic[i] << std::endl;
    }

    for (size_t i = 0; i < following.size(); ++i) {
        std::cout << "User following: ID " << following[i]->getId() << ", Name " << following[i]->getName() << std::endl;
    }
}
string User::getUserDataAsString() const {
    std::string userData;

    userData += "User ID: " + std::to_string(ID) + "\n";
    userData += "User Name: " + Name + "\n";

    for (size_t i = 0; i < postBody.size(); ++i) {
        userData += "Post " + std::to_string(i + 1) + ": " + postBody[i] + "\n";
    }

    for (size_t i = 0; i < postTopic.size(); ++i) {
        userData += "Topic " + std::to_string(i + 1) + ": " + postTopic[i] + "\n";
    }

    for (size_t i = 0; i < following.size(); ++i) {
        userData += "User following: ID " + std::to_string(following[i]->getId()) +
                    ", Name " + following[i]->getName() + "\n";
    }

    return userData;
}
vector<string>User:: getPostsByKeyword(const string& keyword) const
    {
        vector<string> matchingPosts;
        for (const string& post : postBody)
        {
           size_t pos = post.find(keyword);
            if (pos != string::npos) {
                // Check if it is surrounded by spaces or at the beginning/end
                if ((pos == 0 || isspace(post[pos - 1])) &&
                    (pos + keyword.length() == post.length() || isspace(post[pos + keyword.length()]))) {
                    matchingPosts.push_back(post);
                }
            }
        }
        return matchingPosts;
    }

vector<string> User:: gettopicsByKeyword(const string& keyword) const {
        vector<string> matchingtopics;
        for (const string& topic : postTopic) {
            // Check if the keyword is a whole word in the topic
            size_t pos = topic.find(keyword);
            if (pos != string::npos) {
                // Check if it is surrounded by spaces or at the beginning/end
                if ((pos == 0 || isspace(topic[pos - 1])) &&
                    (pos + keyword.length() == topic.length() || isspace(topic[pos + keyword.length()]))) {
                    matchingtopics.push_back(topic);
                }
            }
        }
        return matchingtopics;
    }


// SocialNetwork Class Implementation
SocialNetwork::~SocialNetwork() {
    // Clean up allocated memory
    for (User* user : users) {
        delete user;
    }
}
vector<User*> SocialNetwork::getUsersAsVector()
{
    return users;

}

User* SocialNetwork::createUser() {
    TotalUser++;
    User* newUser = new User();
    users.push_back(newUser);
    return newUser;
}

User* SocialNetwork::getUser(int user_id) const {
    for (User* user : users) {
        if (user->getId() == user_id) {
            return user;
        }
    }
    return nullptr;
}

User* SocialNetwork::getUserWithMostFollowings() {
    User* userWithMostFollowings = nullptr;
    int maxFollowing = -1;

    for (User* user : users) {
        int followingCount = user->following.size();

        if (followingCount > maxFollowing) {
            maxFollowing = followingCount;
            userWithMostFollowings = user;
        }
    }

    return userWithMostFollowings;
}

User* SocialNetwork::getUserWithMostFollowers() {
    User* userWithMostFollowers = nullptr;
    int maxFollowers = -1;

    for (User* user : users) {
        int followersCount = user->get_followersCount();

        if (followersCount > maxFollowers) {
            maxFollowers = followersCount;
            userWithMostFollowers = user;
        }
    }

    return userWithMostFollowers;
}

void SocialNetwork::printMutualFollowers(User* user1, User* user2) {
    for (int i = 0; i < TotalUser; i++) {
        if (users[i]->doYouFollow(user1) && users[i]->doYouFollow(user2)) {
            users[i]->PrintUserData();
        }
    }
}

string SocialNetwork::getMutualFollowers(User* user1, User* user2) {
    string mutualFollower = "" ;
    for (int i = 0; i < TotalUser; i++) {
        if (users[i]->doYouFollow(user1) && users[i]->doYouFollow(user2)) {

            mutualFollower = mutualFollower + users[i]->getUserDataAsString();
        }
    }
    return mutualFollower;
}
string SocialNetwork:: searchByKeyword(const string& keyword) const
    {
        static string Returnd;

        cout << "Search Results for keyword '" << keyword << "':" << endl;

        for (int i=0; i< TotalUser; i++)
        {
            const vector<string> matchingPosts = users[i]->getPostsByKeyword(keyword);
            const vector<string> matchingtopics = users[i]->gettopicsByKeyword(keyword);


            for (const string& post : matchingPosts)
            {
                //user data
                Returnd=Returnd+"User ID: "+to_string (users[i]->getId())+", User Name: "+users[i]->getName()+"\nPost: "+post+"\n";

            }

            for (const string& topic : matchingtopics)
            {
                //user data
            Returnd=Returnd+"User ID: "+ to_string (users[i]->getId())+", User Name: "+users[i]->getName()+"\\nTopic: "+topic+"\\n";

            }
        }
        return Returnd;
    }

string SocialNetwork::getAllUsersDataAsString()  {

    string allUserData = "";

    for(int i = 0 ;i<TotalUser ; i++)
    {
        allUserData = allUserData + users[i]->getUserDataAsString();
    }


    return allUserData;
}

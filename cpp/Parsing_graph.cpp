
/*******************************************************************
* File Name: Parsing_graph.cpp
********************************************************************/

#include "Parsing_graph.h"


void ParsingXml(string fileContents, SocialNetwork * network)
{

    /* Calculating total user number in the file */
    //int TotalUserNumber = getUserNumber(fileContents);
    int TotalUserNumber = getUserNumber(fileContents);


    /* Create pointers to users with the total number calculated */
    vector <User*> users(TotalUserNumber);

    /* Create Users in the network */

    for(int i = 0 ; i<TotalUserNumber ; i++)
    {

        users[i] = network->createUser();

    }


    int startPos = 0;   /* Variables that represent the position of characters in the XML string */
    int endPos = 0;
    int userCounter = 0 ;

    /* Find opening tag position <user> */
    while ((startPos = fileContents.find("<user>", startPos)) != string::npos)
    {

        /* Find opening tag position <user> */
        startPos += 6;

        /* Find closing tag position </user> */
        endPos = fileContents.find("</user>", startPos);

        string userContent = fileContents.substr(startPos, endPos - startPos);

        /* Find opening tag position <id> */
        int idStartPos = userContent.find("<id>");

        /* Check if the user has id */
        if (idStartPos != string::npos)
        {
            /* Find closing tag position </id> */
            int idEndPos = userContent.find("</id>", idStartPos);

            if (idEndPos != string::npos)
            {
                /* Extract user ID  */
                string userID = userContent.substr(idStartPos + 4, idEndPos - idStartPos - 4);

                /* Save user ID */
                users[userCounter]->set_ID(stoi(userID));

            }
        }

        /* Find opening tag position <name> */
        int nameStartPos = userContent.find("<name>");

        /* Check if the user has name */
        if (nameStartPos != string::npos)
        {
            /* Find closing tag position </name> */
            int nameEndPos = userContent.find("</name>", nameStartPos);

            if (nameEndPos != string::npos)
            {
                /* Extract user name */
                string userName = userContent.substr(nameStartPos + 6, nameEndPos - nameStartPos - 6);

                /* Save user name */
                users[userCounter]->set_Name(userName);
            }
        }

        /* Find opening tag position <posts> */
        int postStartPos = userContent.find("<posts>");

        /* Check if the user has posts */
        if (postStartPos != string::npos)
        {
            /* Find closing tag position </posts> */
            int postEndPos = userContent.find("</posts>", postStartPos);

            if (postEndPos != string::npos)
            {
                string postContent = userContent.substr(postStartPos + 7, postEndPos - postStartPos - 7);

                /* Find opening tag position <post> */
                int postStartPos = postContent.find("<post>");


                while (postStartPos != string::npos)
                {
                    /* Find closing tag position </post> */
                    int postEndPos = postContent.find("</post>", postStartPos);

                    if (postEndPos != string::npos)
                    {
                        string singlePostContent = postContent.substr(postStartPos + 6, postEndPos - postStartPos - 6);

                        /* Find opening tag position <body> */
                        int bodyStartPos = singlePostContent.find("<body>");

                        /* Check if the post has body */
                        if (bodyStartPos != string::npos)
                        {
                            /* Find closing tag position </body> */
                            int bodyEndPos = singlePostContent.find("</body>", bodyStartPos);

                            if (bodyEndPos != string::npos)
                            {
                                /* Extract post body */
                                string postBody = singlePostContent.substr(bodyStartPos + 6, bodyEndPos - bodyStartPos - 6);

                                /* Save user post's body */
                                users[userCounter]->set_PostBody(removeLeadingSpaces(postBody));
                            }
                        }

                        /* Find opening tag position <topics> */
                        int topicsStartPos = singlePostContent.find("<topics>");

                        /* Check if the post has topics */
                        if (topicsStartPos != string::npos)
                        {
                            /* Find closing tag position </topics> */
                            int topicsEndPos = singlePostContent.find("</topics>", topicsStartPos);

                            if (topicsEndPos != string::npos)
                            {
                                string topicsContent = singlePostContent.substr(topicsStartPos + 8, topicsEndPos - topicsStartPos - 8);

                                /* Find opening tag position <topic> */
                                int topicStartPos = topicsContent.find("<topic>");



                                while (topicStartPos != string::npos)
                                {
                                    /* Find closing tag position </topic> */
                                    int topicEndPos = topicsContent.find("</topic>", topicStartPos);

                                    if (topicEndPos != string::npos)
                                    {
                                        /* Extract topic */
                                        string topic = topicsContent.substr(topicStartPos + 7,topicEndPos - topicStartPos - 7);

                                        /* Save user post's topic */
                                        users[userCounter]->set_PostTopic(removeLeadingSpaces(topic));

                                    }

                                    topicStartPos = topicsContent.find("<topic>", topicEndPos);
                                }
                            }
                        }
                    }

                    postStartPos = postContent.find("<post>", postEndPos);

                }
            }
        }
        /* Find opening tag position <followers> */
        int followersStartPos = userContent.find("<followers>");

        /* Check if the user has followers */
        if (followersStartPos != string::npos)
        {
            /* Find closing tag position </followers> */
            int followersEndPos = userContent.find("</followers>", followersStartPos);

            if (followersEndPos != string::npos)
            {
                string followersContent = userContent.substr(followersStartPos + 11, followersEndPos - followersStartPos - 11);

                /* Find opening tag position <follower> */
                int followerStartPos = followersContent.find("<follower>");

                while (followerStartPos != string::npos)
                {
                    /* Find closing tag position </follower> */
                    int followerEndPos = followersContent.find("</follower>", followerStartPos);

                    if (followerEndPos != string::npos)
                    {
                        string followerContent = followersContent.substr(followerStartPos + 10, followerEndPos - followerStartPos - 10);

                        /* Find opening tag position <id> */
                        int followerIdStartPos = followerContent.find("<id>");

                        /* Check if the follower has an ID */
                        if (followerIdStartPos != string::npos)
                        {
                            /* Find closing tag position </id> */
                            int followerIdEndPos = followerContent.find("</id>", followerIdStartPos);

                            if (followerIdEndPos != string::npos)
                            {
                                /* Extract follower ID */
                                string followerID = followerContent.substr(followerIdStartPos + 4, followerIdEndPos - followerIdStartPos - 4);
                                int ID = stoi(followerID);

                                /* Save user's followers */
                                users[userCounter]->set_Following(users[ID-1]);
                            }
                        }
                    }

                    followerStartPos = followersContent.find("<follower>", followerEndPos);
                }
            }
        }

        startPos = endPos + 7;  /* To move to the next user */
        userCounter++;
    }

}

int getUserNumber(string fileContents)
{
    size_t startPos = 0;
    int userCounter = 0;

    while ((startPos = fileContents.find("<user>", startPos)) != string::npos)
    {
        userCounter++;
        startPos += sizeof("<user>") - 1;
    }

    return userCounter;
}
string removeLeadingSpaces(string input)
{
    size_t start = input.find_first_not_of(' ');
    if (start != string::npos)
    {
        return input.substr(start);
    }
    else
    {
        // If the string is all spaces, return an empty string
        return "";
    }
}




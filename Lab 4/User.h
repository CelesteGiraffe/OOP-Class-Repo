#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
private:
    std::string userName;
    std::string email;
    std::vector<User*> friendList;

public:
    User(const std::string& userName, const std::string& email);

    //Methods

    void addFriend(User* newFriend);
    void removeFriend(const std::string& friendName);
    int numFriends() const;
    User* getFriendAt(int index) const;

    //Geters and setters 

    std::string getUserName() const;
    void setUserName(const std::string& name);
    std::string getEmail() const;
    void setEmail(const std::string& mail);
};

#endif

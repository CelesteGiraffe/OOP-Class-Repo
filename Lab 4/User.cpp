#include "user.h"
#include <algorithm>
#include <stdexcept>

User::User(const std::string& userName, const std::string& email) 
    : userName(userName), email(email) {}

void User::addFriend(User* newFriend) {
    if (friendList.size() >= 100) {
        throw std::overflow_error("Friend list is full, you're too popular!");
    }
    friendList.push_back(newFriend);
}

void User::removeFriend(const std::string& friendName) {
    auto it = std::remove_if(friendList.begin(), friendList.end(),
        [&friendName](User* u) { return u->getUserName() == friendName; });

    if (it != friendList.end()) {
        friendList.erase(it, friendList.end());
    }
}

int User::numFriends() const {
    return friendList.size();
}

User* User::getFriendAt(int index) const {
    if (index < 0 || index >= numFriends()) {
        throw std::out_of_range("Index is not in the range of friends.");
    }
    return friendList[index];
}

std::string User::getUserName() const {
    return userName;
}

void User::setUserName(const std::string& name) {
    userName = name;
}

std::string User::getEmail() const {
    return email;
}

void User::setEmail(const std::string& mail) {
    email = mail;
}
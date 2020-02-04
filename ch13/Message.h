#ifndef MESSAGE_H_
#define MESSAGE_H_
#include <set>
#include <string>
#include <iostream>
class Folder;
class Message
{
    friend class Folder;
    friend void swap(Message &lref, Message &rref);

public:
    explicit Message(const std::string &str = std::string()) : content(str) {}
    Message(const Message &);
    Message(Message &&);
    Message &operator=(const Message &);
    Message &operator=(Message &&);

    ~Message();
    void save(Folder &);
    void remove(Folder &);
    void debug();

private:
    std::string content;
    std::set<Folder *> folders;
    void addToFolders(const Message &);
    void removeFromFolders();
    void moveFolders(Message *message);
};
void swap(Message &lref, Message &rref);
#endif
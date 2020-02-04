#include <set>
#include <iostream>
#include "Message.h"
using std::set;
class Message;
class Folder
{
public:
    Folder() = default;
    Folder(const Folder& res) = default;
    void addMsg(Message *ptr);
    void remMsg(Message *ptr);
    void debug();
private:
    set<Message*> messages;
};
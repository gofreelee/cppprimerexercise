#include "Message.h"
#include "Folder.h"

Message::Message(const Message &res) : content(res.content), folders(res.folders)
{
    addToFolders(res);
}

Message &Message::operator=(const Message &rhs)
{
    //先对左侧的对象执行析构
    removeFromFolders();
    content = rhs.content;
    folders = rhs.folders;
    addToFolders(rhs);
    return *this;
}

Message::~Message()
{
    removeFromFolders();
}

void Message::save(Folder &res)
{
    //保存message到res中.
    res.addMsg(this);
    folders.insert(&res);
}

void Message::remove(Folder &res)
{
    res.remMsg(this);
    folders.erase(&res);
}

void Message::addToFolders(const Message &message)
{
    for (auto folder : message.folders)
    {
        folder->addMsg(this);
    }
}

void Message::removeFromFolders()
{
    for (auto folder : folders)
    {
        folder->remMsg(this);
    }
}

void swap(Message &lref, Message &rref)
{
    using std::swap;
    for (auto folder : lref.folders)
        folder->remMsg(&lref);
    for (auto folder : rref.folders)
        folder->remMsg(&rref);
    swap(lref.content, rref.content);
    swap(lref.folders, rref.folders);
    for (auto folder : lref.folders)
        folder->addMsg(&lref);
    for (auto folder : rref.folders)
        folder->addMsg(&rref);
}

Message::Message(Message &&rref) : content(std::move(rref.content))
{
    moveFolders(&rref);
}

void Message::moveFolders(Message *message)
{
    folders = std::move(message->folders);
    for (auto ptr : folders)
    {
        ptr->remMsg(message);
        ptr->addMsg(message);
    }
    message->folders.clear();
}

Message &Message::operator=(Message &&rref)
{
    if (this != &rref)
    {
        removeFromFolders();
        content = std::move(rref.content);
        moveFolders(&rref);
    }
    return *this;
}

void Message::debug()
{
    std::cout << content << std::endl;
}
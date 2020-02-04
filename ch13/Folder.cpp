#include "Folder.h"
void Folder::addMsg(Message *ptr)
{
    messages.insert(ptr);
}

void Folder::remMsg(Message *ptr)
{
    messages.erase(ptr);
}

void Folder::debug()
{
    for (auto ptr : messages)
        ptr->debug();
}
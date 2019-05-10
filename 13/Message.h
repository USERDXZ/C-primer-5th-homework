#include <string>
#include <set>
using namespace std;

class Message;
void swap(Message&,Message&);

class Folder{
    friend void swap(Message& lhs,Message& rhs);
    friend class Message;
public:
    Folder() = default;
    Folder(const Folder&);
    ~Folder();
    Folder& operator=(const Folder&);
private:
    set<Message*> msg;
    void addMsg(Message* m){msg.insert(m);}
    void remMsg(Message* m){msg.erase(m);}
    void add_to_Messages(const Folder&);
    void remove_from_Messages();
};

class Message{
    friend class Folder;
    friend void swap(Message&,Message&);
public:
    explicit Message(const string& s=""):contents(s){}
    Message(const Message&);
    Message(Message&&);
    Message& operator=(const Message&);
    Message& operator=(Message&&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
private:
    string contents;
    set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
    void move_Folders(Message*);
    void addFolder(Folder* f){folders.insert(f);}
    void remFolder(Folder* f){folders.erase(f);}
};

Folder::Folder(const Folder& f):msg(f.msg)
{
    add_to_Messages(f);
}

Folder& operator=(const Folder& f)
{
    remove_from_Messages();
    msg = f.msg;
    add_to_Messages(f);
    return *this;
}

Folder::~Folder()
{
    remove_from_Messages();
}

void Folder::add_to_Messages(const Folder& f)
{
    for(auto m:f.msg)
        m->addFolder(this);
}

void Folder::remove_from_Messages()
{
    for(auto m:msg)
        m->remFolder(this);
}

void Message::save(Folder& f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder& f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message& m)
{
    for(auto f:m.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders();
{
    for(auto f:folders)
        f->remMsg(this);
}

Message::Message(const Message& m):contents(m.contents),folders(m.folders)
{
    add_to_Folders(m);
}

void Message::move_Folders(Message* m)
{
    folders = std::move(m->folders);
    for(auto f : folders){
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

Message::Message(Message&& m):contents(std::move(m.contents))
{
    move_Folders(&m);
}

Message& Message::operator=(const Message& m)
{
    remove_from_Folders();
    contents = m.contents;
    folders = m.folders;
    add_to_Folders(m);
    return *this;
}

Message& Message::operator=(Message&& m)
{
    if(this != &m){
        remove_from_Folders();
        contents = std::move(m.contents);
        move_Folders(&m);
    }
    return *this;
}

Message::~Message()
{
    remove_from_Folders();
}

inline void swap(Message& lhs, Message& rhs)
{
    using std::swap;
    for(auto f:lhs.folders)
        f->remMsg(&lhs);
    for(auto f:rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders,rhs.folders);
    swap(lhs.contents,rhs.contents);
    for(auto f:lhs.folders)
        f->addMsg(&lhs);
    for(auto f:rhs.folders)
        f->addMsg(&rhs);
}
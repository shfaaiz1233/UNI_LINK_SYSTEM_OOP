#pragma once
#include "Post.h"
class Event :
    public Post
{
    string Venue;
    string date;
    static int capacity;
    static int attendee_count;
public:
    Event( const string& tit = {}, const string& desc = {}, const string& crID = {}, const string& st = {}, const string &ven= {}, const string& dt = {});
    string getPostDetails();
    string getReplyDetails();
    void setter_for_Event(const string& tit, const string& desc, const string& crID, const string& st, const string& ven, const string& dt);
    void input();
    bool handleReply(Reply&);
    string getPostID();
    void setStatus(const string&);
};


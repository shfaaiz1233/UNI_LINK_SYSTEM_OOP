#pragma once
#include "Post.h"
class Job :
    public Post
{
    int proposed_price, lowest_offer;
    static int job_number;
public:
    Job(const string& tit = {}, const string& desc = {}, const string& crID = {}, const string& st = "OPEN", int = {}, int = {});
    string getReplyDetails();
    string getPostDetails();
    bool handleReply(Reply&);
    void input();
    void setStatus(const string&);
    string getPostID();
};


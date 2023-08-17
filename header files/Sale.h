#pragma once
#include "Post.h"
class Sale :
    public Post
{
    static int post_number;
    int askingPrice;
    int highestPrice;
    int minimumRaise;
public:
    Sale( const string& tit = {}, const string& desc = {}, const string& crID = {}, const string& st = "OPEN", int = {},int = {});
    bool handleReply(Reply& r);
    string getPostDetails();
    string getReplyDetails();
    void input();
    string getPostID();
    void setStatus(const string&);

};


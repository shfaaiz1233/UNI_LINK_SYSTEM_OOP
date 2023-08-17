#pragma once
#include"Reply.h"
class Post
{
protected:
	string Title;
	string Description;
	string creatorID;
	string ID;
	string status;
	int replySize;
	Reply* replies;
public:
	Post(const string& id = {}, const string& tit = {}, const string& desc = {}, const string& crID = {}, const string& st = "OPEN");
	virtual string getReplyDetails() = 0;
	virtual bool handleReply(Reply&)=0;
	virtual void input();
	virtual string getPostDetails();
	virtual string getPostID()=0;
	virtual void setStatus(const string&)=0;

};


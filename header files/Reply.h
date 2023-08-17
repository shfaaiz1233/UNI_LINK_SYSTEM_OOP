#pragma once
#include<string>
using namespace std;
class Reply
{
protected:
	string postID;
	int value;
	string responderID;
public:
	Reply(const string& = {}, int = {},const string& = {});
	void setPostID(const string&);
	string getPostID()const;
	void setValue(int);
	int getValue()const;
	void setResponserID(const string&);
	string getResponserID()const;
};


#include "Reply.h"
Reply::Reply(const string& pID, int v, const string& rID)
{
	postID = pID;
	value = v;
	responderID = rID;
}
void Reply::setPostID(const string& pID)
{
	postID = pID;
}
string Reply::getPostID()const
{
	return postID;
}
void Reply::setValue(int v)
{
	value = v;
}
int Reply::getValue()const
{
	return value;
}
void Reply::setResponserID(const string& rID)
{
	responderID = rID;
}
string Reply::getResponserID()const
{
	return responderID;
}
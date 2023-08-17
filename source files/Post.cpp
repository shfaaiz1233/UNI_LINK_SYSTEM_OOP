#include "Post.h"
#include<iostream>
Post::Post(const string& id, const string& tit, const string& desc, const string& crID, const string& st)
{
	this->replySize = 0;
	this->ID = id;
	this->Title = tit;
	this->Description = desc;
	this->creatorID = crID;
	this->status = st;
}
string Post::getPostDetails()
{
	return "ID: " + ID + "\n" + "Title: " + Title + "\n" + "Description: " + Description + "\n" + "Creator ID: " + creatorID + "\n" + "Status: " + status + "\n";
}
void Post::input()
{
	string temp;
	getline(cin, temp);
	cout << "Title: ";
	getline(cin, Title);
	cout << "Description: ";
	getline(cin, Description);
	cout << "Creator ID: ";
	getline(cin, creatorID);
	status = "OPEN";
	cout << "Status: " << status << endl;
}
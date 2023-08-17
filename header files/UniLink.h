#pragma once
#include"Post.h"
#include"Job.h"
#include"Sale.h"
#include"Event.h"
class UniLink
{
	Post** allPost;
	int total_Posts;
public:
	UniLink(int = {});
	void Menu();
};


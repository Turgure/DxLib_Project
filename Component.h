#pragma once
#include<string>

class Component abstract{
public:
	virtual ~Component(){}
	virtual void update(){}
	virtual const std::string getKeyString() const = 0;
};

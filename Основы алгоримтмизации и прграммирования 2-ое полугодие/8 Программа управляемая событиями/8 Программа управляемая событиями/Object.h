#pragma once
#include "Event.h"

#include <iostream>
#include <string>

using namespace std;


class Object
{
public:
	Object(void);
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual void HandleEvent(const TEvent& e) = 0;
	virtual ~Object(void);

};
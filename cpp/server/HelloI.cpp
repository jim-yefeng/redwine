/*
 * HelloI.cpp
 *
 *  Created on: Feb 20, 2016
 *      Author: jim
 */

#include <IceUtil/IceUtil.h>
#include <Ice/Ice.h>
#include "HelloI.h"

void HelloI::sayHello(::Ice::Int delay, const ::Ice::Current& cur)
{
	if (delay != 0)
	{
		IceUtil::ThreadControl::sleep(IceUtil::Time::milliSeconds(delay));
	}

	std::cout << "Hello World" << std::endl;
}

void HelloI::shutdown(const ::Ice::Current& cur)
{
	std::cout << "Shutting down..." << std::endl;
	cur.adapter->getCommunicator()->shutdown();
}


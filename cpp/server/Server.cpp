/*
 * Server.cpp
 *
 *  Created on: Feb 20, 2016
 *      Author: jim
 */

#include <Ice/Ice.h>
#include "HelloI.h"

class HelloServer : public Ice::Application
{
public:
	virtual int run(int argc, char* argv[]);
};

int main(int argc, char* argv[])
{
	HelloServer app;
	return app.main(argc, argv, "config.server");
}

int HelloServer::run(int argc, char* argv[])
{
	if (argc > 1)
	{
		std::cerr << appName() << ": too many arguments" << std::endl;
		return EXIT_FAILURE;
	}

	Ice::ObjectAdapterPtr adapter = communicator()->createObjectAdapter("Hello");
	Demo::HelloPtr hello = new HelloI;
	adapter->add(hello, communicator()->stringToIdentity("hello"));
	adapter->activate();

	communicator()->waitForShutdown();
	return EXIT_SUCCESS;
}

/*
 * Client.cpp
 *
 *  Created on: Feb 20, 2016
 *      Author: jim
 */

#include <Ice/Ice.h>

#include <Hello.h>

class HelloClient : public Ice::Application
{
public:
	HelloClient();
	virtual int run(int argc, char* argv[]);

private:
	void menu();
};

HelloClient::HelloClient()
	:Ice::Application(Ice::NoSignalHandling)
{

}

void HelloClient::menu()
{
	std::cout <<
	        "usage:\n"
	        "t: send greeting as twoway\n"
	        "o: send greeting as oneway\n"
	        "O: send greeting as batch oneway\n"
	        "d: send greeting as datagram\n"
	        "D: send greeting as batch datagram\n"
	        "f: flush all batch requests\n"
	        "T: set a timeout\n"
	        "P: set server delay\n"
	        "S: switch secure mode on/off\n"
	        "s: shutdown server\n"
	        "x: exit\n"
	        "?: help\n";
}

int HelloClient::run(int argc, char* argv[])
{
	if (argc > 1)
	{
		std::cerr << appName() << ": too many arguments" << std::endl;
		return EXIT_FAILURE;
	}

	Demo::HelloPrx twoway = Demo::HelloPrx::checkedCast(
			communicator()->propertyToProxy("Hello.Proxy")->ice_twoway()->ice_secure(false));
	if (!twoway)
	{
		std::cerr << argv[0] << ": invalid proxy" << std::endl;
		return EXIT_FAILURE;
	}

	Demo::HelloPrx oneway = twoway->ice_oneway();
	Demo::HelloPrx batchOneway = twoway->ice_batchOneway();
	Demo::HelloPrx datagram = twoway->ice_datagram();
	Demo::HelloPrx batchDatagram = twoway->ice_batchDatagram();

	bool secure = false;
	int delay = 0;
	int timeout = -1;

	menu();

	char c = 'x';
	do
	{
		try
		{
			std::cout << "==> ";
			std::cin >> c;
			if (c == 't')
			{
				twoway->sayHello(delay);
			}
			else if (c == 'o')
			{
				oneway->sayHello(delay);
			}
			else if (c == 'O')
			{
				batchOneway->sayHello(delay);
			}
			else if (c == 'd')
			{
				if (secure)
				{
					std::cout << "secure datagrams are not supported" << std::endl;
				}
				else
				{
					datagram->sayHello(delay);
				}
			}
			else if (c == 'D')
			{
				if (secure)
				{
					std::cout << "secure datagrams are not supported" << std::endl;
				}
				else
				{
					batchDatagram->sayHello(delay);
				}
			}
			else if (c == 'f')
			{
				batchOneway->ice_flushBatchRequests();
				batchDatagram->ice_flushBatchRequests();
			}
			else if (c == 'T')
			{
				if (timeout == -1)
				{
					timeout = 2000;
				}
				else
				{
					timeout = -1;
				}

				twoway = twoway->ice_invocationTimeout(timeout);
				oneway = oneway->ice_invocationTimeout(timeout);
				batchOneway = batchOneway->ice_invocationTimeout(timeout);

				if (timeout == -1)
				{
					std::cout << "timeout is now switched off" << std::endl;
				}
				else
				{
					std::cout << "timeout is now set to 2000ms" << std::endl;
				}
			}
			else if (c == 'P')
			{
				if (delay == 0)
				{
					delay = 2500;
				}
				else
				{
					delay = 0;
				}

				if (delay == 0)
				{
					std::cout << "server delay is now deactived" << std::endl;
				}
				else
				{
					std::cout << "server delay is now set to 2500ms" << std::endl;
				}
			}
			else if (c == 'S')
			{
				secure = !secure;
				twoway = twoway->ice_secure(secure);
				oneway = oneway->ice_secure(secure);
				batchOneway = batchOneway->ice_secure(secure);
				datagram = datagram->ice_secure(secure);
				batchDatagram = batchDatagram->ice_secure(secure);

				if (secure)
				{
					std::cout << "secure is now on" << std::endl;
				}
				else
				{
					std::cout << "secure is now off" << std::endl;
				}
			}
			else if (c == 's')
			{
				twoway->shutdown();
			}
			else if (c == 'x')
			{
				// To exit
			}
			else if (c == '?')
			{
				menu();
			}
			else
			{
				std::cout << "unknown command '" << c << "'" << std::endl;
				menu();
			}
		} catch(const Ice::Exception& ex)
		{
			std::cerr << ex << std::endl;
		}

	} while (std::cin.good() && c != 'x');

	return EXIT_SUCCESS;
}

int main(int argc, char* argv[])
{
	HelloClient app;
	return app.main(argc, argv, "config.client");
}

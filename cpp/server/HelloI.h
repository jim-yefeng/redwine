/*
 * HelloI.h
 *
 *  Created on: Feb 20, 2016
 *      Author: jim
 */

#ifndef CPP_SERVER_HELLOI_H_
#define CPP_SERVER_HELLOI_H_

#include <Hello.h>

class HelloI : public Demo::Hello
{
public:
    virtual void sayHello(::Ice::Int delay, const ::Ice::Current& cur = ::Ice::Current());

    virtual void shutdown(const ::Ice::Current& cur = ::Ice::Current());
};



#endif /* CPP_SERVER_HELLOI_H_ */

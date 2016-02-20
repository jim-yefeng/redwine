// **********************************************************************
//
// Copyright (c) 2003-2015 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.6.1
//
// <auto-generated>
//
// Generated from file `Hello.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include <Hello.h>
#include <IceUtil/PushDisableWarnings.h>
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
#include <Ice/Outgoing.h>
#include <Ice/OutgoingAsync.h>
#include <Ice/BasicStream.h>
#include <IceUtil/Iterator.h>
#include <IceUtil/PopDisableWarnings.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 306
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

namespace
{

const ::std::string __Demo__Hello__sayHello_name = "sayHello";

const ::std::string __Demo__Hello__shutdown_name = "shutdown";

}
::IceProxy::Ice::Object* ::IceProxy::Demo::upCast(::IceProxy::Demo::Hello* p) { return p; }

void
::IceProxy::Demo::__read(::IceInternal::BasicStream* __is, ::IceInternal::ProxyHandle< ::IceProxy::Demo::Hello>& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Demo::Hello;
        v->__copyFrom(proxy);
    }
}

void
IceProxy::Demo::Hello::sayHello(::Ice::Int __p_delay, const ::Ice::Context* __ctx)
{
    ::IceInternal::Outgoing __og(this, __Demo__Hello__sayHello_name, ::Ice::Idempotent, __ctx);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(__p_delay);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    __invoke(__og);
}

::Ice::AsyncResultPtr
IceProxy::Demo::Hello::begin_sayHello(::Ice::Int __p_delay, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __Demo__Hello__sayHello_name, __del, __cookie);
    try
    {
        __result->prepare(__Demo__Hello__sayHello_name, ::Ice::Idempotent, __ctx);
        ::IceInternal::BasicStream* __os = __result->startWriteParams(::Ice::DefaultFormat);
        __os->write(__p_delay);
        __result->endWriteParams();
        __result->invoke();
    }
    catch(const ::Ice::Exception& __ex)
    {
        __result->abort(__ex);
    }
    return __result;
}

void
IceProxy::Demo::Hello::end_sayHello(const ::Ice::AsyncResultPtr& __result)
{
    __end(__result, __Demo__Hello__sayHello_name);
}

void
IceProxy::Demo::Hello::shutdown(const ::Ice::Context* __ctx)
{
    ::IceInternal::Outgoing __og(this, __Demo__Hello__shutdown_name, ::Ice::Normal, __ctx);
    __og.writeEmptyParams();
    __invoke(__og);
}

::Ice::AsyncResultPtr
IceProxy::Demo::Hello::begin_shutdown(const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __Demo__Hello__shutdown_name, __del, __cookie);
    try
    {
        __result->prepare(__Demo__Hello__shutdown_name, ::Ice::Normal, __ctx);
        __result->writeEmptyParams();
        __result->invoke();
    }
    catch(const ::Ice::Exception& __ex)
    {
        __result->abort(__ex);
    }
    return __result;
}

void
IceProxy::Demo::Hello::end_shutdown(const ::Ice::AsyncResultPtr& __result)
{
    __end(__result, __Demo__Hello__shutdown_name);
}

const ::std::string&
IceProxy::Demo::Hello::ice_staticId()
{
    return ::Demo::Hello::ice_staticId();
}

::IceProxy::Ice::Object*
IceProxy::Demo::Hello::__newInstance() const
{
    return new Hello;
}

::Ice::Object* Demo::upCast(::Demo::Hello* p) { return p; }

namespace
{
const ::std::string __Demo__Hello_ids[2] =
{
    "::Demo::Hello",
    "::Ice::Object"
};

}

bool
Demo::Hello::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Demo__Hello_ids, __Demo__Hello_ids + 2, _s);
}

::std::vector< ::std::string>
Demo::Hello::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Demo__Hello_ids[0], &__Demo__Hello_ids[2]);
}

const ::std::string&
Demo::Hello::ice_id(const ::Ice::Current&) const
{
    return __Demo__Hello_ids[0];
}

const ::std::string&
Demo::Hello::ice_staticId()
{
#ifdef ICE_HAS_THREAD_SAFE_LOCAL_STATIC
    static const ::std::string typeId = "::Demo::Hello";
    return typeId;
#else
    return __Demo__Hello_ids[0];
#endif
}

::Ice::DispatchStatus
Demo::Hello::___sayHello(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::Ice::Int __p_delay;
    __is->read(__p_delay);
    __inS.endReadParams();
    sayHello(__p_delay, __current);
    __inS.__writeEmptyParams();
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
Demo::Hello::___shutdown(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    __inS.readEmptyParams();
    shutdown(__current);
    __inS.__writeEmptyParams();
    return ::Ice::DispatchOK;
}

namespace
{
const ::std::string __Demo__Hello_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "sayHello",
    "shutdown"
};

}

::Ice::DispatchStatus
Demo::Hello::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< const ::std::string*, const ::std::string*> r = ::std::equal_range(__Demo__Hello_all, __Demo__Hello_all + 6, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __Demo__Hello_all)
    {
        case 0:
        {
            return ___ice_id(in, current);
        }
        case 1:
        {
            return ___ice_ids(in, current);
        }
        case 2:
        {
            return ___ice_isA(in, current);
        }
        case 3:
        {
            return ___ice_ping(in, current);
        }
        case 4:
        {
            return ___sayHello(in, current);
        }
        case 5:
        {
            return ___shutdown(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
Demo::Hello::__writeImpl(::IceInternal::BasicStream* __os) const
{
    __os->startWriteSlice(ice_staticId(), -1, true);
    __os->endWriteSlice();
}

void
Demo::Hello::__readImpl(::IceInternal::BasicStream* __is)
{
    __is->startReadSlice();
    __is->endReadSlice();
}

void 
Demo::__patch(HelloPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = ::Demo::HelloPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(::Demo::Hello::ice_staticId(), v);
    }
}

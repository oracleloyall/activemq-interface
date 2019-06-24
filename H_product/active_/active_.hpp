#ifndef ACTIVE_HPP_
#define ACTIVE_HPP_
#include"../Register/business.hpp"
#include <activemq/library/ActiveMQCPP.h>
#include <activemq/core/ActiveMQConnectionFactory.h>
#include <activemq/util/Config.h>
#include <decaf/lang/Long.h>
#include <cms/Connection.h>
#include <cms/Session.h>
#include <cms/TextMessage.h>
#include <cms/CMSException.h>
#include <cms/ExceptionListener.h>
#include <cms/MessageListener.h>

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <memory>
#include <unistd.h>
#include "../3rd/rapidjson/document.h"
#include "../3rd/rapidjson/writer.h"
#include "../3rd/rapidjson/stringbuffer.h"


using namespace std;

using namespace activemq::core;
using namespace cms;
using namespace decaf::util;
using namespace decaf::lang;
using namespace decaf::util::concurrent;

using namespace rapidjson;
class active_: public ExceptionListener, public MessageListener
{
public:
	virtual void test_send();
	virtual void test_recv();
	active_();
	~active_();
	bool Reconnect();
	void ProcessMQMsg();
	virtual void onMessage(const Message* message);
	virtual void onException(const CMSException& ex AMQCPP_UNUSED);
	void LoadConfig();
	void SaveConfig();
private:
	string am_url;
	string prod;
	string cons;
	bool reconnecting;
    bool connected;
	Connection* am_conn;
    Session* am_sess;
    Destination* am_dest;
	Destination* am_queue;
    MessageConsumer* am_cons;
    MessageProducer* am_prod;
protected:
};
#endif

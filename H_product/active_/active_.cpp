#include"active_.hpp"
active_::active_():reconnecting(false),connected(false)
{
	try
	{
		//Log("Init activemq library..", H_EMERGENCY);
		activemq::library::ActiveMQCPP::initializeLibrary();
		//		Log("Activemq library include.", H_EMERGENCY);
    }
	catch(Exception* e)
	{
		//Log("Error occured when init activemq: " + e->getMessage(), H_DEADLY);
	   return;
	}
	am_url="failover:(tcp://localhost:61616)";
	cons="NMS";
	prod="adaptor001";
	Reconnect();
}
active_::~active_()
{

}
bool active_::Reconnect()
{
	if (reconnecting) return connected;
		// reconnect
		try
		{
		  	reconnecting = true;
		   	auto_ptr<ConnectionFactory> connectionFactory(ConnectionFactory::createCMSConnectionFactory(am_url));
		   	am_conn = connectionFactory->createConnection();
		   	am_conn->start();

		   	// Create a Session
		   	am_sess = am_conn->createSession(Session::AUTO_ACKNOWLEDGE);

		   	// Create the destination (Topic or Queue)
		  	am_dest = am_sess->createQueue(prod);
		   	am_queue = am_sess->createQueue(cons);
		   	am_cons = am_sess->createConsumer(am_queue);
		   	am_cons->setMessageListener(this);
		   	am_prod = am_sess->createProducer(am_dest);
	//	   	am_prod->setDeliveryMode(DeliveryMode::NON_PERSISTENT);
		   	am_prod->setDeliveryMode(DeliveryMode::PERSISTENT);
		   	connected = true;
		}
		catch(Exception* e)
		{
		  	connected = false;
		}
		reconnecting = false;
		return connected;

}

void active_::onException(const CMSException& ex AMQCPP_UNUSED)
{
	Reconnect();
}
void active_::onMessage(const Message* message)
{
	try
{
	cout<<"has message\n";
	const TextMessage* textMessage = dynamic_cast<const TextMessage*> (message);
    if (textMessage == NULL) return;
    string text = textMessage->getText();//获取到的内容
    string sess_id = textMessage->getStringProperty("sess_id");//命名消息类型
    string cmd_type = textMessage->getStringProperty("cmd_type");//消息类型
    if(cmd_type=="")
    	return;
    if(sess_id=="")
    {
    	cout<<"has message\n";
    	cout<<cmd_type<<endl;
    	//DispathMsgS(cmd_type, text);
    }
    else
    {

    	//DispathMsgS(cmd_type, text);
    }

}
	catch(CMSException& e)
	{
		 e.printStackTrace();
	}
}

void active_::ProcessMQMsg()
{

}
void active_::test_send()
{
    cout<<"test send message\n";
//    string text="zhaoxi";
//    TextMessage* msg = am_sess->createTextMessage(text);
//    if(msg!=NULL)
//    {
//    am_prod->send(msg);
//    delete msg;
//    }
//    else
//    {
//
//    }

    string text2 ="zhaoxi";
    std::auto_ptr<TextMessage> message(am_sess->createTextMessage(text2));
    message->setStringProperty("adpt_id", cons);
    message->setStringProperty("sess_id", "");
    message->setStringProperty("cmd_type", "check_devid");
    am_prod->send(message.get());
}
void active_::test_recv()
{
    cout<<"test recv message\n";
}

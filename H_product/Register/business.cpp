#include"business.hpp"
const int MAX_GPR = 64;
const int MAX_GUID = 32768;
hhmii::THHMII* GPI = NULL;
THCmdResponder* GPR = NULL;
THHMSI* GMI = NULL;
THMsgRecv*		GRV	= NULL;
int GPC = 0;
int GMC = 0;
namespace business
{
	bool inited = false;

	class TUnitController
	{
		public:
		TUnitController();
		~TUnitController();
	};

	void Initialization()
	{
		if (!inited)
		{
			GPI = new hhmii::THHMII(MAX_GPR);
			GPR = new THCmdResponder[MAX_GPR];
//			GUIDs = new THHMSI(MAX_GUID);
			inited = true;
		}
	}

	void Finalization()
	{
		if (inited)
		{
			if (GPI) delete GPI;
			if (GPR) delete [] GPR;
//			if (GUIDs) delete GUIDs;
			inited = false;
		}
	}

	TUnitController::TUnitController()
	{
		// Initialization
		Initialization();
	}

	TUnitController::~TUnitController()
	{
		// Finalization();
		Finalization();
	}

	TUnitController ThisUnit;
}

bool RegisterCommandHandler(const int cmd, THCmdResponder Responder)
{
	business::Initialization();
	hhmii::PHElement p = GPI->Find(cmd);
	if (!p)
	    if (GPI->IsFull())
	    	return false;
	    else
	    {
	    	GPR[GPC] = Responder;
	    	GPI->Add(cmd, GPC++);
	    	return true;
	    }
	else
	{
	    GPR[p->Value] = Responder;
	    return true;
	}
}

bool DispatchCommand(string &  Context, const int cmd)
{
	business::Initialization();
	hhmii::PHElement p = GPI->Find(cmd);
	if (!p)
	{
		//不存在注册的事件处理函数
		return false;
	}
	try
	{
	    //调用对应回调
	    (GPR[p->Value])(Context);
	    return true;
	}
	catch(exception& e)
	{
		string s = e.what();
	    return false;
	}
}

bool RegisterMsgRecv(const string cmd,THMsgRecv recv)
{
	business::Initialization();
	PHElement p = GMI->FindS(cmd);
	if (!p)
	    if (GMI->IsFull())
	    	return false;
	    else
	    {
	    	GRV[GMC] = recv;
	    	GMI->AddS(cmd, GMC++);
	    	return true;
	    }
	else
	{
		GRV[p->Value] = recv;
	    return true;
	}
}


bool DispathMsgS(const string cmd, const string text)
{

	business::Initialization();
	cout<<"dispatch1\n";
	PHElement p = GMI->FindS(cmd);
	cout<<"dispatch2\n";
	if (!p)
	{
		return false;
	}
	try
	{

		(GRV[p->Value])(text);
		return true;
	}
	catch(exception& e)
	{
		string s = e.what();
	    return false;
	}
}

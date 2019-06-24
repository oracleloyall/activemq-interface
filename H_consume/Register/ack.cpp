/*
 * ack.cpp
 *
 *  Created on: 2015-1-19
 *      Author: masanari
 */


#ifndef ACK_CPP_
#define ACK_CPP_

//#include "global.hpp"
#include"business.hpp"
namespace cmd_ack // modify here for each cmd!!
{
	void CommandHandler(string&Context)
	{

	}

	void Initialization()
	{
		RegisterCommandHandler(Auth, &CommandHandler);
	}

	void Finalization()
	{

	}

	class TUnitController
	{
		public:
		TUnitController();
		~TUnitController();
	};

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

#endif /* ACK_CPP_ */



#ifndef _FSM_PARAM_H_
#define _FSM_PARAM_H_

#include "ClassFactory/FactoryManager.h"
namespace FSM_SPACE
{
	class FSMParam
	{
	public:
		explicit FSMParam(int nBehaviourID);
		virtual ~FSMParam();
	public:
		int m_nStateID;
		int m_nBehaviourID;
	};
}
#endif
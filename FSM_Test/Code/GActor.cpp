#include "stdafx.h"
#include "GActor.h"
#include "FSM.h"

namespace FSM_SPACE
{
	GActor::GActor()
	{
		m_Guid = 0;
		m_pFSMCom = NULL;
	}

	GActor::~GActor()
	{
		ReleaseComponents();
	}
	
	void GActor::InitialComponents()
	{
		m_pFSMCom = new FSM();
		if(!m_pFSMCom)
		{
			return;
		}
		m_pFSMCom->SetOwner(this);
		m_pFSMCom->EnterDefaultBehaviour();
	}

	void GActor::ReleaseComponents()
	{
		SAFE_DELETE(m_pFSMCom);
	}

	void GActor::Tick(float fFrameTime)
	{
		m_pFSMCom->Tick(fFrameTime);
	}
}
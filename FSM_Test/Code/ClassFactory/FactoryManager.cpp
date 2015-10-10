#include "stdafx.h"
#include "FactoryManager.h"

namespace FSM_SPACE
{
	void* FactoryManager::New(const char* className)
	{
		if(!className)
		{
			return NULL;
		}
		ClassMap::iterator iter = m_ClassMap.find(className);
		if(iter != m_ClassMap.end())
		{
			if(iter->second)
			{
				return iter->second->NewClass();
			}
		}
		return NULL;
	}

	void FactoryManager::Delete(void* ptr)
	{
		if(ptr)
		{
			delete ptr;
			ptr = NULL;
			//只将new出来的类空间清理掉，声明的类指针信息保留;
		}
	}


	void FactoryManager::AddClassObj(FactoryBase_Arg0* pObj)
	{
		if(!pObj)
		{
			return;
		}
		m_ClassMap.insert(ClassMap::value_type(pObj->ClassName(),pObj));
	}
}
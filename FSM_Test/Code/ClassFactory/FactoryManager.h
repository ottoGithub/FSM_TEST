#ifndef _FACTORY_MANAGER_H_
#define _FACTORY_MANAGER_H_
#include "Singleton.h"
#include <map>
#include <string>

#include "Factory.h"
#include "UtilID.h"

namespace FSM_SPACE
{
	class FactoryManager : public Singleton<FactoryManager>
	{
	public:
		FactoryManager(){}
		~FactoryManager(){}

		void* New(const char* className);
		void Delete(void* ptr);

		void AddClassObj(FactoryBase_Arg0* pObj);

	private:
		typedef std::map<UtilID, FactoryBase_Arg0* > ClassMap;
		ClassMap m_ClassMap;
	};

#define DECLARE_CLASS(className) \
private: \
	class ClassFactory_##className : public Factory_Arg0<className> \
	{\
	public:\
	ClassFactory_##className()\
	{\
	SetClassName(#className); \
	FactoryManager::Instance().AddClassObj(this);\
	}\
	~ClassFactory_##className(){} \
	};\
	static ClassFactory_##className m_Factory_##className;

#define IMPLEMENT_CLASS(className) \
	className::ClassFactory_##className className::m_Factory_##className;

#define FACTORY_NEW(className) (className*)FactoryManager::Instance().New(#className)
#define FACTORY_DELETE(pClass) {if(pClass) {FactoryManager::Instance().Delete(pClass); pClass=NULL;} }
}

#endif
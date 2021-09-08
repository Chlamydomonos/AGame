#ifndef MEMORY__REGISTRY__REGISTRY_ENTRY_H
#define MEMORY__REGISTRY__REGISTRY_ENTRY_H

#include "Registry.h"

#include <QString>

/**
 * @brief ��ע������࣬��Ҫʹ�������
 * 
 * ��������ڱ��� RegistryEntry ��ģ��Ķ�̬��
 */
class BaseRegistryEntry {};

/**
 * @brief ��ע�����������Ҫ��ע��ϵͳ�Զ������ڴ����Ļ��ࡣ
 * 
 * ��ע������һ����ģ�壬���ǲ���ֱ��ʹ�ã���Ҫ��һ����̳С�
 * ģ������Ͳ��� T ���Ǽ̳��������������������һ��ʾ����
 * 
 * @code{.cpp}
 * 
 * class XXX : public RegistryEntry<XXX>
 * 
 * @endcode
 * 
 * ÿһ����ע�����ڴ���֮�󶼻��Զ�����ע��ϵͳ��������Ϸ����ر�ʱȫ���Զ�ɾ����
 * ��ˣ���Ҫ������ע�������͵�ջ������Ҳ��Ҫ�ֶ�ɾ����ע���
 */
template<class T>
class RegistryEntry : public BaseRegistryEntry
{
protected:
	const QString name;
public:
	RegistryEntry(const QString &_name) : name(_name)
	{
		if (!AllRegistries::getInstance()->hasRegistry<T>())
			(new Registry<T>())->registerObject(this);
		else
			AllRegistries::getInstance()->getRegistry<T>()->addEntry(this);
	}
	const QString &getName() const { return name; }
};

#endif // !MEMORY__REGISTRY__REGISTRY_ENTRY_H

#ifndef MEMORY__REGISTRY__REGISTRY_ENTRY_H
#define MEMORY__REGISTRY__REGISTRY_ENTRY_H

#include "Registry.h"

#include <QString>

/**
 * @brief ��ע������࣬��Ҫʹ������ࡣ
 * 
 * ��������ڱ��� RegistryEntry ��ģ��Ķ�̬�ԡ�
 * 
 * @see
 * 
 * RegistryEntry
 */
class BaseRegistryEntry
{
protected:
	const QString name;
public:
	BaseRegistryEntry(const QString &_name) : name(_name) {}
	const QString &getName() const { return name; }
};

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
 * 
 * @attention ÿ����ע���Ӧ����һ�����֡�Ӧȷ��ͬһ���͵Ĳ�ͬ��ע����ӵ�в�ͬ�����֡�
 * 
 * @see Registry
 * @see AllRegistries
 */
template<class T>
class RegistryEntry : public BaseRegistryEntry
{
public:

	/**
	 * @brief ���캯��
	 * 
	 * @param _name ���֣��� RegistryEntry::name ��
	 */
	RegistryEntry(const QString &name) : BaseRegistryEntry(name)
	{
		if (!AllRegistries::getInstance()->hasRegistry<T>())
			(new Registry<T>())->registerObject(static_cast<T*>(this));
		else
			AllRegistries::getInstance()->getRegistry<T>()->registerObject(static_cast<T*>(this));
	}
};

#endif // !MEMORY__REGISTRY__REGISTRY_ENTRY_H

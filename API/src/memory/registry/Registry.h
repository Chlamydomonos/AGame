#ifndef MEMORY__REGISTRY__REGISTRY_H
#define MEMORY__REGISTRY__REGISTRY_H

#include "AllRegistries.h"

template<class T>
class RegistryEntry;

/**
 * @brief ע�����࣬��Ҫʹ�ø��ࡣ
 * 
 * ��������ڱ��� Registry ��ģ��Ķ�̬�ԡ�
 * 
 * @see Registry
 */
class BaseRegistry
{

};

/**
 * @brief ע�������ע��ĳһ��ע�������͵����ж���
 * 
 * ��һ����ע�����ͣ��̳� RegistryEntry ��ģ����ࣩ�ĵ�һ��ʵ��������ʱ��
 * ע����Զ�������������ע��ϵͳ�����ԣ���Ҫ�ֶ�����ע�����Ķ���
 * 
 * @see RegistryEntry
 * @see AllRegistries
 */
template<class T>
class Registry : public BaseRegistry
{
private:
	friend class RegistryEntry<T>;

	QMap<QString, RegistryEntry<T> *> map;

	void registerObject(T *obj)
	{
		if (hasObject(obj->getName()))
			return;

		map.insert(obj->getName(), obj);
	}
public:

	/**
	 * @brief ���캯����
	 * 
	 * ���캯����ע����Զ�����ע��ϵͳ�С�
	 */
	Registry() : BaseRegistry(), map()
	{
		static_assert(std::is_convertible<T*, RegistryEntry<T>*>::value, "Cannot create registry without a registry entry");
		AllRegistries::getInstance()->addRegistry<T>();
	}

	/**
	 * @brief ����������
	 * 
	 * ע�������ʱ������¼�����п�ע����ʵ��Ҳ��ͬʱ��������
	 */
	~Registry()
	{
		for (auto i : map)
			delete i;
	}

	/// �ж�ע������Ƿ�����Ϊ name �Ķ���
	bool hasObject(const QString &name)
	{
		return map.contains(name);
	} 

	/**
	 * @brief ��ע����л�ȡ����
	 * 
	 * @param name ���������
	 * 
	 * @return ������ֶ�Ӧ�Ķ�����ڣ��򷵻ظö���
	 * ������󲻴��ڣ����� nullptr��
	 */
	T *get(const QString &name)
	{
		if (!hasObject(name))
			return nullptr;

		return map[name];
	}
};

#endif // !MEMORY__REGISTRY__REGISTRY_H

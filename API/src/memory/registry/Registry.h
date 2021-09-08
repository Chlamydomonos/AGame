#ifndef MEMORY__REGISTRY__REGISTRY_H
#define MEMORY__REGISTRY__REGISTRY_H

#include "AllRegistries.h"

template<class T>
class RegistryEntry;

/**
 * @brief 注册表基类，不要使用该类。
 * 
 * 此类仅用于保持 Registry 类模板的多态性。
 * 
 * @see Registry
 */
class BaseRegistry
{

};

/**
 * @brief 注册表，用于注册某一可注册项类型的所有对象。
 * 
 * 当一个可注册类型（继承 RegistryEntry 类模板的类）的第一个实例被创建时，
 * 注册表自动被创建并加入注册系统。所以，不要手动创建注册表类的对象。
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
	 * @brief 构造函数。
	 * 
	 * 构造函数把注册表自动加入注册系统中。
	 */
	Registry() : BaseRegistry(), map()
	{
		static_assert(std::is_convertible<T*, RegistryEntry<T>*>::value, "Cannot create registry without a registry entry");
		AllRegistries::getInstance()->addRegistry<T>();
	}

	/**
	 * @brief 析构函数。
	 * 
	 * 注册表析构时，它记录的所有可注册项实例也会同时被析构。
	 */
	~Registry()
	{
		for (auto i : map)
			delete i;
	}

	/// 判断注册表中是否有名为 name 的对象。
	bool hasObject(const QString &name)
	{
		return map.contains(name);
	} 

	/**
	 * @brief 从注册表中获取对象。
	 * 
	 * @param name 对象的名字
	 * 
	 * @return 如果名字对应的对象存在，则返回该对象。
	 * 如果对象不存在，返回 nullptr。
	 */
	T *get(const QString &name)
	{
		if (!hasObject(name))
			return nullptr;

		return map[name];
	}
};

#endif // !MEMORY__REGISTRY__REGISTRY_H

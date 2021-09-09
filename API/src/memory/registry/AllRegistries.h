#ifndef MEMORY__REGISTRY__ALL_REGISTRIES_H
#define MEMORY__REGISTRY__ALL_REGISTRIES_H

#include <QMap>
#include <typeinfo>

class BaseRegistry;

template<class T>
class Registry;

/**
 * @brief 注册系统。
 * 
 * 注册系统用于管理所有可注册项的内存。它是一个单实例类，
 * 具有唯一的静态实例。可以通过注册系统获取任何已经创建的
 * 可注册对象（指 RegistryEntry 子类的对象）。
 * 
 * @warning 不要试图删除注册系统的实例。
 * 
 * @see Registry
 * @see RegistryEntry
 */
class AllRegistries
{
private:
	template<class T>
	friend class Registry;

	static AllRegistries instance;

	QMap<QString, BaseRegistry *> map;

	AllRegistries() : map() {}

	template<class T>
	void addRegistry(Registry<T> *registry)
	{
		if (hasRegistry<T>())
			return;
		map.insert(typeid(Registry<T>).name(), static_cast<BaseRegistry *>(registry));
	}
public:
	~AllRegistries();

	static AllRegistries *getInstance() { return &instance; } ///< 获取注册系统实例。

	/// 判断类型 T 的注册表是否存在。
	template<class T>
	bool hasRegistry()
	{
		return map.contains(typeid(Registry<T>).name());
	}

	/**
	 * @brief 获取类型 T 的注册表。
	 * 
	 * @return 如果类型 T 的注册表存在，则返回相应注册表。
	 * 否则，返回 nullptr 。
	 */
	template<class T>
	Registry<T> *getRegistry()
	{
		if (!hasRegistry<T>())
			return nullptr;
		return static_cast<Registry<T> *>(map[typeid(Registry<T>).name()]);
	}
};

#endif // !MEMORY__REGISTRY__ALL_REGISTRIES_H

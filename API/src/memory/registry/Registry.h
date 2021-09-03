#ifndef MEMORY__REGISTRY__REGISTRY_H
#define MEMORY__REGISTRY__REGISTRY_H

#include "AllRegistries.h"

template<class T>
class RegistryEntry;

class BaseRegistry
{

};

template<class T>
class Registry : public BaseRegistry
{
private:
	QMap<QString, RegistryEntry<T> *> map;
public:
	Registry() : BaseRegistry(), map()
	{
		static_assert(std::is_convertible<T*, RegistryEntry<T>*>::value, "Cannot create registry without a registry entry");
		AllRegistries::getInstance()->addRegistry<T>();
	}

	~Registry()
	{
		for (auto i : map)
			delete i;
	}

	bool hasObject(const QString &name)
	{
		return map.contains(name);
	}

	T *get(const QString &name)
	{
		if (!hasObject(name))
			return nullptr;

		return map[name];
	}

	void registerObject(T *obj)
	{
		if (hasObject(obj->getName()))
			return;

		map.insert(obj->getName(), obj);
	}
};

#endif // !MEMORY__REGISTRY__REGISTRY_H

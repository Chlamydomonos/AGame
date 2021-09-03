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
		AllRegistries::getInstance()->addRegistry<T>();
	}

	~Registry()
	{
		for (auto i : map)
			delete i;
	}

	bool hasEntry(const QString &name)
	{
		return map.count(name);
	}

	RegistryEntry<T> *getEntry(const QString &name)
	{
		if (!hasEntry(name))
			return nullptr;

		return map[name];
	}

	void addEntry(RegistryEntry<T> *entry)
	{
		if (hasEntry(entry->getName()))
			return;

		map.insert(entry->getName(), entry);
	}
};

#endif // !MEMORY__REGISTRY__REGISTRY_H

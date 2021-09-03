#ifndef MEMORY__REGISTRY__REGISTRY_ENTRY_H
#define MEMORY__REGISTRY__REGISTRY_ENTRY_H

#include "Registry.h"

#include <QString>

template<class T>
class RegistryEntry
{
protected:
	const QString name;
public:
	RegistryEntry(const QString &_name) : name(_name)
	{
		if (!AllRegistries::getInstance()->hasRegistry<T>())
			(new Registry<T>())->addEntry(this);
		else
			AllRegistries::getInstance()->getRegistry<T>()->addEntry(this);
	}
	const QString &getName() const { return name; }
};

#endif // !MEMORY__REGISTRY__REGISTRY_ENTRY_H

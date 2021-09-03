#ifndef MEMORY__REGISTRY__ALL_REGISTRIES_H
#define MEMORY__REGISTRY__ALL_REGISTRIES_H

#include <QMap>
#include <typeinfo>

class BaseRegistry;

template<class T>
class Registry;

class AllRegistries
{
private:
	static AllRegistries instance;
	QMap<QString, BaseRegistry *> map;
public:
	AllRegistries() : map() {}
	~AllRegistries();

	static AllRegistries *getInstance() { return &instance; }

	template<class T>
	bool hasRegistry()
	{
		return map.count(typeid(Registry<T>).name());
	}

	template<class T>
	Registry<T> *getRegistry()
	{
		if (!hasRegistry<T>())
			return nullptr;
		return static_cast<Registry<T> *>(map[typeid(Registry<T>).name()]);
	}

	template<class T>
	void addRegistry()
	{
		if (hasRegistry<T>())
			return;
		map.insert(typeid(Registry<T>).name(), static_cast<BaseRegistry *>(new Registry<T>()));
	}
};

#endif // !MEMORY__REGISTRY__ALL_REGISTRIES_H

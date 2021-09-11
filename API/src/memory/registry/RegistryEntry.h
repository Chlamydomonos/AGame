#ifndef MEMORY__REGISTRY__REGISTRY_ENTRY_H
#define MEMORY__REGISTRY__REGISTRY_ENTRY_H

#include "Registry.h"

#include <QString>

/**
 * @brief 可注册项基类，不要使用这个类。
 * 
 * 此类仅用于保持 RegistryEntry 类模板的多态性。
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
 * @brief 可注册项，是所有需要用注册系统自动管理内存的类的基类。
 * 
 * 可注册项是一个类模板，但是不能直接使用，需要由一个类继承。
 * 模板的类型参数 T 就是继承它的类的类名。以下是一个示例：
 * 
 * @code{.cpp}
 * 
 * class XXX : public RegistryEntry<XXX>
 * 
 * @endcode
 * 
 * 每一个可注册项在创建之后都会自动加入注册系统，并在游戏程序关闭时全部自动删除。
 * 因此，不要创建可注册项类型的栈变量，也不要手动删除可注册项。
 * 
 * @attention 每个可注册项都应该有一个名字。应确保同一类型的不同可注册项拥有不同的名字。
 * 
 * @see Registry
 * @see AllRegistries
 */
template<class T>
class RegistryEntry : public BaseRegistryEntry
{
public:

	/**
	 * @brief 构造函数
	 * 
	 * @param _name 名字，见 RegistryEntry::name 。
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

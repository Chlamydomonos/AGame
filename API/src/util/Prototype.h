#ifndef UTIL__PROTOTYPE_H
#define UTIL__PROTOTYPE_H

#include <assert.h>

class BasePrototype {};

template <class T>
class BaseItemWithPrototype;

template<class T>
class Prototype : public BasePrototype
{
protected:
	Prototype()
	{
		static_assert(std::is_convertible<T *, BaseItemWithPrototype<T> *>::value, "Cannot create prototype without an item with prototype");
	}
public:
	virtual T *create() const = 0;
};

#endif // !UTIL__PROTOTYPE_H

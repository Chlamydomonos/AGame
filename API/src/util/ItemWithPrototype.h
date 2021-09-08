#ifndef UTIL__ITEM_WITH_PROTOTYPE_H
#define UTIL__ITEM_WITH_PROTOTYPE_H

template<class T>
class Prototype;

class BaseBaseItemWithPrototype {};

template <class T>
class BaseItemWithPrototype : public BaseBaseItemWithPrototype {};

template <class T, class PrototypeClass>
class ItemWithPrototype : public BaseItemWithPrototype<T>
{
protected:
	const PrototypeClass *prototype;
	ItemWithPrototype(const PrototypeClass *_prototype) : prototype(_prototype)
	{
		static_assert(std::is_convertible<PrototypeClass *, Prototype<T> *>::value, "Wrong prototype class");
	}
};

#endif // !UTIL__ITEM_WITH_PROTOTYPE_H


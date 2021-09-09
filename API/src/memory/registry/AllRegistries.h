#ifndef MEMORY__REGISTRY__ALL_REGISTRIES_H
#define MEMORY__REGISTRY__ALL_REGISTRIES_H

#include <QMap>
#include <typeinfo>

class BaseRegistry;

template<class T>
class Registry;

/**
 * @brief ע��ϵͳ��
 * 
 * ע��ϵͳ���ڹ������п�ע������ڴ档����һ����ʵ���࣬
 * ����Ψһ�ľ�̬ʵ��������ͨ��ע��ϵͳ��ȡ�κ��Ѿ�������
 * ��ע�����ָ RegistryEntry ����Ķ��󣩡�
 * 
 * @warning ��Ҫ��ͼɾ��ע��ϵͳ��ʵ����
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

	static AllRegistries *getInstance() { return &instance; } ///< ��ȡע��ϵͳʵ����

	/// �ж����� T ��ע����Ƿ���ڡ�
	template<class T>
	bool hasRegistry()
	{
		return map.contains(typeid(Registry<T>).name());
	}

	/**
	 * @brief ��ȡ���� T ��ע���
	 * 
	 * @return ������� T ��ע�����ڣ��򷵻���Ӧע���
	 * ���򣬷��� nullptr ��
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

#ifndef MEMORY__SERIALIZABLE_OBJECT_H
#define MEMORY__SERIALIZABLE_OBJECT_H

#include "PacketBuffer.h"

#include <QObject>

/**
 * @brief 可序列化对象
 * 
 * 可序列化对象具有 serialize() 和 deserialize() 成员函数，可以把自身序列化为数据或用序列化的数据更新自身。
 * 
 * 一般来说，可序列化对象的子类应该具有一个默认构造函数。
 */
class SerializableObject : public QObject
{
public:
	SerializableObject(QObject *parent = nullptr) : QObject(parent) {}
public slots:
	/**
	* @brief 把自身序列化。
	*
	* 覆写该函数时，应该使用 PacketBuffer 类的相关方法序列化自身所有需要同步的成员变量。
	*
	* @attention 覆写该函数时，应该调用父类的同名函数以序列化父类成员。
	*
	* @attention 覆写 serialize() 和 deserialize() 函数时，应注意两函数对各变量序列化 /
	* 反序列化的顺序有要求，且序列化和反序列化的顺序相反。
	*
	* @param buffer 储存序列化数据的容器
	*/
	virtual void serialize(PacketBuffer *buffer) {};

	/**
	 * @brief 把数据反序列化以更新自身。
	 *
	 * 覆写该函数时，应该使用 PacketBuffer 类的相关方法反序列化自身所有需要同步的成员变量。
	 *
	 * @note dataRecieved() 信号在该函数执行之前发出。
	 *
	 * @attention 覆写该函数时，应该调用父类的同名函数以反序列化父类成员。
	 *
	 * @attention 覆写 serialize() 和 deserialize() 函数时，应注意两函数对各变量序列化 /
	 * 反序列化的顺序有要求，且序列化和反序列化的顺序相反。
	 *
	 * @param buffer 储存反序列化数据的容器
	 */
	virtual void deserialize(PacketBuffer *buffer) {};
};

#endif // !MEMORY__SERIALIZABLE_OBJECT_H

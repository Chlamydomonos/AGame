#ifndef NETWORK__SYNC_OBJECT_H
#define NETWORK__SYNC_OBJECT_H

#include "../memory/SerializableObject.h"
#include "../util/ItemWithPrototype.h"
#include "SyncObjectProrotype.h"
#include "NetworkHandler.h"
#include "Side.h"

/**
* @brief 同步对象，是所有需要在服务器与客户端之间同步的对象的基类。
* 
* 同步对象继承了 SerializableObject 类，可以通过 serialize() 和 deserialize() 方法把自身序列化，以使其可以通过网络发送。
* 同步对象的子类必须覆写 serialize() 和 deserialize() 方法。
* 
* 在同步对象的子类需要同步数据时，需要手动调用 notifyChange() 函数或者发送 changed() 信号。
* 此时，该对象会执行 serialize() 方法，把自己序列化并发送给另一端。
* 从网络接收到数据时，同步对象会自动执行 deserialize() 方法，把收到的数据反序列化并更新自身，
* 并在同时发出 dataRecieved() 信号。
*/
class SyncObject : public SerializableObject
{

	Q_OBJECT
public:
	SyncObject(const BaseSyncObjectPrototype *_prototype, Side _side = Side::SERVER, QObject *parent = nullptr);
public slots:
	/**
	 * @brief 标记对象为已更改。
	 * 
	 * 具体效果为发送 changed() 信号。
	 */
	void notifyChange() { emit changed(); }
signals:
	/**
	 * @brief 该信号发出后，对象将被序列化并通过网络同步。
	 * 
	 * @attention 发出该信号后， serialize() 方法会立刻执行，但数据可能不会立刻被发送。
	 */
	void changed();

	/**
	 * @brief 从网络上接收到数据后，该信号会发送。
	 * 
	 * @note deserialize() 方法在该信号发送前执行。
	 */
	void dataRecieved();

	/**
	 * @brief 对象通过网络创建后，该信号会发送。
	 */
	void createdByNet();
protected:
	Side side;
private slots:
	void notifyDataRecieve() { emit dataRecieved(); }
	void notifyCreatedByNet() { emit createdByNet(); }
	void sendSelf();
private:
	friend class NetworkHandler;
	template<class T>
	friend class SyncObjectPrototype;
	size_t connection;
	const BaseSyncObjectPrototype *prototype;
};

#endif // !NETWORK__SYNC_OBJECT_H

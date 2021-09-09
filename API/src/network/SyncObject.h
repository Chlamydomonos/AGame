#ifndef NETWORK__SYNC_OBJECT_H
#define NETWORK__SYNC_OBJECT_H

#include "../memory/SerializableObject.h"
#include "../util/ItemWithPrototype.h"
#include "SyncObjectProrotype.h"
#include "NetworkHandler.h"
#include "Side.h"

/**
* @brief ͬ��������������Ҫ�ڷ�������ͻ���֮��ͬ���Ķ���Ļ��ࡣ
* 
* ͬ������̳��� SerializableObject �࣬����ͨ�� serialize() �� deserialize() �������������л�����ʹ�����ͨ�����緢�͡�
* ͬ�������������븲д serialize() �� deserialize() ������
* 
* ��ͬ�������������Ҫͬ������ʱ����Ҫ�ֶ����� notifyChange() �������߷��� changed() �źš�
* ��ʱ���ö����ִ�� serialize() ���������Լ����л������͸���һ�ˡ�
* ��������յ�����ʱ��ͬ��������Զ�ִ�� deserialize() ���������յ������ݷ����л�����������
* ����ͬʱ���� dataRecieved() �źš�
*/
class SyncObject : public SerializableObject
{

	Q_OBJECT
public:
	SyncObject(const BaseSyncObjectPrototype *_prototype, Side _side = Side::SERVER, QObject *parent = nullptr);
public slots:
	/**
	 * @brief ��Ƕ���Ϊ�Ѹ��ġ�
	 * 
	 * ����Ч��Ϊ���� changed() �źš�
	 */
	void notifyChange() { emit changed(); }
signals:
	/**
	 * @brief ���źŷ����󣬶��󽫱����л���ͨ������ͬ����
	 * 
	 * @attention �������źź� serialize() ����������ִ�У������ݿ��ܲ������̱����͡�
	 */
	void changed();

	/**
	 * @brief �������Ͻ��յ����ݺ󣬸��źŻᷢ�͡�
	 * 
	 * @note deserialize() �����ڸ��źŷ���ǰִ�С�
	 */
	void dataRecieved();

	/**
	 * @brief ����ͨ�����紴���󣬸��źŻᷢ�͡�
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

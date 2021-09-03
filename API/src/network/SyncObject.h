#ifndef NETWORK__SYNC_OBJECT_H
#define NETWORK__SYNC_OBJECT_H

#include "../memory/SerializableObject.h"

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
	 * @note deserialize() �����ڸ��źŷ��ͺ�ִ�С�
	 */
	void dataRecieved();
private slots:
	void notifyDataRecieve() { emit dataRecieved(); }
};

#endif // !NETWORK__SYNC_OBJECT_H

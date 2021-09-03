#ifndef MEMORY__SERIALIZABLE_OBJECT_H
#define MEMORY__SERIALIZABLE_OBJECT_H

#include "PacketBuffer.h"

#include <QObject>

/**
 * @brief �����л�����
 * 
 * �����л�������� serialize() �� deserialize() ��Ա���������԰��������л�Ϊ���ݻ������л������ݸ�������
 * 
 * һ����˵�������л����������Ӧ�þ���һ��Ĭ�Ϲ��캯����
 */
class SerializableObject : public QObject
{
public:
	SerializableObject(QObject *parent = nullptr) : QObject(parent) {}
public slots:
	/**
	* @brief ���������л���
	*
	* ��д�ú���ʱ��Ӧ��ʹ�� PacketBuffer �����ط������л�����������Ҫͬ���ĳ�Ա������
	*
	* @attention ��д�ú���ʱ��Ӧ�õ��ø����ͬ�����������л������Ա��
	*
	* @attention ��д serialize() �� deserialize() ����ʱ��Ӧע���������Ը��������л� /
	* �����л���˳����Ҫ�������л��ͷ����л���˳���෴��
	*
	* @param buffer �������л����ݵ�����
	*/
	virtual void serialize(PacketBuffer *buffer) {};

	/**
	 * @brief �����ݷ����л��Ը�������
	 *
	 * ��д�ú���ʱ��Ӧ��ʹ�� PacketBuffer �����ط��������л�����������Ҫͬ���ĳ�Ա������
	 *
	 * @note dataRecieved() �ź��ڸú���ִ��֮ǰ������
	 *
	 * @attention ��д�ú���ʱ��Ӧ�õ��ø����ͬ�������Է����л������Ա��
	 *
	 * @attention ��д serialize() �� deserialize() ����ʱ��Ӧע���������Ը��������л� /
	 * �����л���˳����Ҫ�������л��ͷ����л���˳���෴��
	 *
	 * @param buffer ���淴���л����ݵ�����
	 */
	virtual void deserialize(PacketBuffer *buffer) {};
};

#endif // !MEMORY__SERIALIZABLE_OBJECT_H

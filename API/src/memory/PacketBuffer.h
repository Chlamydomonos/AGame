#ifndef MEMORY__PACKET_BUFFER_H
#define MEMORY__PACKET_BUFFER_H

#include <QVector>
#include <QString>

/**
 * @brief �洢���л����ݵ�������
 * 
 * write() �� writeString() ģ�庯���������л����ݣ� read() �� readString() ģ�庯�����ڷ����л����ݡ�
 * 
 * getData() �������ڻ�ȡ���л������ݣ� pushData() �������ڽ������л������ݡ�
 */
class PacketBuffer
{
private:
	QVector<char> data;
public:
	PacketBuffer() : data() {}
	~PacketBuffer() = default;

	/**
	 * @brief �����ݵ�ĩ�˷����л�һ��������ɾ����Ӧ�����ݡ�
	 * 
	 * @attention ʹ�øú���ʱһ��Ҫ��֤���ݵ�ĩ��ȷʵ��ʹ�õĶ�Ӧ�������ݡ�
	 * 
	 * @note ʹ�� readString() ���������л��ַ�����
	 * Ҫ�����л����Ӷ�����Ҫʹ�ö���̳� SyncObject �ಢִ�иö���� SyncObject::deserialize() ������
	 * 
	 * @return �����л������ݡ�
	 */
	template<typename T>
	T read()
	{
		T out;
		char *buf = (char *)(&out);
		size_t len = sizeof(T);
		for (size_t i = 0; i < len; i++)
		{
			buf[len - i - 1] = *(data.end());
			data.pop_back();
		}
		return out;
	}

	/**
	 * @brief ���л�һ����������������ӵ����ݵ�ĩ�ˡ�
	 * 
	 * @attention ֻ���øú������л��������ͻ��߲���ָ��Ķ���
	 * 
	 * @note ʹ�� writeString() �������л��ַ�����
	 * Ҫ���л����Ӷ�����Ҫʹ�ö���̳� SyncObject �ಢִ�иö���� SyncObject::serialize() ������
	 * 
	 * @param value Ҫ���л����ַ�����
	 */
	template<typename T>
	void write(const T &value)
	{
		const char *buf = (char *)(&value);
		size_t len = sizeof(T);
		for (size_t i = 0; i < len; i++)
		{
			data.push_back(buf[i]);
		}
	}

	/**
	 * @brief ������ĩ�˷����л�һ���ַ�������ɾ����Ӧ���ݡ�
	 * 
	 * @attention ʹ�øú���ʱһ��Ҫ��֤���ݵ�ĩ��ȷʵ���ַ���ʹ�õĶ�Ӧ�������ݡ�
	 * 
	 * @return �����л����ַ�����
	 */
	QString readString();

	/**
	 * @brief ���л�һ���ַ�������������ӵ����ݵ�ĩ�ˡ�
	 * 
	 * @param value Ҫ���л����ַ�����
	 */
	void writeString(const QString &value);

	/**
	 * @brief ��ȡ���л������ݡ�
	 * 
	 * @return ��ǰ���ݡ� 
	 */
	const char *getData() const;

	/**
	 * @brief �����ݵ�ĩβ׷�����л������ݡ�
	 * 
	 * @param data Ҫ׷�ӵ����ݡ�
	 * @param len ׷�����ݵĳ��ȡ�
	 */
	void pushData(const char *data, int len);
};

#endif // !MEMORY__PACKET_BUFFER_H

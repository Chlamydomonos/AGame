#ifndef MEMORY__PACKET_BUFFER_H
#define MEMORY__PACKET_BUFFER_H

#include <QVector>
#include <QString>

/**
 * @brief 存储序列化数据的容器。
 * 
 * write() 和 writeString() 模板函数用于序列化数据， read() 和 readString() 模板函数用于反序列化数据。
 * 
 * getData() 函数用于获取序列化的数据， pushData() 函数用于接收序列化的数据。
 */
class PacketBuffer
{
private:
	QVector<char> data;
public:
	PacketBuffer() : data() {}
	~PacketBuffer() = default;

	/**
	 * @brief 从数据的末端反序列化一个变量并删除对应的数据。
	 * 
	 * @attention 使用该函数时一定要保证数据的末端确实是使用的对应类型数据。
	 * 
	 * @note 使用 readString() 方法反序列化字符串。
	 * 要反序列化复杂对象，需要使该对象继承 SyncObject 类并执行该对象的 SyncObject::deserialize() 方法。
	 * 
	 * @return 反序列化的数据。
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
	 * @brief 序列化一个变量并把数据添加到数据的末端。
	 * 
	 * @attention 只能用该函数序列化基本类型或者不含指针的对象。
	 * 
	 * @note 使用 writeString() 方法序列化字符串。
	 * 要序列化复杂对象，需要使该对象继承 SyncObject 类并执行该对象的 SyncObject::serialize() 方法。
	 * 
	 * @param value 要序列化的字符串。
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
	 * @brief 从数据末端反序列化一个字符串，并删除对应数据。
	 * 
	 * @attention 使用该函数时一定要保证数据的末端确实是字符串使用的对应类型数据。
	 * 
	 * @return 反序列化的字符串。
	 */
	QString readString();

	/**
	 * @brief 序列化一个字符串并把数据添加到数据的末端。
	 * 
	 * @param value 要序列化的字符串。
	 */
	void writeString(const QString &value);

	/**
	 * @brief 获取序列化的数据。
	 * 
	 * @return 当前数据。 
	 */
	const char *getData() const;

	/**
	 * @brief 在数据的末尾追加序列化的数据。
	 * 
	 * @param data 要追加的数据。
	 * @param len 追加数据的长度。
	 */
	void pushData(const char *data, int len);
};

#endif // !MEMORY__PACKET_BUFFER_H

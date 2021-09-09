#include "PacketBuffer.h"

QString PacketBuffer::readString()
{
    QByteArray out;
    size_t len = read<size_t>();
    out.resize(len);
    for (size_t i = 0; i < len; i++)
    {
        out[len - i - 1] = data[data.length() - 1];
        data.pop_back();
    }
    return QString(out);
}

void PacketBuffer::writeString(const QString &value)
{
    QByteArray temp = value.toLocal8Bit();
    size_t len = temp.length();
    for (size_t i = 0; i < len; i++)
    {
        data.push_back(temp[i]);
    }
    write<size_t>(len);
}

const char *PacketBuffer::getData() const
{
    return (const char*)(&(data[0]));
}

void PacketBuffer::pushData(const char *data, int len)
{
    for (int i = 0; i < len; i++)
        this->data.push_back(data[i]);
}

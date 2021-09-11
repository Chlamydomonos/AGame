#ifndef UTIL__PATH_FINDER_H
#define UTIL__PATH_FINDER_H

class ServerMap;
#include <QSet>
#include <QMap>
#include <QQueue>

class PathFinder
{
private:
	struct SearchNode
	{
		unsigned long long index;
		int steps;
		unsigned long long from;
	};
	ServerMap *map;
	QMap<unsigned long long, SearchNode> searchMap;
	QQueue<SearchNode> searchQueue;
public:
	PathFinder(ServerMap *_map) : map(_map), searchMap(), searchQueue() {}
	void clear();
	void search(unsigned long long from, int range);
	QSet<unsigned long long> getAvailablePositions();
	QVector<unsigned long long> getPathTo(unsigned long long target);
};

#endif // !UTIL__PATH_FINDER_H

#ifndef UTIL__TARGET_FINDER_H
#define UTIL__TARGET_FINDER_H

class ServerMap;
#include <QSet>
#include <QMap>
#include <QQueue>

class TargetFinder
{
private:
	struct SearchNode
	{
		unsigned long long index;
		int steps;
		bool isTarget;
	};
	ServerMap *map;
	QMap<unsigned long long, SearchNode> searchMap;
	QQueue<SearchNode> searchQueue;
public:
	TargetFinder(ServerMap *_map) : map(_map), searchMap(), searchQueue() {}
	void clear();
	void search(unsigned long long from, int range);
	QSet<unsigned long long> getAvailablePositions();
};

#endif // !UTIL__TARGET_FINDER_H

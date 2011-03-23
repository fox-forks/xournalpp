/*
 * Xournal++
 *
 * Knows the positions of pages in the view
 *
 * @author Xournal Team
 * http://xournal.sf.net
 *
 * @license GPL
 */

#ifndef __PAGEPOSITIONHANDLER_H__
#define __PAGEPOSITIONHANDLER_H__
// TODO: AA: type check

#include <glib.h>

class PageView;
class PagePosition;
class PagePositionCache;

class PagePositionHandler {
public:
	PagePositionHandler();
	virtual ~PagePositionHandler();

public:
	void update(PageView ** viewPages, int viewPagesLen, int maxY);

	PageView * getViewAt(int x, int y, PagePositionCache * cache = NULL);

private:
	void addData(PagePosition * p);
	void allocDataSize(int size);
	void freeData();

	PagePosition * binarySearch(PagePosition ** sortedArray, int first, int last, int y, int & index);

private:
	int dataCount;
	int dataAllocSize;
	PagePosition ** data;

	int maxY;
};

#endif /* __PAGEPOSITIONHANDLER_H__ */

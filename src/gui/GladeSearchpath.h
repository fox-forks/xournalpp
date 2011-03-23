/*
 * GladeSearchpath.h
 *
 *  Created on: 04.03.2011
 *      Author: andreas
 */

#ifndef __GLADESEARCHPATH_H__
#define __GLADESEARCHPATH_H__

#include <glib.h>
#include "../util/XournalType.h"

class GladeSearchpath {
public:
	GladeSearchpath();
	virtual ~GladeSearchpath();

public:
	void addSearchDirectory(const char * directory);
	char * findFile(const char * subdir, const char * file);

private:
	XOJ_TYPE_ATTRIB;

	/**
	 * Search directory for icons and Glade files
	 */
	GList * directories;
};

#endif /* __GLADESEARCHPATH_H__ */

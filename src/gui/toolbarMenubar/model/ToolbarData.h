/*
 * Xournal++
 *
 * Toolbar definitions model
 *
 * @author Xournal Team
 * http://xournal.sf.net
 *
 * @license GPL
 */

#ifndef __TOOLBARDATA_H__
#define __TOOLBARDATA_H__

#include <glib.h>
#include "../../../util/String.h"
#include <vector>

#include "ToolbarEntry.h"
// TODO: AA: type check

class ToolbarData {
public:
	ToolbarData(bool predefined);

public:
	String getName();
	void setName(String name);
	String getId();

	void load(GKeyFile * config, const char * group);

	bool isPredefined();
private:
	String id;
	String name;
	std::vector<ToolbarEntry> contents;

	bool predefined;

	friend class ToolbarModel;
	friend class ToolMenuHandler;
};

#endif /* __TOOLBARDATA_H__ */

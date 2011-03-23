/*
 * Xournal++
 *
 * XML Writer helper class
 *
 * @author Xournal Team
 * http://xournal.sf.net
 *
 * @license GPL
 */
// TODO: AA: type check

#ifndef __TEXTATTRIBUTE_H__
#define __TEXTATTRIBUTE_H__

#include "Attribute.h"

class TextAttribute: public Attribute {
public:
	TextAttribute(const char * name, const char * value);
	virtual ~TextAttribute();

public:
	virtual void writeOut(OutputStream * out);

private:
	char * value;
};


#endif /* __TEXTATTRIBUTE_H__ */

#ifndef __MODULE_H__
#define __MODULE_H__

class Module
{
public:

	virtual bool Init() { return true; }
	virtual int Update()	{ return UPDATE_CONTINUE;	}
	virtual bool CleanUp() { return true; }
};

#endif // __MODULE_H__
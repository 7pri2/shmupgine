#ifndef __script_H__
#define __script_H__	

#include "attribute.h"
#include <functional>

class script : public attribute {
public:
	script();
	script(entity* parent);
	~script();

	void	setLoopFunction(std::function<void()> loop);

private:
	virtual void 			run();
	virtual script*			make_copy(entity* newparent);
	std::function<void()> 	m_loop;
};

#endif

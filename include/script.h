#ifndef __SCRIPT_H__
#define __SCRIPT_H__	

#include "attribute.h"
#include <functional>

class script : public attribute {
public:
	script();
	script(entity* parent);
	~script();

	void	set_loop_function(std::function<void()> loop);

private:
	virtual void 			run();
	virtual script*			make_copy(entity* newparent);
	std::function<void()> 	m_loop;
};

#endif

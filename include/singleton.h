#ifndef __SINGLETON_H__
#define __SINGLETON_H__

template <typename T>
class singleton {
public:
	static T& instance() {
		static T instance;
		return instance;
	}
};

#endif

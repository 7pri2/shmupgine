/**
 * \file	singleton.h
 * \brief	Contains the implementation of the class singleton
 * \author	Cyprien Eymond Laritaz
 */

#ifndef __SINGLETON_H__
#define __SINGLETON_H__

/**
 * \brief	Implementation of the design pattern singleton for the parts of the 
 * 			engine that need to be single
 */

template <typename T>
class singleton {
public:
	static T& instance() {
		static T instance;
		return instance;
	}
};

#endif

#ifdef DEBUG

#include "debug.h"

std::string debug::done		= "\033[;32m done.\n\033[0m";
std::string debug::title	= "\033[4;39m\033[1;37m";
std::string debug::reset 	= "\033[0m";
std::string debug::attr 	= "\033[;33m";
std::string debug::success 	= "\033[;32m";
std::string debug::error 	= "\033[;31m";
std::string debug::scene 	= "\033[;35m";

std::string debug::ptitle(std::string msg) {
	return debug::title + msg + debug::reset;
}

std::string debug::pattr(std::string msg) {
	return debug::attr + msg + debug::reset;
}

std::string debug::psuccess(std::string msg) {
	return debug::success + msg + debug::reset;
}

std::string debug::perror(std::string msg) {
	return debug::error + msg + debug::reset;
}

std::string debug::pscene(std::string msg) {
	return debug::scene + msg + debug::reset;
}
#endif

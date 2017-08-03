#ifndef __BAR_H__
#define __BAR_H__

#include <SFML/Graphics.hpp>
#include <iostream>

#define DRAW_LOCK 		true
#define NO_LOCK			0
#define INFINITE_LOCK	-1

typedef enum {
	BAR,
	NUMBERS,
	BAR_AND_NUMBERS
} drawmode;

class bar {
public:
	bar();
	~bar();

	bool		f_draw_lock;
	bool		f_draw_bar;
	drawmode	f_draw_mode;

	void		subtract(int amount);
	void		add(int amount);

	void		lock(int ms_time, bool draw_or_not = false);

	void 		update();

private:
	int			m_value;
	int			m_max_value;
	int			m_min_value;
	int 		m_regen_per_seconds;

	sf::Clock 	m_regen_timer;

	sf::Clock	m_lock_timer;
	int			m_lock_ms;

	bool		m_backup_draw_lock_flag;
	std::string m_lock_text;

	bool		f_locked;
};

#endif

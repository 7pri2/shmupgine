#include "bar.h"

bar::bar() {
	f_draw_lock = true;
	f_draw_bar = true;
	f_draw_mode = BAR_AND_NUMBERS;
	m_lock_text = "Locked";
	m_lock_ms = NO_LOCK;
	m_value = 100;
	m_max_value = 100;
	m_min_value = 0;
	m_regen_per_seconds = 0;
}

bar::~bar() {

}

void bar::subtract(int amount) {
	std::cout << " = " << m_value << " = ";
	if(!f_locked)  {
		m_value -= amount;
		if(m_value > m_max_value)
			m_value = m_max_value;
		else if(m_value < m_min_value)
			m_value = m_min_value;
	}
}

void bar::add(int amount) {
	if(!f_locked)  {
		m_value += amount;
		if(m_value > m_max_value)
			m_value = m_max_value;
		else if(m_value < m_min_value)
			m_value = m_min_value;
	}
}

void bar::lock(int ms_time, bool draw_or_not) {
	m_backup_draw_lock_flag = f_draw_lock;
	f_locked = true;
	f_draw_lock = draw_or_not;
	m_lock_ms = ms_time;
	m_lock_timer.restart();
}

void bar::update() {
	if(m_lock_timer.getElapsedTime().asMilliseconds() >= m_lock_ms && m_lock_ms != INFINITE_LOCK) {
		f_locked = false;
		f_draw_lock = m_backup_draw_lock_flag;
	}
}

#ifndef SINGLETON_H
#define SINGLETON_H

#include <QWidget>

template <class T> class Singleton {
public:
    static T* Instance() {
        static T* instance = new T;
        return instance;
    }

private:
    T& operator= (const T&){}
};

#endif // SINGLETON_H

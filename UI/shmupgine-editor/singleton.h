#ifndef SINGLETON_H
#define SINGLETON_H

template <typename T>
class singleton {
public:
    static T& instance() {
        static T the_instance;
        return the_instance;
    }
};

#endif // SINGLETON_H

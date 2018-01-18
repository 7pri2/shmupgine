#ifndef PROJECT_DATA_H
#define PROJECT_DATA_H

#define BTN_WIDTH 32

#include <QString>
#include "singleton.h"

enum {
    NAME            = 0,
    WORKING_DIR     = 1,
    COMPILER_PATH   = 2,
    COMPILER_FLAGS  = 3,
    ENGINE_PATH     = 4,
    MAKE_PATH       = 5
};

class project_data : public Singleton<project_data> {
    friend class Singleton<project_data>;

public:
    QString prj_config[6];
    bool    f_config_changed;

private:
    project_data();
    ~project_data();
};

#endif // PROJECT_DATA_H

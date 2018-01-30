#ifndef P_ENTITIES_COLLECTION_H
#define P_ENTITIES_COLLECTION_H

#include "singleton.h"
#include "entities_attributes_panel.h"

class p_entities_collection : public entities_attributes_panel, public Singleton<p_entities_collection> {
    Q_OBJECT

    friend class Singleton<p_entities_collection>;

private:
    p_entities_collection(QWidget* parent = 0);
    p_entities_collection(const p_entities_collection&);
    virtual ~p_entities_collection();
};

#endif // P_ENTITIES_COLLECTION_H

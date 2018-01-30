#include "select_window.h"

select_window::select_window(QString title, QStandardItemModel* model) : QWidget() {
    listview        = new QListView(this);
    btn_ok          = new QPushButton(tr("Select"), this);
    btn_cancel      = new QPushButton(tr("Cancel"), this);
    lay_mainlayout  = new QVBoxLayout(this);
    lay_btn         = new QHBoxLayout(this);

    btn_ok->setEnabled(false);

    setWindowTitle(title);

    lay_btn->addWidget(btn_ok);
    lay_btn->addWidget(btn_cancel);
    lay_mainlayout->addWidget(listview);
    lay_mainlayout->addLayout(lay_btn);

    listview->setModel(model);
    listview->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(btn_cancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(listview, SIGNAL(clicked(QModelIndex)), this, SLOT(item_selected()));
}

select_window ::~select_window () {}

void select_window ::item_selected() {
    btn_ok->setEnabled(true);
}

QString select_window ::get_selected_item() {
    return listview->currentIndex().data().toString();
}

QPushButton* select_window ::get_select_btn() {
    return btn_ok;
}

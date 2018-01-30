#ifndef SELECT_WINDOW_H
#define SELECT_WINDOW_H

#include <QWidget>
#include <QListView>
#include <QStandardItemModel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class select_window : public QWidget {
    Q_OBJECT
public:
    explicit select_window(QString title, QStandardItemModel*);
    ~select_window();

    QString         get_selected_item();
    QPushButton*    get_select_btn();

signals:

public slots:
    void            item_selected();

private:
    QListView*      listview;
    QPushButton*    btn_ok;
    QPushButton*    btn_cancel;
    QVBoxLayout*    lay_mainlayout;
    QHBoxLayout*    lay_btn;
};

#endif // SELECT_WINDOW_H

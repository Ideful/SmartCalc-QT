#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QVector"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


extern "C" {
    #include "../calc.h"
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;

private slots:
    void digitnums();
    void on_push_clear_string_clicked();
    void on_push_clear_sym_clicked();
    void on_push_calculate_clicked();
    void on_makegraph_clicked();
};
#endif // MAINWINDOW_H

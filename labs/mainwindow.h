#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>


class MainWindow : public QMainWindow
{
Q_OBJECT

public:
MainWindow(QWidget *parent = nullptr);
~MainWindow();
private:
QLabel *label_;
QGroupBox *gradientGroupBox_;

};
#endif // MAINWINDOW_H

#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "YTitleBar.h"

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
    MainWindow(QWidget* parent = Q_NULLPTR);
    ~MainWindow();

private:
    void setTitleBar(YTitleBar* titleBar);
    void paintEvent(QPaintEvent* event);

private slots:
    void onButtonMinClicked();
    void onButtonRestoreClicked();
    void onButtonMaxClicked();
    void onButtonCloseClicked();

protected:
    Ui::MainWindowClass ui;
    YTitleBar* titleBar;
};

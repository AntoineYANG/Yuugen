#pragma once

#include <QtWidgets/QMainWindow>
#include "YTitleBar.h"
#include <qlayout.h>
#include <QTextEdit>

class MainWindow : public QWidget {
	Q_OBJECT

public:
    MainWindow(QWidget* parent = Q_NULLPTR);
    ~MainWindow();

private:
    void connectionsInit();
    void uiInit();
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void windowInit();
    void editInit();
    void setFontSize(int pt);

    struct WindowSnapshot {
        int px;
        int py;
        int pxx;
        int pyy;
        int hx;
        int hy;
        int kx;
        int ky;
    } windowSnapshot;

private slots:
    void onButtonCloseClicked();
    void onButtonMaxClicked();
    void onButtonMinClicked();
    void onButtonRestoreClicked();
    void onEdit();

protected:
    QVBoxLayout* bodyLayout;
    QSpacerItem* spring;
    QWidget* container;
    QHBoxLayout* containerLayout;
    YTitleBar* titleBar;
    QTextEdit* editZone;
    QFont font;
    QStringList fontFamilies;
};

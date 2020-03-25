#include "MainWindow.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QPainter>
#include <QFile>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    this->ui.setupUi(this);
    // FramelessWindowHint�������ô���ȥ���߿�;
    // WindowMinimizeButtonHint ���������ڴ�����С��ʱ��������������ڿ�����ʾ��ԭ����;
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    // ���ô��ڱ���͸��;
    setAttribute(Qt::WA_TranslucentBackground);

    // ��ʼ��������;
    this->setTitleBar(new YTitleBar(this));
}

MainWindow::~MainWindow() {}

void MainWindow::setTitleBar(YTitleBar* titleBar) {
    this->titleBar = titleBar;
    this->titleBar->move(0, 0);

    connect(this->titleBar, SIGNAL(signalButtonMinClicked()), this, SLOT(onButtonMinClicked()));
    connect(this->titleBar, SIGNAL(signalButtonRestoreClicked()), this, SLOT(onButtonRestoreClicked()));
    connect(this->titleBar, SIGNAL(signalButtonMaxClicked()), this, SLOT(onButtonMaxClicked()));
    connect(this->titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
}

void MainWindow::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    QPainterPath pathBack;
    pathBack.setFillRule(Qt::WindingFill);
    pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.fillPath(pathBack, QBrush(QColor(238, 223, 204)));

    return QWidget::paintEvent(event);
}

void MainWindow::onButtonMinClicked() {
    showMinimized();
}

void MainWindow::onButtonRestoreClicked() {
    QPoint windowPos;
    QSize windowSize;
    this->titleBar->loadSnapshot(windowPos, windowSize);
    this->setGeometry(QRect(windowPos, windowSize));
}

void MainWindow::onButtonMaxClicked() {
    this->titleBar->saveSnapshot(this->pos(), QSize(this->width(), this->height()));
    QRect desktopRect = QApplication::desktop()->availableGeometry();
    QRect FactRect = QRect(desktopRect.x() - 3, desktopRect.y() - 3, desktopRect.width() + 6, desktopRect.height() + 6);
    setGeometry(FactRect);
}

void MainWindow::onButtonCloseClicked() {
    close();
}
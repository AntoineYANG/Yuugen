#include "MainWindow.h"
#include "CodeHighlight.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QPainter>
#include <QFile>
#include <string>
#include <QMouseEvent>
#include <QTextEdit>
using std::string;
using std::to_string;

MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
    // hide default border
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);

    this->uiInit();

    this->connectionsInit();

    this->onEdit();
}

MainWindow::~MainWindow() {}

void MainWindow::connectionsInit() {
    connect(this->titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
    connect(this->titleBar, SIGNAL(signalButtonMaxClicked()), this, SLOT(onButtonMaxClicked()));
    connect(this->titleBar, SIGNAL(signalButtonMinClicked()), this, SLOT(onButtonMinClicked()));
    connect(this->titleBar, SIGNAL(signalButtonRestoreClicked()), this, SLOT(onButtonRestoreClicked()));
    connect(this->editZone, SIGNAL(textChanged()), this, SLOT(this->onEdit()));
}

void MainWindow::windowInit() {
    // Shape
    this->resize(1200, 734);
    this->setMinimumSize(648, 428);

    // Paint background
    QColor color = QColor(13, 13, 20);
    QPalette p = this->palette();
    p.setColor(QPalette::Window, color);
    this->setPalette(p);

    // Toppest container
    this->bodyLayout = new QVBoxLayout(this);
    this->bodyLayout->setMargin(1);
    this->setLayout(this->bodyLayout);

    // Display title bar
    this->titleBar = new YTitleBar(this);
    this->titleBar->move(0, 0);

    // Title spacer
    this->spring = new QSpacerItem(1, 36, QSizePolicy::Maximum, QSizePolicy::Fixed);
    this->bodyLayout->addSpacerItem(this->spring);

    // Container
    this->container = new QWidget(this);
    this->containerLayout = new QHBoxLayout(this->container);
    this->container->setLayout(this->containerLayout);
    this->bodyLayout->addWidget(this->container);
}

void MainWindow::editInit() {
    // Set font family
    this->fontFamilies.append("Operator Mono Book");
    this->fontFamilies.append("Courier");
    this->font.setFamilies(fontFamilies);
    this->font.setStyleHint(QFont::Monospace);
    this->font.setFixedPitch(true);
    this->font.setWeight(56);

    // Set style
    this->editZone = new QTextEdit(this->container);
    this->editZone->setStyleSheet(
        "border: none;"
        "background-color: rgb(49,50,51);"
        "selected-background-color: rgb(245,241,240);"
        "color: rgb(245,241,240);"
        "selection-color: rgb(245,241,240);"
    );
    this->setFontSize(10);

    // Add to widget
    this->containerLayout->addWidget(this->editZone);

    // Get focused
    this->editZone->setFocus();
}

void MainWindow::setFontSize(int pt) {
    this->font.setPointSize(pt);
    this->editZone->setFont(this->font);

    // Set width of tab
    const int tabStop = 4;
    QFontMetrics metrics(this->font);
    this->editZone->setTabStopWidth(tabStop * metrics.width(' '));
}

void MainWindow::uiInit() {
    // Initialize window geometry
    this->windowInit();
    // Initialize edit zone
    this->editInit();
}

void MainWindow::mousePressEvent(QMouseEvent* event) {
    this->windowSnapshot = {
        event->x(),
        event->y(),
        this->geometry().width(),
        this->geometry().height(),
        this->geometry().x(),
        this->geometry().y(),
        this->cursor().pos().x(),
        this->cursor().pos().y()
    };
    this->update();
}

void MainWindow::mouseMoveEvent(QMouseEvent* event) {
    if (this->windowSnapshot.px > this->windowSnapshot.pxx - 10
        && this->windowSnapshot.px < this->windowSnapshot.pxx
        && this->windowSnapshot.py < this->windowSnapshot.pyy - 10
        && this->windowSnapshot.py >= 0) {
        this->setGeometry(
            this->windowSnapshot.hx,
            this->windowSnapshot.hy,
            this->windowSnapshot.pxx + event->x() - this->windowSnapshot.px,
            this->windowSnapshot.pyy
        );
    }
    if (this->windowSnapshot.py > this->windowSnapshot.pyy - 10
        && this->windowSnapshot.py < this->windowSnapshot.pyy
        && this->windowSnapshot.px < this->windowSnapshot.pxx - 10
        && this->windowSnapshot.px >= 0) {
        this->setGeometry(
            this->windowSnapshot.hx,
            this->windowSnapshot.hy,
            this->windowSnapshot.pxx,
            this->windowSnapshot.pyy + event->y() - this->windowSnapshot.py
        );
    }
    if (this->windowSnapshot.py > this->windowSnapshot.pyy - 10
        && this->windowSnapshot.py < this->windowSnapshot.pyy
        && this->windowSnapshot.px > this->windowSnapshot.pxx - 10
        && this->windowSnapshot.px < this->windowSnapshot.pxx) {
        this->setGeometry(
            this->windowSnapshot.hx,
            this->windowSnapshot.hy,
            this->windowSnapshot.pxx + event->x() - this->windowSnapshot.px,
            this->windowSnapshot.pyy + event->y() - this->windowSnapshot.py
        );
    }
    if (this->windowSnapshot.px > 0
        && this->windowSnapshot.px < this->windowSnapshot.pxx - 10
        && this->windowSnapshot.py > 0
        && this->windowSnapshot.py < this->windowSnapshot.pyy - 10) {
        this->setGeometry(
            this->windowSnapshot.hx + cursor().pos().x() - this->windowSnapshot.kx,
            this->windowSnapshot.hy + cursor().pos().y() - this->windowSnapshot.ky,
            this->windowSnapshot.pxx,
            this->windowSnapshot.pyy
        );
    }
    update();
}

void MainWindow::onButtonMinClicked() {
    this->showMinimized();
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
    this->setGeometry(FactRect);
}

void MainWindow::onButtonCloseClicked() {
    this->close();
}

void MainWindow::onEdit() {
    QStringList keywordPatterns;
    keywordPatterns << "\\bchar\\b" << "\\bclass\\b" << "\\bconst\\b"
        << "\\bdouble\\b" << "\\benum\\b" << "\\bexplicit\\b"
        << "\\bfriend\\b" << "\\binline\\b" << "\\bint\\b"
        << "\\blong\\b" << "\\bnamespace\\b" << "\\boperator\\b"
        << "\\bprivate\\b" << "\\bprotected\\b" << "\\bpublic\\b"
        << "\\bshort\\b" << "\\bsignals\\b" << "\\bsigned\\b"
        << "\\bslots\\b" << "\\bstatic\\b" << "\\bstruct\\b"
        << "\\btemplate\\b" << "\\btypedef\\b" << "\\btypename\\b"
        << "\\bunion\\b" << "\\bunsigned\\b" << "\\bvirtual\\b"
        << "\\bvoid\\b" << "\\bvolatile\\b" << "\\bbool\\b";

    CodeHighlight* h = new CodeHighlight(
        keywordPatterns,
        QBrush(QColor(196, 220, 164)),
        this->editZone->document()
    );
    /*
    const int len = this->ui.YEditor->toPlainText().split("\n").length();
    string content = "";
    for (int i = 0; i < len || i < 1; i++) {
        content += to_string(i + 1) + "\n";
    }
    this->ui.YIndexView->setPlainText(QString::fromStdString(content));
    this->ui.YIndexView->setFixedWidth(to_string(len + 1).length() * 8 + 20);
    */
}

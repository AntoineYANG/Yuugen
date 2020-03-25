#include "YTitleBar.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QFile>
#include <QMouseEvent>

#define BUTTON_HEIGHT 36        // 按钮高度;
#define BUTTON_WIDTH 36         // 按钮宽度;
#define TITLE_HEIGHT 36         // 标题栏高度;

YTitleBar::YTitleBar(QWidget* parent): QWidget(parent), m_isPressed(false) {
    this->setFixedHeight(TITLE_HEIGHT);
    initControl();
    initConnections();
}

YTitleBar::~YTitleBar() {}

// 初始化控件;
void YTitleBar::initControl() {
    this->setStyleSheet("QWidget{background:rgb(23,23,24);color:rgb(254,252,242);}");

    m_pIcon = new QLabel;
    m_pIcon->setFixedSize(TITLE_HEIGHT, TITLE_HEIGHT);
    // set icon
    QPixmap titleIcon(":/images/public/images/icon0.png");
    m_pIcon->setPixmap(titleIcon.scaled(QSize(28, 28)));
    m_pIcon->setMargin(4);
    m_pIcon->setStyleSheet("QLabel{background:rgb(23,23,24);}");

    m_pTitleContent = new QLabel;
    m_pTitleContent->setContentsMargins(6, 6, 6, 6);
    m_pTitleContent->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    m_pTitleContent->setFixedHeight(TITLE_HEIGHT);
    // set font of the header
    QFont font = m_pTitleContent->font();
    font.setPointSize(12);
    m_pTitleContent->setObjectName("TitleContent");
    m_pTitleContent->setFont(font);
    m_pTitleContent->setStyleSheet("QLabel{background:rgb(23,23,24);color:rgb(254,252,242);}");
    this->setTitle("Yuugen: an editor");

    const QString buttonStyle = "QPushButton{border:none;background:rgb(23,23,24);}\
        QPushButton:hover{border:none;background:rgb(32,32,34);}\
        QPushButton:pressed{border:none;background:rgb(42,42,48);}";

    m_pButtonMin = new QPushButton;
    m_pButtonMin->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_pButtonMin->setObjectName("ButtonMin");
    m_pButtonMin->setIconSize(QSize(24, 24));
    m_pButtonMin->setIcon(QIcon(":/images/public/images/minimize.png"));
    m_pButtonMin->setToolTip(QStringLiteral("最小化"));
    m_pButtonMin->setStyleSheet(buttonStyle);

    m_pButtonRestore = new QPushButton;
    m_pButtonRestore->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_pButtonRestore->setObjectName("ButtonRestore");
    m_pButtonRestore->setIconSize(QSize(24, 24));
    m_pButtonRestore->setIcon(QIcon(":/images/public/images/restore.png"));
    m_pButtonRestore->setToolTip(QStringLiteral("还原"));
    m_pButtonRestore->setVisible(false);
    m_pButtonRestore->setStyleSheet(buttonStyle);

    m_pButtonMax = new QPushButton;
    m_pButtonMax->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_pButtonMax->setObjectName("ButtonMax");
    m_pButtonMax->setIconSize(QSize(24, 24));
    m_pButtonMax->setIcon(QIcon(":/images/public/images/maximize.png"));
    m_pButtonMax->setToolTip(QStringLiteral("最大化"));
    m_pButtonMax->setStyleSheet(buttonStyle);

    m_pButtonClose = new QPushButton;
    m_pButtonClose->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_pButtonClose->setObjectName("ButtonClose");
    m_pButtonClose->setIconSize(QSize(24, 24));
    m_pButtonClose->setIcon(QIcon(":/images/public/images/close.png"));
    m_pButtonClose->setToolTip(QStringLiteral("关闭"));
    m_pButtonClose->setStyleSheet(buttonStyle);

    QHBoxLayout* mylayout = new QHBoxLayout(this);
    mylayout->addWidget(m_pIcon);
    mylayout->addWidget(m_pTitleContent);
    mylayout->addWidget(m_pButtonMin);
    mylayout->addWidget(m_pButtonRestore);
    mylayout->addWidget(m_pButtonMax);
    mylayout->addWidget(m_pButtonClose);

    mylayout->setContentsMargins(0, 0, 0, 0);
    mylayout->setSpacing(0);

    this->setFixedHeight(TITLE_HEIGHT);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

// 信号槽的绑定;
void YTitleBar::initConnections() {
    connect(m_pButtonMin, SIGNAL(clicked()), this, SLOT(onButtonMinClicked()));
    connect(m_pButtonRestore, SIGNAL(clicked()), this, SLOT(onButtonRestoreClicked()));
    connect(m_pButtonMax, SIGNAL(clicked()), this, SLOT(onButtonMaxClicked()));
    connect(m_pButtonClose, SIGNAL(clicked()), this, SLOT(onButtonCloseClicked()));
}

// 设置标题内容;
void YTitleBar::setTitle(QString titleContent) {
    // 设置标题内容;
    m_titleContent = titleContent;
    m_pTitleContent->setText(titleContent);
}

// 保存窗口最大化前窗口的位置以及大小;
void YTitleBar::saveSnapshot(const QPoint point, const QSize size) {
    m_restorePos = point;
    m_restoreSize = size;
}

// 获取窗口最大化前窗口的位置以及大小;
void YTitleBar::loadSnapshot(QPoint& point, QSize& size) {
    point = m_restorePos;
    size = m_restoreSize;
}

// 绘制标题栏背景色
void YTitleBar::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    QPainterPath pathBack;
    pathBack.setFillRule(Qt::WindingFill);
    pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // 当窗口最大化或者还原后，窗口长度变了，标题栏的长度应当一起改变
    const int width = this->parentWidget()->width();
    if (this->width() != width) {
        this->setFixedWidth(width);
    }
    QWidget::paintEvent(event);
}

// 双击响应事件，主要是实现双击标题栏进行最大化和最小化操作
void YTitleBar::mouseDoubleClickEvent(QMouseEvent* event) {
    // 通过最大化按钮的状态判断当前窗口是处于最大化还是原始大小状态;
    // 或者通过单独设置变量来表示当前窗口状态;
    if (m_pButtonMax->isVisible()) {
        onButtonMaxClicked();
    } else {
        onButtonRestoreClicked();
    }

    return QWidget::mouseDoubleClickEvent(event);
}

// 以下通过mousePressEvent、mouseMoveEvent、mouseReleaseEvent三个事件实现了鼠标拖动标题栏移动窗口的效果;
void YTitleBar::mousePressEvent(QMouseEvent* event) {
    // 在窗口最大化时禁止拖动窗口;
    if (m_pButtonMax->isVisible()) {
        m_isPressed = true;
        m_startMovePos = event->globalPos();
    }

    return QWidget::mousePressEvent(event);
}

void YTitleBar::mouseMoveEvent(QMouseEvent* event) {
    if (m_isPressed) {
        QPoint movePoint = event->globalPos() - m_startMovePos;
        QPoint widgetPos = this->parentWidget()->pos();
        m_startMovePos = event->globalPos();
        this->parentWidget()->move(widgetPos.x() + movePoint.x(), widgetPos.y() + movePoint.y());
    }
    return QWidget::mouseMoveEvent(event);
}

void YTitleBar::mouseReleaseEvent(QMouseEvent* event) {
    m_isPressed = false;
    return QWidget::mouseReleaseEvent(event);
}

// 以下为按钮操作响应的槽;
void YTitleBar::onButtonMinClicked() {
    emit signalButtonMinClicked();
}

void YTitleBar::onButtonRestoreClicked() {
    m_pButtonRestore->setVisible(false);
    m_pButtonMax->setVisible(true);
    emit signalButtonRestoreClicked();
}

void YTitleBar::onButtonMaxClicked() {
    m_pButtonMax->setVisible(false);
    m_pButtonRestore->setVisible(true);
    emit signalButtonMaxClicked();
}

void YTitleBar::onButtonCloseClicked() {
    emit signalButtonCloseClicked();
}

// 该方法主要是让标题栏中的标题显示为滚动的效果;
void YTitleBar::onRollTitle() {
    static int nPos = 0;
    QString titleContent = m_titleContent;
    // 当截取的位置比字符串长时，从头开始;
    if (nPos > titleContent.length()) {
        nPos = 0;
    }

    m_pTitleContent->setText(titleContent.mid(nPos));
    nPos++;
}

#include "YTitleBar.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QFile>
#include <QMouseEvent>

#define BUTTON_HEIGHT 36        // ��ť�߶�;
#define BUTTON_WIDTH 36         // ��ť���;
#define TITLE_HEIGHT 36         // �������߶�;

YTitleBar::YTitleBar(QWidget* parent): QWidget(parent), m_isPressed(false) {
    this->setFixedHeight(TITLE_HEIGHT);
    initControl();
    initConnections();
}

YTitleBar::~YTitleBar() {}

// ��ʼ���ؼ�;
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
    m_pButtonMin->setToolTip(QStringLiteral("��С��"));
    m_pButtonMin->setStyleSheet(buttonStyle);

    m_pButtonRestore = new QPushButton;
    m_pButtonRestore->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_pButtonRestore->setObjectName("ButtonRestore");
    m_pButtonRestore->setIconSize(QSize(24, 24));
    m_pButtonRestore->setIcon(QIcon(":/images/public/images/restore.png"));
    m_pButtonRestore->setToolTip(QStringLiteral("��ԭ"));
    m_pButtonRestore->setVisible(false);
    m_pButtonRestore->setStyleSheet(buttonStyle);

    m_pButtonMax = new QPushButton;
    m_pButtonMax->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_pButtonMax->setObjectName("ButtonMax");
    m_pButtonMax->setIconSize(QSize(24, 24));
    m_pButtonMax->setIcon(QIcon(":/images/public/images/maximize.png"));
    m_pButtonMax->setToolTip(QStringLiteral("���"));
    m_pButtonMax->setStyleSheet(buttonStyle);

    m_pButtonClose = new QPushButton;
    m_pButtonClose->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_pButtonClose->setObjectName("ButtonClose");
    m_pButtonClose->setIconSize(QSize(24, 24));
    m_pButtonClose->setIcon(QIcon(":/images/public/images/close.png"));
    m_pButtonClose->setToolTip(QStringLiteral("�ر�"));
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

// �źŲ۵İ�;
void YTitleBar::initConnections() {
    connect(m_pButtonMin, SIGNAL(clicked()), this, SLOT(onButtonMinClicked()));
    connect(m_pButtonRestore, SIGNAL(clicked()), this, SLOT(onButtonRestoreClicked()));
    connect(m_pButtonMax, SIGNAL(clicked()), this, SLOT(onButtonMaxClicked()));
    connect(m_pButtonClose, SIGNAL(clicked()), this, SLOT(onButtonCloseClicked()));
}

// ���ñ�������;
void YTitleBar::setTitle(QString titleContent) {
    // ���ñ�������;
    m_titleContent = titleContent;
    m_pTitleContent->setText(titleContent);
}

// ���洰�����ǰ���ڵ�λ���Լ���С;
void YTitleBar::saveSnapshot(const QPoint point, const QSize size) {
    m_restorePos = point;
    m_restoreSize = size;
}

// ��ȡ�������ǰ���ڵ�λ���Լ���С;
void YTitleBar::loadSnapshot(QPoint& point, QSize& size) {
    point = m_restorePos;
    size = m_restoreSize;
}

// ���Ʊ���������ɫ
void YTitleBar::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    QPainterPath pathBack;
    pathBack.setFillRule(Qt::WindingFill);
    pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // ��������󻯻��߻�ԭ�󣬴��ڳ��ȱ��ˣ��������ĳ���Ӧ��һ��ı�
    const int width = this->parentWidget()->width();
    if (this->width() != width) {
        this->setFixedWidth(width);
    }
    QWidget::paintEvent(event);
}

// ˫����Ӧ�¼�����Ҫ��ʵ��˫��������������󻯺���С������
void YTitleBar::mouseDoubleClickEvent(QMouseEvent* event) {
    // ͨ����󻯰�ť��״̬�жϵ�ǰ�����Ǵ�����󻯻���ԭʼ��С״̬;
    // ����ͨ���������ñ�������ʾ��ǰ����״̬;
    if (m_pButtonMax->isVisible()) {
        onButtonMaxClicked();
    } else {
        onButtonRestoreClicked();
    }

    return QWidget::mouseDoubleClickEvent(event);
}

// ����ͨ��mousePressEvent��mouseMoveEvent��mouseReleaseEvent�����¼�ʵ��������϶��������ƶ����ڵ�Ч��;
void YTitleBar::mousePressEvent(QMouseEvent* event) {
    // �ڴ������ʱ��ֹ�϶�����;
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

// ����Ϊ��ť������Ӧ�Ĳ�;
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

// �÷�����Ҫ���ñ������еı�����ʾΪ������Ч��;
void YTitleBar::onRollTitle() {
    static int nPos = 0;
    QString titleContent = m_titleContent;
    // ����ȡ��λ�ñ��ַ�����ʱ����ͷ��ʼ;
    if (nPos > titleContent.length()) {
        nPos = 0;
    }

    m_pTitleContent->setText(titleContent.mid(nPos));
    nPos++;
}

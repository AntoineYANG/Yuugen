#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

enum class WindowAction {
    MIN_BUTTON = 0,         // ��С���͹رհ�ť;
    MIN_MAX_BUTTON,        // ��С������󻯺͹رհ�ť;
    ONLY_CLOSE_BUTTON       // ֻ�йرհ�ť;
};

class YTitleBar : public QWidget {
    Q_OBJECT

public:
    YTitleBar(QWidget* parent);
    ~YTitleBar();

    // set title text
    void setTitle(QString titleContent);

    // save/load snapshots of the absolute position od the window
    void saveSnapshot(const QPoint point, const QSize size);
    void loadSnapshot(QPoint& point, QSize& size);

private:
    void paintEvent(QPaintEvent* event);
    void mouseDoubleClickEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

    // load all components
    void initControl();
    // bind all connections
    void initConnections();

signals:
    void signalButtonMinClicked();
    void signalButtonRestoreClicked();
    void signalButtonMaxClicked();
    void signalButtonCloseClicked();

private slots:
    void onButtonMinClicked();
    void onButtonRestoreClicked();
    void onButtonMaxClicked();
    void onButtonCloseClicked();

private:
    QLabel* m_pIcon;                    // ������ͼ��;
    QLabel* m_pTitleContent;            // ����������;
    QPushButton* m_pButtonMin;          // ��С����ť;
    QPushButton* m_pButtonRestore;      // ��󻯻�ԭ��ť;
    QPushButton* m_pButtonMax;          // ��󻯰�ť;
    QPushButton* m_pButtonClose;        // �رհ�ť;

    // ��󻯣���С������;
    QPoint m_restorePos;
    QSize m_restoreSize;
    // �ƶ����ڵı���;
    bool m_isPressed;
    QPoint m_startMovePos;
    // ����������;
    QString m_titleContent;
};

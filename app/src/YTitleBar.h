#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

enum class WindowAction {
    MIN_BUTTON = 0,         // 最小化和关闭按钮;
    MIN_MAX_BUTTON,        // 最小化、最大化和关闭按钮;
    ONLY_CLOSE_BUTTON       // 只有关闭按钮;
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
    QLabel* m_pIcon;                    // 标题栏图标;
    QLabel* m_pTitleContent;            // 标题栏内容;
    QPushButton* m_pButtonMin;          // 最小化按钮;
    QPushButton* m_pButtonRestore;      // 最大化还原按钮;
    QPushButton* m_pButtonMax;          // 最大化按钮;
    QPushButton* m_pButtonClose;        // 关闭按钮;

    // 最大化，最小化变量;
    QPoint m_restorePos;
    QSize m_restoreSize;
    // 移动窗口的变量;
    bool m_isPressed;
    QPoint m_startMovePos;
    // 标题栏内容;
    QString m_titleContent;
};

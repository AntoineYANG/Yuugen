#ifndef CODEHIGHLIGHT_H
#define CODEHIGHLIGHT_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QRegularExpression>

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE


class CodeHighlight : public QSyntaxHighlighter {
    Q_OBJECT

public:
    CodeHighlight(QStringList keywordPatterns, QBrush brush, QTextDocument* parent);

protected:
    void highlightBlock(const QString& text) override;

private:

    struct HighlightingRule {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QRegularExpression commentStartExpression;
    QRegularExpression commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
};

#endif // CODEHIGHLIGHT_H

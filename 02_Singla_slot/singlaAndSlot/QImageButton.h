#ifndef QIMAGEBUTTON_H
#define QIMAGEBUTTON_H

#include <QPushButton>

class QImage;

class QImageButton : public QPushButton
{
    Q_OBJECT
public:
    QImageButton(QWidget *parent = 0);
    ~QImageButton();


    enum ButtonStyle{
        onlyTitle = 0, // 只有 title
        onlyImage, // 只有图片

        titlePre_ImageBackground, // 标题在图片的上面, 图片为背景

        imageLeft_TitleRight, // 图标在左, 标题在右
        titleLeft_ImageRight, // 标题在左, 图标在右
        imageTop_titleBottom, // 图标在上, 标题在下
        titleTop_ImageBottom, // 标题在上, 图标在下
    };

    enum QBtnState
    {
        isNormal = 0,
        isOver,
        isTracking,
        isDisable
    };

	bool setBtnImage(QString strImageName);

    void setButtonStyle(ButtonStyle btnStyle = titlePre_ImageBackground); // 设置按钮的样式, 默认为 图片为背景的按钮
    // modify Date: 2016/5/23 add Button`s Title
    void setText(QString text);
    void setFont(QFont font);
    // 正常, 鼠标悬浮, 禁用, 点击
    void setTitleColor(QColor normalColor = Qt::black, QColor overColor = Qt::black, QColor disableColor = Qt::black, QColor trackColor= Qt::black);
    //...
    void setTextWithRectAndAlignment(QString text, QRect textRect, Qt::Alignment alignment);

    void setEnabled(bool enabled);
    void setDisabled(bool disable);

    void setTag(int tag);
    int tag();

    void setToolTipText(const QString &);

signals:
    void clicked(int tag);

    void sign_setShowToolTip(QString toolTip);
    void sign_HiddenToolTip();


protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void changeEvent(QEvent *e);

    void paintEvent(QPaintEvent *event);

    bool event(QEvent *e);
    void timerEvent(QTimerEvent *);

private:
    void caculateSize();

    QImage *m_pImage;
    QBtnState m_btnState;

    // modify date:2016/5/23
    QString m_title;
    QFont m_titleFont;
    QColor m_normalColor;
    QColor m_overColor;
    QColor m_trackColor;
    QColor m_disableColor;

    ButtonStyle m_btnStyle; // 按钮样式
    // ...

    QRect m_textRect;
    Qt::Alignment m_Alignment;

    int m_pTag;     // 按钮的tag值

    QString m_toolTip;

    int m_toolTimer;
};

#endif // QIMAGEBUTTON_H

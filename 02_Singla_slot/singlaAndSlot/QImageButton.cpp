#include "QImageButton.h"
#include <QMouseEvent>
#include <QPainter>


//#include "QCommonUser.h"


QImageButton::QImageButton(QWidget *parent):
        QPushButton(parent),
		m_pImage(NULL),
        m_btnState(isNormal),
        m_btnStyle(titlePre_ImageBackground),
        m_toolTimer(0)
{
    setAttribute(Qt::WA_LayoutUsesWidgetRect);

    m_pTag = 0;

    m_titleFont = QFont("Tahoma", 12);

    m_textRect = QRect();
    m_Alignment = Qt::AlignCenter;

    m_title = "";
}


QImageButton::~QImageButton()
{
    if (NULL != m_pImage)
    {
        delete m_pImage;
        m_pImage = NULL;
    }
}

void QImageButton::setText(QString text) {
    m_title = text;

    this->caculateSize();
    update();
}

void QImageButton::setFont(QFont font) {
    m_titleFont = font;
    update();
}

// 设置title 四种状态下的颜色
void QImageButton::setTitleColor(QColor normalColor, QColor overColor, QColor disableColor, QColor trackColor) {
    m_normalColor = normalColor;
    m_overColor = overColor;
    m_disableColor = disableColor;
    m_trackColor = trackColor;

    update();
}

void QImageButton::setTextWithRectAndAlignment(QString text, QRect textRect, Qt::Alignment alignment)
{
    m_title = text;
    m_textRect = textRect;
    m_Alignment = alignment;

    update();
}

void QImageButton::setEnabled(bool enabled)
{
    if (!enabled) {
        m_btnState = isDisable;
    } else {
        m_btnState = isNormal;
    }

    update();

    QPushButton::setEnabled(enabled);
}

void QImageButton::setDisabled(bool disable)
{
    if (disable) {
        m_btnState = isDisable;
    } else {
        m_btnState = isNormal;
    }

    update();

    QPushButton::setDisabled(disable);
}

void QImageButton::setTag(int tag)
{
    m_pTag = tag;
}

int QImageButton::tag()
{
    return m_pTag;
}

bool QImageButton::setBtnImage(QString strImageName)
{
	if (m_pImage)
	{
		delete m_pImage;
		m_pImage = NULL;
	}
    m_pImage = new QImage(strImageName);
	if (!m_pImage)
	{
		return false;
	}

    this->resize(m_pImage->width()/4, m_pImage->height());
    this->setFixedSize(m_pImage->width()/4, m_pImage->height());

    update();
    return true;
}

void QImageButton::setButtonStyle(ButtonStyle btnStyle) {
    m_btnStyle = btnStyle;

    this->caculateSize();
    update();
}

void QImageButton::caculateSize()
{
    QFontMetrics fm(m_titleFont); // 获取字体中的设置信息
    QRect titleRect = fm.boundingRect(m_title); // 获取字符串的边界信息; 也就是字符串的宽度和高度;

    int image_W = 0;
    int image_H = 0;
    if (m_pImage && !m_pImage->isNull()) {
        image_W = m_pImage->width();
        image_H = m_pImage->height();
    }

    if (m_btnStyle == onlyImage) {
        this->resize(image_W/4, image_H);
        this->setFixedSize(image_W/4, image_H);
    }

    // 只有文字
    if (m_btnStyle == onlyTitle) {
        this->resize(titleRect.width() + 10, titleRect.height() + 5);
        this->setFixedSize(titleRect.width() + 10, titleRect.height() + 5);
    }

    if (m_btnStyle == titlePre_ImageBackground) {
        int window_Width = (titleRect.width() > image_W/4) ? (titleRect.width() + 4) : image_W/4;
        int window_H = (titleRect.height() > image_H) ? (titleRect.height() + 4) : image_H;

        this->resize(window_Width, window_H);
        this->setFixedSize(window_Width, window_H);
    }

    if (m_btnStyle == titleLeft_ImageRight || m_btnStyle == imageLeft_TitleRight) {
        this->resize(image_W/4 + titleRect.width() + 5, image_H);
        this->setFixedSize(image_W/4 + titleRect.width() + 5, image_H);
    }

    if (m_btnStyle == imageTop_titleBottom || m_btnStyle == titleTop_ImageBottom) {
        if (titleRect.width() >= image_W/4) {  // title 的长度 > 图片的长度
            this->resize(titleRect.width(), image_W + 5 + titleRect.height());
            this->setFixedSize(titleRect.width(), m_pImage->height() + 5 + titleRect.height());
        } else { // 图片长度 > 文字长度
            this->resize( image_W, image_H + 5 + titleRect.height());
            this->setFixedSize(image_W, image_H + 5 + titleRect.height());
        }
    }
}

void QImageButton::mousePressEvent(QMouseEvent *event)
{
	if (event->button() != Qt::LeftButton)
	{
		QPushButton::mousePressEvent(event);
		return ;
	}

	if ( !this->isEnabled() )
	{
		m_btnState = isDisable;
		QPushButton::mousePressEvent(event);
		return;
	}

	if ( isTracking != m_btnState)
	{
		m_btnState = isTracking;
		this->repaint();
	}
	QPushButton::mousePressEvent(event);
}

void QImageButton::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() != Qt::LeftButton)
	{
		QPushButton::mouseReleaseEvent(event);
		return ;
	}

	if ( !this->isEnabled() )
	{
		m_btnState = isDisable;
		QPushButton::mouseReleaseEvent(event);
		return;
	}

	if ( isTracking == m_btnState)
	{
		m_btnState = isNormal;
		this->repaint();
	}

    emit clicked(m_pTag);
	QPushButton::mouseReleaseEvent(event);
}

void QImageButton::enterEvent(QEvent *event)
{
    if ( !this->isEnabled() )
    {
        m_btnState = isDisable;
		QPushButton::enterEvent(event);
        return;
    }

    if ( isOver != m_btnState)
    {
        m_btnState = isOver;
		this->repaint();
    }
	QPushButton::enterEvent(event);
}

void QImageButton::leaveEvent(QEvent *event)
{
	if ( !this->isEnabled() )
	{
		m_btnState = isDisable;
		QPushButton::leaveEvent(event);
		return;
	}

	if ( isOver == m_btnState)
	{
		m_btnState = isNormal;
		this->repaint();
	}
	QPushButton::leaveEvent(event);
}

void QImageButton::changeEvent(QEvent *e)
{
	if (QEvent::EnabledChange == e->type())
	{
		if(this->isEnabled())
		{
			m_btnState = isNormal;
		}
		else
		{
			m_btnState = isDisable;
		}
	}
	QPushButton::changeEvent(e);
}

void QImageButton::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);

    int image_Width; // 绘制图片的长度

    QRect titleRect;
    QRect imageRect;
    if (m_pImage) {
        image_Width = m_pImage->width()/4;
    } else {
        image_Width = 0;
    }

    // 1. title 在背景图片上, 或者只有背景图片
    if (m_btnStyle == titlePre_ImageBackground || m_btnStyle == onlyImage || m_btnStyle == onlyTitle) {
        titleRect = QRect(0, 0, this->width(), this->height());

        if (m_btnStyle == onlyTitle) {
            imageRect = QRect(0, 0, 0, 0);
        } else {
            imageRect = QRect(0, 0, this->width(), this->height());
        }
    }

    if (m_btnStyle == titleLeft_ImageRight ) {
        titleRect = QRect(0, 0, this->width() - image_Width, this->height());
        imageRect = QRect(this->width() - image_Width, 0, image_Width, this->height());
    }

    if (m_btnStyle == imageLeft_TitleRight) {
        imageRect = QRect(0, 0, image_Width, this->height());
        titleRect = QRect(image_Width, 0, this->width() - image_Width, this->height());
    }

    if (m_btnStyle == titleTop_ImageBottom) {
        titleRect = QRect(0, 0, this->width(), this->height() - m_pImage->height());
        imageRect = QRect((this->width() - image_Width)/2, this->height() - m_pImage->height() , image_Width, m_pImage->height());
    }

    if (m_btnStyle == imageTop_titleBottom) {
        imageRect = QRect((this->width() - image_Width)/2, 0, image_Width, m_pImage->height());
        titleRect = QRect(0, this->height() - m_pImage->height() , this->width(), this->height() - m_pImage->height());
    }


    int paintWidth; // 绘制图片的长度
    QColor paintColor; // 绘制文字的颜色
    switch(m_btnState)
    {
    case isNormal:
        paintWidth = image_Width * 0;
        paintColor = m_normalColor;
        break;
    case isOver:
        paintWidth = image_Width * 1;
        paintColor = m_overColor;
        break;
    case isTracking:
        paintWidth = image_Width * 2;
        paintColor = m_trackColor;
        break;
    case isDisable:
        paintWidth = image_Width * 3;
        paintColor = m_disableColor;
        break;
    default:
        paintWidth = image_Width * 0;
        paintColor = m_normalColor;
        break;
    }

    // 有背景图, 绘制背景图
    if (m_pImage) {
        paint.drawImage(imageRect.x(), imageRect.y(), *m_pImage, paintWidth, 0, imageRect.width(), imageRect.height());
    }

    // 有 title, 绘制 title
    if(m_title.length()){
        paint.setFont(m_titleFont); // 设置绘制文字的字体
        paint.setPen(paintColor); // 设置绘制文字的颜色

        if (m_textRect.isEmpty()) {
            paint.drawText(titleRect, Qt::AlignCenter, m_title);  // 居中绘制文字
        } else {
            QTextOption op;
            op.setAlignment(m_Alignment);
            op.setWrapMode(QTextOption::WordWrap);
            paint.drawText(m_textRect, m_title, op);
        }
    }
}

void QImageButton::setToolTipText(const QString &toolTip)
{
    m_toolTip = toolTip;
}

bool QImageButton::event(QEvent *e) {
    if (e->type() == QEvent::ToolTip) {
//        LogWriteManager::WLog(LOG_INFO, "QEvent::ToolTip");
        if (!m_toolTip.isEmpty()) {
//            m_toolTimer = startTimer(2 * 1000);
            emit sign_setShowToolTip(m_toolTip);
        }
    } else if (e->type() == QEvent::Leave) {
//        LogWriteManager::WLog(LOG_INFO, "other event");
//        killTimer(m_toolTimer);
//        m_toolTimer = 0;
        emit sign_HiddenToolTip();
    }

    return QWidget::event(e);
}

void QImageButton::timerEvent(QTimerEvent *)
{
    killTimer(m_toolTimer);
    m_toolTimer = 0;

    emit sign_setShowToolTip(m_toolTip);
}

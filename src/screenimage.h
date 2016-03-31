#ifndef SCREENIMAGE
#define SCREENIMAGE

#include <QWidget>
#include <memory>

class QImage;
class QLabel;
class QScrollArea;
class QString;
class QPoint;

class ScreenImage : public QWidget
{
    Q_OBJECT

public:
    explicit ScreenImage(QWidget *pWd = 0);
    //true if image don't loaded
    bool isEmpty() const;
public:
    //File menu
    bool loadImage(const QImage &img, const QString &name);
    void closeImage();
    //Edit menu
    void horizontalFlip();
    void verticalFlip();
    void clockwiseRotate();
    void counterClockwiseRotate();
    void zoomInImage();
    void zoomOutImage();
    //View menu
    void fitImage();
protected:
    virtual void resizeEvent(QResizeEvent *);
    virtual void wheelEvent(QWheelEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
private:
    void showImage();
    void imageWasChanged();
    void showSomeError(const QString &title, const QString &str);
    void bestImageGeometry();
    void zoomImage(const qreal zoomFactor);
    void flipImge(const bool horizontal, const bool vertical);

    std::shared_ptr<QScrollArea> _pScrollArea;
    std::shared_ptr<QLabel> _pLabel;
    QImage m_Image;

    const qint32 clockwiseValue;
    const qint32 counterClockwiseValue;

    qint32 angle;

    bool imageChanged;
    const qreal zoomInValue;
    const qreal zoomOutValue;
    qreal zoomFactor;

    QString _fileName;
    QPoint _mousePosition;
};

#endif // SCREENIMAGE

#ifndef STAR_H
#define STAR_H

#include <QPainter>
#include <QWidget>
#include <QTimer>

class Star : public QWidget
{
    Q_OBJECT
    double rotate = 0;
    qreal centerX = 0;
    qreal centerY = 0;
    qreal speedRotate = 0.1;

protected:
    void drawStar(qreal xpoint, qreal ypoint, bool isRotate);
    virtual void paintEvent(QPaintEvent* event);

public:
    Star();

};



#endif // STAR_H

#include "star.h"

#include <QPen>
#include <QColor>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QTime>

void Star::drawStar(qreal xpoint, qreal ypoint, bool isRotate) {
    QPainter painter(this);
    // Определяем центр оси по координатам x, y
    int centerX = width() / 2;
    int centerY = height() / 2;
    // Определяем радиус звезды
    int radius = qMin(width(), height()) / 2;
    // количество вершин звезды
    int numPoints = 8;

    // Вектор для координат вершин звезды
    QVector<QPointF> points;

    for (uint32_t i = 0; i < numPoints * 2; i++) {
        // Вычисляем угол поворота для каждой вершины звезды
        qreal angle = i * M_PI / numPoints;
        // Вычисляем координаты вершин в полярных координатах
        qreal x = centerX + radius * ypoint / (i % 2 ? xpoint : 1) * qCos(angle);
        qreal y = centerY + radius * ypoint / (i % 2 ? xpoint : 1) * qSin(angle);
        // Добавляем координаты вершин в вектор
        points.append(QPointF(x, y));
    }
    // Устанавливаем основной цвет
    painter.setBrush(QColor("#fff"));
    // Устанавливаем цвет кисти
    painter.setPen(QColor("#000"));

    if (isRotate) {
        // Смещаем виджет в начало координат
        painter.translate(centerX, centerY);
        // Поворащиваем фигуру на угол rotate
        painter.rotate(rotate);
        rotate += speedRotate;
        // Возвращаем на центр
        painter.translate(-centerX, -centerY);
    }

    // Отрисовываем звезду
    painter.drawPolygon(points.data(), points.size());
}


void Star::paintEvent(QPaintEvent* event) {

    drawStar(1.308, 1, 0);
    drawStar(3, 1, 0); // Вызываем функцию отрисовки
    drawStar(1.308, 0.435, 1);
}

Star::Star() {}



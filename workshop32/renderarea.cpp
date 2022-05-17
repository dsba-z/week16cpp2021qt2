#include "renderarea.h"

#include <QPainter>

RenderArea::RenderArea(QWidget* parent)
    : QWidget(parent),
      levels(2)
{

}

void RenderArea::setLevels(int lvls)
{
    levels = lvls;
    
    // update() replains the widget on next frame
    // If you change something visual about a widget, only
    // internal variables get changed, but you still
    // see the old visuals.
    // This function recalculates and redraws the look
    // of a widget.
    // https://doc.qt.io/qt-5/qwidget.html#update
    update();
}
void RenderArea::drawCantor(QPainter& painter, int x, int y, int w, int h, int level)
{
    if (level < 0)
    {
        return;
    }
    painter.drawRect(x, y, w, h);
    drawCantor(painter, x, y + h*2 , w/3, h, level-1);
    drawCantor(painter, x + 2.0*w/3, y + h*2 , w/3, h, level-1);
    
}

void RenderArea::paintEvent(QPaintEvent* /* event */)
{
    // Initialize painter, the object that draws primitive shapes
    QPainter painter(this);
    // Set fill color to gray
    painter.setBrush(Qt::GlobalColor::gray);
    
    // ask painter object to draw a rectangle
    // first, convert (x, y, widht, height) to a QRect object
    // then pass this object to painter.
    painter.drawRect(QRect(0, 0, this->width() - 1, this->height() - 1));


    // Set fill color to blue and line color to red
    QBrush figBrush(Qt::GlobalColor::blue);
    QPen figPen(Qt::GlobalColor::red);
    painter.setBrush(figBrush);
    painter.setPen(figPen);


    // Code to draw Cantor Fractal.

    // Task:
    // Convert this code to a function that takes a painter object and the number of levels
    int newHeight = 15;
    int w = width();
    drawCantor(painter, 0, 0, w, newHeight, levels);
//    painter.drawRect(0, 0, width(), newHeight);
    
//    if (levels > 1)
//    {
//        //               x                y                width       height
//        painter.drawRect(0,               newHeight * 2, width() / 3, newHeight);
//        painter.drawRect(width() * 2 / 3, newHeight * 2, width() / 3, newHeight);
//    }
    
}

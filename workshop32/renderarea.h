#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget* parent = nullptr);

    void setLevels(int lvls);
    
    void drawCantor(QPainter& painter, int x, int y, int w, int h, int level);
protected:
    int levels;
    void paintEvent(QPaintEvent* event) override;

signals:

};

#endif // RENDERAREA_H

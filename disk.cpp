#include <QWidget>
#include <QPainter>
#include "disk.h"
#include "pole.h"

extern float scale;
QColor diskColor(200,200,0);
QColor diskEdgeColor(100,100,0);

int diskHeight = 8;

Disk::Disk(int inSize, int inPos, Pole *inOn, QWidget *par)
    :size(inSize), pos(inPos), on(inOn)
{
    this->setParent(par);
    show();
    raise();
}

void Disk::paintEvent(QPaintEvent *){
    int top = 199;

    QPainter p(this);

    resize(120 * scale, 240 * scale);
    p.scale(scale, scale);
    p.setRenderHint(QPainter::Antialiasing);
    p.setBrush(diskColor);
    p.setPen(diskEdgeColor);
    p.save();

    p.drawEllipse(QPoint(60,top - pos * diskHeight), (15 + size * 6), (15 + size * 6)/2);
    p.setPen(Qt::NoPen);
    p.drawRect(60-(15 + size * 6),top - pos * diskHeight-diskHeight, 2*(15 + size * 6), diskHeight);
    p.setPen(diskEdgeColor);
    p.drawEllipse(QPoint(60,top - pos * diskHeight-diskHeight), (15 + size * 6), (15 + size * 6)/2);
    p.drawLine(60+(15 + size * 6),top - pos * diskHeight, 60+(15 + size * 6), top - pos * diskHeight-diskHeight);
    p.drawLine(60-(15 + size * 6),top - pos * diskHeight, 60-(15 + size * 6), top - pos * diskHeight-diskHeight);
    p.setBrush(diskEdgeColor);
    p.drawEllipse(QPoint(60,top - pos * diskHeight-diskHeight), 6, 3);
    p.restore();
}

void Disk::Lift(){
    pos = 21;
    repaint();
}

void Disk::setPolePos(Pole *d, int p)
{
    if(on !=d){
        on = d;
        this->setParent(d->parentWidget());
        show();
    }
    pos = p;
    repaint();
}

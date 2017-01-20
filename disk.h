#ifndef DISK_H
#define DISK_H

class Pole;
class Disk: public QWidget
{
private:
    Pole *on;
    int size; // size of disk
    int pos; // index on pole

    void setPolePos(Pole *d, int p);
    void Lift();
    int Size(){return size;}

public:
    Disk(int inSize, int inPos, Pole *inOn, QWidget *par);
    void paintEvent(QPaintEvent *);
    Pole *On(){return on;}
    friend class Pole;
};

#endif // DISK_H

#include "move.h"
#include <QtGlobal>

Move::Move(qint16 f, qint16 t)
    :from(f),to(t)
{}

Move::Move()
    :from(0),to(0)
{}

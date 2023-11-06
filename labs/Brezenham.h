#ifndef BREZENHAM_H
#define BREZENHAM_H

//#include "material.h"
#include <QPainter>

/* struct Material {
    QColor color;   // Цвет материала
    double absorption;  // Сила поглощения
}; */

double drawBresenhamLine(QPainter *p, int **map_obj, int x1, int y1, int x2, int y2);




#endif // BRESENHAM_H

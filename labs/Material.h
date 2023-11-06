#ifndef MATERIAL_H
#define MATERIAL_H

#include <QtWidgets>
#include <QGroupBox>
#include <QWidget>
#include <cmath>

void add_material_to_map(int **map, int px, int py, int sx, int sy, int type);


struct Material {
    QColor color;   // Цвет материала
    double absorption;  // Сила поглощения
};

extern Material materials[];

//extern Material materials[4];
#endif // MATERIAL_H

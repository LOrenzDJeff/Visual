#ifndef MAP_HEAT_H
#define MAP_HEAT_H



#include <iostream>

#include <QtDataVisualization/Q3DTheme>
#include <QtDataVisualization/QCustom3DItem>
#include <QtDataVisualization/QCustom3DLabel>
#include <QtGui/QImage>

#include <QtDataVisualization/Q3DSurface>
#include <QtDataVisualization/QSurfaceDataProxy>
#include <QtDataVisualization/QHeightMapSurfaceDataProxy>
#include <QtDataVisualization/QSurface3DSeries>
#include <QtWidgets/QSlider>
#include <QtWidgets/QLabel>
#include <QtCore/QPropertyAnimation>

using namespace QtDataVisualization;


class QWidget;

class map_heat : public QObject
{
public:
    map_heat(int pos_x, int pos_y, int size_x, int size_y, int size_map_x, int size_map_y);

    QWidget *get_container();
    QSurface3DSeries *get_QSurface3DSeries();
    Q3DSurface *graph;
    void draw(char *file_texture);
private:
    int pos_x, pos_y;
    int size_x, size_y;
    int size_map_x, size_map_y;
    QWidget *container;
    QSurface3DSeries *layerOneSeries;

    char filename2[FILENAME_MAX] = "C:/Denis/labs/map_heights2.jpg";

};
#endif // MAP_HEAT_H

#include "mainwindow.h"
#include <QtWidgets>
#include <QGroupBox>
#include <QWidget>
#include <cmath>

double math(double f, double d) {
return 28 + 22 * log10(f) + 20 * log10(d);
}

float calculate(int x1,int x2,int y1,int y2){
return sqrt(pow(abs(x1 - x2),2) + pow(abs(y1 - y2),2));
}

float pix_translate(float x, int pix_distance){
return x*pix_distance;
}

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
{
QGraphicsScene* scene = new QGraphicsScene();
int Pix_to_Meters = 250;
int Tx_Power = 23;
int Antena_Gain = -12;
float frequency = 2.5;
int Bs_PosX = 500;
int Bs_PosY = 500;
QPixmap map(1000, 1000);
QPainter p(&map);

srand(QTime::currentTime().msec());
for(int i = 0; i < 1000; i++){
for(int j = 0; j < 1000; j++){
float distance = 0;
distance = calculate(Bs_PosX,i,Bs_PosY,j);
distance = pix_translate(distance, Pix_to_Meters);
float Signal_Power = Tx_Power + Antena_Gain - math(frequency, distance);

// Определение типа препятствия случайным образом
int obstacleType = 1; // Здесь 4 - общее количество типов препятствий
QColor obstacleColor;

// В зависимости от типа препятствия, установите цвет и добавьте его на карту
switch (obstacleType) {
    case 0:
        obstacleColor = QColor(0, 0, 0); // Черное - стеклопакет
        break;
    case 1:
        obstacleColor = QColor(128, 128, 128); // Серое - IRR стекло
        break;
    case 2:
        obstacleColor = QColor(128, 64, 0); // Коричневое - бетон
        break;
    case 3:
        obstacleColor = QColor(255, 165, 0); // Оранжевое - дерево/гипсокартон
        break;
    // Добавьте другие типы препятствий, если необходимо
}

if(Signal_Power < -44 && Signal_Power >= -54){
p.setPen(QColor(255, 0, 0, 255));
} else if (Signal_Power < -54 && Signal_Power >= -64) {
p.setPen(QColor(220, 50, 0, 255));
} else if (Signal_Power < -64 && Signal_Power >= -74){
p.setPen(QColor(255,165,0,255));
} else if(Signal_Power < -74 && Signal_Power >= -84){
p.setPen(QColor(255,255,0,255));
} else if(Signal_Power < -84 && Signal_Power >= -94){
p.setPen(QColor(173,255,47,255));
} else if(Signal_Power < -94 && Signal_Power >= -104){
p.setPen(QColor(0,255,0,255));
} else if(Signal_Power < -104 && Signal_Power >= -114){
p.setPen(QColor(0,250,154,255));
} else if(Signal_Power < -114 && Signal_Power >= -124){
p.setPen(QColor(102,205,170,255));
} else if(Signal_Power < -124 && Signal_Power >= -134){
p.setPen(QColor(65,105,225,255));
} else if(Signal_Power < -134 && Signal_Power >= -144){
p.setPen(QColor(0,0,255,255));
}
else {
    // Если Signal_Power не соответствует ни одному из условий
    // установите цвет прозрачным, чтобы обозначить отсутствие сигнала
    obstacleColor = QColor(0, 0, 0, 0);
}
p.setPen(obstacleColor);
p.drawPoint(i, j);
}
}

p.end();
scene->addPixmap(map);
QGraphicsView* view = new QGraphicsView(scene);
setCentralWidget(view);
view -> setGeometry(250,100,500,500);
this->layout()->addWidget(view);

gradientGroupBox_ = new QGroupBox(QStringLiteral("Signal Strength"));

int height = 400;
int width = 150;
int border = 10;
QLinearGradient gr(0, 0, 1, height - 2 * border);
gr.setColorAt(1.0f, Qt::blue);
gr.setColorAt(0.8f, Qt::cyan);
gr.setColorAt(0.6f, Qt::green);
gr.setColorAt(0.4f, Qt::yellow);
gr.setColorAt(0.0f, Qt::red);

//blue,cyan,green,yellow,red
QPixmap pm(width, height);
pm.fill(Qt::transparent);
QPainter pmp(&pm);
pmp.setBrush(QBrush(gr));
pmp.setPen(Qt::NoPen);
pmp.drawRect(border, border, 35, height - 2 * border);
pmp.setPen(Qt::black);
int step = (height - 2 * border) / 10;
for (int i = 0; i < 11; i++) {
int yPos = i * step + border;
pmp.drawLine(border, yPos, 55, yPos);
pmp.drawText(60, yPos + 2, QString("%1 [dBm]").arg(-44 - (i * 10)));
}

label_ = new QLabel();
label_->setPixmap(pm);

QVBoxLayout *colorMapVBox = new QVBoxLayout;
colorMapVBox->addWidget(label_);
gradientGroupBox_->setLayout(colorMapVBox);
gradientGroupBox_->setGeometry(50,10,600,600);
this->layout()->addWidget(gradientGroupBox_);

}

MainWindow::~MainWindow()
{

}

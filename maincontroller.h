#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>
#include <QObject>

#include "playerentity.h"

class MainController: public QObject
{
    Q_OBJECT

public slots:
    void loadMapSlot(int id);

private:
    QGraphicsScene *scene;
    QGraphicsView *view;

    QList<QList<QList<QString>>> map;
public:
    const int PIXELS = 32;
    const int SIZE = 20;

    MainController(QList<QList<QList<QString>>> map);

    QList<QList<QList<QString> > > getMap() const;
    void setMap(const QList<QList<QList<QString> > > &value);
};

#endif // MAINCONTROLLER_H

﻿#ifndef _BUBBLECHATBOX_H
#define _BUBBLECHATBOX_H

#include <QGraphicsObject>
#include <QTimer>

class BubbleChatLabel;

class BubbleChatBox : public QGraphicsObject
{
    Q_OBJECT

public:
    explicit BubbleChatBox(const QRect &area, QGraphicsItem *parent = 0);
    ~BubbleChatBox();

    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    virtual QPainterPath shape() const;

    void setText(const QString &text);

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

private:
    QPixmap m_backgroundPixmap;
    QRectF m_rect;
    QRect m_area;
    QTimer m_timer;
    BubbleChatLabel *m_chatLabel;

private slots:
    void clear();
};

#endif
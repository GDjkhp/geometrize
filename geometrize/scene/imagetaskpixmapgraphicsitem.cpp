#include "imagetaskpixmapgraphicsitem.h"

#include <QEvent>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneWheelEvent>
#include <QPixmap>

#include "customtabletevent.h"

namespace geometrize
{

namespace scene
{

ImageTaskPixmapGraphicsItem::ImageTaskPixmapGraphicsItem() : QGraphicsPixmapItem()
{
    setAcceptHoverEvents(true);
    setAcceptTouchEvents(true);
    setFlag(ItemIsMovable, false);
    setFlag(ItemIsSelectable, false);
    setZValue(1000);
}

ImageTaskPixmapGraphicsItem::ImageTaskPixmapGraphicsItem(const QPixmap& pixmap) : QGraphicsPixmapItem(pixmap)
{
}

ImageTaskPixmapGraphicsItem::~ImageTaskPixmapGraphicsItem()
{
}

bool ImageTaskPixmapGraphicsItem::sceneEvent(QEvent* event)
{
    // Handle custom tablet events forwarded from the ImageTaskScene
    if(event->type() == geometrize::scene::CustomTabletEvent::customEventId) {
        emit signal_onCustomTabletEvent(*static_cast<geometrize::scene::CustomTabletEvent*>(event));
        return true;
    }
    return QGraphicsPixmapItem::sceneEvent(event);
}

void ImageTaskPixmapGraphicsItem::hoverMoveEvent(QGraphicsSceneHoverEvent* event)
{
    QGraphicsPixmapItem::hoverMoveEvent(event);
    emit signal_onHoverMoveEvent(event->lastScenePos().x(), event->lastScenePos().y(), event->scenePos().x(), event->scenePos().y(), event->modifiers() & Qt::ControlModifier);
}

void ImageTaskPixmapGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsPixmapItem::mousePressEvent(event);
    emit signal_onMouseMoveEvent(event->lastScenePos().x(), event->lastScenePos().y(),event->scenePos().x(), event->scenePos().y(), event->modifiers() & Qt::ControlModifier);
}

void ImageTaskPixmapGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsPixmapItem::mouseReleaseEvent(event);
    emit signal_onMouseReleaseEvent(event->scenePos().x(), event->scenePos().y(), event->modifiers() & Qt::ControlModifier);
}

void ImageTaskPixmapGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsPixmapItem::mouseMoveEvent(event);
    emit signal_onMouseMoveEvent(event->lastScenePos().x(), event->lastScenePos().y(), event->scenePos().x(), event->scenePos().y(), event->modifiers() & Qt::ControlModifier);
}

void ImageTaskPixmapGraphicsItem::wheelEvent(QGraphicsSceneWheelEvent* event)
{
    QGraphicsPixmapItem::wheelEvent(event);
    emit signal_onWheelEvent(event->scenePos().x(), event->scenePos().y(), event->delta(), event->modifiers() & Qt::ControlModifier);
}

void ImageTaskPixmapGraphicsItem::keyPressEvent(QKeyEvent* event)
{
    QGraphicsPixmapItem::keyPressEvent(event);
    emit signal_onKeyPressEvent(event->key(), event->modifiers() & Qt::ControlModifier);
}

void ImageTaskPixmapGraphicsItem::keyReleaseEvent(QKeyEvent* event)
{
    QGraphicsPixmapItem::keyReleaseEvent(event);
    emit signal_onKeyReleaseEvent(event->key(), event->modifiers() & Qt::ControlModifier);
}

void ImageTaskPixmapGraphicsItem::focusInEvent(QFocusEvent* event)
{
    QGraphicsPixmapItem::focusInEvent(event);
    emit signal_onFocusInEvent();
}

void ImageTaskPixmapGraphicsItem::focusOutEvent(QFocusEvent* event)
{
    QGraphicsPixmapItem::focusOutEvent(event);
    emit signal_onFocusOutEvent();
}

}

}

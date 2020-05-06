#pragma once

#include "svgitem.h"

#include <QByteArray>

class QGraphicsSceneWheelEvent;


namespace geometrize
{

namespace scene
{

/**
 * @brief The AreaOfInfluenceShapeItem class represents a graphical visualization of a shape that the user interacts with
 * to control where shapes are spawned/mutated as an image is geometrized.
 */
class AreaOfInfluenceShapeItem : public SvgItem
{
    Q_OBJECT
public:
    explicit AreaOfInfluenceShapeItem(const QByteArray& data);
    virtual ~AreaOfInfluenceShapeItem();
};

}

}

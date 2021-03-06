#ifndef MEDUSA_H
#define MEDUSA_H

#include <memory>
#include <iostream>

#include <QColor>

#include "hyperedge.h"
#include "medusatype.h"

namespace grammar
{
    typedef std::shared_ptr<MedusaType> type_ptr;

    class Medusa : public HyperEdge
    {
        private:
            type_ptr type_;
        public:
            QColor color_;
            double x_;
            double y_;
            double rotation_; // In radians

            Medusa(type_ptr type);

            type_ptr getType();

            friend std::ostream & operator<<(std::ostream & out,
                                             Medusa & medusa);
    };
}

#endif // MEDUSA_H

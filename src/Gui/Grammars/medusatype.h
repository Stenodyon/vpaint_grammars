#ifndef MEDUSATYPE_H
#define MEDUSATYPE_H

#include <ostream>
#include <string>
#include <vector>

#include "Eigen/Eigen"

namespace grammar
{
    typedef Eigen::Vector2d vec2;

    class MedusaType
    {
        public:
            std::string name;
            std::vector<vec2> points;

            MedusaType(std::string name,
                       std::vector<vec2> points = std::vector<vec2>());

            friend std::ostream & operator<<(std::ostream & out,
                                             MedusaType & medtype);
    };

}

#endif // MEDUSATYPE_H

#include "medusatype.h"

namespace grammar
{
    MedusaType::MedusaType(std::string name,
                           std::vector<vec2> points)
        : name(name), points(points)
    {}

    std::ostream & operator<<(std::ostream & out,
                              MedusaType & medtype)
    {
        return out << medtype.name;
    }
}

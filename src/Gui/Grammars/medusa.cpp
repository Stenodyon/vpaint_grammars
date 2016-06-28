#include "medusa.h"

namespace grammar
{
    Medusa::Medusa(type_ptr type)
        : type_(type)
    {}

    type_ptr Medusa::getType()
    {
        return this->type_;
    }

    std::ostream & operator<<(std::ostream & out,
                              Medusa & medusa)
    {
        return out << medusa.type_->name;
    }
}

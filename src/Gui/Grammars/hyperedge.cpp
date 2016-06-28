#include "hyperedge.h"

#include "medusa.h"

namespace grammar
{
    HyperEdge::HyperEdge() {}

    std::ostream& operator<<(std::ostream& os, const HyperEdge & he)
    {
        os << "<";
        for(unsigned int node : he)
            os << node << ",";
        os << ">";
        return os;
    }
}

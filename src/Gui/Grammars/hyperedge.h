// This class represents edges in an HyperGraph with a list of nodes
// This class stores a pointer to associate user data with edges
// This pointer is _not_ deleted by the edge, it is owned solely by the user

#ifndef HYPEREDGE_H
#define HYPEREDGE_H

#include <vector>
#include <cstring>
#include <ostream>

namespace grammar
{
    // Nodes are unsigned ints, and hyperedges are sets of nodes. However, since
    // node order has an importance, a set is not enough for our needs and a list
    // is required

    class HyperEdge : public std::vector<unsigned int>
    {
        public:
            HyperEdge();

            // String output function
            friend std::ostream& operator<<(std::ostream& os,
                                            const HyperEdge & he);
    };
}

#endif // HYPEREDGE_H

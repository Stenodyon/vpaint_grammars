// This class represents production rules for grammars

#ifndef PRODUCTION_H
#define PRODUCTION_H

#include <memory>
#include <vector>

#include "hypergraph.h"
#include "medusatype.h"

namespace grammar
{
    class Medusa;

    // data structure representing a new structure to be created
    typedef std::shared_ptr<MedusaType> type_ptr;
    typedef std::pair<type_ptr, std::vector<unsigned int>> restruct;
    typedef std::shared_ptr<restruct> restruct_ptr;

    typedef std::shared_ptr<Medusa> edge_ptr;

    class Production
    {
        private:
            // type of the non-terminal being replaced
            type_ptr head_;
            // number of new nodes to introduce
            unsigned int newNodes_;
            // list of structures to create
            std::vector<restruct_ptr> body_;
        public:
            Production(type_ptr head, unsigned int newNodes);

            type_ptr getHead() const;
            void addBodyStructure(restruct_ptr rs);
            void apply(HyperGraph<Medusa> * graph,
                       edge_ptr edge) const;
    };
}


#endif // PRODUCTION_H

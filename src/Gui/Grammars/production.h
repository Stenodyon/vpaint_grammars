// This class represents production rules for grammars

#ifndef PRODUCTION_H
#define PRODUCTION_H

#include <memory>
#include <vector>

#include "hypergraph.h"
#include "medusatype.h"
#include "attributeexpr.h"

namespace grammar
{
    class Medusa;

    // data structure representing a new structure to be created
    typedef std::shared_ptr<MedusaType> type_ptr;

    typedef std::shared_ptr<Medusa> edge_ptr;

    class Production
    {
        public:
            struct result_structure : public std::vector<unsigned int>
            {
                    type_ptr type;
                    AttributeExpr * x_expr = new InheritedXAttributeExpr();
                    AttributeExpr * y_expr = new InheritedYAttributeExpr();
                    AttributeExpr * rotation =
                            new InheritedRotationAttributeExpr();
                    result_structure(type_ptr type,
                                     std::vector<unsigned int> * aps);
                    result_structure(type_ptr type,
                                     std::list<unsigned int> * aps);
            };
            typedef std::shared_ptr<result_structure> restruct_ptr;

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

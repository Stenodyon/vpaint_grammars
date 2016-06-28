// This class represents a grammar with its structures (terminal and
// non-terminal), and its productions.

#ifndef GRAMMAR_H
#define GRAMMAR_H

#include "hypergraph.h"
#include "hyperedge.h"
#include "medusa.h"
#include "production.h"
#include "productionmanager.h"

#include <vector>
#include <memory>
#include <utility>

#include <QString>
#include <QXmlStreamReader>

namespace grammar
{
    // typedefs <3 much verbose, very lengthy, wow
    typedef std::shared_ptr<Production> prod_ptr;
    typedef std::shared_ptr<MedusaType> type_ptr;

    typedef Eigen::Vector2d vec2;

    // Virtual Grammar class
    class Grammar
    {
        protected:
            ProductionManager prodman_;
            // List of structures
            std::vector<type_ptr> medusas_;

            type_ptr axiom_;
        public:
            // Empty grammar
            Grammar();
            // Read grammar from file
            Grammar(QString filename);

            // adds a production rule to the grammar
            void addProduction(prod_ptr production);
            // returns all production rules applicable to the structure
            // with id "id"
            std::vector<prod_ptr> * getProduction(type_ptr type);

            // adds a new structure to the grammar
            void addMedusaType(type_ptr medtype);

            // renders the resulting hypergraph to VAC
            // pre-condition :
            // - There are no terminals in the graph
            //   (it is in normal form/fully derived)
            void draw(HyperGraph<Medusa> * graph);

            void setAxiom(type_ptr medtype);
            type_ptr getAxiom();
    };

    // Keith Haring Grammar
    class KHG : public Grammar
    {
        public:
            KHG();
    };
}

#endif // GRAMMAR_H

#include "grammargenerator.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "medusa.h"

#include <QFileDialog>
#include <QString>
#include <QObject>
#include <QTextStream>

namespace grammar
{
    typedef std::shared_ptr<Medusa> edge_ptr;

    GrammarGenerator::GrammarGenerator()
        : hg_(HyperGraph<Medusa>())
    {
        std::srand(std::time(0));
    }

    bool GrammarGenerator::step()
    {
        for( edge_ptr edge : *(this->hg_.getEdges()) )
        {
            type_ptr medtype = edge->getType();
            std::vector<prod_ptr> * prodlist =
                    this->grammar_->getProduction(medtype);
            if( prodlist && prodlist->size() )
            {
                unsigned int random_index = std::rand() % prodlist->size();
                prod_ptr prod = prodlist->at(random_index);
                prod->apply(&(this->hg_), edge);
                return true;
            }
        }
        return false;
    }

    void GrammarGenerator::generate()
    {
        QString filename = QFileDialog::getOpenFileName(
                    0,
                    QObject::tr("Open grammar definition"),
                    "/home/kevin/Documents/C++/grammars",
                    QObject::tr("Grammar files *.*"));
        if( filename != "" )
        {
            // Loading the grammar
            this->grammar_ = std::make_shared<Grammar>(filename);
            type_ptr type = grammar_->getAxiom();
            edge_ptr edge = std::make_shared<Medusa>(type);
            hg_.addEdge(edge); // Adding the axiom
            //std::cout << this->hg_;
            // Actual generation
            while( this->step() );
            std::cout << "Resulting hypergraph: "<< std::endl << this->hg_;
            // Drawing the result to the VGC
            this->grammar_->draw(&(this->hg_));
        }
    }
}

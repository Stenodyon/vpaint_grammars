#include "grammar.h"

#include <stdexcept>
#include <ostream>

#include "Global.h"
#include "VectorAnimationComplex/VAC.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QRegExp>

//#include "parser.h"

extern void parse_grammar(QString string, grammar::Grammar * grammar);

namespace vac = VectorAnimationComplex;

namespace grammar
{
    // GRAMMAR
    Grammar::Grammar()
    {}

    Grammar::Grammar(QString filename)
    {
        QFile file(filename);
        if( !file.open(QIODevice::ReadOnly | QIODevice::Text) )
        {
            return;
        }
        QTextStream stream(&file);
        QString contents = stream.readAll();
        file.close();
        parse_grammar(contents, this);
        //std::cout << "Finished parsing" << std::endl;
    }

    void Grammar::addProduction(prod_ptr production)
    {
        this->prodman_.addProduction(production);
    }

    std::vector<prod_ptr> * Grammar::getProduction(type_ptr type)
    {
        return this->prodman_.getProductions(type);
    }

    void Grammar::addMedusaType(type_ptr medtype)
    {
        this->medusas_.push_back(medtype);
    }

    void Grammar::draw(HyperGraph<Medusa> * graph)
    {
        vac::VAC * vac = global()->currentVAC();
        for( edge_ptr edge : *(graph->getEdges()) )
        {
            type_ptr type = edge->getType();
            unsigned int pointCount = type->points.size();
            std::vector<vac::KeyVertex *> vertices;
            for(Eigen::Vector2d point : type->points)
                vertices.push_back(
                            vac->newKeyVertex(Time(), point));
            for(unsigned int index = 0; index < pointCount; index++)
            {
                vac::KeyEdge * ke = vac->newKeyEdge(
                            Time(),
                            vertices[index],
                            vertices[(index + 1) % pointCount],
                            0, 1);
                //vac::KeyHalfedge * he = new vac::KeyHalfedge(ke, false);
                std::cout << "KeyEdge(" << index << ","
                          << (index + 1) % pointCount << ")" << std::endl;
            }
        }
    }

    struct name_equality_predicate
    {
            const QString * to_find;

            bool operator()(type_ptr tp)
            {
                return tp->name == to_find->toStdString();
            }
    };

    void Grammar::setAxiom(type_ptr medtype)
    {
        this->axiom_ = medtype;
    }

    type_ptr Grammar::getAxiom()
    {
        return this->axiom_;
    }
}

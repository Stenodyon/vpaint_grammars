#include "grammar.h"

#include <cmath>
#include <ostream>
#include <stdexcept>

#include "Global.h"
#include "VectorAnimationComplex/VAC.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
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

    Eigen::Vector2d * rotate(Eigen::Vector2d & vec, double angle)
    {
        double x = vec[0];
        double y = vec[1];
        double newx = x * cos(angle) - y * sin(angle);
        double newy = x * sin(angle) + y * cos(angle);
        return new Eigen::Vector2d(newx, newy);
    }

    // This is a real mess
    void Grammar::draw(HyperGraph<Medusa> * graph)
    {
        vac::VAC * vac = global()->currentVAC();
        for( edge_ptr edge : *(graph->getEdges()) )
        {
            type_ptr type = edge->getType();
            unsigned int pointCount = type->points.size();
            std::vector<vac::KeyVertex *> vertices;
            // offset as evaluated from attributes
            Eigen::Vector2d offset = Eigen::Vector2d(edge->x_, edge->y_);
            for(Eigen::Vector2d point : type->points)
            {
                std::unique_ptr<Eigen::Vector2d> newpoint =
                        std::unique_ptr<Eigen::Vector2d>(
                            rotate(point, edge->rotation_));
                vertices.push_back(
                            vac->newKeyVertex(Time(), *newpoint + offset));
            }
            for(unsigned int index = 0; index < pointCount; index++)
            {
                vac::KeyEdge * ke = vac->newKeyEdge(
                            Time(),
                            vertices[index],
                            vertices[(index + 1) % pointCount],
                            0, 10);
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

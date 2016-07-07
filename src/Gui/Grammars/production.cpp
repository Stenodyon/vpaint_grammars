#include "production.h"

#include "medusa.h"

namespace grammar
{
    Production::result_structure::result_structure(type_ptr type,
                                                   std::vector<unsigned int> * aps)
        : std::vector<unsigned int>(*aps), type(type)
    {}
    Production::result_structure::result_structure(type_ptr type,
                                                   std::list<unsigned int> * aps)
        : type(type)
    {
        for(unsigned int node : *aps)
        {
            this->push_back(node);
        }
    }

    // PRODUCTION
    Production::Production(type_ptr head, unsigned int newNodes)
        : head_(head), newNodes_(newNodes)
    {}

    type_ptr Production::getHead() const
    {
        return this->head_;
    }

    void Production::addBodyStructure(restruct_ptr rs)
    {
        this->body_.push_back(rs);
    }

    void Production::apply(HyperGraph<Medusa> * graph,
                           edge_ptr edge) const
    {
        graph->removeEdge(edge);
        std::vector<unsigned int> nodeMap;
        for(unsigned int node_id : *edge)
            nodeMap.push_back(node_id);
        for(unsigned int node = 0; node < this->newNodes_; node++)
            nodeMap.push_back(graph->newNode());
        for(restruct_ptr rs : this->body_)
        {
            edge_ptr newEdge = std::make_shared<Medusa>(rs->type);
            newEdge->x_ = rs->x_expr->evaluate(edge);
            newEdge->y_ = rs->y_expr->evaluate(edge);
            newEdge->rotation_ = rs->rotation->evaluate(edge);
            for(unsigned int noderef : *rs)
                newEdge->push_back(nodeMap[noderef]);
            graph->addEdge(newEdge);
        }
    }
}

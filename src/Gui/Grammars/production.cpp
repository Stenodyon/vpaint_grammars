#include "production.h"

#include "medusa.h"

namespace grammar
{
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
            type_ptr type = rs->first;
            edge_ptr newEdge = std::make_shared<Medusa>(type);
            for(unsigned int noderef : rs->second)
                newEdge->push_back(nodeMap[noderef]);
            graph->addEdge(newEdge);
        }
    }
}

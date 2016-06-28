// HyperGraph class, represents hypergraphs with limited operations
// available (mainly removing vertices is not possible)

// Vertices are called Nodes here (shorter to write and has the same meaning)

#ifndef HYPERGRAPH_H
#define HYPERGRAPH_H

#include <list>
#include <memory>
#include <iostream>
#include <sstream>

namespace grammar
{
    template <typename HyperEdge>
    class HyperGraph
    {
        private:
            typedef std::shared_ptr<HyperEdge> edge_ptr;
            // Nodes cannot be removed (not necessary for our usage and makes things
            // very convenient)
            unsigned int nodeCount_;

            // List for easy removal of edges (happens constantly since it's going
            // to be used for edge _replacement_ grammars)
            std::list<edge_ptr> edges_;

        public:
            HyperGraph()
                    : nodeCount_(0), edges_(std::list<edge_ptr>())
            {}

            // Returns the new node
            unsigned int newNode()
            {
                return ++nodeCount_;
            }

            void addEdge(edge_ptr edge)
            {
                // Maintaining the invariant that no edge is linked to a node that doesn't
                // exist by enforcing correct values.
                for(unsigned int node : *edge)
                {
                    if( node > nodeCount_ )
                    {
                        // A bit sad that C++'s string formatting is this verbose
                        // But it does is well
                        std::ostringstream stringStream;
                        stringStream << "Node " << node << " is not in the hypergrap ("
                                     << nodeCount_ << ")";
                        throw std::out_of_range(stringStream.str());
                    }
                }
                // At this point everything's alright
                this->edges_.push_back(edge);
            }

            // const so that the invariant is preserved for sure
            const std::list<edge_ptr> * getEdges()
            {
                return &this->edges_;
            }

            // easy edge removal
            void removeEdge(edge_ptr edge)
            {
                this->edges_.remove(edge);
            }

            // outputing (mainly for debugging)
            template <typename U>
            friend std::ostream& operator<<(std::ostream & os,
                                            const HyperGraph<U> & hg)
            {
                os << "Hypergraph(" << hg.nodeCount_ << " nodes, "
                   << hg.edges_.size() << " edges)" << std::endl;
                for( std::shared_ptr<HyperEdge> edge : hg.edges_ )
                    os << *edge << std::endl;
                return os;
            }
    };
}

#endif // HYPERGRAPH_H

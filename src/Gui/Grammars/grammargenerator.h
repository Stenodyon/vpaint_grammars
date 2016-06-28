#ifndef GRAMMARGENERATOR_H
#define GRAMMARGENERATOR_H

#include "hypergraph.h"
#include "grammar.h"

namespace grammar
{
    class GrammarGenerator
    {
    private:
        std::shared_ptr<Grammar> grammar_;
        HyperGraph<Medusa> hg_;
        bool step();

    public:
        GrammarGenerator();

        void generate();
    };
}

#endif // GRAMMARGENERATOR_H

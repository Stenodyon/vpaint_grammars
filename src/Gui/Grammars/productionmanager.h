#ifndef PRODUCTIONMANAGER_H
#define PRODUCTIONMANAGER_H

#include <map>
#include <memory>

#include "production.h"
#include "medusatype.h"

namespace grammar
{
    typedef std::shared_ptr<Production> prod_ptr;
    class ProductionManager
    {
        private:
            std::map<MedusaType *, std::vector<prod_ptr>> productions_;
        public:
            ProductionManager();

            void addProduction(prod_ptr production);
            std::vector<prod_ptr> * getProductions(type_ptr type);
    };
}

#endif // PRODUCTIONMANAGER_H

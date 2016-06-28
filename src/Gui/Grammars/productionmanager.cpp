#include "productionmanager.h"

namespace grammar
{
    ProductionManager::ProductionManager()
    {}

    void ProductionManager::addProduction(prod_ptr production)
    {
        this->productions_[production->getHead().get()].push_back(production);
    }

    std::vector<prod_ptr> * ProductionManager::getProductions(type_ptr type)
    {
        try
        {
            return &(this->productions_.at(type.get()));
        }
        catch(const std::out_of_range & exception)
        {
            return (std::vector<prod_ptr>*)NULL;
        }
    }
}

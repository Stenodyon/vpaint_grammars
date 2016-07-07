#ifndef ATTRIBUTEEXPR_H
#define ATTRIBUTEEXPR_H

#include <memory>

#include "medusa.h"

namespace grammar
{
    typedef std::shared_ptr<Medusa> edge_ptr;

    class AttributeExpr
    {
        public:
            AttributeExpr();
            virtual double evaluate(edge_ptr parent) = 0;
    };

    class ConstantAttributeExpr : public AttributeExpr
    {
        private:
            double value_;
        public:
            ConstantAttributeExpr(double value)
                : value_(value)
            {}

            double evaluate(edge_ptr parent) override { return value_; }
    };

    class AddAttributeExpr : public AttributeExpr
    {
        private:
            AttributeExpr * a_;
            AttributeExpr * b_;
        public:
            AddAttributeExpr(AttributeExpr * a, AttributeExpr * b)
                : a_(a), b_(b)
            {}

            double evaluate(edge_ptr parent) override
            {
                return a_->evaluate(parent) + b_->evaluate(parent);
            }
    };

    class MultAttributeExpr : public AttributeExpr
    {
        private:
            AttributeExpr * a_;
            AttributeExpr * b_;
        public:
            MultAttributeExpr(AttributeExpr * a, AttributeExpr * b)
                : a_(a), b_(b)
            {}

            double evaluate(edge_ptr parent) override
            {
                return a_->evaluate(parent) * b_->evaluate(parent);
            }
    };

    class InheritedXAttributeExpr : public AttributeExpr
    {
        public:
            InheritedXAttributeExpr()
            {}

            double evaluate(edge_ptr parent) override
            {
                return parent->x_;
            }
    };

    class InheritedYAttributeExpr : public AttributeExpr
    {
        public:
            InheritedYAttributeExpr()
            {}

            double evaluate(edge_ptr parent) override
            {
                return parent->y_;
            }
    };

    class InheritedRotationAttributeExpr : public AttributeExpr
    {
        public:
            InheritedRotationAttributeExpr()
            {}

            double evaluate(edge_ptr parent) override
            {
                return parent->rotation_;
            }
    };
}

#endif // ATTRIBUTEEXPR_H

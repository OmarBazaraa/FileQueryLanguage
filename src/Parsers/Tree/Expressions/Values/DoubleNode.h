#ifndef __DOUBLE_NODE_H_
#define __DOUBLE_NODE_H_

#include <string>

#include <Parsers/Tree/Expressions/Values/ValueNode.h>

namespace FQL
{
    class DoubleNode : public ValueNode
    {
    protected:
        double value = 0.0;

    public:
        DoubleNode(double value = 0.0)
        {
            this->value = value;
            this->type = TYPE_DOUBLE;
        }

        virtual bool GetBool() const
        {
            return this->value != 0;
        }

        virtual int GetInt() const
        {
            return this->value;
        }

        virtual double GetDouble() const
        {
            return this->value;
        }

        virtual std::string GetString() const
        {
            return std::to_string(this->value);
        }

        virtual void DumpTree(std::ostream& out, int indent = 0) const
        {
            out << std::string(indent, ' ') << this->value;
        }
    };
}

#endif

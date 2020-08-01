#ifndef __INT_NODE_H_
#define __INT_NODE_H_

#include <string>

#include <Parsers/Tree/Expressions/Values/ValueNode.h>

namespace FQL
{
    class IntNode : public ValueNode
    {
    protected:
        int value = 0;

    public:
        IntNode(int value = 0)
        {
            this->value = value;
            this->type = TYPE_INT;
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

#ifndef __BOOL_NODE_H_
#define __BOOL_NODE_H_

#include <string>

#include <Parsers/Tree/Expressions/Values/ValueNode.h>

namespace FQL
{
    class BoolNode : public ValueNode
    {
    protected:
        bool value = false;

    public:
        BoolNode(bool value = false)
        {
            this->value = value;
            this->type = TYPE_BOOL;
        }

        virtual bool GetBool() const
        {
            return this->value;
        }

        virtual int GetInt() const
        {
            return this->value ? 1 : 0;
        }

        virtual double GetDouble() const
        {
            return this->value ? 1 : 0;
        }

        virtual std::string GetString() const
        {
            return this->value ? "true" : "false";
        }

        virtual void DumpTree(std::ostream& out, int indent = 0) const
        {
            out << std::string(indent, ' ') << this->value;
        }
    };
}

#endif

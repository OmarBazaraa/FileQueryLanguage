#pragma once

#include "Parsers/Tree/Expressions/Values/ValueNode.h"

namespace FQL
{
    class StringNode : public ValueNode
    {
    protected:
        std::string value;

    public:
        StringNode(const std::string& value)
        {
            this->value = value;
            this->type = TYPE_STRING;
        }

        virtual bool GetBool() const
        {
            // TODO: throw exception.
            return false;
        }

        virtual int GetInt() const
        {
            // TODO: throw exception.
            return 0;
        }

        virtual double GetDouble() const
        {
            // TODO: throw exception.
            return 0;
        }

        virtual std::string GetString() const
        {
            return this->value;
        }

        virtual void DumpTree(std::ostream& out, int indent = 0) const
        {
            out << std::string(indent, ' ') << "\"" << this->value << "\"";
        }
    };
}

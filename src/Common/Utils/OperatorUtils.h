#ifndef __OPERATOR_UTILS_H_
#define __OPERATOR_UTILS_H_

#include <string>

#include <Common/Enums/DataTypes.h>
#include <Common/Enums/Operators.h>

namespace FQL
{
    /**
     * Collection of static operator utility functions.
     */
    struct OperatorUtils
    {
        /**
         * Checks whether the given operator is an arithmetic operator or not.
         *
         * @param opr the operator to check.
         *
         * @return `true` if the given operator is arithmetic; `false` otherwise.
         */
        static bool IsArithmeticOpr(Operator opr)
        {
            switch (opr)
            {
                case OPR_ADD:
                case OPR_U_PLUS:
                case OPR_SUB:
                case OPR_U_MINUS:
                case OPR_MUL:
                case OPR_DIV:
                case OPR_MOD:
                    return true;
            }

            return false;
        }

        /**
         * Checks whether the given operator is a logical operator or not.
         *
         * @param opr the operator to check.
         *
         * @return `true` if the given operator is logical; `false` otherwise.
         */
        static bool IsLogicalOpr(Operator opr)
        {
            switch (opr)
            {
                case OPR_AND:
                case OPR_OR:
                case OPR_NOT:
                case OPR_GREATER:
                case OPR_GREATER_EQUAL:
                case OPR_LESS:
                case OPR_LESS_EQUAL:
                case OPR_EQUAL:
                case OPR_NOT_EQUAL:
                    return true;
            }

            return false;
        }

        /**
         * Checks whether the given operator is a bitwise operator or not.
         *
         * @param opr the operator to check.
         *
         * @return `true` if the given operator is bitwise; `false` otherwise.
         */
        static bool IsBitwiseOpr(Operator opr)
        {
            switch (opr)
            {
                case OPR_BIT_AND:
                case OPR_BIT_OR:
                case OPR_BIT_XOR:
                case OPR_BIT_NOT:
                case OPR_BIT_SHL:
                case OPR_BIT_SHR:
                    return true;
            }

            return false;
        }

        /**
         * Converts the given operator into its corresponding token string.
         *
         * @param opr the operator to convert.
         *
         * @return the corresponding token string.
         */
        static std::string ToString(Operator opr)
        {
            switch (opr)
            {
                case OPR_ASSIGN:
                    return "=";
                case OPR_ADD:
                case OPR_U_PLUS:
                    return "+";
                case OPR_SUB:
                case OPR_U_MINUS:
                    return "-";
                case OPR_MUL:
                    return "*";
                case OPR_DIV:
                    return "/";
                case OPR_MOD:
                    return "%";
                case OPR_BIT_AND:
                    return "&";
                case OPR_BIT_OR:
                    return "OR";
                case OPR_BIT_XOR:
                    return "^";
                case OPR_BIT_NOT:
                    return "~";
                case OPR_BIT_SHL:
                    return "<<";
                case OPR_BIT_SHR:
                    return ">>";
                case OPR_AND:
                    return "&&";
                case OPR_OR:
                    return "||";
                case OPR_NOT:
                    return "!";
                case OPR_GREATER:
                    return ">";
                case OPR_GREATER_EQUAL:
                    return ">=";
                case OPR_LESS:
                    return "<";
                case OPR_LESS_EQUAL:
                    return "<=";
                case OPR_EQUAL:
                    return "==";
                case OPR_NOT_EQUAL:
                    return "!=";
            }

            return "#";
        }
    };
}

#endif

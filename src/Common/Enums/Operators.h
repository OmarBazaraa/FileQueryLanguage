#ifndef __OPERATORS_H_
#define __OPERATORS_H_

namespace FileManager
{
    /**
     * Enum holding all the supported operators.
     */
    enum Operator
    {
        OPR_ASSIGN = 100,       // a = b

        OPR_ADD,                // a + b
        OPR_U_PLUS,             // +54

        OPR_SUB,                // a - b
        OPR_U_MINUS,            // -54

        OPR_MUL,                // a * b
        OPR_DIV,                // a / b
        OPR_MOD,                // a % b

        OPR_BIT_AND,            // a & b
        OPR_BIT_OR,             // a | b
        OPR_BIT_XOR,            // a ^ b
        OPR_BIT_NOT,            // ~a
        OPR_BIT_SHL,            // a << 1
        OPR_BIT_SHR,            // a >> 1

        OPR_AND,                // a && b
        OPR_OR,                 // a || b
        OPR_NOT,                // !a

        OPR_GREATER,            // a > b
        OPR_GREATER_EQUAL,      // a >= b
        OPR_LESS,               // a < b
        OPR_LESS_EQUAL,         // a <= b
        OPR_EQUAL,              // a == b
        OPR_NOT_EQUAL,          // a != b
    };
}

#endif

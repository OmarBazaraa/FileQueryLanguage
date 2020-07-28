#ifndef __Node_H_
#define __Node_H_

#include <iostream>

namespace FileManager {

    class BaseNode {
    public:
        
        BaseNode() = default;

        virtual ~BaseNode() = default;

        virtual void dumpTree(std::ostream& out, int indent = 0) const = 0;
    };
}

#endif
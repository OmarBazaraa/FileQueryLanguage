#ifndef __DATA_TYPES_H_
#define __DATA_TYPES_H_

namespace FileManager {

    /**
     * Enum holding all the supported primitive data types.
     */
    enum DataType {
        TYPE_VOID = 300,
        TYPE_NULL,
        TYPE_BOOL,
        TYPE_INT,
        TYPE_DOUBLE,
        TYPE_CHAR,
        TYPE_STRING,
        TYPE_UNKNOWN
    };
}

#endif

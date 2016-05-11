//
// Created by kirrok on 30.04.16.
//

#ifndef JSON_TEST_JCONVERTER_TWO_H
#define JSON_TEST_JCONVERTER_TWO_H


#include <json/json_object.h>
#include "jconverter.h"

class jconverter_two : public jconverter {

public:
    jconverter_two(json_object *j) : jconverter(j) { };

    const char *convert();

};


#endif //JSON_TEST_JCONVERTER_TWO_H

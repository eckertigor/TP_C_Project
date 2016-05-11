//
// Created by kirrok on 30.04.16.
//

#ifndef JSON_TEST_JCONVERTER_ONE_H
#define JSON_TEST_JCONVERTER_ONE_H

#include "jconverter.h"

struct data {
    int lt, ut, *act, act_number;
};

class jconverter_one : public jconverter {
public:

    jconverter_one(json_object *j) : jconverter(j) { };
    ~jconverter_one();

    data &convert();

private:
    data data_;
};


#endif //JSON_TEST_JCONVERTER_ONE_H

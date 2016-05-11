//
// Created by kirrok on 30.04.16.
//

#ifndef JSON_TEST_JCONVERTER_H
#define JSON_TEST_JCONVERTER_H


#include <json/json.h>

class jconverter {
public:
    static int type(json_object *query);

    jconverter(json_object *j) : jstring(j) { };
protected:
    json_object *jstring;
};


#endif //JSON_TEST_JCONVERTER_H

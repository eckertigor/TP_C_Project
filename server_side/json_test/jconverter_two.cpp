//
// Created by kirrok on 30.04.16.
//

#include "jconverter_two.h"

const char *jconverter_two::convert() {
    return json_object_to_json_string(json_object_object_get(jstring, "name"));
}


//
// Created by kirrok on 30.04.16.
//

#include <cstdlib>
#include "jconverter.h"


int jconverter::type(json_object *query) {
    return atoi(json_object_to_json_string(json_object_object_get(query, "type")));
}


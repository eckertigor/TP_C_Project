//
// Created by kirrok on 30.04.16.
//


#include "jconverter_one.h"

data &jconverter_one::convert() {

    data_.lt = atoi(json_object_to_json_string(json_object_object_get(jstring, "lt")));
    data_.ut = atoi(json_object_to_json_string(json_object_object_get(jstring, "ut")));
    json_object *jarray = json_object_object_get(jstring, "act");
    data_.act_number = json_object_array_length(jarray);
    data_.act = new int[data_.act_number];
    for (int i = 0; i < data_.act_number; i++) {
        data_.act[i] = atoi(json_object_to_json_string(json_object_array_get_idx(jarray, i)));
    }
    return data_;
}

jconverter_one::~jconverter_one() {
    delete[] data_.act;
}




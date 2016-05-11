//
// Created by kirrok on 01.05.16.
//

#include <iostream>
#include "jconverter.h"


jconverter::~jconverter() {
    if (data_.act != NULL)
        delete[] data_.act;
}

int jconverter::type() {

    return atoi(json_object_to_json_string(json_object_object_get(jstring, "type")));
}

data &jconverter::convert_json_to_data_one() {

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

json_object *jconverter::convert_db_response_to_json_one(MYSQL_RES *res, unsigned long rows_number) {

    MYSQL_ROW row;

    jresult = json_object_new_array();

    json_object *jstruct[rows_number];
    json_object *jid;
    json_object *jname;
    json_object *jweather;

    for (int i = 0; i < rows_number; i++) {
        row = mysql_fetch_row(res);

        jstruct[i] = json_object_new_object();

        jid = json_object_new_int(atoi(row[0]));
        jname = json_object_new_string(row[1]);
        jweather = json_object_new_int(atoi(row[2]));
        json_object_object_add(jstruct[i], "id", jid);
        json_object_object_add(jstruct[i], "name", jname);
        json_object_object_add(jstruct[i], "weather", jweather);

        json_object_array_put_idx(jresult, i, jstruct[i]);

    }

    return jresult;
}

int jconverter::convert_json_to_data_two() {
    int id = atoi(json_object_to_json_string(json_object_object_get(jstring, "id")));
    return id;
}

json_object *jconverter::convert_db_response_to_json_two(MYSQL_RES *res) {

    MYSQL_ROW row = mysql_fetch_row(res);

    jresult = json_object_new_object();

    json_object_object_add(jresult, "about", json_object_new_string(row[0]));
    json_object_object_add(jresult, "logo", json_object_new_string(row[1]));
    json_object_object_add(jresult, "activity", json_object_new_string(row[2]));
    json_object_object_add(jresult, "language", json_object_new_string(row[3]));
    json_object_object_add(jresult, "food", json_object_new_string(row[4]));
    json_object_object_add(jresult, "money", json_object_new_string(row[6]));

    return jresult;
}

jconverter::jconverter(json_object *j) {
    jstring = json_object_new_object();
    jstring = json_object_get(j);
}


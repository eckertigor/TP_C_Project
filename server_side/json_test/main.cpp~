#include <stdio.h>
#include <iostream>
#include <cstring>
#include "json/json.h"

using namespace std;

int main(int argc, char **argv) {

    json_object *jquery = json_object_new_object();
    json_object *jtype = json_object_new_int(1);
    json_object *jlt = json_object_new_int(-19);
    json_object *jut = json_object_new_int(31);
    json_object *jarray = json_object_new_array();

    json_object *jactivities[3];
    jactivities[0] = json_object_new_int(1);
    jactivities[1] = json_object_new_int(3);
    jactivities[2] = json_object_new_int(7);


    json_object_array_put_idx(jarray, 0, jactivities[0]);
    json_object_array_put_idx(jarray, 1, jactivities[1]);
    json_object_array_put_idx(jarray, 2, jactivities[2]);


    json_object_object_add(jquery, "type", jtype);
    json_object_object_add(jquery, "lt", jlt);
    json_object_object_add(jquery, "ut", jut);
    json_object_object_add(jquery, "act", jarray);


    cout << json_object_to_json_string(jquery) << endl << endl;

    //==============
    //RECEIVED JSON STRING , LET'S PARSE IT!:

    json_object *jtype_serv_side = json_object_object_get(jquery, "type");
    json_object *jlt_serv_side = json_object_object_get(jquery, "lt");
    json_object *jut_serv_side = json_object_object_get(jquery, "ut");

    printf("%s %s %s    ", json_object_to_json_string(jtype_serv_side), json_object_to_json_string(jlt_serv_side),
           json_object_to_json_string(jut_serv_side));

    json_object *jarray_serv_side = json_object_object_get(jquery, "act");
             //ssss
    int act_number = json_object_array_length(jarray_serv_side);

    for (int i = 0; i < act_number; i++) {
        json_object *jact = json_object_array_get_idx(jarray_serv_side, i);
        cout << json_object_to_json_string(jact) << " " ;
    }


    return 0;
}

/*
/home/kirrok/.CLion2016.1/system/cmake/generated/json_test-e8171b7f/e8171b7f/Debug/json_test
JSON STRING:
 [ { "city": "MOSCOW", "weather": 6 }, { "city": "SOCHI", "weather": -8 }, { "city": "NOGINSK", "weather": 11 } ]
3
SIZE by size_of:8
SIZE by strlen:112
SIZE by strlen(string)112
"MOSCOW"   6
"SOCHI"   -8
"NOGINSK"   11
Process finished with exit code 0
*/





/*    int cities_number = 3;
    json_object *jobj[cities_number];
    json_object *jname[cities_number];
    json_object *jweather[cities_number];
    json_object *jarray = json_object_new_array();

    for (int i = 0; i < cities_number; i++) {
        jobj[i] = json_object_new_object();
    }

    jname[0] = json_object_new_string("MOSCOW");
    jname[1] = json_object_new_string("SOCHI");
    jname[2] = json_object_new_string("NOGINSK");

    jweather[0] = json_object_new_int(6);
    jweather[1] = json_object_new_int(-8);
    jweather[2] = json_object_new_int(11);

    for (int i = 0; i < cities_number; i++) {
        json_object_object_add(jobj[i], "city", jname[i]);
        json_object_object_add(jobj[i], "weather", jweather[i]);
    }

    for (int i = 0; i < cities_number; i++) {
        json_object_array_put_idx(jarray, i, jobj[i]);
    }

    printf("JSON STRING: \n %s\n\n\n", json_object_to_json_string(jarray));

    cout << json_object_array_length(jarray) << endl;

    cout << "SIZE by size_of:" << sizeof(json_object_to_json_string(jarray)) << endl;
    cout << "SIZE by strlen:" << strlen(json_object_to_json_string(jarray)) << endl;

    string jsons = json_object_to_json_string(jarray);

    cout << "SIZE by strlen(string)" << strlen(jsons.c_str()) << endl;
    //=======
    json_object *jcity;
    json_object *jt;

    for (int i = 0; i < cities_number; i++) {
        json_object *j_by_index = json_object_array_get_idx(jarray, i);
        jcity = json_object_object_get(j_by_index, "city");
        jt = json_object_object_get(j_by_index, "weather");

        printf("%s   %s \n", json_object_to_json_string(jcity), json_object_to_json_string(jt));
    }
*/

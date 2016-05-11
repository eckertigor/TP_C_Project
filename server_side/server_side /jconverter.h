//
// Created by kirrok on 01.05.16.
//

#ifndef SERVER_SIDE_JCONVERTER_H
#define SERVER_SIDE_JCONVERTER_H

#include <json/json.h>
#include <mysql/mysql.h>
#include <string>

struct data {
    int lt, ut, *act = NULL, act_number;
};

class jconverter {
public:

    jconverter(json_object *j);
    ~jconverter();

    int type();

    data &convert_json_to_data_one();

    json_object *convert_db_response_to_json_one(MYSQL_RES *res, unsigned long number);

    int convert_json_to_data_two();

    json_object *convert_db_response_to_json_two(MYSQL_RES *res);

protected:
    json_object *jstring;
    json_object *jresult;
    data data_;

};

#endif //SERVER_SIDE_JCONVERTER_H

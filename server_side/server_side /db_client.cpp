//
// Created by kirrok on 01.05.16.
//

#include <iostream>
#include <stdexcept>
#include <cstring>
#include "db_client.h"

unsigned long db_client::query(data &data_) throw(ss_exception) {

    std::string query_;
    query_ = "SELECT place_id, place_name, place_weather from appDB.place WHERE place.place_weather BETWEEN ";
    query_ += std::to_string(data_.lt);
    query_ += " AND ";
    query_ += std::to_string(data_.ut);
    query_ += " AND place_activity IN(";

    for (size_t i = 0; i < data_.act_number; i++) {

        if (i != data_.act_number - 1)
            query_ += std::to_string(data_.act[i]) + ",";
        else
            query_ += std::to_string(data_.act[i]);
    }
    query_ += ");";

    MYSQL *conn = mysql_init(NULL);
    if (conn == 0)
        throw ss_exception("Init database one");

    if (!mysql_real_connect(conn, host, user, password, name, port, socket, 0))
        throw ss_exception("Connection to database one");

    if (mysql_query(conn, query_.c_str())) {
        std::cout << mysql_error(conn) << std::endl;
        throw ss_exception("Query one");
    }
    res = mysql_store_result(conn);

    if (res == 0)
        throw ss_exception("Store results one");

    unsigned long rows_number = (unsigned long) mysql_num_rows(res);

    mysql_close(conn);

    return rows_number;
}

unsigned long db_client::query(int id) throw(ss_exception) {

    std::string query_;
    query_ = "SELECT descr_about, descr_logo, descr_activity, descr_language, descr_food, descr_language, descr_money from appDB.place_description WHERE place_description.descr_place = ";
    query_ += std::to_string(id);
    query_ += ";";

    MYSQL *conn = mysql_init(NULL);
    if (conn == 0)
        throw ss_exception("Init database two");

    if (!mysql_real_connect(conn, host, user, password, name, port, socket, 0))
        throw ss_exception("Connection to database two");

    if (mysql_query(conn, query_.c_str()))
        throw ss_exception("Query two");

    res = mysql_store_result(conn);

    if (res == 0)
        throw ss_exception("Store results two");

    unsigned long rows_number = (unsigned long) mysql_num_rows(res);

    mysql_close(conn);

    return rows_number;
}
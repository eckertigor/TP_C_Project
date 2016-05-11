//
// Created by kirrok on 28.04.16.
//

#include "db_client.h"
#include <iostream>
#include <cstring>


db_client::~db_client() {
    // delete[] row;
}

unsigned long db_client::query_(std::string &query) {

    MYSQL *conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, host, user, password, name, port, socket, 0)) {
        std::cout << ": mysql connect error: " << mysql_error(conn) << "\n";
        return (unsigned long) -1;
    }
    mysql_query(conn, query.c_str());

    res = mysql_store_result(conn);

    unsigned long rows_number = (unsigned long) mysql_num_rows(res);

    mysql_close(conn);
    return rows_number;
}
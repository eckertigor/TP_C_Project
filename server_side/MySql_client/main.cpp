#include <iostream>
#include "db_client.h"
#include "app_request.h"

int main() {

    db_client db;
    int activities[3] = {1, 2, 4};
    app_request ar(-90, 45, 3, activities);

    std::string query = ar.build_query();
    unsigned long rows_number = db.query_(query);
    MYSQL_RES *res = db.get_res();
    MYSQL_ROW row;

    for (int i = 0; i < rows_number; i++) {
        row = mysql_fetch_row(res);
        std::cout << row[0] << ", " << row[1] << ", " << row[2] << std::endl;
    }

    return 0;
}
#include <iostream>
#include <json/json_object.h>
#include "jconverter.h"
#include "db_client.h"
#include "server.h"
#include <string.h>

using namespace std;

int main(int argc, char **argv) {

    server serv;

    int port = 5002;

    if (argc > 1) {
        port = atoi(argv[1]);
    }

    try {
        serv.listen(port, 5);
    }
    catch (ss_exception ex) {
        cout << ex.type() << endl;
        return 0;
    }

    while (1) {

        try {
            serv.accept();
        }
        catch (ss_exception ex) {
            cerr << ex.type() << endl;
            continue;
        }

        char *buf;

        try {
            buf = serv.read();
        }
        catch (ss_exception ex) {
            cerr << ex.type() << endl;
            serv.free_buf();
            continue;
        }

        json_object *jquery = json_tokener_parse(buf);

        cout << " \nПарсим json: " << json_object_to_json_string(jquery) << endl;

        jconverter converter(jquery);

        db_client db;
        json_object *response;

        if (converter.type() == 1) {

            data data_ = converter.convert_json_to_data_one();
            unsigned long rows_number;

            try {
                rows_number = db.query(data_);
            }
            catch (ss_exception ex) {
                cout << ex.type() << endl;
                continue;
            }

            MYSQL_RES *res = db.get_res();

            response = converter.convert_db_response_to_json_one(res, rows_number);

            cout << "\n Json - ответ:  " << json_object_to_json_string(response) << endl << endl;

        } else if (converter.type() == 2) {
            int id = converter.convert_json_to_data_two();
            unsigned long rows_number;

            try {
                rows_number = db.query(id);
            }
            catch (ss_exception ex) {
                cout << ex.type() << endl;
                continue;
            }

            MYSQL_RES *res = db.get_res();

            response = converter.convert_db_response_to_json_two(res);

            cout << "\n Json - ответ: " << json_object_to_json_string(response) << endl;

        } else {
            cout << "Incorrect request type!" << endl;
            continue;
        }
        try {
            serv.write(json_object_to_json_string(response), strlen(json_object_to_json_string(response)));
        }
        catch (ss_exception ex) {
            cerr << ex.type() << endl;
            serv.free_buf();
            continue;
        }
        serv.free_buf();
    }
    return 0;
}
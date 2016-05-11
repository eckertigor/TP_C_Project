//
// Created by kirrok on 28.04.16.
//
#include <string>

#ifndef MYSQL_CLIENT_APP_REQUEST_H
#define MYSQL_CLIENT_APP_REQUEST_H


class app_request {
public:
    app_request(int lt_, int ut_, int anum, int *activities_);
    ~app_request();
    std::string &build_query();

private:
    int lt;
    int ut;
    int activities_number;
    int *activities;
    std::string query;
};


#endif //MYSQL_CLIENT_APP_REQUEST_H

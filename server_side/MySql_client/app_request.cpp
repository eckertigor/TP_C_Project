//
// Created by kirrok on 28.04.16.
//

#include <cstring>
#include <iostream>
#include "app_request.h"

app_request::app_request(int lt_, int ut_, int anum, int *activities_) {
    activities_number = anum;
    activities = new int[activities_number * sizeof(int)];

    memcpy(activities, activities_, activities_number * sizeof(int));

    lt = lt_;
    ut = ut_;
}

app_request::~app_request() {
    delete[] activities;
}

std::string &app_request::build_query() {
    query = "SELECT place_id, place_name, place_weather from appDB.place WHERE place.place_weather BETWEEN ";
    query += std::to_string(lt);
    query += " AND ";
    query += std::to_string(ut);
    query += " AND place_activity IN(";
    for (size_t i = 0; i < activities_number; i++) {

        if (i != activities_number - 1)
            query += std::to_string(activities[i]) + ",";
        else
            query += std::to_string(activities[i]);
    }
    query += ");";
    return query;
}
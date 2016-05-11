//
// Created by kirrok on 10.05.16.
//

#ifndef SERVER_SIDE_SS_EXCEPTION_H
#define SERVER_SIDE_SS_EXCEPTION_H


#include <exception>
#include <string>

class ss_exception : public std::exception {
public:
    ss_exception(const char *t) : ex_type(t) { };

    std::string &type() {
        return ex_type;
    }

private:
    std::string ex_type;
};


#endif //SERVER_SIDE_SS_EXCEPTION_H

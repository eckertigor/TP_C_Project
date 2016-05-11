//
// Created by kirrok on 08.05.16.
//

#ifndef SERVER_SIDE_SERVER_H
#define SERVER_SIDE_SERVER_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdexcept>
#include "ss_exception.h"


class server {
public:
    server() : main_sock(-1) { };

    ~server() { if (main_sock > 0) close(main_sock); }

    void listen(int port, int queue_size)       throw(ss_exception);

    void accept()                               throw(ss_exception);

    char *read()                                throw(ss_exception);

    void write(const char *data, int size)      throw(ss_exception);

    void close_connection();

    void set_rcv_timeout(int sec, int microsec) throw(std::exception);

    void free_buf() {
        if (buf != NULL)
            delete[] buf;
    }

private:
    int main_sock;
    int client_sock;
    char *buf = NULL;
};

#endif //SERVER_SIDE_SERVER_H

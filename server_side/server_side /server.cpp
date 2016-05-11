//
// Created by kirrok on 08.05.16.
//

#include <iostream>
#include "jconverter.h"
#include "server.h"
#include <string.h>

using namespace std;


void server::listen(int port, int queue_size) throw(ss_exception) {

    sockaddr_in serv_addr;

    main_sock = socket(AF_INET, SOCK_STREAM, 0);

    if (main_sock < 0)
        throw ss_exception("Creating socket");
    int t = 1;

    setsockopt(main_sock, SOL_SOCKET, SO_REUSEADDR, &t, sizeof(int));

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (::bind(main_sock, (sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        close(main_sock);
        throw ss_exception("Binding");
    }

    ::listen(main_sock, queue_size);

    cout << "Listening!" << endl;
}


void server::accept() throw(ss_exception) {
    socklen_t clilent_addr_size;
    sockaddr_in cli_addr;

    clilent_addr_size = sizeof(cli_addr);
    client_sock = ::accept(main_sock, (sockaddr *) &cli_addr, &clilent_addr_size);

    if (client_sock < 0)
        throw ss_exception("Accept");
}

char *server::read() throw(ss_exception) {

    int already_read = 0;
    int header_size = sizeof(int);
    int *header = new int;

    bzero(header, header_size);

    int n;

    while (already_read < header_size) {

        n = ::read(client_sock, header, header_size - already_read);

        if (n == 0)
            throw ss_exception("Connestion closed on reading header");
        if (n == -1)
            throw ss_exception("Error on reading header");

        already_read += n;

    }

    cout << "Получили от клиента длину: " << *header << endl;

    already_read = 0;

    buf = new char[*header + 1];

    bzero(buf, *header + 1);

    while (already_read < *header) {

        n = ::read(client_sock, buf, *header);

        if (n == 0)
            throw ss_exception("Connection closed on reading data");
        if (n == -1)
            throw ss_exception("Errro on reading header");

        already_read += n;
    }
    cout << "\nПолучили от клиента строку:" << buf << endl;
    return buf;
}

void server::write(const char *data, int size) throw(ss_exception) {

    int header_size = sizeof(int);
    int *header = new int;
    int already_written = 0;

    *header = size + 1; // ВАЖНО ЧТО +1

    int n;
    while (already_written < header_size) {

        n = ::write(client_sock, header, header_size - already_written);

        if (n == -1)
            throw ss_exception("Error on writing header");

        already_written += n;
    }

    already_written = 0;

    while (already_written < *header) {

        n = ::write(client_sock, data, *header);
        if (n == -1)
            throw ss_exception("Error on writing data");

        already_written += n;
    }
}
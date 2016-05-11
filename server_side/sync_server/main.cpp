/*
    sync_server
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <memory>
#include <json/json.h>
#include <cstdlib>
/*
class server {
    public:
        server()  : main_sockfd(-1) {}
        ~server() {
            if (main_sockfd > 0)
                close(main_sockfd);
        }

        void create_server_socket(uint32_t port, uint32_t queue_size);
        void send(char *data);
        void recv();
        int accept();
        void set_timeout(int sec, int microsec);

    private:
        const int listen_queue_size = 5;
        int main_sockfd;
        char buffer[256];
};

int server::accept() {
    struct sockaddr_in client_addr;
    bzero(&client_addr, sizeof(client_addr));
    socklen_t cli_len = sizeof(client_addr);

    int new_socket = ::accept(main_sockfd, (struct sockaddr*)&client_addr, &cli_len);

    return new_socket;
}


void server::create_server_socket(uint32_t port, uint32_t queue_size) {
    int sd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    struct sockaddr_in serv_addr;

    bzero(&serv_addr,sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(port);

    bind(sd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    ::listen(sd, listen_queue_size);

    main_sockfd = sd;
}

void server::send(char *data) {



}

int main () {
    return 0;
}

*/

void error(const char *msg) {
    perror(msg);
    exit(1);
}

using namespace std;

const int portno = 5002;
const int HEADER_SIZE_ONE = 5;
const int HEADER_SIZE_TWO = 4;

int main() {
    int sockfd, newsockfd;
    socklen_t clilent_addr_size;

    size_t *header = new size_t;
    char *buffer = new char[256];

    sockaddr_in serv_addr, cli_addr;

    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd, 5);
    cout << "LISTENING!" << endl;

//    while (1) {

        clilent_addr_size = sizeof(cli_addr);

        newsockfd = accept(sockfd, (sockaddr *) &cli_addr, &clilent_addr_size);

        if (newsockfd < 0)
            error("ERROR on accept");

        bzero(buffer, 256);

//      n = read(newsockfd, header, sizeof(size_t));
        n = read(newsockfd, buffer, sizeof(size_t));

	
	//cout << (size_t)(*header) <<endl;
	cout << buffer << endl;
        // n = write(newsockfd,json_object_to_json_string(jobj1),256);


        if (n < 0) error("ERROR reading to socket");

        close(newsockfd);

//}
    close(sockfd);
    return 0;
}





// реализовать класс shared_ptr на очереди
// температура (интервал). и вид актривности
// есть записи городов с двумя данными
/*  1. температура
    2. виды активностей
/ клиент отправляет фиксированный набор данных
который состоит из полей
название  char[6] от - 40 до + 40
массив активностей вида [6] [0,0,1,0,1,0]
сумма char[12]
[6 | 6 ]
сервер читает всегда 12 char
*/

//нужно понять в каком формате будем слать данные .



/*  1.получаем данные от клиента в виде json строки
            /*отдельный класс, ходящий в базу и возвращающий json строку.// отдельная задача !
    2.парсим
    3.идем в базу
    4.получаем данные из базы
    5.собираем json строку

    6.отправляем клиенту.
*/





//std::shared_ptr<int> foo = std::make_shared<int> (10);
/* json_object * jobj = json_object_new_object();
 json_object *jlower_temp = json_object_new_int(-10);
 json_object *jupper_temp = json_object_new_int(+31);

 json_object *jactivity_array[6];

 for (int i = 0; i < 6; i++) {
     jactivity_array[i] = json_object_new_boolean(1);
 }

 json_object *jarray = json_object_new_array();

 for(int i = 0;i < 6; i++) {
     json_object_array_add(jarray,jactivity_array[i]);
 }

 json_object_object_add(jobj,"lt", jlower_temp);
 json_object_object_add(jobj,"ut", jupper_temp);
 json_object_object_add(jobj,"activities", jarray);

*/


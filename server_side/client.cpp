
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <json/json.h>
#include <iostream>
#include <cstring>  
using namespace std;
void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

   
    portno = 5002;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname("localhost");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
        
//  building 1st request:        
/*    json_object *jquery = json_object_new_object();
    json_object *jtype = json_object_new_int(1);
    json_object *jlt = json_object_new_int(-25);
    json_object *jut = json_object_new_int(11);
    json_object *jarray = json_object_new_array();

    json_object *jactivities[3];
    jactivities[0] = json_object_new_int(1);
    jactivities[1] = json_object_new_int(3);
    jactivities[2] = json_object_new_int(7);
    

    json_object_array_put_idx(jarray, 0, jactivities[0]);
    json_object_array_put_idx(jarray, 1, jactivities[1]);
    json_object_array_put_idx(jarray, 2, jactivities[2]);


    json_object_object_add(jquery, "type", jtype);
    json_object_object_add(jquery, "lt", jlt);
    json_object_object_add(jquery, "ut", jut);
    json_object_object_add(jquery, "act", jarray);
        
    cout <<"Json to send:\n" << json_object_to_json_string(jquery) << endl; 
    cout <<"length:\n" << strlen(json_object_to_json_string(jquery)) << endl;
*/
// building 2nd request:
    
    json_object *jquery = json_object_new_object();
    json_object *jid = json_object_new_int(3);
    json_object *jtype = json_object_new_int(2);    
    
    json_object_object_add(jquery, "type", jtype);
    json_object_object_add(jquery, "id", jid);
   
    cout <<"Json to send:\n" << json_object_to_json_string(jquery) << endl; 
    cout <<"length:\n" << strlen(json_object_to_json_string(jquery)) << endl;
   
    size_t *header = new size_t;
    *header = strlen(json_object_to_json_string(jquery));
    n = write(sockfd, header,sizeof(size_t));
    if (n < 0) 
         error("ERROR writing to socket");
    
    n = write(sockfd, json_object_to_json_string(jquery),strlen(json_object_to_json_string(jquery)));
    if (n < 0) 
         error("ERROR writing to socket");
    
    n = read(sockfd, header,sizeof(size_t));
    if (n < 0) 
         error("ERROR reading from socket");

    char *response = new char[*header];
    n = read(sockfd, response, *header);
    if (n < 0) 
         error("ERROR reading from socket");
    else cout<<"RESPONSE: \n" << response << endl;
    
    close(sockfd);
    return 0;
}

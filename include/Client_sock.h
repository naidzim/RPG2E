#ifndef DEF_CLIENT_SOCK
#define DEF_CLIENT_SOCK

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int create_socket();
int attaqueAdv (int point_acces_client,int choixj1);
std::string comunicate_choix(int point_acces_client, std::string *choixj1);
void fin_comm(int point_acces_client);

#endif //DEF_CLIENT_SOCK

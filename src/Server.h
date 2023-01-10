#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "Socket.cpp"
#include "Util.cpp"

using namespace std;

#define INITPORT 23456

class Server {
private:
    int lastPort;
    Socket socket;
    Socket c_socket;//control socket
    Socket d_socket;//data socket
    string client_IP;//To store the IP address of the client

public:
    Server();
    int getNewPort();
    int sendData(string str);    //For sending through the data port
    int sendData(char *data, int num_bytes);//Overloaded function
    int sendControl(string str);    //For sending through the control port
    int receiveFile(string str);    //For receiving a file through the data socket with filename str
    int transferFile(string str);    //For transferring a file through the data socket with filename str
    int recvData(char *data);    //For receiving data
    string recvControl(int toRead);    //For receiving control information
    int fileExists(const char *filename);//To determine if a file exists with a given name
    int isEmpty(string filename);    //To determine if a file is empty
    int start();
    int acceptClient();
    int allocateDataPort();
    int handleClients();
    int sendResponse();

    Socket getSocket();
    Socket getControlSocket();
    Socket getDataSocket();

    void setSocket(Socket Socket);
    void setControlSocket(Socket Socket);
    void setDataSocket(Socket Socket);
};

string getStrFromInt(int val);

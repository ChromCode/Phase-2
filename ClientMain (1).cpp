#include "includes.h"
#include "common.h"
#include "TCPServerSocket.h"
#include "TCPSocket.h"

int main(){
	TCPSocket *okclient = new TCPSocket("127.0.0.1",1234,1024,1024);
	FILE *open = fopen("TEST.txt","r");
	char buffer[1024];
	int count = 0;
	int a = 0;
	string ok;
	while(!open.eof()){
		getline(open,ok);
		cout<<count;
		send(okclient->sock,ok.c_str(),ok.length(),0);
	}
	close(okclient->sock);
	fclose(open);
	delete(okclient);
	return 0;
}

/****************** CLIENT CODE ****************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/select.h>

int main(){
  int clientSocket;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;
  FILE *fp;

  /*---- Create the socket. The three arguments are: ----*/
  /* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
  
  /*---- Configure settings of the server address struct ----*/
  /* Address family = Internet */
  serverAddr.sin_family = AF_INET;
  /* Set port number, using htons function to use proper byte order */
  serverAddr.sin_port = htons(8888);
  /* Set IP address to localhost */
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  /* Set all bits of the padding field to 0 */
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  /*---- Connect the socket to the server using the address struct ----*/
  addr_size = sizeof serverAddr;
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

  /*---- Read the message from the server into the buffer ----*/
  //recv(clientSocket, buffer, 1024, 0);

  /*---- Print the received message ----*/
  //printf("Data received: %s",buffer);   
  fp=fopen("mahoa.txt","r");
  for(;;){
  	if(feof(fp)) break;
  	if(recv(clientSocket,buffer,1024,0)!=0){
  		fgets(buffer,1024,fp);
  		send(clientSocket,buffer,strlen(buffer)+1,0);
  		puts(buffer);
  	}
  }
  send(clientSocket,"CLOSE",6,0);
  puts("CLOSE");

  return 0;
}

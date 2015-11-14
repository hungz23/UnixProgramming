int main(int argc, char **argv){
  int         i, maxi, maxfd, listenfd, connfd, sockfd;
  int         nready, client[FD_SETSIZE];
  ssize_t       n;
  fd_set        rset, allset;
  char        buf[1024];
  socklen_t     clilen;
  struct sockaddr_in  cliaddr, servaddr;

  listenfd = socket(AF_INET, SOCK_STREAM, 0);

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family      = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  servaddr.sin_port        = htons(7891);

  bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

  listen(listenfd, LISTENQ);

  maxfd = listenfd;     /* initialize */
  maxi = -1;          /* index into client[] array */
  for (i = 0; i < FD_SETSIZE; i++)
    client[i] = -1;     /* -1 indicates available entry */
  FD_ZERO(&allset);
  FD_SET(listenfd, &allset);
/* end fig01 */
printf("%d\n",FD_SETSIZE);
clilen = sizeof(cliaddr);
printf("1\n");
connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);
printf("2\n");
send(connfd,"hung",5,0);
printf("hung\n");
/* include fig02 */


}
/* end fig02 */
#include "EstablishConnection.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h> 
#include <unistd.h>
#include <cstring>

void Connection(std::string IPAddress,int port)
{
	int sock0;
	struct sockaddr_in addr;
	struct sockaddr_in client;
	int len;
	int sock;
	char buf[32];
	int buf_len;
	int n;

	/* ソケットの作成 */
	sock0 = socket(AF_INET, SOCK_STREAM, 0);

	/* ソケットの設定 */
	addr.sin_family = AF_INET;
	addr.sin_port = htons(64000);
	addr.sin_addr.s_addr = INADDR_ANY;
	bind(sock0, (struct sockaddr *)&addr, sizeof(addr));

	/* TCPクライアントからの接続要求を待てる状態にする */
	while(1){
		listen(sock0, 5);

		/* TCPクライアントからの接続要求を受け付ける */
		len = sizeof(client);
		sock = accept(sock0, (struct sockaddr *)&client, (socklen_t *)&len);

		memset(buf, 0, sizeof(buf));
		n = read(sock, buf, sizeof(buf));   
		printf("%d, %s\n", n, buf);

		/* 5文字送信 */
		write(sock, "HELLO", 5);
	}
	/* TCPセッションの終了 */
	close(sock);

	/* listen するsocketの終了 */
	close(sock0);
}
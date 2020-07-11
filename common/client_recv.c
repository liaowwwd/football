/*************************************************************************
	> File Name: client_recv.c
	> Author: 
	> Mail: 
	> Created Time: Fri 10 Jul 2020 07:43:17 PM CST
 ************************************************************************/

#include "head.h"
extern int sockfd;
void *do_recv(void *arg){
    struct ChatMsg msg;
    while (1) {
        
        bzero(&msg,sizeof(msg));
        int ret = recv(sockfd,(void*)&msg,sizeof(msg),0);
        if (ret != sizeof(msg)) continue;
        if (msg.type & CHAT_WALL){
            printf(""BLUE"%s"NONE" : %s\n",msg.name,msg.msg);
        }
        else if (msg.type & CHAT_MSG){
            printf(""RED"%s"NONE" : %s\n",msg.name,msg.msg);
        }
        else if(msg.type & CHAT_SYS){
            printf(YELLOW"SERVER INFO"NONE" :%s\n",msg.msg);
        }
        else if (msg.type & CHAT_FIN){
            printf(L_RED"SERVER INFO"NONE"SERVER DOWN!\n");
            exit(1);
        }
    }
}


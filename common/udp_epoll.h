/*************************************************************************
	> File Name: udp_epoll.h
	> Author: suyelu 
	> Mail: suyelu@126.com
	> Created Time: Thu 09 Jul 2020 04:40:49 PM CST
 ************************************************************************/

#ifndef _UDP_EPOLL_H
#define _UDP_EPOLL_H
#include "datatype.h"
void add_event(int epollfd, int fd, int events);
void del_event(int epollfd, int fd);
int udp_connect(struct sockaddr_in *serveraddr);
int udp_accept(int fd, struct User *user);
void add_to_sub_reactor(struct User *user);
#endif

#include <termios.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int uart_open(char* port);
void uart_close(int fd);
int uart_config(int fd, int bandrate);
int uart_send(int fd, char *buf_send, int buf_len);
int uart_read(int fd, char *buf_read, int buf_len);


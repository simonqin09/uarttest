#include "uartconfig.h"

int main(int argc, char **argv)
{

	int fd,len,ch;
	char data_send[1024];
	char data_read[1024];

	/* check required parameters(corresponding uart port device) for main application*/
	if(argc != 2){
        printf("Usage: %s /dev/ttymxc* \n",argv[0]);
		return -1;
	}
	/* open and config uart port, only bandrate can be set here ---
	--- the orther need to be modified in uart_config in uartconfig.c file */
	fd = uart_open(argv[1]);
	/* predefined baud rate list:
	B921600,B460800,B230400,B115200,B57600,B38400,B19200,B9600,B4800,B2400,B1200*/
    ch = uart_config(fd, B115200);
	if(ch == -1)
	{
		printf("uart setup error!");
		return -1;
	}
    /*Sending data part*/
    len = sprintf(data_send,"this is a test program");

	if(len != -1)
	{
		ch = uart_send(fd,data_send,len);
		if(ch == -1)
		{
			printf("send error\n");
			return -1;
		}
		printf("send sucessfully\n");
	}

	/*Receiving data part*/
	memset(data_read,0,sizeof(data_read));
	for(int i=0;;i++)
	{
		len = uart_read(fd, data_read, sizeof(data_read));
		if(len > 0)
		{
			data_read[len]='\0';
			printf("%s",data_read);
		}
		else
		{
			printf("can't receive data\n");
			break;
		}

		if('\n' == data_read[len-1])
		    break;
	}

uart_close(fd);
return 0;
}

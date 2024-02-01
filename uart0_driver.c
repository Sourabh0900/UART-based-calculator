#include <LPC21xx.H>
#include "header.h"
#include<stdlib.h>

#define THRE ((U0LSR>>5)&1)
#define RDR (U0LSR&1)


void uart0_init(unsigned int baud)
{
int res;
res=15000000/(16*baud);
PINSEL0=0x05; //activate tx nad rx pin of port 0
U0LCR=0x83;	//unlock uart0 setting
U0DLL=res&0xff;	 //masking lower 8 bit
U0DLM=(res>>8)&0xff;  //upper 8 bit shift and mask
U0LCR=0x03;	 //lock uart0 setting

}


void uart0_tx(unsigned char data)
{
U0THR=data;
while(THRE==0);
}

void uart0_tx_string(char *p)
{
	while(*p)
	{
	uart0_tx(*p);
	p++;
	}
}


unsigned char uart0_rx(void)
{
while(RDR==0);
return U0RBR;
}

void uart0_rx_string(char *p)
{	
	int i=0;
	while(1)
	{  
		while(RDR==0);
		p[i]=U0RBR;
	//	uart0_tx(p[i]); //loopback 
		if(p[i]=='\r')
		{
		p[i]='\0';
		break;
		}
		i++;
	}
}

void uart0_integer(int num)
{
char p[10];
int i=0;
if(num==0)
{
uart0_tx('0');
return;
}
if(num<0)
{
uart0_tx('-');
num=-num;
}
while(num>0)
{
p[i]=num%10;
num=num/10;
i++;
}

for(i=i-1;i>=0;i--)
{
uart0_tx(p[i]+48);
}
}

void uart0_float(float f)
{
int n=f;
uart0_integer(n);
uart0_tx('.');
n=(f-n)*1000;
uart0_integer(n);
}


////////RFID//////
void uart0_rx_RFID(char *p)
{	
	int j=0;
	for(j=0;j<12;j++)
	{  
		while(RDR==0);
		p[j]=U0RBR;
	//	uart0_tx(p[i]); //loopback 
		if(j==12)
		{
		p[j]='\0';
		//break;
		}
	}
}



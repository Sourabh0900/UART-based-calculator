#include <LPC21xx.H>
#include "header.h"

int main()
{
unsigned char r,n1,n2,op;
uart0_init(9600);
uart0_tx_string("Uart calculator:\r\n");

while(1)
{
uart0_tx_string("ENter the expression :");
n1=uart0_rx();
uart0_tx(n1);
op=uart0_rx();
uart0_tx(op);
n2=uart0_rx();
uart0_tx(n2);
while(uart0_rx()!='\r');
switch(op)
{
case '+': r=(n1-48)+(n2-48);
		break;
case '-': r=(n1-48)-(n2-48);
		break;
case '*': r=(n1-48)*(n2-48);
		break;
case '/': r=(n1-48)/(n2-48);
		break;
}			 
uart0_tx_string("\r\nRESULT=");
uart0_tx((r/10)+48);
uart0_tx((r%10)+48);
uart0_tx_string("\r\n");

}
}
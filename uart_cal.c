#include <LPC21xx.H>
#include "header20.h"

main()
{
	u8 n1,n2,op,r;
	uart0_init(9600);
	uart0_tx_string("UART CALCULATOR\n\r");

	while(1)
	{
		uart0_tx_string("Enter Expression:");	
		n1=uart0_rx();
		uart0_tx(n1);

		op=uart0_rx();
		uart0_tx(op);

		n2=uart0_rx();
		uart0_tx(n2);

		while(uart0_rx()!=13);
		if(op=='+') 
			r=(n1-48)+(n2-48);
		else if(op=='-')
			{
			if(n2>n1)
			 {
				r=(n2-48)-(n1-48);
			}
			else
			r=(n1-48)-(n2-48);
			}
		else if(op=='*')
			r=(n1-48)*(n2-48);
		else if(op=='/')
			r=(n1-48)/(n2-48);
		else if(op=='%')
			r=(n1-48)%(n2-48);
		

			uart0_tx_string("\r\n result=");
			if(op=='-' && n2>n1)
			uart0_tx('-');
			uart0_tx((r/10)+48);
			uart0_tx((r%10)+48);
			uart0_tx_string("\n\r");
			
	}

}

#include <LPC21xx.H>
#include "header20.h"

main()
{
	u8 a[20];
	lcd_4bit_init();
	uart0_init(9600);
	uart0_tx_string("UART CALCULATOR\n\r");

	while(1)
	{
		uart0_tx_string("Enter Expression:");
		uart0_rx_string(a);
		uart0_tx_string(a);	   //loopback
//		uart0_tx_string("\r\n");
		uart0_cal(a);
		
	
	
		
	}

}

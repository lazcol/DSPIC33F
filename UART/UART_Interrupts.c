//UART Transmit ISR
void __attribute__((__interrupt__, no_auto_psv)) _U1TXInterrupt(void)
{     
    IFS0bits.U1TXIF = 0; // clear TX interrupt flag
    U1TXREG = ReceivedChar; // Transmit one character
}

//UART Receive ISR
void __attribute__((interrupt, auto_psv)) _U1RXInterrupt( void )               
{

    if(U1STAbits.FERR == 1)
        {
        ReceivedChar='0';
        }     
    
    if ( U1STAbits.OERR == 1 )
        {
        U1STAbits.OERR = 0;
        }
    
    ReceivedChar = (char)U1RXREG;
    IFS0bits.U1RXIF = 0;    
}

// #include"hw3.cpp"

class UdpSocket;
// Alex
int clientStopWait(UdpSocket &sock, const int max, int message[]);
void serverReliable(UdpSocket &sock, const int max, int message[]);

int clientStopWait(UdpSocket &sock, const int max, int message[]){
 return 0;
}
void serverReliable(UdpSocket &sock, const int max, int message[]){
}

/* ***************************************************************************
 * UDPHW3.CPP
 *  This assignment is a demonstration of understanding of two algorithms:
 *  Stop-and-wait and Sliding-Window. 
 * 
 * Authors:   Alex Van Matre and Keziah May
 * School:    University of Washington Bothell
 * Course:    CSS432 Computer Networking
 * Professor: Dr. Ahmed Awad
 * 
 * Sources:
 *  
 * ***************************************************************************/

// // Me
int clientSlidingWindow(UdpSocket &sock, const int max, int message[], int windowSize);
void serverEarlyRetrans(UdpSocket &sock, const int max, int message[], int windowSize);


/* A client keeps writing a message sequence number in message[0] 
 * and sending message[] as long as the number of in-transit messages 
 * is less than a given windowSize.
 *
 * sends message[] and receiving an acknowledgment from a server max (=20,000) 
 * times using the sock object. As described above, the client can continuously 
 * send a new message[] and increasing the sequence number as long as the number 
 * of in-transit messages (i.e., # of unacknowledged messages) is less than "windowSize." 
 * That number should be decremented every time the client receives an acknowledgment. 
 * If the number of unacknowledged messages reaches "windowSize," the client should 
 * start a Timer. If a timeout occurs (i.e., no response after 1500 usec), it must resend 
 * the message with the minimum sequence number among those which have not yet been 
 * acknowledged. The function must count the number of messages (not bytes) re-transmitted 
 * and return it to the main function as its return value.
 * */
int clientSlidingWindow(UdpSocket &sock, const int max, int message[], int windowSize) {
  
  return 0;
}

/* The server receives message[], saves the message's sequence number 
 * (stored in message[0]) in a local buffer array and returns a cumulative 
 * acknowledgement, i.e., the last received message in order.
 *
 * receives message[] and sends an acknowledgment to the client max (=20,000) times 
 * using the sock object. Every time the server receives a new message[], it must save 
 * the message's sequence number in an array and return a cumulative acknowledgment, i.e., 
 * the last received message in order.
 * */
void serverEarlyRetrans(UdpSocket &sock, const int max, int message[], int windowSize) {

}
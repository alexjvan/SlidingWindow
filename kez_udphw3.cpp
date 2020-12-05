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
  cerr << "client sliding window test:"  << endl;

  // Set variables
  int ackedNums[max] = {0};
  int ptrL = 0;
  int ptrH = ptrL + windowSize;    // Exclusive
  int unackedCount = 0;
  int maxSent = -1;
  int retransmittedCounter = 0;

  // traverse messages to send
  while(ptrL < max) {
    if(ackedNums[ptrL]) {  // If low-pointer packet is acked, move the window up. 
      ++ptrL; ++ptrH;
    }
    // for each packet in window, if not acked, send again
    else{
      int packet = ptrL
      while((packet < ptrH) && (packet < max)) {
        if(ackedNums[ptrL]) continue;                 // if acked, move on
        message[0] = packet;                          // otherwise, set message,
        sock.sendTo((char *)message, MSGSIZE);        // send it to server,
        cerr << "message = " << message[0] << endl;   // and print its contents.
        maxSent = max(maxSent, packet);               // Update the largest sequence # sent so far
        if(maxSent != packet) ++retransmittedCounter; // Have we sent this before?
        ++packet; ++unackedCount;
      }

      // after all packets in window are sent, start a timer for 1500usec
      sleep(0.0015)

      // check which packets were acked
      packet = ptrL
      while((packet < ptrH) && (packet < max)) {      // For each packet sent
        if(sock.pollRecvFrom() > 0) {                 // If there is a message in the sock
          sock.recvFrom((char *)message, MSGSIZE);    // receive the message (ACK)
          // mark packet as acked, if not dupliate, decrement unacked counter
          (ackedNums[message[0]]++) ? : --unackedCount;
        }
        ++packet;
      } 

      // if all acked, move window the full window block
      if(!unackedCount) {
        ptrL = ptrH;
        ptrH += windowSize;
      }
    }
  }

  return retransmittedCounter;
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
  // cerr << "server sliding window test:" << endl;

  // int receivedSeqNum[max] = {0};
  // int lastReceivedSeqNum = -1;
  // int currentSeqNum = -1;

  // // receive message[] max times
  // int i = 0;
  // while (i < max) {
  //   // Receive the first window
  //   for(int j = 0; j < windowSize; ++j) {
  //     // If there is data to read
  //     if(sock.pollRecvFrom() > 0) {
  //       sock.recvFrom((char *) message, MSGSIZE );      // udp message receive
  //       currentSeqNum = message[0];                     // Sequence # received
  //       if(currentSeqNum == (lastReceivedSeqNum + 1)) { // Check in order
  //         lastReceivedSeqNum = currentSeqNum;
  //       }
  //       cerr << message[0] << endl;                     // print out message
  //       ++i;
  //     }

  //   }
  // }
}
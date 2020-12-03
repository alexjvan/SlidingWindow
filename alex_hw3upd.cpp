#include <iostream>
#include "UdpSocket.h"
#include "Timer.h"

using namespace std;

#define PORT 23460       // my UDP port
#define MAX 20000        // times of message transfer
#define MAXWIN 30        // the maximum window size
#define LOOP 10          // loop in test 4 and 5


int clientStopWait( UdpSocket &sock, const int max, int message[] ) {
	// PURPOSE: return number of times retransmission is needed
	int retransmissions = 0;
	
	// Only attempt until max attempts...
	for(int i = 0; i < max; i++) {
		// Send message
		message[0] = i;
		sock.sendTo((char*)message, MSGSIZE);
		
		bool timeOut = false;
		Timer timer;
		timer.start();
		// Forever loop - check if any response
		while(true) {
			// If any data available...
			int avail = sock.pollRecFrom();
			// If data available...
			if(avail > 0)
				// Exit
				break;
			// If not, check if its time to timeout
			if(timer.lap() > TIME_OUT && !timeOut) {
				// Timeout and exit
				timeOut = true;
				break;
			}
		}
		
		// If we had to time out..
		if(timeOut) {
			// Need to redo message
			i--;
			retransmission++;
			continue;
		}
		sock.recvFrom((char*)message, MSGSIZE);
		// If we have the wrong ack...
		if(message[0] != i) {
			// Need to redo message
			i--;
			retransmission++;
			continue;
		}
	}
	
	return retransmissions;
}

void serverReliable( UdpSocket &sock, const int max, int message[] ) {
	// Only acknowledge up to max times
	for(int i = 0; i < max; i++) {
		// Forever loop as it will test many times...
		while(true) {
			// Try accept a message
			if(sock.pollRecvFrom() > 0) {
				// Recieve message
				sock.recvFrom((char*)message, MSGSIZE);
				// If we are expecting to acknowledge this message...
				if(message[0] == i) {
					// Acknowledge!
					sock.ackTo((char*)i, sizeof(i));
					break;
				}
			}
		}
	}
}
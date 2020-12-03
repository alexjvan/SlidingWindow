#include <iostream>
#include "UdpSocket.h"
#include "Timer.h"

using namespace std;

#define PORT 23460       // my UDP port
#define MAX 20000        // times of message transfer
#define MAXWIN 30        // the maximum window size
#define LOOP 10          // loop in test 4 and 5


int clientStopWait( UdpSocket &sock, const int max, int message[] ) {
	
}

void serverReliable( UdpSocket &sock, const int max, int message[] ) {
	
}
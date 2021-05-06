/*Import this produced file as raw data using Audacity with settings:

  Encoding:  Unsigned 8-bit PCM
Byte order:  Little-endian
  Channels:  1 Channel (Mono)

Then export as mp3.   */

#include <fstream>
#include <iostream>
using namespace std;

int main()
{	ifstream in_stream;
	ofstream out_stream;
	
	out_stream.open("untitled.raw");
	//Writes silence.
	for(int a = 0; a < 40000; a++) {out_stream.put(127);}
	
	//n = number of bytes to produce in this file made here.
	for(int n = 0; n < 1000; n++)
	{	for(int a = 0; a < 4; a++) {out_stream.put(-80);} for(int a = 0; a < 6; a++) {out_stream.put(127);} //Spike, long  wait = 0
		for(int a = 0; a < 4; a++) {out_stream.put(-80);} for(int a = 0; a < 6; a++) {out_stream.put(127);} //Spike, long  wait = 0
		for(int a = 0; a < 4; a++) {out_stream.put(-80);} for(int a = 0; a < 2; a++) {out_stream.put(127);} //Spike, short wait = 1
		for(int a = 0; a < 4; a++) {out_stream.put(-80);} for(int a = 0; a < 6; a++) {out_stream.put(127);} //Spike, long  wait = 0
		for(int a = 0; a < 4; a++) {out_stream.put(-80);} for(int a = 0; a < 2; a++) {out_stream.put(127);} //Spike, short wait = 1
		for(int a = 0; a < 4; a++) {out_stream.put(-80);} for(int a = 0; a < 6; a++) {out_stream.put(127);} //Spike, long  wait = 0
		for(int a = 0; a < 4; a++) {out_stream.put(-80);} for(int a = 0; a < 2; a++) {out_stream.put(127);} //Spike, short wait = 1
		for(int a = 0; a < 4; a++) {out_stream.put(-80);} for(int a = 0; a < 2; a++) {out_stream.put(127);} //Spike, short wait = 1
	}
	
	//Writes one '0' bit at the end to signify end-of-stream in RICIN 3.
	for(int a = 0; a < 4; a++) {out_stream.put(-80);} for(int a = 0; a < 100; a++) {out_stream.put(127);} //Spike, VERY LONG WAIT = end.
	
	//Writes silence.
	for(int a = 0; a < 10000; a++) {out_stream.put(127);}
	out_stream.close();
}

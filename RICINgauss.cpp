/// RICINgauss - Restricted Interface Computation Isolation Network.
/// Transfer any file through magnetic induction between online and secure offline machines.
/// Nikolay Valentinovich Repnitskiy - License: WTFPLv2+ (wtfpl.net)


/*Version 1.1, gets 250kB from 6-min recording if 4 zeros/byte. 700B/s, 1MB/24m,
or transfer this source code in 30s.    github.com/compromise-evident/RICINgauss
In the original RICIN program you transfer files through sound using a headphone
and tiny microphone taped together  face-to-face.  Procedures for RICINgauss are
all the same except both 3.5mm cords must be mono (two connections on the tips.)
Find those headphones which are given away gratis as you fly,  the ones with two
epoxied plain wires going to each headphone.  Take two wires and scrape the ends
to expose the copper under that epoxy.  Find a ferrite torus core (6mm diameter,
3mm hole, and 2mm thickness  or 6x3x2.)  Wind two turns for each wire--onto this
tiny donut and connect those  3.5mm mono cables to each winding.  Now you have a
simple transformer. Audio-out on one computer will induce a current in the other
coil which is the microphone-in on the other computer. No sound insulation here.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* WARNING:  always assume the proprietary software on your proprietary design is
  broadcasting your computer details  as it assumes that something is listening,
  and perhaps sending back instructions undermining your  privacy, security, and
  freedom from classification--such as the list  "compromised dumbass citizens."
  Now that you know  security is impossible through any attempt to assemble your
  proprietary things in some clever way, you are  encouraged  only to send files
  one way from online to offline machines only! Online machine pass instructions
  when you're not looking--only to never hear back--otherwise your  offline keys
  may be transmitted as the  offline machine might attempt to encode data on top
  of what's already being sent such as the frequencies and timing between spikes
  and silent moments of your mp3 files. Anything  proprietary  is the only risk.
* CAUTION: you MIGHT need to turn down the volume of the sending machine to 75%.
  USE THE GIVEN HASH  of each encode and decode for matching, and adjust volume.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
How to run the program  -  Software package repositories for GNU+Linux operating
systems have all the tools you can imagine. Open a terminal and use this command
as root to install Geany and g++ on your computer: apt install geany g++   Geany
is a fast & lightweight text editor and Integrated Development Environment where
you can write and run code. g++ is the GNU compiler for C++ which allows written
code to run. The compiler operates in the background and displays errors in your
code as you will see in the lower Geany box. Make a new folder somewhere on your
machine. Paste this code into Geany. For clarity in auditing, enable indentation
guides: go to View >> Show Indentation Guides. Save the document as anything.cpp
within the newly-created folder. Use these shortcuts to run the program: F9, F5.
You may paste over this code with other  .cpp files, or open a new tab & repeat.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
How to make an executable with g++  -  Save this program as anything.cpp, open a
terminal, and type g++ then space. Drag & drop this saved file into the terminal
and its directory will be  appended to your pending entry. Click on the terminal
and press enter.   a.out now resides in the user directory, you may rename it to
anything.  To run that executable, simply drag and drop it into a terminal, then
click on the terminal and press enter.  Reminder:  executable's effect-directory
is the user directory on your machine, for example:  /home/nikolay    Enjoy. */

#include <fstream>
#include <iostream>
using namespace std;

int main()
{	bool standard_aux_cord = false; /* DEFAULT = false.  Set this to true if you
	wish to use a standard aux cord of three connections on the tips to transfer
	data. CAUTION: you MIGHT need to turn down the volume of the sending machine
	to 75%. USE THE GIVEN HASH of each encode and decode for matching and adjust
	the volume. WARNING: this method is faster but unsafe (direct connection.)*/
	
	ifstream in_stream;
	ofstream out_stream;
	
	cout << "\n(RICIN magnetic induction)\n\n"
	
	     << "(1) Encode file\n"
	     << "(2) Decode recording\n\n"
	
	     << "Enter option: ";
	
	int user_option; cin >> user_option;
	if((user_option != 1) && (user_option != 2)) {cout << "\nInvalid, program ended.\n"; return 0;}
	
	
	
	
	
	//Gets path to file from user.
	cout << "\nDrag & drop file into terminal or enter path:\n\n";
	char catching_new_line[1];
	char  path_to_file[10000];
	for(int a = 0; a < 10000; a++) {path_to_file[a] = '\0';} //Fills path_to_file[] with null.
	cin.getline(catching_new_line, 1);
	cin.getline(path_to_file, 10000);
	if(path_to_file[0] == '\0') {cout << "\nNo path given.\n"; return 0;}
	
	//Fixes path to file if drag & dropped (removes single quotes for ex:)   '/home/nikolay/my documents/hush hush.bmp'
	if(path_to_file[0] == '\'')
	{	for(int a = 0; a < 10000; a++)
		{	path_to_file[a] = path_to_file[a + 1];
			if(path_to_file[a] == '\'')
			{	path_to_file[a] = '\0';
				path_to_file[a + 1] = '\0';
				path_to_file[a + 2] = '\0';
				break;
			}
		}
	}
	
	//Checks if file exists (failure can be bad path info as well.)
	in_stream.open(path_to_file);
	if(in_stream.fail() == true) {in_stream.close(); cout << "\n\nNo such file or directory.\n";             return 0;}
	char sniffed_one_file_character;
	in_stream.get(sniffed_one_file_character);
	if(in_stream.eof() == true) {in_stream.close();  cout << "\n\nNothing to process, the file is empty.\n"; return 0;}
	in_stream.close();
	
	//Gets location of the first encountered end-null coming from the left in path_to_file[].
	int path_to_file_null_bookmark;
	for(int a = 0; a < 10000; a++) {if(path_to_file[a] == '\0') {path_to_file_null_bookmark = a; break;}}
	
	
	
	
	
	//______________________________________________________Encode____________________________________________________//
	if(user_option == 1)
	{	//Prepares two file streams (read with one, write with another while both open--dynamic codec.)
		in_stream.open(path_to_file);
		path_to_file[path_to_file_null_bookmark    ] = '.'; //Appending .raw to file name in path to file.
		path_to_file[path_to_file_null_bookmark + 1] = 'r';
		path_to_file[path_to_file_null_bookmark + 2] = 'a';
		path_to_file[path_to_file_null_bookmark + 3] = 'w';
		out_stream.open(path_to_file);
		
		//Prepares for the hash or deductive lossy compression.
		long long deductive_lossy_compression[4]; //4 16-digit integers strung together, unique compression for each.
		long long snapshots[4];                   //Same but takes snapshots of compression, applies to compression after.
		for(int a = 0; a < 4; a++) {deductive_lossy_compression[a] = 5555555555555555; snapshots[a] = 5555555555555555;}
		int snapshots_interval = 0;
		
		//Writes the beginning-silence to the file.
		for(int a = 0; a < 50000; a++) {out_stream.put(127);}
		
		//Encodes and takes a hash of the input file one byte at time.
		char temp_file_byte;
		int  temp_file_byte_normal;
		in_stream.get(temp_file_byte);
		for(; in_stream.eof() == false;)
		{	//Converts file byte to (0 to 255.)
			temp_file_byte_normal = temp_file_byte;
			if(temp_file_byte_normal < 0) {temp_file_byte_normal += 256;}
			
			//Applies file byte to the hash.
			for(int a = 0; a < 4; a++)
			{	deductive_lossy_compression[a] += temp_file_byte_normal;
				deductive_lossy_compression[a] *= (a + 2);
				deductive_lossy_compression[a] %= 10000000000000000;
			}
			
			//Takes snapshots of the hash as it evolves over time.
			if((snapshots_interval ==     60) //60 catches something for the ~80-character OTP/groupOTP messages if automated with RICIN.
			|| (snapshots_interval ==   1000)
			|| (snapshots_interval ==  20000)
			|| (snapshots_interval ==  90000)
			|| (snapshots_interval == 200000))
			{	for(int a = 0; a < 4; a++)
				{	snapshots[a] += deductive_lossy_compression[a];
					snapshots[a] %= 10000000000000000;
				}
			}
			snapshots_interval++;
			
			//Converts file byte to binary of 00000000 to 11111111.
			bool binary[8] = {0};
			int place_value = 128;
			for(int a = 0; a < 8; a++)
			{	if(temp_file_byte_normal >= place_value)
				{	binary[a] = 1;
					temp_file_byte_normal -= place_value;
				}
				
				place_value /= 2;
			}
			
			//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
			///Writes 1 byte to file based on binary[].
			//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
			if(standard_aux_cord == true)
			{	for(int a = 0; a < 8; a++)
				{	if(binary[a] == 0)
					{	out_stream.put(-126); for(int a = 0; a < 6; a++) {out_stream.put(127);} //Spike, long  wait = 0
					}
					else
					{	out_stream.put(-126); for(int a = 0; a < 2; a++) {out_stream.put(127);} //Spike, short wait = 1
					}
				}
			}
			else
			{	for(int a = 0; a < 8; a++)
				{	if(binary[a] == 0)
					{	for(int a = 0; a < 4; a++) {out_stream.put(-80);} for(int a = 0; a < 6; a++) {out_stream.put(127);} //Spike, long  wait = 0
					}
					else
					{	for(int a = 0; a < 4; a++) {out_stream.put(-80);} for(int a = 0; a < 2; a++) {out_stream.put(127);} //Spike, short wait = 1
					}
				}
			}
			
			in_stream.get(temp_file_byte);
		}
		
		//Writes one '0' to file immediately after data to signify end-of-stream.
		//Look to the schematics and sample detailed in option 2 ("Decode recording".)
		if(standard_aux_cord == true)
		{	out_stream.put(-126); for(int a = 0; a < 100; a++) {out_stream.put(127);} //Spike, VERY LONG WAIT = end.
		}
		else
		{	for(int a = 0; a < 4; a++) {out_stream.put(-80);} for(int a = 0; a < 100; a++) {out_stream.put(127);} //Spike, long  wait = 0
		}
		
		//Writes the ending-silence to the file.
		for(int a = 0; a < 10000; a++) {out_stream.put(127);}
		
		in_stream.close();
		out_stream.close();
		
		//Applies snapshots to last stage of compression per integer (hash is worked on in the next few blocks.)
		for(int a = 0; a < 4; a++)
		{	deductive_lossy_compression[a] += snapshots[a];
			deductive_lossy_compression[a] %= 10000000000000000;
		}
		
		//Ensures all 4 compression integers are 16 digits long.
		for(int a = 0; a < 4; a++)
		{	if(deductive_lossy_compression[a] < 1000000000000000) {deductive_lossy_compression[a] += 1000000000000000;}
		}
		
		//Converts deductive_lossy_compression[] to 32 characters (1 char for every two contiguous digits.)
		unsigned char number[32];
		int  number_write_bookmark = 0;
		for(int a = 0; a < 4; a++)
		{	number[number_write_bookmark] =  (deductive_lossy_compression[a] / 100000000000000);        number_write_bookmark++;
			number[number_write_bookmark] = ((deductive_lossy_compression[a] /   1000000000000) % 100); number_write_bookmark++;
			number[number_write_bookmark] = ((deductive_lossy_compression[a] /     10000000000) % 100); number_write_bookmark++;
			number[number_write_bookmark] = ((deductive_lossy_compression[a] /       100000000) % 100); number_write_bookmark++;
			number[number_write_bookmark] = ((deductive_lossy_compression[a] /         1000000) % 100); number_write_bookmark++;
			number[number_write_bookmark] = ((deductive_lossy_compression[a] /           10000) % 100); number_write_bookmark++;
			number[number_write_bookmark] = ((deductive_lossy_compression[a] /             100) % 100); number_write_bookmark++;
			number[number_write_bookmark] =  (deductive_lossy_compression[a]                    % 100); number_write_bookmark++;
		}
		
		//Applies snapshots to the last character of the hash.
		for(int a = 0; a < 4; a++) {number[31] += (snapshots[a] % 100); number[31] %= 100;}
		
		//Fixes the hash, it is now complete.
		for(int a = 0; a < 32; a++)
		{	if(number[a] == 0) {number[a]++;}     //Ensures no spaces.
			if(number[a] > 94) {number[a] -= 94;} //Ensures no values > 94.
		}
		
		cout << "\n\n\n\n\nHash: "; for(int a = 0; a < 32; a++) {cout << char(number[a] + 32);}
		
		cout << "\n\nEncoded raw file now resides in the given directory. Import this raw file in\n"
		     << "Audacity: File >> Import >> Raw Data. ALWAYS use the following specifications.\n"
		     << "                   |                                     |\n"
		     << "                   |    Encoding:  Unsigned 8-bit PCM    |\n"
		     << "                   |  Byte order:  Little-endian         |\n"
		     << "                   |    Channels:  1 Channel (Mono)      |\n"
		     << "                   |                                     |\n"
		     << "Now export as mp3 @320kbps. Play it here and use Audacity on the other machine\n"
		     << "to record then Ctrl+Shift+E to export as \"other uncompressed files\" with...\n"
		     << "                   |                                     |\n"
		     << "                   |      Header:  RAW (header-less)     |\n"
		     << "                   |    Encoding:  Unsigned 8-bit PCM    |\n"
		     << "                   |                                     |\n"
		     << "RICIN may now decode this raw recording as produced on the other machine.";
	}
	
	
	
	
	
	//______________________________________________________Decode____________________________________________________//
	if(user_option == 2)
	{	//Prepares two file streams (read with one, write with another while both open--dynamic codec.)
		in_stream.open(path_to_file);
		if((path_to_file[path_to_file_null_bookmark - 4] == '.')
		&& (path_to_file[path_to_file_null_bookmark - 3] == 'r')
		&& (path_to_file[path_to_file_null_bookmark - 2] == 'a')
		&& (path_to_file[path_to_file_null_bookmark - 1] == 'w'))
		{
			path_to_file[path_to_file_null_bookmark - 4] = '-'; //If .raw present, overwrites extension with -decoded.
			path_to_file[path_to_file_null_bookmark - 3] = 'd';
			path_to_file[path_to_file_null_bookmark - 2] = 'e';
			path_to_file[path_to_file_null_bookmark - 1] = 'c';
			path_to_file[path_to_file_null_bookmark    ] = 'o';
			path_to_file[path_to_file_null_bookmark + 1] = 'd';
			path_to_file[path_to_file_null_bookmark + 2] = 'e';
			path_to_file[path_to_file_null_bookmark + 3] = 'd';
		}
		else
		{	path_to_file[path_to_file_null_bookmark    ] = '-'; //Appends -decoded if .raw not present.
			path_to_file[path_to_file_null_bookmark + 1] = 'd';
			path_to_file[path_to_file_null_bookmark + 2] = 'e';
			path_to_file[path_to_file_null_bookmark + 3] = 'c';
			path_to_file[path_to_file_null_bookmark + 4] = 'o';
			path_to_file[path_to_file_null_bookmark + 5] = 'd';
			path_to_file[path_to_file_null_bookmark + 6] = 'e';
			path_to_file[path_to_file_null_bookmark + 7] = 'd';
		}
		out_stream.open(path_to_file);
		
		//Prepares for the hash or deductive lossy compression.
		long long deductive_lossy_compression[4]; //4 16-digit integers strung together, unique compression for each.
		long long snapshots[4];                   //Same but takes snapshots of compression, applies to compression after.
		for(int a = 0; a < 4; a++) {deductive_lossy_compression[a] = 5555555555555555; snapshots[a] = 5555555555555555;}
		int snapshots_interval = 0;
		
		//Skips through the first 100,000 file bytes (user or audio player might discharge/make noise immediately after play & record.)
		char temp_file_byte;
		for(int a = 0; a < 100000; a++)
		{	in_stream.get(temp_file_byte);
			if(in_stream.eof() == true)
			{	cout << "\n\n\nFile is too short.\n\n\n";
				in_stream.close();
				out_stream.close();
				return 0;
			}
		}
		
		/*Note: other than one '0' bit appended to the data stream, audio data remains free from header and footer data or anything other
		than file data provided by the user. This makes RICIN a clean base for those modifying. You can safely append or prepend any bits
		("spike, long wait" and "spike, short wait") for metadata, but move that last '0' bit to the end of all your information.
		If observing the encoded file (raw recording) using the following program,
		~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		#include <fstream>
		#include <iostream>
		using namespace std;
		
		int main()
		{	ifstream in_stream;
			ofstream out_stream;
			
			in_stream.open("untitled.raw");
			if(in_stream.fail() == true) {cout << "no file"; return 0;}
			char temp_file_byte;
			in_stream.get(temp_file_byte);
			for(; in_stream.eof() == false;)
			{	in_stream.get(temp_file_byte);
				
				if(temp_file_byte > 95) {cout << "#";}
				else {cout << " ";}
			}
			in_stream.close();
		}
		~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		you will see tolerances are unbroken.
		* Short strings of ########### are only 9 to 11 in length,
		* long  strings of ########################### are only 17 to 21 in length.
		These are counted on file read-in and accepted if in a certain range.
		And # # are bounded to: ##### ##### and ##### # #####
		
		
		       (Always reads until this combo: space, pound, pound.) Just before that is a spike; power to the coil.
		                               |
		                              ___
		.......##################### # ################# # ################### ######### ##################### ######### # ################### ########### ######### # ################### ################### ######### # ################### ########### ################### ########### ########### ################### ################### ########### ################### ########### ################### ########### ########### #######################################################################.........
		                                     0                    0               1                0               1               0               1           1               0                   0               1                0              1               0               1            1               0                   0              1               0               1                0               1          1                    0      (45 of pound symbols means remaining silence; decoder cuts out.) Last bit is always one '0'.
		
		*/
		
		//Finds the first combo: space, pound, pound.
		char cache[3] = {'#', '#', '#'}; //Looks for " ##" string.
		for(; in_stream.eof() == false;)
		{	in_stream.get(temp_file_byte);
			
			cache[0] = cache[1];
			cache[1] = cache[2];
			if(temp_file_byte > 95) {cache[2] = '#';}
			else                    {cache[2] = ' ';}
			
			if((cache[0] == ' ')
			&& (cache[1] == '#')
			&& (cache[2] == '#')) {break;}
		}
		
		if(in_stream.eof() == true)
		{	cout << "\n\n\nNo substance detected.\n\n\n";
			in_stream.close();
			out_stream.close();
			return 0;
		}
		
		//Decodes.
		int binary[8];
		int binary_write_bookmark = 0;
		for(int pound_counter = 0;;)
		{	//Reads until the next " ##" string and counts pound symbols.
			for(; in_stream.eof() == false;)
			{	in_stream.get(temp_file_byte);
				
				cache[0] = cache[1];
				cache[1] = cache[2];
				if(temp_file_byte > 95) {cache[2] = '#'; pound_counter++;}
				else                    {cache[2] = ' ';                 }
				
				if((cache[0] == ' ')
				&& (cache[1] == '#')
				&& (cache[2] == '#')) {break;}
			}
			
			//Silence of 38 or more pound symbols means no new bit-header is visible; this cuts the input stream early.
			if(pound_counter > 45) {break;}
			
			if(in_stream.eof() == true)
			{	cout << "\n\n\nRecording corrupted.\n\n\n";
				
				in_stream.close();
				out_stream.close();
				return 0;
			}
			
			//Retrieves one bit of data.
			if(standard_aux_cord == true)
			{	if(pound_counter > 6) {binary[binary_write_bookmark] = 0;}
				else                  {binary[binary_write_bookmark] = 1;}
			}
			else
			{	if(pound_counter > 14) {binary[binary_write_bookmark] = 0;}
				else                   {binary[binary_write_bookmark] = 1;}
			}
			
			//Resetting & updating.
			binary_write_bookmark++;
			pound_counter = 0;
			
			//Extracts one byte if data if binary[] is full.
			if(binary_write_bookmark == 8)
			{	binary_write_bookmark = 0; //Resetting.
				
				//Converts from 8 binary bits to an integer.
				int extracted_byte = 0;
				int place_value = 128;
				for(int a = 0; a < 8; a++)
				{	if(binary[a] == 1) {extracted_byte += place_value;}
					
					place_value /= 2;
				}
				
				///~~~~~~~~~~~~~~~~///
				//Writes byte to file.
				///~~~~~~~~~~~~~~~~///
				if(extracted_byte < 128) {out_stream.put(extracted_byte      );}
				else                     {out_stream.put(extracted_byte - 256);}
				
				//Applies file byte to the hash.
				for(int a = 0; a < 4; a++)
				{	deductive_lossy_compression[a] += extracted_byte;
					deductive_lossy_compression[a] *= (a + 2);
					deductive_lossy_compression[a] %= 10000000000000000;
				}
				
				//Takes snapshots of the hash as it evolves over time.
				if((snapshots_interval ==     60) //60 catches something for the ~80-character OTP/groupOTP messages if automated with RICIN.
				|| (snapshots_interval ==   1000)
				|| (snapshots_interval ==  20000)
				|| (snapshots_interval ==  90000)
				|| (snapshots_interval == 200000))
				{	for(int a = 0; a < 4; a++)
					{	snapshots[a] += deductive_lossy_compression[a];
						snapshots[a] %= 10000000000000000;
					}
				}
				snapshots_interval++;
			}
		}
		
		in_stream.close();
		out_stream.close();
		
		//Applies snapshots to last stage of compression per integer (hash is worked on in the next few blocks.)
		for(int a = 0; a < 4; a++)
		{	deductive_lossy_compression[a] += snapshots[a];
			deductive_lossy_compression[a] %= 10000000000000000;
		}
		
		//Ensures all 4 compression integers are 16 digits long.
		for(int a = 0; a < 4; a++)
		{	if(deductive_lossy_compression[a] < 1000000000000000) {deductive_lossy_compression[a] += 1000000000000000;}
		}
		
		//Converts deductive_lossy_compression[] to 32 characters (1 char for every two contiguous digits.)
		unsigned char number[32];
		int  number_write_bookmark = 0;
		for(int a = 0; a < 4; a++)
		{	number[number_write_bookmark] =  (deductive_lossy_compression[a] / 100000000000000);        number_write_bookmark++;
			number[number_write_bookmark] = ((deductive_lossy_compression[a] /   1000000000000) % 100); number_write_bookmark++;
			number[number_write_bookmark] = ((deductive_lossy_compression[a] /     10000000000) % 100); number_write_bookmark++;
			number[number_write_bookmark] = ((deductive_lossy_compression[a] /       100000000) % 100); number_write_bookmark++;
			number[number_write_bookmark] = ((deductive_lossy_compression[a] /         1000000) % 100); number_write_bookmark++;
			number[number_write_bookmark] = ((deductive_lossy_compression[a] /           10000) % 100); number_write_bookmark++;
			number[number_write_bookmark] = ((deductive_lossy_compression[a] /             100) % 100); number_write_bookmark++;
			number[number_write_bookmark] =  (deductive_lossy_compression[a]                    % 100); number_write_bookmark++;
		}
		
		//Applies snapshots to the last character of the hash.
		for(int a = 0; a < 4; a++) {number[31] += (snapshots[a] % 100); number[31] %= 100;}
		
		//Fixes the hash, it is now complete.
		for(int a = 0; a < 32; a++)
		{	if(number[a] == 0) {number[a]++;}     //Ensures no spaces.
			if(number[a] > 94) {number[a] -= 94;} //Ensures no values > 94.
		}
		
		cout << "\n\n\n\n\nHash: "; for(int a = 0; a < 32; a++) {cout << char(number[a] + 32);}
		
		cout << "\n\nExtracted file now resides in the given directory.\n\n\n";
	}
}

// NOT well tested :)
// This is a simple system to ask questions and answer them.
// It is not a real system. It is just a simple example to show how to use classes and objects.

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <utility>
#include <cassert>
<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> 5c9d4ae2798303fd57eb1a8903f43f602f939582
=======
>>>>>>> 562d284e68ddcdd9378bf9958e6c20b4a8598a24
#include "AskMeSystem.h"
using namespace std;



int main() {
	AskMeSystem service;
	service.Run();

	return 0;
}


/*
101,-1,11,13,0,Should I learn C++ first or Java,I think C++ is a better Start
203,101,11,13,0,Why do you think so!,Just Google. There is an answer on Quora.
205,101,45,13,0,What about python?,
211,-1,13,11,1,It was nice to chat to you,For my pleasure Dr Mostafa
212,-1,13,45,0,Please search archive before asking,
300,101,11,13,1,Is it ok to learn Java for OOP?,Good choice
301,-1,11,13,0,Free to meet?,
302,101,11,13,1,Why so late in reply?,

13,mostafa,111,mostafa_saad_ibrahim,mostafa@gmail.com,1
11,noha,222,noha_salah,nono171@gmail.com,0
45,ali,333,ali_wael,wael@gmail.com,0
*/


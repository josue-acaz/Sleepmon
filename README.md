===================== Sleepmon =====================

Requeriments
	1. Jetson TK1
	2. SQLite3
	3. GCC Compiler

Compile and run:

	$ bash build.sh

or

	$ g++ -std=c++0x -Wno-write-strings menuPrincipal.cpp sensors/sensores.cpp sensors/hcsr04.cpp sensors/jetsonGPIO.c -o bin/Debug/Sleepmon -l sqlite3
	$ ./bin/Debug/Sleepmon
	

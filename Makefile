all:

	g++ -std=c++0x -Wno-write-strings menuPrincipal.cpp sensors/sensores.cpp sensors/hcsr04.cpp sensors/jetsonGPIO.c -o bin/Debug/Sleepmon -l sqlite3

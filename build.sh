 #!/bin/bash

#C++11: -std=c++0x
echo "Compilando..."
if ! g++ -std=c++0x -Wno-write-strings menuPrincipal.cpp sensors/sensores.cpp sensors/hcsr04.cpp sensors/jetsonGPIO.c -o bin/Debug/Sleepmon -l sqlite3
then
    echo "Erro ao compilar!"
    exit 1
fi
echo "Compilação bem sucedida!"

echo "Inicializando..."
if ! ./bin/Debug/Sleepmon
then
    echo "Inicialização bem sucedida!"
    exit 1
fi
echo "Process terminated with status (0)!"

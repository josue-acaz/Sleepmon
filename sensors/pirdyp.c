// BIBLIOTECA SIMPLES PARA UTILIZAÇÃO DO SENSOR PIR DYP-ME003 NA JETSON TK1

#include <stdio.h>
#include <unistd.h>
#include "jetsonGPIO.h"

// [EDITAR]
jetsonGPIO pirsensor = gpio166; // pino utilizado pelo sensor

// define o valor para a calibração do sensor
#define calibracao 45

unsigned int pirvalue = low;

// inicializa o sensor
void pirSetup()
{
    // disponibiliza no espaço de usuário
    gpioExport(pirsensor);
    gpioSetDirection(pirsensor,inputPin);

    printf("Calibrando sensor PIR DYP-ME003...");
    for(int i = 0; i < calibracao; i++)
    {
        printf(".");
        usleep(200000);
    }

    printf("Sensor ativado!");
    usleep(5000);
}

// lê o valor que está no sensor e retorna um inteiro (0 ou 1) == (low ou high)
int pirLeitura()
{
    pirvalue = gpioGetValue(pirsensor, &pirvalue);
    return pirvalue;
}

void pirCleanUp()
{
    gpioUnexport(pirsensor);
}

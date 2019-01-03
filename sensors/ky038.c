// BIBLIOTECA SIMPLES PARA UTILIZAÇÃO DO SENSOR KY-038 NA JETSON TK1

#include <stdio.h>
#include <unistd.h>
#include "jetsonGPIO.h"

// [EDITAR]
jetsonGPIO kysensor = gpio161; // pino utilizado pelo sensor

unsigned int kyvalue = low;

// inicializa o sensor
void kySetup()
{
    // disponibiliza no espaço de usuário
    gpioExport(kysensor);
    gpioSetDirection(kysensor,inputPin);
}

// lê o valor que está no sensor e retorna um inteiro (0 ou 1) == (low ou high)
int kyLeitura()
{
    kyvalue = gpioGetValue(pirsensor, &kyvalue);
    return kyvalue;
}

void kyCleanUp()
{
    gpioUnexport(kysensor);
}

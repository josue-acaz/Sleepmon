#include <iostream>
#include <string.h>
#include <string>
#include "sensores.h"
#include "../database/conectaDB.c"
#include "../aux/util.c"
#include "hcsr04.h"
#include "pirdyp.c"
#include "ky038.c"

HCSR04 hcsr; // Objeto da classe HCSR04

void Sensores::iniciaSensores()
{
    // PIR-DYPME003 SENSOR
    movimento();

    // KY-038 SENSOR
    ruido();

    // HC-SR04
    distancia();

    // ARMAZENA OS DADOS
    armazenaDados();
}

void Sensores::luminosidade()
{
    //...
}

void Sensores::distancia()
{
    // SETUP
    hcsr.exportGPIO();
    hcsr.setDirection();
    // ... implementar
}

void Sensores::movimento()
{
    pirSetup();
}

void Sensores::climate()
{
    //...
}

void Sensores::ruido()
{
    kySetup();
}

void Sensores::armazenaDados()
{
    
    iniciaDB(); // EFETUA CONEXÃO COM O BANCO DE DADOS
    criaSchema(); // CRIA SCHEMA CASO SEJA O PRIMEIRO ACESSO

    // MOTION
    executeSQL(concat("INSERT INTO motion (pir,coleta_em) VALUES(", concat(intToChar(pirLeitura(), 200), ", CURRENT_TIMESTAMP);")));

    // NOISE
    executeSQL(concat("INSERT INTO noise (ruido,coleta_em) VALUES(", concat(intToChar(kyLeitura(), 300), ", CURRENT_TIMESTAMP);")));

    // DISTANCIA
    // ... executeSQL(...)

    fechaDB(); // FECHA A CONEXÃO COM O BANCO DE DADOS
}

void Sensores::closeAllSensors()
{
    std::cout << "Fechando espaços do usuário..." << std::endl;
    pirCleanUp(); // Movimento
    kyCleanUp(); // Ruído
    //...
}

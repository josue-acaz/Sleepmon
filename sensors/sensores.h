#ifndef SENSORES_H
#define SENSORES_H

using namespace std;

class Sensores{
public:
    void iniciaSensores();
    void armazenaDados();

    //SENSORES
    void luminosidade(); //Sensor de luminosidade BH1750
    void distancia(); //Sensor de distância ultrasônico HC-SR04
    void movimento(); //Sensor de movimento PIR DYP-MR003
    void climate(); //Sensor de temperatura e humidade DHT22
    void ruido(); //Sensor de som ou ruído KY-038

    //FECHA SENSORES
    void closeAllSensors();
};

#endif
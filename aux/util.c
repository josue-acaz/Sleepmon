#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

// Função para concatenar cadeia de caracteres
// O primeiro argumento é a cadeia destino da operação
// O segundo argumento é a cadeia que será concatenada a cadeia destino
static char* concat(char* destination, char* source)
{
    size_t aValue = strlen(destination);
    size_t bValue = strlen(source);

    char* str1 = (char*)malloc(sizeof(char)*aValue);
    char* str2 = (char*)malloc(sizeof(char)*bValue);
    strcpy (str1,destination);
    strcpy (str2,source);
    strncat (str1, str2, (aValue+bValue));

    return str1;
}

// Função para converter um inteiro em uma cedeia de caracteres do tipo char*
// O primeiro argumento é o valor a ser convertido
// O segundo argumento é o tamanho da memória que será alocada dinâmicamente
char* intToChar(int value, size_t tam)
{
    char *buffer = (char*)malloc(sizeof(char)*tam);
    sprintf(buffer,"%d",value);
    
    return buffer;
}

// Função para testar sensor ultrasônico HCSR04
int getkey() {
    int character;
    struct termios orig_term_attr;
    struct termios new_term_attr;

    /* set the terminal to raw mode */
    tcgetattr(fileno(stdin), &orig_term_attr);
    memcpy(&new_term_attr, &orig_term_attr, sizeof(struct termios));
    new_term_attr.c_lflag &= ~(ECHO|ICANON);
    new_term_attr.c_cc[VTIME] = 0;
    new_term_attr.c_cc[VMIN] = 0;
    tcsetattr(fileno(stdin), TCSANOW, &new_term_attr);

    /* read a character from the stdin stream without blocking */
    /*   returns EOF (-1) if no character is available */
    character = fgetc(stdin);

    /* restore the original terminal attributes */
    tcsetattr(fileno(stdin), TCSANOW, &orig_term_attr);

    return character;
}

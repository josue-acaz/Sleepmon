#ifndef CONECTADB_H
#define CONECTADB_H

//TO REALIZE BASIC OPERATION IN DATABASE
static int callback(void *NotUsed, int argc, char **argv, char **azColName);

//FUNCTIONS FOR CONECTION DATABASE
int iniciaDB();
void criaSchema();
void fechaDB();
void executeArraySQL(char command[][200], int length);
void executeSQL(char value[]);

#endif
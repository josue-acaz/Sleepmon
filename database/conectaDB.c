#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "conectaDB.h"

// Variáveis globais
sqlite3 *db;
char *zErrMsg = 0;
int rc;
const char* data = "Callback function called";

// função que realiza operações de criação de tabelas e/ou inserção de valores
static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

// essa função pode ser utilizada para diminuir o código de criação das tabelas
// 'command' é um vetor de char que abriga todo o código de criação de tabelas
// 'length' é o número de elementos desse vetor, ou seja, o número de tabelas
void executeArraySQL(char command[][200], int length)
{
   for (int i = 0; i < length; i++)
  {
    rc = sqlite3_exec(db, command[i], callback, 0, &zErrMsg);
  }
}

// essa função é utilizada para inserir os valores no banco de dados
void executeSQL(char value[])
{
   rc = sqlite3_exec(db, value, callback, 0, &zErrMsg);
}

// função que faz a conexão com o banco de dados
int iniciaDB()
{
   rc = sqlite3_open("database/sensores.db", &db);

   if( rc ) {
      fprintf(stderr, "Erro ao estabelecer conexao com o banco de dados! %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stdout, "Conexao bem sucedida!\n");
   }
}

// função que contém o código de criação das tabelas
void criaSchema()
{
   //CÓDIGO SQL DE CRIAÇÃO DE TABELAS
   //5 TABELAS
   char sql[5][200] = {"CREATE TABLE IF NOT EXISTS climate("  \
        "idclimate INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," \
        "temperatura REAL," \
        "umidade REAL," \
        "coleta_em TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL);",

        "CREATE TABLE IF NOT EXISTS luminosity(" \
        "idluminosity INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," \
        "luminosidade REAL," \
        "coleta_em TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP);",

        "CREATE TABLE IF NOT EXISTS motion(" \
        "idmotion INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," \
        "pir BOOLEAN," \
        "coleta_em TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL);",

        "CREATE TABLE IF NOT EXISTS noise("  \
        "idnoise INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"  \
        "ruido REAL,"  \
        "coleta_em TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL);",
        
        "CREATE TABLE IF NOT EXISTS distance("  \
        "iddistance INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"  \
        "ultrasonic REAL,"  \
        "coleta_em TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL);"};

        // CHAMA A FUNÇÃO PARA CRIAR TABELAS
        executeArraySQL(sql, 5);

   // VERIFICA DEPENDÊNCIAS
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Operacao realizada com sucesso!\n");
   }
}

// função que fecha o banco de dados
void fechaDB()
{
   sqlite3_close(db);
}

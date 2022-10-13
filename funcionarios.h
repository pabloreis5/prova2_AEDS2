#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

#include <stdio.h>

typedef struct Funcionario {
    int codigo;
    char nome[50];
    char cpf[15];
    char data_nascimento[11];
    double salario;
} Tfunc;

void salva(Tfunc *func, FILE *out);
Tfunc  *le (FILE *in);
void cria_base_dados(FILE *arq, int nFunc);
void imprimir();


#endif // FUNCIONARIOS_H

#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

#include <stdio.h>

#define TAM_NOME 200

typedef struct Funcionario {
    int cod;
    char nome[TAM_NOME];
    char cpf[15];
    char data_nascimento[11];
    double salario;
}TFunc;

TFunc *funcionario(int cod, char *nome, char *cpf, char *data, double salario);

int tamanho_registro();

void salva_funcionario(TFunc *func, FILE *out);

TFunc *le_funcionario(FILE *in);

void imprime_funcionario(TFunc *funcionario);

void cria_base_dados_funcionarios(FILE* arq, FILE* arqIndicePrimario, FILE* arqIndicePrimarioNaoOrdenado, int nFunc);

void cria_base_dados_funcionarios_teste(FILE* arq, FILE* arqIndicePrimario,  FILE* arqIndicePrimarioNaoOrdenado, int nFunc);

void imprime_base_dados_funcionarios(FILE *arq, int nFunc);

void imprime_indice_primario_funcionarios(FILE *arqIndicePrimario, int nFunc);

#endif

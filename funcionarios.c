#include "funcionarios.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

void salva(Tfunc *func, FILE *out) {

    fwrite(&func->codigo, sizeof(int), 1, out);
    fwrite(func->nome, sizeof(char), sizeof(func->nome), out);
    fwrite(func->cpf, sizeof(char), sizeof(func->cpf), out);
    fwrite(func->data_nascimento, sizeof(char), sizeof(func->data_nascimento), out);
    fwrite(&func->salario, sizeof(double), 1, out);

}

Tfunc  *le (FILE *in) {

    Tfunc *func = (Tfunc *) malloc(sizeof(Tfunc));

    if(0 >= fread(&func->codigo, sizeof(int), 1,in)) {
        free(func);
        return NULL;
    }

    fread(func->nome, sizeof(char), sizeof(func->nome), in);
    fread(func->cpf, sizeof(char), sizeof(func->cpf), in);
    fread(func->data_nascimento, sizeof(char), sizeof(func->data_nascimento), in);
    fread(&func->salario, sizeof(double), 1, in);

    return func;
}

void cria_base_dados(FILE *arq, int nFunc) {

    srand(time(NULL));

    FILE * arqIndex;
    arqIndex = fopen("dadosIndex.bin", "wb");

    for(int i = 1; i <= nFunc; i++) {
        int r = rand() % 1000;
        Tfunc func;
        func.codigo = r;
        sprintf(func.nome, "Funcionario %d", i);
        sprintf(func.cpf, "111.111.111-11");
        sprintf(func.data_nascimento, "01/06/2000");
        func.salario = 1000 + i;

        fwrite(&func.codigo, sizeof(int), 1, arqIndex);
        fwrite(&i, sizeof(int), 1, arqIndex);

        fseek(arq, i * sizeof(Tfunc), SEEK_SET);
        salva(&func, arq);
    }

    fclose(arqIndex);
}
void imprimir(){

    int i = 1;
    FILE * arqRead;
    arqRead = fopen("dados.bin", "rb");

    fseek(arqRead, i * sizeof(Tfunc), SEEK_SET);
    Tfunc *tfunc = le(arqRead);
    printf(">(%d) %d | %s | \n", i,tfunc->codigo, tfunc->nome);



}



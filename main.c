#include <stdio.h>
#include "funcionarios.h"

int main() {

    FILE * arq;
    arq = fopen("dados.bin", "wb");
    cria_base_dados(arq, 10);

    imprimir();




    fclose(arq);

    return 0;
}

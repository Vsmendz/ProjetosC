#include "fila_din.c"
#include "fila_din.h"

int main(int argc, char const *argv[])
{
    tipo_fila *fila = NULL;
    inserir_fila(&fila,10);
    inserir_fila(&fila,30);
    inserir_fila(&fila,20);

    printf("primeiro %d\n",print_primeiro(fila));

    print_all(fila);

    printf("removido %d\n", remover_fila(&fila));
    printf("removido %d\n", remover_fila(&fila));
    printf("removido %d\n", remover_fila(&fila));
   return 0;
}

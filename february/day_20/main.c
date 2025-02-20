#include "lista_din.c"

int main(int argc, char const *argv[])
{
    tipo_lista *ls;
    ls = NULL;

    inserir_first(&ls,10);
    inserir_first(&ls,20);
    inserir_first(&ls,30);
    inserir_first(&ls,40);
    inserir_end(&ls,100);
    inserir_index(&ls,43,2);
    remover_first(&ls);
    remover_end(&ls);
    remover_index(&ls,2);
    remover_valor(&ls,43);
    imprimir(ls);
    printf("valores %d\n",contagem(ls));
    
    return 0;
}

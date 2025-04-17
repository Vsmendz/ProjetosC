#include "heap_sort.c"

int main(int argc, char const *argv[])
{
    tipo_heap* th = iniciar_heap();


    inserir(th,4);
    inserir(th,2);
    inserir(th,5);
    inserir(th,6);
    inserir(th,7);

    remove_raiz_ord(th);
    remove_raiz_ord(th);
    remove_raiz_ord(th);
    remove_raiz_ord(th);

    printf("Lista heap\n");
    int i;
    for (i = 0; i < th->cont; i++)
    {
        printf("[%d]",th->lista[i]);
    }
    printf("\n");
    printf("Lista heap ord\n");
    for (i = 0; i < th->cont_ord; i++)
    {
        printf("[%d]",th->lista_ord[i]);
    }
    return 0;
}

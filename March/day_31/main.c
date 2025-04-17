#include "heap.c"

int main(int argc, char const *argv[])
{
    tipo_heap* th = iniciar_heap();
    
    inserir(th,4);
    inserir(th,2);
    inserir(th,5);
    inserir(th,6);
    inserir(th,7);

    remove_raiz(th);

    int i;
    for (i = 0; i < th->cont; i++)
    {
        printf("[%d]",th->lista[i]);
    }
    
    return 0;
}

#include "lista_d.c"

int main(int argc, char const *argv[])
{
    tipo_lista *ls = NULL;
    inserirIni(&ls,10);
    inserirIni(&ls,20);
    inserirFim(&ls,90);
    inserirId(&ls,780,1);
    removerFim(&ls);
    removerIni(&ls);
    removerId(&ls,10);
    inserirFim(&ls,90);
    removerValor(&ls,7870);
    imprimir(ls);

    return 0;
}

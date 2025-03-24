#include "tabela_hash.h"

// Função que aloca um novo nó na tabela hash
no_tabela_hash* aloca_no(int chave, int valor) {
    // Aloca memória para um novo nó
    no_tabela_hash* novo_no = malloc(sizeof(no_tabela_hash));
    
    // Atribui os valores de chave e valor ao nó
    novo_no->chave = chave;
    novo_no->valor = valor;
    
    // Inicializa o ponteiro para o próximo nó como NULL
    novo_no->prox = NULL;
    
    // Retorna o ponteiro para o novo nó
    return novo_no;
}

// Função de hash que calcula o índice baseado na chave
int funcao_hash(int chave) {
    // Retorna o índice calculado através do módulo
    return chave % TAM;
}

// Função para inicializar a tabela hash, setando todas as posições como NULL
void iniciar_tabela(est_tabela_hash *tab) {
    int i;
    
    // Percorre todas as posições da tabela e as inicializa como NULL
    for (i = 0; i < TAM; i++) {
        tab->tabela_hash[i] = NULL;
    }
}

// Função para inserir um novo valor na tabela hash
void inserir_tabela(est_tabela_hash* tab, int chave, int valor) {
    // Calcula o índice usando a função de hash
    int index = funcao_hash(chave);
    
    // Se o índice está vazio, aloca um novo nó diretamente
    if (tab->tabela_hash[index] == NULL) {
        tab->tabela_hash[index] = aloca_no(chave, valor);
    } else {
        // Caso contrário, percorre a lista encadeada no índice até o final
        no_tabela_hash *aux = tab->tabela_hash[index];
        
        // Vai até o final da lista
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        
        // Insere o novo nó no final da lista
        aux->prox = aloca_no(chave, valor);
    }
}

// Função para remover um valor da tabela hash
void remover_tabela(est_tabela_hash* tab, int chave) {
    // Calcula o índice usando a função de hash
    int index = funcao_hash(chave);
    
    // Ponteiros auxiliares para percorrer a lista e remover o nó
    no_tabela_hash *aux, *ant;
    aux = tab->tabela_hash[index];
    ant = tab->tabela_hash[index];
    
    // Verifica se o primeiro nó da lista é o que desejamos remover
    if (tab->tabela_hash[index]->chave == chave) {
        tab->tabela_hash[index] = aux->prox;  // Atualiza o ponteiro da tabela
        free(aux);  // Libera a memória do nó removido
    } else {
        // Caso o nó não seja o primeiro, percorre a lista
        while (aux != NULL && aux->chave != chave) {
            aux = aux->prox;
        }
    }
    
    // Caso não tenha encontrado o nó, imprime mensagem de erro
    if (aux == NULL) {
        printf("chave nao encontrada\n");
        return;
    }
    
    // Se o nó foi encontrado, percorre até o nó anterior
    while (ant->prox != aux) {
        ant = ant->prox;
    }
    
    // Atualiza o ponteiro do nó anterior para o próximo do nó removido
    ant->prox = aux->prox;
    
    // Libera a memória do nó removido
    free(aux);
}

// Função para buscar um valor na tabela hash
void buscar_tabela(est_tabela_hash* tab, int chave) {
    // Verifica se a tabela está inicializada
    if (tab == NULL) {
        printf("Tabela hash nao inicializada\n");
        return; // Retorna sem fazer nada se a tabela não estiver inicializada
    }
    
    // Calcula o índice usando a função de hash
    int index = funcao_hash(chave);
    
    // Ponteiro auxiliar para percorrer a lista encadeada no índice
    no_tabela_hash* aux = tab->tabela_hash[index];
    
    // Percorre a lista até encontrar a chave
    while (aux != NULL) {
        if (aux->chave == chave) {
            // Se a chave for encontrada, retorna o valor associado
            return aux->valor;
        }
        aux = aux->prox;
    }
    
    // Se a chave não for encontrada, imprime mensagem de erro
    printf("Chave %d nao encontrada na tabela\n", chave);
    return; // Retorna sem valor
}

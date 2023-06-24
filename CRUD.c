#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Documentacao do codigo: https://level-chevre-849.notion.site/Documenta-o-290b148b42c84fda81250703b42eacdf
#define MAX_ITEMS 200
#define FILENAME "items.txt"

typedef struct
{
    char cod[50];
    char name[50];
    char category[50];
    char quantity[20];
} Item;

Item Items[MAX_ITEMS];
int numItems = 0;

void createItem()
{

    if (numItems >= MAX_ITEMS) // Verifica se a lista de itens está cheia
    {
        printf("A lista de items esta cheia.\n");
        return;
    }

    Item newItem; // Declara uma nova variável do tipo Item para armazenar os dados do novo item

    printf("Digite (s p/ sair):\n");
    printf("Digite o codigo do item: ");
    scanf("%s", newItem.cod); // Solicita ao usuário para digitar o código do item e armazena

    if (strcmp(newItem.cod, "s") == 0) // Verifica se o código digitado é igual a "s"
    {
        return; // Retorna, encerrando a função
    }

    printf("Digite o nome do item: ");
    scanf("%s", newItem.name);

    if (strcmp(newItem.name, "s") == 0)
    {
        return;
    }

    printf("Digite a categoria do item: ");
    scanf("%s", newItem.category);

    if (strcmp(newItem.category, "s") == 0)
    {
        return;
    }

    printf("Digite a quantidade de item(s): ");
    scanf("%s", newItem.quantity);

    if (strcmp(newItem.quantity, "s") == 0)
    {
        return;
    }

    int itemIndex = -1;                // Declara e inicializa uma variável para armazenar o índice do item na lista, iniciando com -1
    for (int i = 0; i < numItems; i++) // Itera sobre os itens existentes na lista
    {
        if (strcmp(Items[i].cod, newItem.cod) == 0) // Verifica se o código do item atual é igual ao código do novo item
        {
            itemIndex = i; // Armazena o índice do item atual na variável itemIndex
            break;         // Sai do loop
        }
    }

    if (itemIndex == -1) // Verifica se o item não existe na lista (índice igual a -1)
    {
        Items[numItems] = newItem; // Adiciona o novo item na lista, na posição numItems
        numItems++;                // Incrementa o contador de itens
        printf("Item criado com sucesso.\n");
        createItem(); // Chama recursivamente a função para permitir a criação de mais itens
    }
    else // Caso o item já exista na lista
    {
        int num1 = atoi(Items[itemIndex].quantity); // Converte a quantidade do item existente para um inteiro
        int num2 = atoi(newItem.quantity);          // Converte a quantidade do novo item para um inteiro
        int num3 = num1 + num2;                     // Soma as quantidades
        sprintf(newItem.quantity, "%d", num3);      // Converte o resultado de volta para uma string
        Items[itemIndex] = newItem;                 // Atualiza o item existente na lista com as informações
        printf("Item atualizado com sucesso.\n");
        createItem();
    }

    FILE *file = fopen(FILENAME, "w"); // Abre o arquivo no modo de escrita ("w")
    if (file == NULL)                  // Verifica se ocorreu um erro ao abrir o arquivo
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < numItems; i++) // Itera sobre os itens na lista
    {
        fprintf(file, "Codigo: %s Nome: %s Categoria: %s Quantidade: %s\n", Items[i].cod, Items[i].name, Items[i].category, Items[i].quantity); // Escreve as informações do item no arquivo
    }

    fclose(file);
}

void readItems()
{
    FILE *file = fopen(FILENAME, "r"); // Abre o arquivo no modo de leitura ("r")
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int lineCount = 1;                              // Declara e inicializa uma variável para contar as linhas do arquivo, começando em 1
    char line[200];                                 // Declara um array de caracteres para armazenar cada linha lida do arquivo
    while (fgets(line, sizeof(line), file) != NULL) // Lê cada linha do arquivo até o final
    {
        printf("%s", line);
        lineCount++;
    }

    fclose(file);
}

void updateItem()
{
    char searchCod[50]; // Declara um array de caracteres para armazenar o código de busca
    int itemIndex = -1; // Declara e inicializa uma variável para armazenar o índice do item a ser atualizado, iniciando com -1

    if (numItems == 0) // Verifica se a lista de itens está vazia
    {
        printf("A lista de items esta vazia.\n");
        return;
    }

    printf("Digite o codigo do item que deseja atualizar(s p/ sair): ");
    scanf("%s", searchCod);

    if (strcmp(searchCod, "s") == 0)
    {
        return;
    }

    for (int i = 0; i < numItems; i++) // Itera sobre os itens existentes na lista
    {
        if (strcmp(Items[i].cod, searchCod) == 0) // Verifica se o código do item atual é igual ao código de busca
        {
            itemIndex = i; // Armazena o índice do item atual na variável itemIndex
            break;         // Sai do loop
        }
    }

    if (itemIndex == -1) // Verifica se o item não foi encontrado (índice igual a -1)
    {
        printf("Item nao encontrado, Digite novamente.\n");
        updateItem(); // Chama recursivamente a função para permitir nova tentativa de atualização
    }
    else // Caso o item tenha sido encontrado
    {
        printf("Digite o nome do novo item: ");
        scanf("%s", Items[itemIndex].name); // Solicita ao usuário o novo nome do item e armazena

        printf("Digite a categoria do novo item: ");
        scanf("%s", Items[itemIndex].category);

        printf("Digite a quantidade de novo(s) item(s): ");
        scanf("%s", Items[itemIndex].quantity);

        FILE *file = fopen(FILENAME, "w"); // Abre o arquivo no modo de escrita ("w")
        if (file == NULL)                  // Verifica se ocorreu um erro ao abrir o arquivo
        {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }

        for (int i = 0; i < numItems; i++) // Itera sobre os itens na lista
        {
            fprintf(file, "Codigo: %s Nome: %s Categoria: %s Quantidade: %s\n", Items[i].cod, Items[i].name, Items[i].category, Items[i].quantity); // Escreve as informações do item no arquivo
        }

        fclose(file);

        printf("Item atualizado com sucesso.\n");
        updateItem(); // Chama recursivamente a função para permitir a atualização de mais itens
    }
}

void deleteItem()
{
    if (numItems == 0) // Verifica se a lista de itens está vazia
    {
        printf("A lista de items esta vazia.\n");
        return;
    }

    char searchCod[50]; // Declara um array de caracteres para armazenar o código de busca
    printf("Digite o codigo do item que deseja excluir(s p/ sair): ");
    scanf("%s", searchCod); // Solicita ao usuário o código do item a ser excluído e armazena em searchCod

    if (strcmp(searchCod, "s") == 0)
    {
        return;
    }

    int itemIndex = -1;                // Declara e inicializa uma variável para armazenar o índice do item a ser excluído, iniciando com -1
    for (int i = 0; i < numItems; i++) // Itera sobre os itens existentes na lista
    {
        if (strcmp(Items[i].cod, searchCod) == 0) // Verifica se o código do item atual é igual ao código de busca
        {
            itemIndex = i; // Armazena o índice do item atual na variável itemIndex
            break;         // Sai do loop
        }
    }

    if (itemIndex == -1) // Verifica se o item não foi encontrado (índice igual a -1)
    {
        printf("Item nao encontrado.\n");
        deleteItem(); // Chama recursivamente a função para permitir nova tentativa de exclusão
    }

    for (int i = itemIndex; i < numItems - 1; i++) // Desloca os itens seguintes para preencher o espaço do item excluído
    {
        Items[i] = Items[i + 1];
    }

    numItems--; // Decrementa o número total de itens

    FILE *file = fopen(FILENAME, "w"); // Abre o arquivo no modo de escrita ("w")
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < numItems; i++) // Itera sobre os itens na lista
    {
        fprintf(file, "Codigo: %s Nome: %s Categoria: %s Quantidade: %s\n", Items[i].cod, Items[i].name, Items[i].category, Items[i].quantity); // Escreve as informações do item no arquivo
    }

    fclose(file);
    printf("Item excluido com sucesso.\n");
    deleteItem(); // Chama recursivamente a função para permitir a exclusão de mais itens
}

void queryItem()
{
    if (numItems == 0) // Verifica se a lista de itens está vazia
    {
        printf("A lista de items esta vazia.\n");
        return;
    }

    char searchCod[50];
    printf("Digite o codigo do item que deseja consultar(s p/ sair): ");
    scanf("%s", searchCod);

    if (strcmp(searchCod, "s") == 0)
    {
        return;
    }

    int itemIndex = -1;
    for (int i = 0; i < numItems; i++) // Itera sobre os itens existentes na lista
    {
        if (strcmp(Items[i].cod, searchCod) == 0) // Verifica se o código do item atual é igual ao código de busca
        {
            itemIndex = i; // Armazena o índice do item atual na variável itemIndex
            break;
        }
    }

    if (itemIndex == -1)
    {
        printf("Item nao encontrado.\n");
        queryItem(); // Chama recursivamente a função para permitir nova tentativa de consulta
    }

    printf("Codigo: %s Nome: %s Categoria: %s Quantidade: %s\n", Items[itemIndex].cod, Items[itemIndex].name, Items[itemIndex].category, Items[itemIndex].quantity); // Exibe as informações do item consultado

    queryItem(); // Chama recursivamente a função para permitir a consulta de mais itens
}

void generatePopularItemsReport()
{
    if (numItems == 0)
    {
        printf("A lista de itens esta vazia.\n");
        return;
    }

    int maxQuantities[3] = {0};        // Declara um array para armazenar as três maiores quantidades de itens, iniciando com zeros
    for (int i = 0; i < numItems; i++) // Itera sobre os itens existentes na lista
    {
        int quantity = atoi(Items[i].quantity); // Converte a quantidade do item atual para um valor inteiro usando a função atoi()

        if (quantity > maxQuantities[0]) // Verifica se a quantidade é maior que a maior quantidade atual (índice 0)
        {
            maxQuantities[2] = maxQuantities[1]; // Move a segunda maior quantidade para o índice 2
            maxQuantities[1] = maxQuantities[0]; // Move a maior quantidade para o índice 1
            maxQuantities[0] = quantity;         // Armazena a nova maior quantidade no índice 0
        }
        else if (quantity > maxQuantities[1]) // Verifica se a quantidade é maior que a segunda maior quantidade atual (índice 1)
        {
            maxQuantities[2] = maxQuantities[1]; // Move a segunda maior quantidade para o índice 2
            maxQuantities[1] = quantity;         // Armazena a nova segunda maior quantidade no índice 1
        }
        else if (quantity > maxQuantities[2]) // Verifica se a quantidade é maior que a terceira maior quantidade atual (índice 2)
        {
            maxQuantities[2] = quantity; // Armazena a nova terceira maior quantidade no índice 2
        }
    }

    printf("Tres itens com as maiores quantidades:\n");

    int count = 0;                     // Variável para contar a quantidade de itens já exibidos
    for (int i = 0; i < numItems; i++) // Itera sobre os itens na lista
    {
        int quantity = atoi(Items[i].quantity); // Converte a quantidade do item atual para um valor inteiro usando a função atoi()

        if (quantity == maxQuantities[0] || quantity == maxQuantities[1] || quantity == maxQuantities[2]) // Verifica se a quantidade do item atual é uma das três maiores quantidades
        {
            printf("Codigo: %s\n", Items[i].cod);
            printf("Nome: %s\n", Items[i].name);
            printf("Categoria: %s\n", Items[i].category);
            printf("Quantidade: %s\n\n", Items[i].quantity);
            count++; // Incrementa o contador de itens exibidos

            if (count == 3) // Verifica se já foram exibidos os três itens
                break;      // Sai do loop
        }
    }
}

void generateLowStockReport()
{
    if (numItems == 0) // Verifica se a lista de itens está vazia
    {
        printf("A lista de itens esta vazia.\n"); // Exibe uma mensagem informando que a lista está vazia
        return;                                   // Retorna, encerrando a função
    }

    int minQuantities[3] = {INT_MAX, INT_MAX, INT_MAX}; // Declara um array para armazenar as três menores quantidades de itens, iniciando com o valor máximo de um inteiro
    for (int i = 0; i < numItems; i++)                  // Itera sobre os itens existentes na lista
    {
        int quantity = atoi(Items[i].quantity); // Converte a quantidade do item atual para um valor inteiro usando a função atoi()

        if (quantity < minQuantities[0]) // Verifica se a quantidade é menor que a menor quantidade atual (índice 0)
        {
            minQuantities[2] = minQuantities[1]; // Move a segunda menor quantidade para o índice 2
            minQuantities[1] = minQuantities[0]; // Move a menor quantidade para o índice 1
            minQuantities[0] = quantity;         // Armazena a nova menor quantidade no índice 0
        }
        else if (quantity < minQuantities[1]) // Verifica se a quantidade é menor que a segunda menor quantidade atual (índice 1)
        {
            minQuantities[2] = minQuantities[1]; // Move a segunda menor quantidade para o índice 2
            minQuantities[1] = quantity;         // Armazena a nova segunda menor quantidade no índice 1
        }
        else if (quantity < minQuantities[2]) // Verifica se a quantidade é menor que a terceira menor quantidade atual (índice 2)
        {
            minQuantities[2] = quantity; // Armazena a nova terceira menor quantidade no índice 2
        }
    }

    printf("Tres itens com estoque mais baixo:\n");
    int count = 0;                     // Variável para contar a quantidade de itens já exibidos
    for (int i = 0; i < numItems; i++) // Itera sobre os itens na lista
    {
        int quantity = atoi(Items[i].quantity); // Converte a quantidade do item atual para um valor inteiro usando a função atoi()

        if (quantity == minQuantities[0] || quantity == minQuantities[1] || quantity == minQuantities[2]) // Verifica se a quantidade do item atual é uma das três menores quantidades
        {
            printf("Codigo: %s\n", Items[i].cod);            // Exibe o código do item
            printf("Nome: %s\n", Items[i].name);             // Exibe o nome do item
            printf("Categoria: %s\n", Items[i].category);    // Exibe a categoria do item
            printf("Quantidade: %s\n\n", Items[i].quantity); // Exibe a quantidade do item
            count++;                                         // Incrementa o contador de itens exibidos

            if (count == 3) // Verifica se já foram exibidos os três itens
                break;      // Sai do loop
        }
    }
}

void generateStockByCategoryReport()
{
    // Verifica se a lista de itens está vazia
    if (numItems == 0)
    {
        printf("A lista de itens está vazia.\n");
        return;
    }

    // Variáveis para armazenar as categorias e quantidades
    int numCategories = 0;
    char categories[MAX_ITEMS][50];
    int quantities[MAX_ITEMS] = {0};

    // Loop para percorrer todos os itens
    for (int i = 0; i < numItems; i++)
    {
        // Obtém a categoria e quantidade do item atual
        char *category = Items[i].category;
        int quantity = atoi(Items[i].quantity);

        // Verifica se a categoria já foi encontrada anteriormente
        int categoryIndex = -1;
        for (int j = 0; j < numCategories; j++)
        {
            if (strcmp(categories[j], category) == 0)
            {
                categoryIndex = j;
                break;
            }
        }

        // Se a categoria não foi encontrada, adiciona-a ao vetor de categorias
        // e incrementa o número de categorias encontradas
        if (categoryIndex == -1)
        {
            categoryIndex = numCategories;
            strcpy(categories[numCategories], category);
            numCategories++;
        }

        // Incrementa a quantidade total da categoria encontrada
        quantities[categoryIndex] += quantity;
    }

    // Imprime o relatório de estoque por categoria e quantidade
    printf("Relatorio de estoque por categoria e quantidade:\n");
    for (int i = 0; i < numCategories; i++)
    {
        printf("Categoria: %s\n", categories[i]);
        printf("Quantidade: %d\n\n", quantities[i]);
    }
}

void reportMenu()
{
    printf("\n");
    printf("Selecione uma opcao:\n");
    printf("[ 1 ] Relatorio de itens com maior quantidade:\n");
    printf("[ 2 ] Relatorio de estoque baixo:\n");
    printf("[ 3 ] Relatorio de estoque por categoria e quantidade:\n");
    printf("[ 0 ] Voltar\n");
}

void menu()
{
    printf("\n");
    printf("Selecione uma opcao:\n");
    printf("[ 1 ] Criar um item\n");
    printf("[ 2 ] Listar items\n");
    printf("[ 3 ] Atualizar um item\n");
    printf("[ 4 ] Excluir um item\n");
    printf("[ 5 ] Consultar item\n");
    printf("[ 6 ] Gerar relatorio\n");
    printf("[ 0 ] Sair\n");
}

void switchReportMenu(int choice)
{
    switch (choice)
    {
    case 0:
        printf("Saindo...\n");
        break;
    case 1:
        generatePopularItemsReport();
        break;
    case 2:
        generateLowStockReport();
        break;
    case 3:
        generateStockByCategoryReport();
        break;
    default:
        printf("Opcao invalida.\n");
        break;
    }
}

void generateReport()
{
    int choice;
    while (1)
    {
        reportMenu();
        scanf("%d", &choice);
        if (choice == 0)
        {
            break;
        }

        switchReportMenu(choice);
    }
}

void switchMenu(int choice)
{
    switch (choice)
    {
    case 0:
        printf("Saindo...\n");
        exit(0);
    case 1:
        createItem();
        break;
    case 2:
        readItems();
        break;
    case 3:
        updateItem();
        break;
    case 4:
        deleteItem();
        break;
    case 5:
        queryItem();
        break;
    case 6:
        generateReport();
        break;
    default:
        printf("Opcao invalida. Tente novamente.\n");
        break;
    }
}

int main()
{
    int choice;

    FILE *file = fopen(FILENAME, "r");
    if (file != NULL)
    {
        Item item;
        char line[200];
        while (fgets(line, sizeof(line), file) != NULL)
        {
            sscanf(line, "Codigo: %s Nome: %s Categoria: %s Quantidade: %s\n", item.cod, item.name, item.category, item.quantity);
            Items[numItems] = item;
            numItems++;
        }
        fclose(file);
    }

    while (1)
    {
        menu();
        scanf("%d", &choice);
        switchMenu(choice);
    }

    return 0;
}

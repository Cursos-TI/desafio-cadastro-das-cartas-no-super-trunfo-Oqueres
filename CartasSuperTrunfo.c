#include <stdio.h>

typedef struct
{
    char id_card;          // Identificador do card (primeira letra do estado)
    char state[50];        // Nome do estado
    char nome_cidade[50];  // Nome da cidade
    int population;        // População da cidade
    long int pib;          // PIB da cidade
    int area;              // Área da cidade (em km²)
    int spot_tourist;      // Quantidade de pontos turísticos
    double pib_per_capita; // PIB per capita da cidade
    double densidade;      // Densidade populacional da cidade
} card;


//Funçao para imprimir os dados de um card.
void imprimir_card(card c)
{
    c.pib_per_capita = (double)c.pib / c.population;
    c.densidade = (double)c.population / c.area;

    printf(
        "CARD: %c\n"
        "ESTADO: %s\n"
        "NOME DA CIDADE: %s\n"
        "POPULAÇAO: %d\n"
        "PIB: %ld\n"
        "AREA: %d\n"
        "PONTOS TURISTICOS: %d\n"
        "DENSIDADE: %.2f\n"
        "PIB PER CAPITA: %.2f\n",
        c.id_card, c.state, c.nome_cidade, c.population, c.pib, c.area, c.spot_tourist, c.densidade, c.pib_per_capita);
};

//Funçao para cadastrar um novo card.
void newCard(card *cards, int *last_position)
{
    card c;
    printf("Digite o Estado: \n");
    scanf("%s", c.state);
    printf("Digite o Nome da cidade: \n");
    scanf("%s", c.nome_cidade);
    printf("Digite a populaçao: \n");
    scanf("%d", &c.population);
    printf("Digite o pib: \n");
    scanf("%ld", &c.pib);
    printf("Digite o area: \n");
    scanf("%d", &c.area);
    printf("Digite a quantidade de pontos turisticos: \n");
    scanf("%d", &c.spot_tourist);
    c.id_card = c.state[0];

    cards[*last_position] = c; // Armazenando o card no vetor.
    (*last_position)++;        // Atualiza a posiçao para o proximo card.
};

void listarCards(card *cards, int last_position)
{
    for (int i = 0; i < last_position; i++)
    {
        imprimir_card(cards[i]);
    }
}

int main()
{
    card cards[50];
    int last_position = 0;
    int opcao = 0;

    while (opcao != 3)
    {
        printf(
            "1-Cadastrar Card: \n"
            "2-Listar Cards: \n"
            "3-Sair do programa. \n"
            "Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
            newCard(cards, &last_position); // Cadastrar um novo card.
            break;

        case 2:
            listarCards(cards, last_position); // Listar todos os cards.
            break;

        case 3:
            printf("Saindo do Programa... \n");
            break;

        default:
            printf("Opcao Invalida! \n");
            break;
        };
    };

    return 0;
};
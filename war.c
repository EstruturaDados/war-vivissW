#include<stdio.h>
#include<string.h>

//// Definição da estrutura (struct)

struct Territorio {
    char nome[30];
    char cor [10];
    int tropas;
};
//Começo (int main)

int main (){

    printf("=================================== \n");
    printf("Vamos cadastrar os 5 Territórios iniciais do nosso mundo. \n");
    printf("--- Cadastrando Território 1 --- \n");

//Território 1
 struct Territorio t1;
    printf("Nome do Território: ");
    scanf("%s", t1.nome);
    printf("Cor do Exercito (ex: Azul, Verde): ");
    scanf("%s", t1.cor);
    printf("Número de Tropas: ");
    scanf("%d", &t1.tropas);

printf("\n");

//Território 2
 struct Territorio t2;
    printf("--- Cadastrando Território 2 --- \n");
    printf("Nome do Território: ");
    scanf("%s", t2.nome);
    printf("Cor do Exercito (ex: Azul, Verde): ");
    scanf("%s", t2.cor);
    printf("Número de Tropas: ");
    scanf("%d", &t2.tropas);
    printf("\n");

//Território 3
struct Territorio t3;
    printf("--- Cadastrando Território 3 --- \n");
    printf("Nome do Território: ");
    scanf("%s", t3.nome);
    printf("Cor do Exercito (ex: Azul, Verde): ");
    scanf("%s", t3.cor);
    printf("Número de Tropas: ");
    scanf("%d", &t3.tropas);
    printf("\n");

//Território 4
struct Territorio t4;
    printf("--- Cadastrando Território 4 --- \n");
    printf("Nome do Território: ");
    scanf("%s", t4.nome);
    printf("Cor do Exercito (ex: Azul, Verde): ");
    scanf("%s", t4.cor);
    printf("Número de Tropas: ");
    scanf("%d", &t4.tropas);
    printf("\n");

//Território 5
struct Territorio t5;
    printf("--- Cadastrando Território 5 --- \n");
    printf("Nome do Território: ");
    scanf("%s", t5.nome);
    printf("Cor do Exercito (ex: Azul, Verde): ");
    scanf("%s", t5.cor);
    printf("Número de Tropas: ");
    scanf("%d", &t5.tropas);
    printf("\n");

//Finalização 

printf("Cadastro inicial concluido com sucesso! \n");
printf("\n");
printf("=================================== \n");
printf("   MAPA DO MUNDO - ESTADO ATUAL   \n");
printf("=================================== \n");
printf("\n");


printf("TERRITÓRIO 1: \n");
printf(" - Nome: %s \n - Dominado por: Exercito %s \n - Tropas: %d\n",t1.nome, t1.cor, t1.tropas);
printf("\n");

printf("TERRITÓRIO 2: \n");
printf(" - Nome: %s \n - Dominado por: Exercito %s \n - Tropas: %d\n",t2.nome, t2.cor, t2.tropas);
printf("\n");

printf("TERRITÓRIO 3: \n");
printf(" - Nome: %s \n - Dominado por: Exercito %s \n - Tropas: %d\n",t3.nome, t3.cor, t3.tropas);
printf("\n");

printf("TERRITÓRIO 4: \n");
printf(" - Nome: %s \n - Dominado por: Exercito %s \n - Tropas: %d\n",t4.nome, t4.cor, t4.tropas);
printf("\n");

printf("TERRITÓRIO 5: \n");
printf(" - Nome: %s \n - Dominado por: Exercito %s \n - Tropas: %d\n",t5.nome, t5.cor, t5.tropas);
printf("\n");

    

}
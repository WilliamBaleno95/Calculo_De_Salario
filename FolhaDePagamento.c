#include <stdio.h>

int main() {

    // varieveis para guardar o nome, cargo, horas trabalhadas e valor por hora
    char nome[50];
    char cargo[50];
    float horasTrabalhadas;
    float valorPorHora;


    // =================================== 1- Solicitar ao utilizador as informa��es sobre o funcionario =============================================

    printf("Digita o nome do funcionario: "); //Escrever "Digita o seu nome" na tela
    gets(nome);//Guardar o nome digitado na variavel "nome"
    //scanf("%s", nome); podes utilizar "scanf()" mas essa abordagem interrompe a leitura quando encontra um espa�o em branco, por isso n�o � adequando para inserir nome completo, apenas o primeiro nome
    // por isso � melhor utilizar "gets()"

    printf("Digite o cargo do funcionario: "); //...
    gets(cargo);
    //scanf("%s", cargo);

    printf("Digite as horas trabalhadas: ");
    scanf("%f", &horasTrabalhadas);

    printf("Digite o valor por hora: ");
    scanf("%f",&valorPorHora);



    // ================================ 2- Calcular o salario bruto do funcionario =================================================

    float salarioBruto = horasTrabalhadas * valorPorHora; // calcular o salario bruto


    // ================================ 3- Calcular os descontos do sal�rio bruto, aplicando as taxas vigentes em Cabo Verde ============================

    float descontoIUR = salarioBruto * 0.20 ; // desconto IUR � 20% do salario bruto
    float descontoINPS = salarioBruto * 0.085; // desconto INPS � 8.5% do salario Bruto


    //=================================== 4- Calcular e exibir o sal�rio liquido do funcionario ==================================

    float salarioLiquido = salarioBruto - descontoIUR - descontoINPS; // salario liquido � igual ao salario bruto menos os descontos de IUR e INPS
    printf("Salario Liquido: %.2f\n", salarioLiquido);


    //=================================== 5 - Gerar um ficheiro com o nome Folha de Pagamento e guardar todos os dados do funcionario nele ======================

    // "*ficheiro" ponteiro para o ficheiro
    // "w" indica que � modo de leitura e grava��o
    // "fopen" fun��o utilizada para abrir um ficheiro
    FILE *ficheiro = fopen("Folha_de_Pagamento.txt","w");

    //A fun��o fprintf funciona de maneira semelhante � fun��o printf, mas em vez de imprimir na tela, ela escreve os dados em um ficheiro.
    fprintf(ficheiro, "Nome: %s\n", nome);  //"\n" mudar de linha
    fprintf(ficheiro, "Cargo: %s\n", cargo);
    fprintf(ficheiro, "Horas Trabalhadas: %.2f\n", horasTrabalhadas);
    fprintf(ficheiro, "Valor por Hora: %.2f\n", valorPorHora);
    fprintf(ficheiro, "Salario Bruto: %.2f\n", salarioBruto);
    fprintf(ficheiro, "IUR: %.2f\n", descontoIUR);
    fprintf(ficheiro, "INPS: %.2f\n", descontoINPS);
    fprintf(ficheiro, "Salario Liquido: %.2f\n", salarioLiquido);

    // fechar o ficheiro depois de escrever todas as informa��es
    fclose(ficheiro);

    return 0;
}

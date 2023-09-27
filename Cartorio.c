#include <stdio.h> //Bibloteca de cominica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o  de espa�o em mem�ria
#include <locale.h> // Bibliotecade aloca��o de texto por regi�o
#include <string.h> // Bibioteca responsavel por cuidar das strings

int registro()//Fun��o responsavel por cadastrar usuarios nos sistema
{
	//Inicio cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: ");//Coletando informa��es do usu�rio
	scanf("%s", cpf);// %s revere-se a strings
	
	strcpy(arquivo, cpf); // Copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w");// cria arquivo eo "w" siginica escrever
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file);  // fecha o arquivo
	
	file = fopen(arquivo, "a");// Abre o arquivo para adicionar informa��es
	fprintf(file,",");// Adiciona uma v�rgula como separador
	fclose(file);// Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "%s", nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()// Fun��o para consultar informa��es de um usu�rio
{
	setlocale(LC_ALL, "Portuguese"); // Definindo linguagem
		
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");// Abre o arquivo com o CPF fornecido para leitura
	
	if(file == NULL)// Verifica se o arquivo existe
	{
		printf("N�o foi pssivel abrir o arquivo, n�o localizado \n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL)// L� o conte�do do arquivo linha por linha
	{
		printf("\nEssas s�o informa��es do usu�rio: ");
		printf("%s", conteudo); // Exibe as informa��es na tela
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()// Fun��o para deletar informa��es de um usu�rio
{
		
		char cpf[40];
	
		printf("Digite o CPF a ser deletado: ");
		scanf("%s",cpf);
		
		remove(cpf);// Remove o arquivo com o CPF fornecido
		
		FILE *file;
		file = fopen(cpf,"r");// Tenta abrir o arquivo novamente
		
		if(file == NULL) // Verifica se o arquivo n�o existe ap�s a remo��o
		{
			printf("O usuario n�o se encotra no sistema!.\n");
			system("pause");
		}
}


int main()// Fun��o principal
	{
	int opcao=0; // Definindo variaveis
	int laco=1;// Vari�vel de controle de loop
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");// Senha de acesso
	printf("Login de admistrador!\n\n Digite a sua senha:");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		
		for(laco=1; laco==1;)// Loop principal
		{
	
			system("cls");
		
			setlocale(LC_ALL, "Portuguese"); // Definindo linguagem
	
			printf("### Cart�rio da EBAC ###\n\n"); // Inicio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Resgistrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("opcao:"); // Fim do menu
	
			scanf("%d", &opcao); // Armanezamendo as escolhas
	
			system("cls");// Limpa a tela novamente
	
		switch(opcao)// Executa a a��o com base na escolha do usu�rio
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
		
			default:
			printf("opcao nao esta disponivel\n");
			system("pause");
			break;
		}
		}
	}
	else
		printf("Senha Incorreta");
}

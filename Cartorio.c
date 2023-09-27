#include <stdio.h> //Bibloteca de cominicação com o usuário
#include <stdlib.h> // Biblioteca de alocação  de espaço em memória
#include <locale.h> // Bibliotecade alocação de texto por região
#include <string.h> // Bibioteca responsavel por cuidar das strings

int registro()//Função responsavel por cadastrar usuarios nos sistema
{
	//Inicio criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: ");//Coletando informações do usuário
	scanf("%s", cpf);// %s revere-se a strings
	
	strcpy(arquivo, cpf); // Copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w");// cria arquivo eo "w" siginica escrever
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file);  // fecha o arquivo
	
	file = fopen(arquivo, "a");// Abre o arquivo para adicionar informações
	fprintf(file,",");// Adiciona uma vírgula como separador
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

int consulta()// Função para consultar informações de um usuário
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
		printf("Não foi pssivel abrir o arquivo, não localizado \n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL)// Lê o conteúdo do arquivo linha por linha
	{
		printf("\nEssas são informações do usuário: ");
		printf("%s", conteudo); // Exibe as informações na tela
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()// Função para deletar informações de um usuário
{
		
		char cpf[40];
	
		printf("Digite o CPF a ser deletado: ");
		scanf("%s",cpf);
		
		remove(cpf);// Remove o arquivo com o CPF fornecido
		
		FILE *file;
		file = fopen(cpf,"r");// Tenta abrir o arquivo novamente
		
		if(file == NULL) // Verifica se o arquivo não existe após a remoção
		{
			printf("O usuario não se encotra no sistema!.\n");
			system("pause");
		}
}


int main()// Função principal
	{
	int opcao=0; // Definindo variaveis
	int laco=1;// Variável de controle de loop
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");// Senha de acesso
	printf("Login de admistrador!\n\n Digite a sua senha:");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		
		for(laco=1; laco==1;)// Loop principal
		{
	
			system("cls");
		
			setlocale(LC_ALL, "Portuguese"); // Definindo linguagem
	
			printf("### Cartório da EBAC ###\n\n"); // Inicio do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Resgistrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("opcao:"); // Fim do menu
	
			scanf("%d", &opcao); // Armanezamendo as escolhas
	
			system("cls");// Limpa a tela novamente
	
		switch(opcao)// Executa a ação com base na escolha do usuário
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

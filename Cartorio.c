#include <stdio.h>//biblioteca de comunicação com usuário
#include <stdlib.h>//biblioteca de localização de espaço em memória
#include <locale.h>//biblioteca de localização de texto por região
#include <string.h>//biblioteca rsponsável por cuidar das string


int registro()//Função reponsavel por cadastrar os usuários no sistema
{
	//Variáveis
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   
   //Cdastro do CPF
   printf("Digite o CPF a ser cadastrado: ");
   scanf("%s", cpf);
   
   strcpy(arquivo, cpf); //Responsável por copiar os valores das string
   
   FILE *file; // cria o aquivo
   file = fopen(arquivo, "w"); // cria o arquivo
   fprintf(file,cpf);// salvo o valor da variavel
   fclose(file);// fechar o arquivo
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   //Cadastro do NOME
   printf("Digite o NOME a ser cadastrado: "); 
   scanf("%s", nome);
   
   file = fopen(arquivo, "a"); // cria o arquivo
   fprintf(file,nome);// salvo o valor da variavel
   fclose(file);// fechar o arquivo
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   //Cadastro do SOBRE NOME
   printf("Digite o SOBRE NOME a ser cadastrado: ");
   scanf("%s", sobrenome);
   
   file = fopen(arquivo, "a"); // cria o arquivo
   fprintf(file,sobrenome);// salvo o valor da variavel
   fclose(file);// fechar o arquivo
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   //Cadastro do CARGO
   printf("Digite o SOBRE CARGO a ser cadastrado: ");
   scanf("%s", cargo);
   
   file = fopen(arquivo, "a"); // cria o arquivo
   fprintf(file,cargo);// salvo o valor da variavel
   fclose(file);// fechar o arquivo
   
   system("pause");
   
   
}

int consulta() // Função de consulta
{
    setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
    
	char cpf[40];
	char conteudo[200];
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");	
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)//Função que busca os arquivos saLvos 
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		fclose(file);
	}
	
	system("pause");
	
}

int deletar()//Deleta os arquivos desejados
{

    char cpf[40];
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
	
	if(file == NULL)//Função identifica arquivo que não existe 
    {
    	printf("O usuário não se encontra no sistema!.\n");
    	system("pause");
    	return 0;
	}
	
	fclose(file);
	
	 if(remove(cpf) == 0)//Remove arquivos desejados
    {
    	printf("Usuário removido com sucesso!.\n");
    	
	}
	
	system("pause");
	return 0;

	
}

int main() 
{
	int opcao=0; //Definindo variáveis
	int laco=1;

	
		
	  for(laco=1;laco=1;)//Função que repete o menu ao final de um processo
	  {
	
	
	      setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
	      printf("### Cartório da EBAC ###\n\n"); // inicio do menu
     	  printf("Escolha a opção desejada do menu:\n\n");
	      printf("\t1 - Registro nomes\n");
     	  printf("\t2 - Consulta nomes\n");
          printf("\t3 - Deletar nomes\n\n");
          printf("\t4 - Sair do sistema");
       	  printf("Esse Software é de livre uso dos alunos\n\n");
    	  printf("Opção: ");
	
	      scanf("%d", &opcao); //armazenando a escolha do usuário
	    
	      system("cls"); //Linpar tela
	    
	      switch(opcao)//Função de escolha do munu
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
	    	  
	    	  case 4:
	    	  printf("Obrigado por ultilizar o sistema!\n");
	    	  return 0;
	    	  break;
	    	
	    	  default:
	    	  printf("Essa opção não está disponivel\n");
	    	  system("pause");
	    	  break;
	    	
		   }
		      system("cls");
       }
	
}

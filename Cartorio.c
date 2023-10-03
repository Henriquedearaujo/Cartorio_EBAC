#include <stdio.h>//biblioteca de comunica��o com usu�rio
#include <stdlib.h>//biblioteca de localiza��o de espa�o em mem�ria
#include <locale.h>//biblioteca de localiza��o de texto por regi�o
#include <string.h>//biblioteca rspons�vel por cuidar das string


int registro()//Fun��o reponsavel por cadastrar os usu�rios no sistema
{
	//Vari�veis
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   
   //Cdastro do CPF
   printf("Digite o CPF a ser cadastrado: ");
   scanf("%s", cpf);
   
   strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
   
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

int consulta() // Fun��o de consulta
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
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)//Fun��o que busca os arquivos saLvos 
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
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
	
	if(file == NULL)//Fun��o identifica arquivo que n�o existe 
    {
    	printf("O usu�rio n�o se encontra no sistema!.\n");
    	system("pause");
    	return 0;
	}
	
	fclose(file);
	
	 if(remove(cpf) == 0)//Remove arquivos desejados
    {
    	printf("Usu�rio removido com sucesso!.\n");
    	
	}
	
	system("pause");
	return 0;

	
}

int main() 
{
	int opcao=0; //Definindo vari�veis
	int laco=1;

	
		
	  for(laco=1;laco=1;)//Fun��o que repete o menu ao final de um processo
	  {
	
	
	      setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
	      printf("### Cart�rio da EBAC ###\n\n"); // inicio do menu
     	  printf("Escolha a op��o desejada do menu:\n\n");
	      printf("\t1 - Registro nomes\n");
     	  printf("\t2 - Consulta nomes\n");
          printf("\t3 - Deletar nomes\n\n");
          printf("\t4 - Sair do sistema");
       	  printf("Esse Software � de livre uso dos alunos\n\n");
    	  printf("Op��o: ");
	
	      scanf("%d", &opcao); //armazenando a escolha do usu�rio
	    
	      system("cls"); //Linpar tela
	    
	      switch(opcao)//Fun��o de escolha do munu
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
	    	  printf("Essa op��o n�o est� disponivel\n");
	    	  system("pause");
	    	  break;
	    	
		   }
		      system("cls");
       }
	
}

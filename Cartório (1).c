#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro()
{
    char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	
	printf("Digite o cpf a ser cadastrado:");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);
	
	FILE *file;
	file = fopen(arquivo, "w");
	fprintf(file, "\tCPF:");
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n\tNOME:");
	fclose(file);
	
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf (file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n\tCARGO: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fprintf(file, "\n\n");
	fclose(file);
	
	system("pause");
	
	
}

int consultar()
{
	setlocale (LC_ALL, "portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	system("cls");
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("NÃO FOI POSSÍVEL ABRIR O ARQUIVO, NÃO LOCALIZADO!\n");
	}
	
		printf("AS INFORMAÇÕES LOCALIZADAS DO USUÁRIO CADASTRADO SÃO:\n\n");
	
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	
	system("pause");
	
	
	
}

int deletar()
{
    char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	system("cls");
	
		printf("\n\tUSUÁRIO DELETADO!\n");
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	
	
	if(file == NULL);
	{
		printf(" O usuário não se encontra no sistema!\n");
		system("pause");
	}
}

int main()
    {   
    int opcao=0;
    int laco=1;
    
    for(laco=1;laco=1;)
	{
    
      system("cls");
	
      setlocale (LC_ALL, "portuguese");
     
      printf("## BEM-VINDO AO CARTÓRIO DA EBAC!\n\n");
      printf("Escolha a opção desejada no menu:\n\n");
      printf("\t1 - REGISTRAR NOMES\n");
      printf("\t2 - CONSULTAR NOMES\n");
      printf("\t3 - DELETAR NOMES\n");
      printf("\t4 - SAIR DO SISTEMA\n");
      printf("Opção:"); 
    
      scanf("%d" , &opcao);
    
      system("cls");
      
      
      switch(opcao)
      {
      	  case 1:
      	  registro();
          break;
        
          case 2:
          consultar();
	 	  break;
	 	
	 	  case 3:
	      deletar();
		  break;
		  
		  case 4:
		  printf("OBRIGADO POR UTILIZAR O SISTEMA!\n");
		  return 0;
		  break;
		
		  default:
		  printf("ESSA OPÇÃO NÃO ESTÁ DISPONÍVEL! TENTE NOVAMENTE...\n");
		  system("pause");
	 	  break;
	   }
 
    }
}

    


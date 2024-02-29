#include <stdio.h> //biblioteca de comunica��o com o usu�rioA main fun��o serve como ponto de partida para a execu��o do programa. Em geral, ela controla a execu��o direcionando as chamadas para outras fun��es no programa.G
#include <stdio.h> //biblioteca de aloca��o em mem�ria
#include <locale.h> //biblioteca de aloca�oes de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cri��o de vari�veis/string
	char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40];
    char cargo[40];
    //final da cri��o de variaveis/string
    
    printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio 
    scanf("%s", cpf);//%s refere-se a string

    strcpy(arquivo, cpf); //Responsavel por copiar os valores das string 
    
    FILE *file; // cria o arquivo 
    file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); // salvo o valor da variavel
    fclose(file); // fecha o arquivo 

    file = fopen(arquivo, "a"); // abre um arquivo e o "a" e os dados ser�o adicionados no fim do arquivo,  se ele ja existir, ou um novo arquivo sera criado
    fprintf(file,","); // salvo o valor da variavel
    fclose(file); // fecha o arquivo 
    
    printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio 
    scanf("%s",nome); //%s refere-se a string
    
    file = fopen(arquivo, "a"); //abre um arquivo e o "a" e os dados ser�o adicionados no fim do arquivo,  se ele ja existir, ou um novo arquivo sera criado
    fprintf(file,nome); // salvo o valor da variavel
    fclose(file); // fecha o arquivo 
    
    file = fopen(arquivo, "a"); //abre um arquivo e o "a" e os dados ser�o adicionados no fim do arquivo,  se ele ja existir, ou um novo arquivo sera criado
    fprintf(file,","); // salvo o valor da variavel
    fclose(file); // fecha o arquivo 
    
    printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio 
    scanf("%s",sobrenome); //%s refere-se a string
    
    file = fopen(arquivo, "a"); //abre um arquivo e o "a" e os dados ser�o adicionados no fim do arquivo,  se ele ja existir, ou um novo arquivo sera criado
    fprintf(file,sobrenome); // salvo o valor da variavel
    fclose(file); // fecha o arquivo 
    
    file = fopen(arquivo, "a"); //abre um arquivo e o "a" e os dados ser�o adicionados no fim do arquivo,  se ele ja existir, ou um novo arquivo sera criado
    fprintf(file,","); // salvo o valor da variavel
    fclose(file); // fecha o arquivo 
    
    printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio 
    scanf("%s",cargo); //%s refere-se a string
    
    file = fopen(arquivo, "a"); //abre um arquivo e o "a" e os dados ser�o adicionados no fim do arquivo,  se ele ja existir, ou um novo arquivo sera criado
    fprintf(file,cargo); // salvo o valor da variavel
    fclose(file); // fecha o arquivo 
    
    system("pause"); //comando para pausar a tela
    
}

int consulta() //Fun��o responsavel por consultar informa��es do usu�rio
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a lingueagem
	
    char cpf[40];
    char conteudo [200];

    printf("Digite o CPF a ser consultado: "); //coletando informa��o para consulta do usu�rio
    scanf("%s",cpf);
    
    FILE *file; // cria o arquivo
    file = fopen(cpf,"r"); //Abre um arquivo. O arquivo deve existir antes de ser aberto.
    
    if(file == NULL); // caso o arquivo nao exista, exibir printf ao usu�rio
    {
        printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); //informando usu�rio 
	}

    while(fgets(conteudo, 200, file) != NULL);
    {
    	printf("\nEssas s�o as informa��es do usu�rio: "); //informac�es do usu�rio
    	printf("%s", conteudo);	
    	printf("\n\n");
    }

    system("pause"); //comando para pausar a tela
    
    
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usu�rio a ser deletado:"); //coletando informa��o para deletar o usu�rio
    scanf("%s",cpf);
    
    remove(cpf);

    FILE *file; // cria o arquivo
    file = fopen(cpf,"r"); // Abre um arquivo texto para leitura e grava��o. O arquivo deve existir e pode ser modificado.
    
    if(file == NULL);
    {
    	printf("Usu�rio deletado com sucesso!.\n"); //informando usu�rio 
    	system("pause"); //comando para pausar a tela
	}

}

int main()
{
    int opcao=0; //Definindo vari�veis
    int laco=1;
    char senhadigitada[10]="a";
    int comparacao;
			       
    printf("###Cart�rio da EBAC###\n\n");
    printf("Login de administrador!\n\nDigite a sua senha:");
    scanf("%s", senhadigitada);
    
    comparacao = strcmp(senhadigitada, "admin");
    
    if(comparacao == 0)
    {
        system ("cls");
        for(laco=1;laco=1;)
        {

            setlocale(LC_ALL, "Portuguese"); //Definindo a lingueagem 

	        printf("###Cart�rio da EBAC###\n\n"); //inicio do menu
	        printf("Escolha a op��o desejada do menu:\n\n");
	        printf("\t1 - Registrar nomes\n");
	        printf("\t2 - Consultar nomes\n");
            printf("\t3 - Deletar nomes\n\n"); 
            printf("\t4 - Sair do sitema\n\n");
            printf("Op��o: "); //fim do menu
    
            scanf("%d", &opcao); //armazenando a escolha do usu�rio

           system("cls");//responsavel por limpar a tela
         
           switch(opcao)//inicio da sele��o do menu
           {
        	    case 1:
                registro();//chamada de fu��es
			    break;	
			
			    case 2:
			    consulta();
		    	break;
			
			    case 4:
		        printf("Obrigado por ultilizar o sistema!\n");
			    return 0;	
			    break;
		
		
			    case 3:
		        deletar();
    		    break;
    		
    	    	default:
    	        printf("Essa op��o n�o est� dispon�vel!\n");	
			    system("pause");
			    break;
			} //fim da sele��o
        }
	}
	
	else
	    printf("Senha incorreta!");
    
}

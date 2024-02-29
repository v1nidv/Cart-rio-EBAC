#include <stdio.h> //biblioteca de comunicação com o usuárioA main função serve como ponto de partida para a execução do programa. Em geral, ela controla a execução direcionando as chamadas para outras funções no programa.G
#include <stdio.h> //biblioteca de alocação em memória
#include <locale.h> //biblioteca de alocaçoes de texto por região 
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio crição de variáveis/string
	char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40];
    char cargo[40];
    //final da crição de variaveis/string
    
    printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário 
    scanf("%s", cpf);//%s refere-se a string

    strcpy(arquivo, cpf); //Responsavel por copiar os valores das string 
    
    FILE *file; // cria o arquivo 
    file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); // salvo o valor da variavel
    fclose(file); // fecha o arquivo 

    file = fopen(arquivo, "a"); // abre um arquivo e o "a" e os dados serão adicionados no fim do arquivo,  se ele ja existir, ou um novo arquivo sera criado
    fprintf(file,","); // salvo o valor da variavel
    fclose(file); // fecha o arquivo 
    
    printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário 
    scanf("%s",nome); //%s refere-se a string
    
    file = fopen(arquivo, "a"); //abre um arquivo e o "a" e os dados serão adicionados no fim do arquivo,  se ele ja existir, ou um novo arquivo sera criado
    fprintf(file,nome); // salvo o valor da variavel
    fclose(file); // fecha o arquivo 
    
    file = fopen(arquivo, "a"); //abre um arquivo e o "a" e os dados serão adicionados no fim do arquivo,  se ele ja existir, ou um novo arquivo sera criado
    fprintf(file,","); // salvo o valor da variavel
    fclose(file); // fecha o arquivo 
    
    printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário 
    scanf("%s",sobrenome); //%s refere-se a string
    
    file = fopen(arquivo, "a"); //abre um arquivo e o "a" e os dados serão adicionados no fim do arquivo,  se ele ja existir, ou um novo arquivo sera criado
    fprintf(file,sobrenome); // salvo o valor da variavel
    fclose(file); // fecha o arquivo 
    
    file = fopen(arquivo, "a"); //abre um arquivo e o "a" e os dados serão adicionados no fim do arquivo,  se ele ja existir, ou um novo arquivo sera criado
    fprintf(file,","); // salvo o valor da variavel
    fclose(file); // fecha o arquivo 
    
    printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário 
    scanf("%s",cargo); //%s refere-se a string
    
    file = fopen(arquivo, "a"); //abre um arquivo e o "a" e os dados serão adicionados no fim do arquivo,  se ele ja existir, ou um novo arquivo sera criado
    fprintf(file,cargo); // salvo o valor da variavel
    fclose(file); // fecha o arquivo 
    
    system("pause"); //comando para pausar a tela
    
}

int consulta() //Função responsavel por consultar informações do usuário
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a lingueagem
	
    char cpf[40];
    char conteudo [200];

    printf("Digite o CPF a ser consultado: "); //coletando informação para consulta do usuário
    scanf("%s",cpf);
    
    FILE *file; // cria o arquivo
    file = fopen(cpf,"r"); //Abre um arquivo. O arquivo deve existir antes de ser aberto.
    
    if(file == NULL); // caso o arquivo nao exista, exibir printf ao usuário
    {
        printf("Não foi possivel abrir o arquivo, não localizado!.\n"); //informando usuário 
	}

    while(fgets(conteudo, 200, file) != NULL);
    {
    	printf("\nEssas são as informações do usuário: "); //informacões do usuário
    	printf("%s", conteudo);	
    	printf("\n\n");
    }

    system("pause"); //comando para pausar a tela
    
    
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado:"); //coletando informação para deletar o usuário
    scanf("%s",cpf);
    
    remove(cpf);

    FILE *file; // cria o arquivo
    file = fopen(cpf,"r"); // Abre um arquivo texto para leitura e gravação. O arquivo deve existir e pode ser modificado.
    
    if(file == NULL);
    {
    	printf("Usuário deletado com sucesso!.\n"); //informando usuário 
    	system("pause"); //comando para pausar a tela
	}

}

int main()
{
    int opcao=0; //Definindo variáveis
    int laco=1;
    char senhadigitada[10]="a";
    int comparacao;
			       
    printf("###Cartório da EBAC###\n\n");
    printf("Login de administrador!\n\nDigite a sua senha:");
    scanf("%s", senhadigitada);
    
    comparacao = strcmp(senhadigitada, "admin");
    
    if(comparacao == 0)
    {
        system ("cls");
        for(laco=1;laco=1;)
        {

            setlocale(LC_ALL, "Portuguese"); //Definindo a lingueagem 

	        printf("###Cartório da EBAC###\n\n"); //inicio do menu
	        printf("Escolha a opção desejada do menu:\n\n");
	        printf("\t1 - Registrar nomes\n");
	        printf("\t2 - Consultar nomes\n");
            printf("\t3 - Deletar nomes\n\n"); 
            printf("\t4 - Sair do sitema\n\n");
            printf("Opção: "); //fim do menu
    
            scanf("%d", &opcao); //armazenando a escolha do usuário

           system("cls");//responsavel por limpar a tela
         
           switch(opcao)//inicio da seleção do menu
           {
        	    case 1:
                registro();//chamada de fuções
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
    	        printf("Essa opção não está disponível!\n");	
			    system("pause");
			    break;
			} //fim da seleção
        }
	}
	
	else
	    printf("Senha incorreta!");
    
}

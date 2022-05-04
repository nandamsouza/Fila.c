
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 10

typedef struct Fila Fila;

	struct Fila{
		
		int vet[tam];
		int quantidade,inicio,final;
	};
	
	void inicia_fila(Fila *a){
		
		a->quantidade =0;
		a->inicio =0;
		a->final =0;
	}
	
	void vetor_fila(int *vet,int inicio,int final){
		
		int i,fim;
		if(final>0){
		 	fim = final -1;
		}else{
		 	fim = tam -1;
		}
		i = inicio;
		while(i!=fim){
		 	 printf("\t|         %d        |\n", vet[i]);
			if(i == tam -1){
				i =0;
			}else{
				i++;
			}
		}
			 printf("\t|         %d        |\n", vet[i]);
	}
	void mostrar_fila(Fila a){
		
		if(a.quantidade == 0){
				printf("---------------------------------");
		  	  printf("\n|           FILA VAZIA         |\n");
		    	printf("---------------------------------\n");
		}else{
				printf("\n----------- Fila de Espera -------------\n");
			    vetor_fila(a.vet,a.inicio,a.final);
			    printf("------------------------------------------\n");
		}
	}
	void insere_fila(Fila *a,int valor){
		
		if(a->quantidade < tam ){
			
		 	 printf("---------------------------------");
		   printf("\n|           SENHA : %d         |\n",valor);
		     printf("---------------------------------\n");
		     
			 a->vet[a->final] = valor;
			if(a->final < tam-1){
				a->final++;	
			}else{
				a->final =0;
			}
			a->quantidade++;
		}else{
			 printf("-------------------------------");
		   printf("\n|         FILA CHEIA         |\n");
		     printf("-------------------------------\n");
		}
	}
	int remove_fila(Fila *a){
		
		if(a->quantidade > 0){
			     printf("--------------------------------------------");
				 printf("\n| SENHA [%d] COMPARECER AO ATENDIMENTO!  |\n", a->vet[a->inicio]);
				 printf("--------------------------------------------\n");
			int removido = a->vet[a->inicio];
			if(a->inicio < tam-1){
				a->inicio++;
			}else{
				a->inicio =0;
			}
				a->quantidade = a->quantidade-1;
				return removido;
		}else{
			 printf("--------------------------------");
		   printf("\n|          FILA VAZIA         |\n");
			 printf("--------------------------------\n");
		}
	}
	int posicao_fila(Fila *a, int numeroSenha){
		int i, posicaoSenha;
		
		if(a->quantidade > 0){
			for(i = 0;i <= tam ;i++){
				if(numeroSenha == a->vet[i]){
					 posicaoSenha = i - a->inicio;
					 
					  if(posicaoSenha > -1){
					  	
					  		 printf("-------------------------------------------");
		   	  		       printf("\n|  NUMERO DE SENHAS NA SUA FRENTE: %d    |\n", posicaoSenha);
							 printf("-------------------------------------------\n");
					  }else{
					  	
					  		 printf("-------------------------------------------");
		   	               printf("\n|          SENHA JA FOI CHAMADA          |\n");
			                 printf("-------------------------------------------\n");
					   }
					 break; 		
				}else if(numeroSenha != a->vet[i] && i == tam){
					
					  printf("-------------------------------------------");
		 	        printf("\n| SENHA SOLICITADA NAO FOI ENCONTRADA   |\n");	
		 	          printf("-------------------------------------------\n");
				}
			}		
		}else{
			 printf("--------------------------------");
		   printf("\n|          FILA VAZIA         |\n");
			 printf("--------------------------------\n");
		}
    } 
	

	void menu(){
					
		printf("\n");
		printf("---------------------- Menu ---------------------\n");
		printf("|    [0]Sair                                   | \n");
		printf("|    [1]Gerar senha                            | \n");
		printf("|    [2]Mostrar fila                           | \n");
		printf("|    [3]Chamar proxima senha                   | \n");
		printf("|    [4]Mostrar quantas senhas estao na frente | \n");
		printf("-------------------------------------------------\n");
	}
	
		
int main(){
		
		Fila f;
    	inicia_fila(&f);
    	int i, opcao,senha;
	
	do{
				
		menu();
	
		printf("Escolha uma Opcao: ");
		scanf("%d",&opcao);
	
		switch (opcao){
			case 0:
						printf("-------------------------------------------");
		 	          printf("\n|       - ATENDIMENTO ENCERRADO -        |\n");	
			        	printf("-------------------------------------------\n");
				break;
			case 1:
				//gerar senha
					 srand(time(NULL));
					 senha = 100+ rand() % 999;
					
					 insere_fila(&f,senha);
				break;
			case 2:
				 //Mostrar fila
				     mostrar_fila(f);
				break;
			case 3:
				 //Chamar próximo da fila
					 remove_fila(&f);
				break;		
			case 4:
				 //Mostrar quantas senhas estão na frente
					 printf("Digite sua senha: ");
					 scanf("%d", &senha);
					 posicao_fila(&f,senha);
				
				 break;	
			default:
				// nenhuma das opções
				 printf("------------------------------------------------------------------");
		 	   printf("\n| *[ERRO]* OPCAO INVALIDA! *[Escolha uma das opcoes do MENU]*   |\n");	
		 	     printf("------------------------------------------------------------------\n");
				
			}
			system("pause");
			system("cls");
		
   	}while(opcao != 0);
	
		return 0;
}
	

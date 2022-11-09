#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

//SISTEMA PARA CADASTRO DE ALUNOS, COM DESTAQUE NOS INDICES DE MASSA CORPORAIS DOS ALUNOS

//Funções

int menu();
int Escolha();
int cadastraAluno();
int listarAlunos();
int removerAluno();
int listarIMCalunos();
int consultarAlunoEspecifico();
int atualizaAluno();
int dadosAluno(int posicao);
int informarDadosAluno(int posicao);
float calculaIMC(float peso, float altura); 


//Struct

struct Aluno{
    char nome[50];
    char email[50];
    float peso;
    float altura;
    float IMC;
    int verificaCadastrado;
};

typedef struct Aluno Aluno;

Aluno armazenaAlunos[20];

int main(){
    setlocale(LC_ALL,"Portuguese");

    menu();

    system("pause");
}

int menu(){
     setlocale(LC_ALL,"Portuguese");

    int opcao;
    int sair = 1;

    while (sair != 0){

        puts("\n---------Cadastro de Alunos------------\n");
        puts("OPÇÕES: ");
        printf("CADASTRA ALUNO - 1\n");
        printf("LISTAR ALUNOS - 2\n");
        printf("APAGAR ALUNO - 3\n");
        printf("LISTAR IMC DE ALUNOS - 4\n");
        printf("ATUALIZAR ALUNO - 5 \n");
        printf("SAIR - 0\n");
        printf("Informe sua opção: ");
        scanf("%d", &opcao);

        sair = Escolha(opcao);

    }

    printf("\nFim do Programa, Obrigado por utilizar este software!!!\n");
}

int Escolha(int opcao){
     setlocale(LC_ALL,"Portuguese");

    int valor;

    if(opcao == 1){

        valor = cadastraAluno();
        return valor;

    } else {
        if (opcao == 2){

            valor = listarAlunos();
            return valor;

        } else {
            if (opcao == 3){

                valor = removerAluno();
                return valor;

            } else {
                if (opcao == 4){

                    valor = listarIMCalunos();
                    return valor;

                } else {
                    if (opcao == 5){
                        valor = atualizaAluno();
                        return valor;
                    } else {
                        if (opcao == 0){
                            return 0;
                        } else{
                            system("cls");
                            printf("\nOPÇÃO INVALIDA, TENTE NOVAMENTE!\n");
                            return 1;
                        }
                    }
                }
            }
        }
    }

}

float calculaIMC(float peso, float altura){
     setlocale(LC_ALL,"Portuguese");

    return peso/(altura*altura);

}

int cadastraAluno(){
     setlocale(LC_ALL,"Portuguese");

    system("cls");
    int posicao;

    printf("Escolha a posição do aluno:(1 a 20): ");
    scanf("%d", &posicao);
    fflush(stdin);

    posicao -= 1;
    
    if (posicao >= 0 && posicao <20){
    	if (armazenaAlunos[posicao].verificaCadastrado != 1){

		    informarDadosAluno(posicao);
		
		    puts("\nALUNO CADASTRADO COM SUCESSO!!!\n");
		
		    armazenaAlunos[posicao].IMC = calculaIMC(armazenaAlunos[posicao].peso, armazenaAlunos[posicao].altura);
		    armazenaAlunos[posicao].verificaCadastrado = 1;
		
		    return 1;
		} else {
			int tenteNovamente = 0;
			printf("\nPOSIÇÃO OCUPADA\n");
			printf("\nDeseja tentar novamente um cadastro ou retornar ao menu? (1 - Cadastro de Aluno / 2 - Menu): ");
			scanf("%d", &tenteNovamente);
			fflush(stdin);
			
			if (tenteNovamente == 1){
				system("cls");
				cadastraAluno();
			} else {
				if (tenteNovamente == 2){
					system("cls");
					return 1;
				} else {
					printf("\n\nValor Invalido, por padrão retorno ao menu\n\n");
					return 1;
				}
			}
		}
			
	} else {
		int tenteNovamente = 0;
		
		printf("\nPOSIÇÃO INEXISTENTE\n");
		printf("\nDeseja tentar novamente um cadastro ou retornar ao menu? (1 - Cadastro de Aluno / 2 - Menu): ");
		scanf("%d", &tenteNovamente);
		fflush(stdin);
		
		if(tenteNovamente == 1){
			system("cls");
			cadastraAluno();
		} else {
			if(tenteNovamente == 2){
				system("cls");
				return 1;
			} else {
				printf("\n\nValor Invalido, por padrão retorno ao menu\n\n");
				return 1;
			}
		}
	}
}


int listarAlunos(){
     setlocale(LC_ALL,"Portuguese");

    int i, contadorCadastro = 0, visitaAluno = 0;
    system("cls");


    puts("ALUNOS CADASTRADOS: ");

    for (i = 0; i<20; i++){
        if(armazenaAlunos[i].verificaCadastrado == 1){
            printf("Posição: %d -----Aluno: %s\n", i+1, armazenaAlunos[i].nome);
            contadorCadastro++;
        }
    }

    if(contadorCadastro == 0){
        printf("\nNENHUM ALUNO CADASTRADO\n\n");
    } else {
    	
	    printf("Deseja consultar algum aluno?(1 - SIM / 0 - NÃO): ");
	    scanf("%d", &visitaAluno);
	    
	    if (visitaAluno == 1){
	    	return consultarAlunoEspecifico();
		} else {
			system("cls");
		}
	}
	
	return 1;

}

int removerAluno(){
    setlocale(LC_ALL,"Portuguese");

    system("cls");
    int posicao;

    printf("Informe a posição do aluno que você deseja remover(1 a 20): ");
    scanf("%d", &posicao);
    fflush(stdin);

    posicao -= 1;

    if (posicao >= 0 && posicao < 20 && armazenaAlunos[posicao].verificaCadastrado == 1){
        printf("\nNome do Aluno: %s", armazenaAlunos[posicao].nome);
        printf("\nemail: %s", armazenaAlunos[posicao].email);
        printf("\nAltura: %.2f\n", armazenaAlunos[posicao].altura);
        printf("\npeso do aluno: %.2f\n", armazenaAlunos[posicao].peso);

        int certeza=0;

        printf("\nDeseja remove-lo com certeza?(1 - SIM / 0 - NÃO): ");
        scanf("%d", &certeza);
        fflush(stdin);

        if (certeza == 1){
            strcpy(armazenaAlunos[posicao].nome, "");
            strcpy(armazenaAlunos[posicao].email, "");
            armazenaAlunos[posicao].peso = 0;
            armazenaAlunos[posicao].altura = 0;
            armazenaAlunos[posicao].verificaCadastrado = 0;

            printf("\nALUNO REMOVIDO!!!\n");
            return 1;
        } else{
            return 1;
        }

    } else {
        printf("\nAluno não encontrado.\n\n");
        return 1;
    }

}

int listarIMCalunos(){
    setlocale(LC_ALL,"Portuguese");

	system("cls");

    int i, contadorCadastro = 0;


    puts("LISTA DE IMC DOS ALUNOS: ");

    for (i=0;i<20;i++){
        
        if (armazenaAlunos[i].verificaCadastrado == 1){
            printf("\n\nAluno: %s-------IMC: %.2f", armazenaAlunos[i].nome, armazenaAlunos[i].IMC);
            contadorCadastro++;
        }

    } 

    if(contadorCadastro == 0){
        printf("\nNENHUM ALUNO CADASTRADO\n\n");
    }

    return 1;

}

int consultarAlunoEspecifico(){
	setlocale(LC_ALL,"Portuguese");
	system("cls");
	
	int posicao;
	char volta;
	
	printf("Informe a posição do aluno(1 a 20): ");
	scanf("%d", &posicao);
	fflush(stdin);
	
	posicao -= 1;
	
	if (posicao >=0 && posicao <20 && armazenaAlunos[posicao].verificaCadastrado == 1){
	
		dadosAluno(posicao);
	    
	    printf("Deseja voltar para a lista de alunos ou ir para o Menu? (1 - Lista de Alunos / 2 - Menu):  ");
	    scanf("%d", &volta);
	    
	    if (volta == 1){
	    	listarAlunos();
		} else {
			if (volta == 2){
				system("cls");
				return 1;
			} else {
				printf("Valor Invalido, por padrão retorno ao menu");
                return 1;
			}
		}
	} else {
		int tenteNovamente = 0;
		
		printf("\nALUNO NÃO ENCONTRADO\n");
		printf("Deseja Tentar Novamente?(1 - SIM / 0 - NÃO): ");
		scanf("%d", &tenteNovamente);
		
		if (tenteNovamente == 1){
			consultarAlunoEspecifico();
		}
	}	
    
}

int atualizaAluno(){

    system("cls");
    int posicao;

    printf("Informa a posicao do aluno(1 a 20): ");
    scanf("%d", &posicao);

    posicao -= 1;

    if (posicao >= 0 && posicao < 20 && armazenaAlunos[posicao].verificaCadastrado == 1){

        dadosAluno(posicao);

        int certeza = 0;

        printf("Deseja atualizar estes dados?:(1 - Continua / 2 - Menu) \n");
        scanf("%d", &certeza);

        if (certeza == 1){
            system("cls");

            printf("\nINFORME OS NOVOS DADOS: \n");

            informarDadosAluno(posicao);

            printf("\nALUNO ATUALIZADO COM SUCESSO!!!\n");    
            return 1;

        } else {
            if(certeza == 2){
                return 1;
            } else {
               printf("Valor Invalido, por padrão retorno ao menu");
            }
        }
        
    } else {
        int tenteNovamente = 0;
        printf("\nALUNO NÃO ENCONTRADO\n");
        printf("Deseja tentar atualizar os dados de um aluno novamente ou voltar para o menu?(1 - ATUALIZAR ALUNO/ 2 - MENU): ");
        scanf("%d", &tenteNovamente);

        if (tenteNovamente == 1){
            return atualizaAluno();
        } else {
            if (tenteNovamente == 2){
                return 1;
            } else {
                printf("Valor Invalido, por padrão retorno ao menu");
                return 1;
            }
        }
        
    }

}

int dadosAluno(int posicao){

    puts("DADOS DO ALUNO: ");
    printf("\nNome: %s\n", armazenaAlunos[posicao].nome);
    printf("email: %s\n", armazenaAlunos[posicao].email);
    printf("Altura do Aluno: %.2f\n", armazenaAlunos[posicao].altura);
    printf("\nPeso do aluno: %.2f\n", armazenaAlunos[posicao].peso);
    printf("\nIMC %.2f\n\n", armazenaAlunos[posicao].IMC);

}

int informarDadosAluno(int posicao){

    fflush(stdin);
    printf("\nInforme seu nome: ");
    fgets(armazenaAlunos[posicao].nome, 50, stdin);
    fflush(stdin);

    printf("\nInforme seu email: ");
    fgets(armazenaAlunos[posicao].email, 50, stdin);
    fflush(stdin);

    printf("\nInforme o peso do Aluno (KG): ");
    scanf("%f", &armazenaAlunos[posicao].peso);
    fflush(stdin);

    printf("\nInforme a altura do aluno: ");
    scanf("%f", &armazenaAlunos[posicao].altura);
    fflush(stdin);

}
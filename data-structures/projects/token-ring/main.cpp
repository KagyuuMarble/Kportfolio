/*
CODIGO FEITO POR:
KEVIN KURPIAS RODRIGUES	RA:22017826
GUSTAVO GUSE MARTINS	RA:22009526
NICOLAS FOLQUENIN	RA:22019026
*/	

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>


#define READ 0
#define WRITE 1
#define MAX 500

int main(int argc, char* argv[]){
	
//NUMERO MÁXIMO DE PROCESSOS
	int num_process;

//RECEBER ARGUMENTOS PARA MAIN, SE ARGUMENTOS FOREM INVALIDOS OU NÃO EXISTIREM, COLOCAR ARGUMENTOS PARA 1.
	if((argc > 1) && (atoi(argv[1]) > 0 && atoi(argv[1]) <= MAX)){
		num_process = atoi(argv[1]);
	}
	else{
		num_process = 1;
	}

//FILE DESCRIPTORS PARA OS PIPES
	int file_descriptor_1[2], file_descriptor_2[2];

//PARA USO DE INPUT E OUTPUT NOS PROCESSOS FILHOS
	int child_IO_1, child_IO_2;
	
	int status;

//STRING DA MENSAGEM A SER PASSADA PELO PIPE
	char initial_message[MAX] = "#";

	int p_pid = getpid();
	printf("Processo pai <%d> enviara <%s>\n", p_pid, initial_message);
	
	sleep(1);
	
//CRIAÇÃO DE PIPE PARA ESCREVER AO PROCESSO FILHO
	if(pipe(file_descriptor_1) < 0){
		perror("Erro de encanação amigo!");
		exit(1);
	}

//ESCREVER PARA O PROCESSO FILHO
	child_IO_1 = dup(file_descriptor_1[WRITE]);
	write(child_IO_1, &initial_message, MAX);
	printf("Gerando <%d> processos...\n", num_process);

	for(int i = 0; i < num_process;i++){
		sleep(1);	
		
//CRIAÇÃO DE PIPE PARA COMUNICAÇÃO ENTRE OS PROCESSOS FILHOS
		if(pipe(file_descriptor_2)){
			perror("Erro de encanação entre os processos filhos amigo!");
			exit(1);
		}
		fflush(stdout);

//FORKING PROCESSO
		pid_t pid = fork();
		if(pid < 0){
			perror("Fork failed.");
			exit(1);
		}
		else if(pid == 0){
//PROCESSO FILHO
//FECHAR WRITE DO INPUT NO PIPE
			close(file_descriptor_1[WRITE]);
//FECHAR READ DO OUTPUT NO PIPE
			close(file_descriptor_2[READ]);
//LEITURA DA MENSAGEM
			char message[MAX];
			read(file_descriptor_1[READ], &message, MAX);
			printf("Filho <%d> com PID <%d> recebeu a mensagem: <%s>\n", i, getpid(), message);
//PASSANDO MENSAGEM CONCATENADA
			char concat[4];
			sprintf(concat, "%d", i);
			strcat(message, concat);

			write(file_descriptor_2[WRITE], &message, MAX);
			printf("Filho <%d> com PID <%d> enviou a mensagem: <%s>\n", i, getpid(), message);
			close(file_descriptor_1[READ]);
			close(file_descriptor_2[WRITE]);
			wait(&status);
			exit(0);
		}
//FECHAR OS PIPES E MOVER PARA O PRÓXIMO
		close(file_descriptor_1[READ]);
		close(file_descriptor_1[WRITE]);
		file_descriptor_1[READ] = file_descriptor_2[READ];
		file_descriptor_1[WRITE] = file_descriptor_2[WRITE];
		printf("<%d>\n", getpid());
		wait(&pid);
	}
//O PROCESSO PAI INICIAL RECEBENDO A MENSAGEM
	child_IO_2 = file_descriptor_2[READ];
	close(file_descriptor_2[WRITE]);
	close(child_IO_1);

	char final_message[MAX];
	read(child_IO_2, &final_message, MAX);
	close(child_IO_2);

	printf("O Pai <%d> recebeu a mensagem final: <%s>\n", getpid(), final_message);

	return 0;
}

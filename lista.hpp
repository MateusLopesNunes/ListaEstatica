#include <iostream>
#include <cstdlib>
#define MAX 100
using namespace std;

struct cadastro { //variavel hetérogenia
	int id;
	char nome[50];
	char email[100];
};

struct lista {
	int qtd; //variavel de controle, aponta para o ultimo espaço valio e mostra a quantidade de dados alocados;
	struct cadastro cad[MAX]; //vetor de cadastro
};

typedef struct lista listaCadastro; //cria o tipo listaCadastro;
//typedef cria um tipo usável;

listaCadastro* criaLista(void) {
	listaCadastro *p = (listaCadastro*) malloc(sizeof(struct lista)); //aloca memoria, criando um ponteiro vetor;
	if (p != NULL) {
		p->qtd = 0; //declara a variavel de controle para 0, apontando que a posição 0 está vazia e existem 0 elementos no vetor;s
	}
	return p; //retorna o penteiro vetor;
}

void liberaLista(listaCadastro *p) {
	free(p); //limpa a limpa
}

int tamanhoLista(listaCadastro *p) { //retorna o tamanho da lista
	if (p == NULL) {
		return -1;
	}
	else {
		return p->qtd;
	}
}

bool listaCheia(listaCadastro *p) { //retorna se a lista está cheia ou não
	if (p == NULL) {
		return -1;
	}
	else {
		return (p->qtd == MAX);
	}
}

bool listaVazia(listaCadastro *p) {  //retorna se a lista está cheia ou não
	if (p == NULL) {
		return -1;
	}
	else {
		return (p->qtd == 0);
	}
}

void insereListaFinal(listaCadastro *p, struct cadastro ca) {
	if (p == NULL) {
		cout << "Erro ao inserir cadastro" << endl;
	}
	else if (listaCheia(p)) {
		cout << "Erro, a lista está cheia" << endl;

	}
	else {
		p->cad[p->qtd] = ca; //o cadastro da lista na posição qtd (que marca um espaço vazio na lista), recebe o cadastro do cliente 
		p->qtd++; //qtd recebe +1, mostrando um espaço vaxio da lista
		cout << "cadastro inserido com sucesso" << endl;
	}
}

void insereListaInicio(listaCadastro *p, struct cadastro ca) {
	if (p == NULL) {
		cout << "Erro ao  inserir cadastro" << endl;
	}
	else if (listaCheia(p)) { 
		cout << "Erro, a lista está cheia" << endl;
	}
	else {
		int i;
		for (i = p->qtd - 1; i >= 0; i--) { // 
			p->cad[p->qtd + 1] = p->cad[i];
		}
		/*exemplo de qtd = 3:
		
		for (i = 2; i>=0; i--) {
			cad[3] = cad[2];
		}	
		for (i = 1; i>=0; i--) {
			cad[2] = cad[1];
		}
		for (i = 0; i>=0; i--) {
			cad[1] = cad[0];
		}
		*/
		
		p->cad[0] = ca;
		p->qtd++;
	}
}

void insereListaMeio (listaCadastro *p, struct cadastro ca) {
	if (p == NULL) {
		cout << "Erro ao  inserir cadastro" << endl;
	}
	else if (listaCheia(p)) { 
		cout << "Erro, a lista está cheia" << endl;
	}
	else {
		int c, i = 0;
		while (i <= p->qtd && p->cad[i].id < ca.id) {
			i++;
		}
		/*enquanto i for menor ou igual a qtd, e cadastro da lista menor que o cadastro do parametro,
		o i é iterado. Este i é a posiçao onde o novo cadastro será colocadoS*/
		
		for (c = p->qtd-1; c>=i; c--) {
			p->cad[c+1] = p->cad[c];
		}
		/*exemplo de qtd = 3 e i = 1:
		
		for (c = 2; 2>=1; c--) {
			cad[2] = cad[1];
		}	
		for (c = 0; 0>=1; c--) {
			cad[1] = cad[0];
		}
		cad[i] = ca;	
		*/
		
		p->cad[i] = ca;
		p->qtd++;
	}
}

void removeListaFinal(listaCadastro *p) {
	if (p == NULL) {
		cout << "Erro ao remover cadastro" << endl;
	}
	else if (listaVazia(p)) {
		cout << "Erro, a lista está vazia" << endl;
	}
	else {
		p->qtd--;  //qtd recebe -1, diminuindo em 1 o tamanho da lista, 'apagando' o ultimo elemento
		cout << "cadastro removido com sucesso" << endl;
	}
}

void removeListaInicio(listaCadastro *p) {
	if (p == NULL) {
		cout << "Erro ao remover cadastro" << endl;
	}
	else if (listaVazia(p)) {
		cout << "Erro, a lista está  vazia" << endl;
	}
	else {
		int i;
		for (i=0; i < p->qtd-1; i++) { //coloca todos os elementos com uma casa a esquerda(-1)
			p->cad[i] = p->cad[i+1];
		}
		/*Exemplo de qtd = 3:
		for (i=0; i < 2; i++) {
			cad[0] = cad[1];
		}
		
		for (i=1; i < 2; i++) {
			cad[1] = cad[2];
		}		
		*/
		p->qtd--; //deleta o ultimo  elemento que agr é lixo de memória
	}
}

void removeListaMeio(listaCadastro *p, int id) {
	if (p == NULL) {
		cout << "Erro ao remover cadastro" << endl;
	}
	else if (listaVazia(p)) {
		cout << "Erro, a lista está  vazia" << endl;
	}
	else {
		int k, i = 0;
		while (i <= p->qtd && p->cad[i].id != id) {
			i++;
		}
		/*enquanto i for menor ou igual a qtd, e id da lista menor que o id do parametro,
		o i é iterado. Este i é a posiçao onde o novo cadastro será colocado*/
		
		if (i == p->qtd) {
			cout << "Id não encontrado" << endl;
		}
		else if (i == p->qtd-1) {
			p->qtd--;
		}
		else {
			for (k=i; k < p->qtd-1; k++) {
				p->cad[k] = p->cad[k+1];	
			}
			p->qtd--;
		}
	}
}

void findAll(listaCadastro *p) {
	if (p == NULL) {
		cout << "Erro ao remover cadastro" << endl;
	}
	else if (listaVazia(p)) {
		cout << "Erro, a lista está vazia" << endl;
	}
	else {
		for (int i = 0; i < p->qtd; i++) {
			cout << p->cad[i].id << endl;
			cout << p->cad[i].nome << endl;
			cout << p->cad[i].email << endl;
		}
	}
}

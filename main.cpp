#include <iostream>
#include <cstdlib>
#include <limits>
#include "lista.hpp"

using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	listaCadastro *c = criaLista();
	
	struct cadastro ca;
	
	char opc;
	int i=0;
	do {
		ca.id = i;
		cout << "Informe seu nome: " << endl;
		cin >> ca.nome;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Informe seu email: " << endl;
		cin >> ca.email;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		cout << "Você deseja continuar ? (s/n)";
		cin >> opc;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		i++;
		insereListaMeio(c, ca);
	} while(opc != 'n');
	
	//removeListaInicio(c);
	
	if (tamanhoLista(c) != -1) {
		cout << tamanhoLista(c) << endl;
	}
	else {
		cout << "Erro" << endl;
	}
	
	cout << endl << "Posições da lista: ";
	findAll(c);
	
	liberaLista(c);
}

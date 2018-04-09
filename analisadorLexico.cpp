#include<iostream>
#include<stack>
#include<string>
#include <stdlib.h>

using namespace std;

string testaExpressao(string expressao);
bool IsOperator(char C);  //Verifica se é um operador
bool IsOperand(char C); //Verifica s é um caractere alfanumerico
bool IsLetter(char C);

string testaExpressao(string expressao){       // Função que avalia a expressão
	stack<char> S; //Inicialização de uma pilha vazia para os operadores
	string pos_fix = "";
	for(int i = 0;i< expressao.length();i++){
		if(expressao[i] == ' '){
            continue;
		}
		else if(expressao[i] == '.'){
            pos_fix += expressao[i];
		}
		else if(IsOperator(expressao[i])){  //Se o caracter for um operador irá inserir dois elementos na pilha
			while(!S.empty()){   //Enquanto a pilha não estiver vazia
				pos_fix += S.top();  // Adiciona ao 'posfix' o elemento do topo
				S.pop();  //Remove o elemento do topo
			}
			S.push(expressao[i]); //Insere o elemento atual na pilha
		}
		else if(IsOperand(expressao[i])){   //Caso seja um operando
			pos_fix += expressao[i];
		}
		else if(IsLetter(expressao[i])){
            pos_fix = "Erro Lexico..\n";
            break;
		}
	}
	while(!S.empty()){
		pos_fix += S.top();
		S.pop();
	}
	return pos_fix;
}

int somar_expressao(string ex){
    char x[100];
    char operadores[100];
    int conta = 0;
    int tam_vet = 0;
    int tam_vet_operadores = 0;
    int j=0;
    for(int i = 0;i< ex.length();i++){
        x[i] = ex[i];
        tam_vet++;
        if(IsOperator(x[i])){
            operadores[j] = x[i];
            j++;
            tam_vet_operadores++;
        }
    }
    for(int i = 0; i<tam_vet; i++){
        if(IsOperand(x[i])){
            if(operadores[z] == '+'){

            }
            else if (operadores[z] == '-'){

            }
        }
    }
    return conta;
}

bool IsOperand(char C){
	if(C >= '0' && C <= '9'){
        return true;
	}
	else{
        return false;
	}
}
bool IsOperator(char C){
	if(C == '+' || C == '-' || C == '*' || C == '/'){
        return true;
	}
    else{
        return false;
    }
}

bool IsLetter(char C){
    if(C >= 'a' && C <= 'z'){
        return true;
	}
    if(C >= 'A' && C <= 'Z'){
        return true;
	}
	else{
        return false;
	}
}
int main(){
	string expressao;
	char resposta;
	cout << "Expressao: \n";
	getline(cin,expressao);
	string pos_fix = testaExpressao(expressao);
	cout << "\nSaida: " << pos_fix << "\n";

	cout << "Deseja fazer a soma ? [s/n]: ";
	cin >> resposta;
    if(resposta == 's' || resposta == 'S'){
        int conta = somar_expressao(pos_fix);
        cout << "Resultado: " << conta;
    }
    else{
        return 0;
    }
}

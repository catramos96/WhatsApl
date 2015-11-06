#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <time.h>

#include "Mensagem.h"

using namespace std;

/********************************
 *		CLASSE MENSAGEM			*
 *******************************/

int Mensagem::id = 0;

Mensagem::Mensagem(Data data, Horas hora) : numero(++id){
	this->data = data;
	this->hora = hora;
}

void Mensagem::imprimirMsg() {
	cout << "Mensagem : "<< numero << endl;
	cout << "Data: " << data << " Hora : " << hora << endl;
	cout << "Emissor: " << emissor << endl;
}

string Mensagem::getEmissor() const{
	return emissor;
}

Data Mensagem::getData() const {
	return data;
}

Horas Mensagem::getHora() const {
	return hora;
}

int Mensagem::getNumero() const{
	return numero;
}

void Mensagem::setEmissor(string emissor){
	this->emissor = emissor;
}

/********************************
 *		CLASSE MSG TEXTO		*
 *******************************/

MsgTexto::MsgTexto(string conteudo, Data d, Horas h) : Mensagem(d,h)
{
	this->conteudo = conteudo;
}

string MsgTexto::getConteudo() const {
	return conteudo;
}

void MsgTexto::imprimirMsg() {
	Mensagem::imprimirMsg();
	cout << "Tipo: texto " << endl;
	cout << "Conteudo: \n   " << conteudo << endl;
}

/********************************
 *		CLASSE MSG VIDEO		*
 *******************************/

MsgVideo::MsgVideo(Data d, Horas h) : Mensagem(d,h)
{}

void MsgVideo::imprimirMsg(){
	Mensagem::imprimirMsg();
	cout << "Tipo: video " << endl;
}

/********************************
 *		CLASSE MSG IMAGEM		*
 *******************************/
MsgImagem::MsgImagem(Data d, Horas h) : Mensagem(d,h)
{}

void MsgImagem::imprimirMsg(){
	Mensagem::imprimirMsg();
	cout << "Tipo: imagem " << endl;
}

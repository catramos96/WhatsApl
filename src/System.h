#ifndef SRC_SYSTEM_H_
#define SRC_SYSTEM_H_

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>
#include <windows.h> 
#include <fstream>
#include "Excecoes.h"

using namespace std;

/**
 * @brief Classe Horas.
 * Classe que indica as horas (hora e minuto) ao utilizador.
 * E possivel modificar as horas.
 */
class Horas
{
private:
	int hora, /**<  membro privado que representa a hora */
		min; /**<  membro privado que representa os minutos*/
public:
	/**
	 * @brief Classe HoraInvalida.
	 * E uma classe que indica uma execao da classe Horas.
	 */
	class HoraInvalida{};
	/**
	 * @brief Constutor
	 * Construtor default que inicializa as horas e os minutos a zero
	 */
	Horas();
	/**
	 * @brief Construtor
	 * Construtor que inicializa os membros hora e minutos com os valores introduzidos pelo utilizador
	 */
	Horas(int h,int m);
	/**
	 * @ brief Funcao que permite o utilizador alterar as horas e os minutos atuais com verificacoes de input.
	 * @ param h : representa a hora
	 * @ param min : representa os minutos
	 * @ return void
	 */
	void setHoras(int h,int min);
	/**
	 * @brief Funcao que retorna as horas atuais.
	 * @return hora atual
	 */
	int getHora() const;
	/**
	 * @brief Funcao que retorna os minutos atuais
	 * @return minutos
	 */
	int getMinutos() const;
	/**
	 * @brief Funcao friend: funcao que acede aos membros privados da classe.
	 * operator<< permite imprimir no ecra o objeto Horas
	 * @param out output
	 * @param h objeto Horas
	 * @return out
	 */
	friend ostream & operator<<(ostream & out, const Horas & h);
	/**
	 * @brief Operator <. Funcao que faz o overloading do operador < para o Objeto Horas.
	 * Os fatores de comparacao sao as horas e os minutos.
	 * @param h Horas com que vamos comparar.
	 * @return True se as horas forem menores que h ou false se se verificar o contrario.
	 */
	bool operator<(const Horas &h) const;
};

/**
 * @brief Classe Data.
 * Classe que indica as data (dia mes e ano) ao utilizador.
 * E possivel modificar a data
 */
class Data
{
private:
	int dia,	/**< membro privado que representa o dia */
		mes,	/** < membro privado que representa o mes */
		ano;	/** < membro privado que representa o ano */
public:
	/**
	 * @brief Constutor
	 * Construtor default que inicializa o dia mes e ano a zero.
	 */
	Data();
	/**
	 * @brief Construtor.
	 * Inicializa o dia, mes e ano com os dados que o utilizador insere.
	 * @param d Dia.
	 * @param m Mes.
	 * @param a Ano.
	 */
	Data(int d,int m,int a);
	/**
	 * @brief Funcao que permite o utilizador alterar o dia mes e ano atuais com verificações de input.
	 * @ param d Representa o dia.
	 * @ param m Representa o mes.
	 * @ param a Represnta o ano.
	 */
	void setData(int d, int m, int a);
	/**
	 * @brief Funcao que retorna o dia atual.
	 * @return Dia atual.
	 */
	int getDia() const;
	/**
	 * @brief Funcao que retorna o mes atual.
	 * @return Mes atual.
	 */
	int getMes() const;
	/**
	 * @brief Funcao que retorna o ano atual.
	 * @return Ano atual
	 */
	int getAno() const;
	/**
	 * @brief Operator <. Funcao que faz o overloading do operador < para o Objeto Data.
	 * Os fatores de comparacao sao o ano, o mes e o dia.
	 * @param d Data com que vamos comparar.
	 * @return True se a data for menores que d ou false se se verificar o contrario.
	 */
	bool operator<(const Data&d) const;
	/**
	 * @brief Funcao friend: funcao que acede aos membros privados da classe.
	 * operator<< permite imprimir no ecra o objeto Data
	 * @param out output
	 * @param d objeto Data
	 * @return out
	 */
	friend ostream & operator<<(ostream & out, const Data & d);
	/**
	 * @brief Operador==. Funcao que faz o overloafing do operador == para o objeto Data.
	 * Os fatores de comparacao sao o ano, o mes e o dia.
	 * @param d Data que usamos para comparacao.
	 * @return True se as datas forem iguais, false se nao se verificar a igualdade.
	 */
	bool operator==(const Data&d) const;
};

// ainda nao sei se devo comentar

class HoraNova{
private:
	time_t t;
public:
	HoraNova();
	HoraNova(time_t time1);
	void setHoraNova(time_t time1);
	time_t getHoraNova();
	const string getHoraNovaCompleta();
	const string getHoraNovaHoras();
	const string getHoraNovaData();
};

void clrscr(void);

template <class N>
void input(N &valor);

void imprimirFicheiro(string textfile);

template <class N>
void input(N &valor) {
  cin >> valor;
  if (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    throw InputFail();
  }
}

void header(string msg);

void menuInicial();

void menuLogin();

void menuRegistar();

void menuComunidade();

void menuUtilizador();

void menuAmigos();

void menuDefinicoes();

void menuAlterarDefinicoes();

void menuComunidadeOrdenada();

void menuInformacao();


#endif /* SRC_SYSTEM_H_ */

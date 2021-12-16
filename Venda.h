#ifndef VENDA_H
#define VENDA_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Pessoa.h"

#include "Data.h"

class Venda
{
public:
 Venda( );
  Venda( const string &, const string &,  const vector< string > & );
    Venda( const Venda & );
	Venda( int, const Data & = Data( 25, 9, 2014) );
	~Venda( );

	static void mostrarInfo( );
	
	void updateHistory( const string & );
	
	void listHistory( ) const;
	
	void mostrarData( ) const;

	void printListaVendas( ) const;

	void addVenda( const Pessoa & );
	void addVenda( const string &, const string &, const vector< string > & );

	void deleteListaVendas( );
	
private:

	int pinCode;

	const int IDVENDA;
	
	static int numVendas;
	
	const static Data RELEASEDATE;
	
	vector< string > history;
	
	Data dataAtual;	

	vector< Pessoa * > estoque;

};

#endif // VENDA_H
#ifndef PRODUTOS_H
#define PRODUTOS_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Pessoa.h"

#include "Data.h"

class Produto
{
public:
	Produto( );
	Produto( const Produto &);
	Produto( int, const Data & = Data( 25, 9, 2014) );
	~Produto( );

	static void mostrarInfo( );
	
	void updateHistory( const string & );
	
	void listHistory( ) const;
	
	void mostrarData( ) const;

	void printContactList( ) const;

	void addProduto( const Pessoa & );
	void addProduto( const string &, const string &, const vector< string > & );

	void deleteListaProdutos( );
	
private:

	int pinCode;

	const int IDPRODUTO;
	
	static int numPhones;
	
	const static Data RELEASEDATE;
	
	vector< string > history;
	
	Data dataAtual;	

	vector< Pessoa * > estoque;

};

#endif // PRODUTOS_H
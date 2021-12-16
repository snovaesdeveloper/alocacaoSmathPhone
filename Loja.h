#ifndef LOJA_H
#define LOJA_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Pessoa.h"
#include "Produtos.h"

#include "Data.h"

class Loja
{
public:
	Loja( );
	Loja( const Loja &);
	Loja( int, const Data & = Data( 25, 9, 2014) );
	~Loja( );
	
	
	static void mostrarInfo( );
  	
	static void mostrarMenu( );

//  static void validacao( const  opt & );
	
	void updateHistory( const string & );
	
	void listHistory( ) const;
	
	void mostrarData( ) const;

	void printContactList( ) const;

	void addContact( const Pessoa & );
	void addContact( const string &, const string &, const vector< string > & );

	void deleteLastContact( );
	
private:

	int pinCode;

	const int IDPHONE;
	
	static int numPhones;
	
	const static Data RELEASEDATE;
	
	vector< string > history;
	
	Data dataAtual;	

	vector< Pessoa * > contacts;
 // vector< Produtos * > produtos;


};

#endif // LOJA_H
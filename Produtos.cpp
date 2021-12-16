#include "Produtos.h"

#include <iostream>
using std::cout;

int Produto::numPhones = 0;

const Data Produto::RELEASEDATE = Data( 25, 9, 2021 );

Produto::Produto( )
:pinCode(0), IDPRODUTO( 12345 ), dataAtual( )
{
	numPhones++;	
}

Produto::Produto( int IDPh, const Data &dataOut )
:IDPRODUTO(IDPh), dataAtual(dataOut)
{
	numPhones++;	
}

  Produto::Produto( const Produto &sp )
  :pinCode(sp.pinCode), IDPRODUTO(sp.IDPRODUTO), dataAtual(sp.dataAtual)
  {
    history = sp.history;
    numPhones++;
    
    //Update contact list
    estoque.resize( sp.estoque.size( ) );
    for( int i = 0; i < estoque.size( ); i++ )
      estoque[ i ] = new Pessoa( *sp.estoque[ i ] );//deferenciar o ponteiro. estoque é um vector de Pessoas

  }

Produto::~Produto( )
{

	for( int i = 0; i < estoque.size( ); i++ )
		delete estoque[ i ];

}

void Produto::mostrarInfo( )
{
	cout << "A data de lancamento deste modelo eh: ";
	RELEASEDATE.print( );
	cout << '\n';
	cout << "O numero de Produtos vendidos eh: " << numPhones << '\n'; 
		 
}

void Produto::updateHistory(const string &newPage)
{
	history.push_back( newPage );
}

void Produto::listHistory( ) const
{
	cout << "As paginas visitas foram\n";
	for( unsigned int i = 0; i < history.size( ); i++ )
		cout << history[ i ] << '\n';
}

void Produto::mostrarData( ) const
{
	cout << "A data atual eh: "; dataAtual.print( );	
	cout << '\n';
}

void Produto::printContactList( ) const
{
	cout << "Minha lista de produtos eh:\n\n";
	for( int i = 0; i < estoque.size( ); i++ )
		cout << *estoque[ i ] << '\n';
}

void Produto::addProduto( const Pessoa &newcontact )
{
	estoque.push_back( new Pessoa( newcontact ) );	
}

void Produto::addProduto( const string &name, const string &phoneNumber, const vector< string > &socialMediaConection )
{
	estoque.push_back( new Pessoa( name, phoneNumber, socialMediaConection ) );	
}

void Produto::deleteListaProdutos( )
{
	delete estoque[ estoque.size() - 1 ];
	estoque.pop_back( );
}
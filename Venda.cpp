#include "Venda.h"
#include "Produtos.h"

#include <iostream>
using std::cout;

int Venda::numVendas = 0;

const Data Venda::RELEASEDATE = Data( 25, 9, 2021 );

Venda::Venda( )
:pinCode(0), IDVENDA( 12345 ), dataAtual( )
{
	numVendas++;	
}

Venda::Venda( int IDPh, const Data &dataOut )
:IDVENDA(IDPh), dataAtual(dataOut)
{
	numVendas++;	
}




  Venda::Venda( const Venda &sp )
  :pinCode(sp.pinCode), IDVENDA(sp.IDVENDA), dataAtual(sp.dataAtual)
  {
    history = sp.history;
    numVendas++;
    
    //Update contact list
    estoque.resize( sp.estoque.size( ) );
    for( int i = 0; i < estoque.size( ); i++ )
      estoque[ i ] = new Pessoa ( *sp.estoque[ i ] );//deferenciar o ponteiro. estoque é um vector de Pessoas

  }

Venda::~Venda( )
{

	for( int i = 0; i < estoque.size( ); i++ )
		delete estoque[ i ];

}

void Venda::mostrarInfo( )
{
	cout << "A data de lancamento deste modelo eh: ";
	RELEASEDATE.print( );
	cout << '\n';
	cout << "O numero de Vendas vendidos eh: " << numVendas << '\n'; 
		 
}

void Venda::updateHistory(const string &newPage)
{
	history.push_back( newPage );
}

void Venda::listHistory( ) const
{
	cout << "Os produtos visitados foram\n";
	for( unsigned int i = 0; i < history.size( ); i++ )
		cout << history[ i ] << '\n';
}

void Venda::mostrarData( ) const
{
	cout << "A data atual eh: "; dataAtual.print( );	
	cout << '\n';
}

void Venda::printListaVendas( ) const
{
	cout << "Minha lista de Vendas eh:\n\n";
	for( int i = 0; i < estoque.size( ); i++ )
		cout << *estoque[ i ] << '\n';
}

void Venda::addVenda( const Pessoa &newcontact )
{
	estoque.push_back( new Pessoa( newcontact ) );	
}

void Venda::addVenda( const string &name, const string &phoneNumber, const vector< string > &socialMediaConection )
{
	estoque.push_back( new Pessoa( name, phoneNumber, socialMediaConection ) );	
}

void Venda::deleteListaVendas( )
{
	delete estoque[ estoque.size() - 1 ];
	estoque.pop_back( );
}
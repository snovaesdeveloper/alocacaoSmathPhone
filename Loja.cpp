#include "Loja.h"
#include <iostream>
#include <string>
#include <iostream>
using std::cout;
using std::string;
using namespace  std;

int Num1;
int Loja::numPhones = 0;

const Data Loja::RELEASEDATE = Data( 25, 9, 2021 );

Loja::Loja( )
:pinCode(0), IDPHONE( 12345 ), dataAtual( )
{
	numPhones++;	
}

Loja::Loja( int IDPh, const Data &dataOut )
:IDPHONE(IDPh), dataAtual(dataOut)
{
	numPhones++;	
}

  Loja::Loja( const Loja &sp )
  :pinCode(sp.pinCode), IDPHONE(sp.IDPHONE), dataAtual(sp.dataAtual)
  {
    history = sp.history;
    numPhones++;
    
    //Update contact list
    contacts.resize( sp.contacts.size( ) );
    for( int i = 0; i < contacts.size( ); i++ )
      contacts[ i ] = new Pessoa( *sp.contacts[ i ] );//deferenciar o ponteiro. Contacts é um vector de Pessoas

  }

Loja::~Loja( )
{

	for( int i = 0; i < contacts.size( ); i++ )
		delete contacts[ i ];

}

void Loja::mostrarInfo( )
{
	cout << "A data de lancamento deste modelo eh: ";
	RELEASEDATE.print( );
	cout << '\n';
	cout << "O numero de Lojas vendidos eh: " << numPhones << '\n'; 
		 
}

void Loja::updateHistory(const string &newPage)
{
	history.push_back( newPage );
}

void Loja::listHistory( ) const
{
	cout << "As paginas visitas foram\n";
	for( unsigned int i = 0; i < history.size( ); i++ )
		cout << history[ i ] << '\n';
}

void Loja::mostrarData( ) const
{
	cout << "A data atual eh: "; dataAtual.print( );	
	cout << '\n';
}

void Loja::printContactList( ) const
{
	cout << "Minha lista de contatos eh:\n\n";
	for( int i = 0; i < contacts.size( ); i++ )
		cout << *contacts[ i ] << '\n';
}

void Loja::addContact( const Pessoa &newcontact )
{
	contacts.push_back( new Pessoa( newcontact ) );	
}

void Loja::addContact( const string &name, const string &phoneNumber, const vector< string > &socialMediaConection )
{
	contacts.push_back( new Pessoa( name, phoneNumber, socialMediaConection ) );	
}

void Loja::deleteLastContact( )
{
	delete contacts[ contacts.size() - 1 ];
	contacts.pop_back( );
}



void Loja::mostrarMenu( )
{


  printf("******************************\n");
  printf("* BEM VINDO A LOJA C++ *\n");
  printf("* SAMUEL MENDES NOVAES *\n");
  printf("******************************\n\n");
  


  // Lista as opções do programa.
	cout << ("\nO que voce deseja fazer:\n");
	cout << ("\n1) Inserir um cliente");
	cout << ("\n2) Inserir um produto");
	cout << ("\n3) Vender um produto para um cliente");
	cout << ("\n4) Retirar um produto de um cliente");
	cout << ("\n9) Sair do programa\n\n");

	printf("******************************\n\n");

  	cout << ("Digite uma opcao: "); 	 
}


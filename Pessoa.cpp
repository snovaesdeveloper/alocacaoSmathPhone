#include "Pessoa.h"
#include <vector>
#include <iostream>
using std::cout;
using std::vector;

Pessoa::Pessoa( )
:phoneNumber(""), name("")
{
        
}

Pessoa::Pessoa( const string &name, const string& phoneNumber,  const vector< string > &socialMediaConection )
{
    this->name = name;

    this->phoneNumber = phoneNumber;
    
    this->socialMediaConection.resize( socialMediaConection.size() );
    for( int i = 0; i < this->socialMediaConection.size( ); i++ )
         this->socialMediaConection[ i ] = socialMediaConection[ i ];

    printListaProdutos( );
}



Pessoa::Pessoa( const Pessoa &pessoaOut )
{
    this->name = pessoaOut.name;
    this->phoneNumber = pessoaOut.phoneNumber;

    this->socialMediaConection.resize( pessoaOut.socialMediaConection.size() );
    for( int i = 0; i < this->socialMediaConection.size( ); i++ )
        this->socialMediaConection[ i ] = pessoaOut.socialMediaConection[ i ];
}


Pessoa::~Pessoa( )
{

	for( int i = 0; i < contacts.size( ); i++ )
		delete contacts[ i ];

}



 void Pessoa::printListaProdutos( ) const
 {
     cout << "List o rodutos compradas no site:\n";
     for( int i = 0; i < this->socialMediaConection.size( ); i++ )
        cout << this->socialMediaConection[ i ] << '\n';
 }

ostream &operator<<( ostream &out, const Pessoa &p )
{
    out << "Name: ";
    out << p.name << "\n";
    
    out << "Phone number: ";
    out << p.phoneNumber << "\n";

    p.printListaPessoas( );

    return out;
}
void Pessoa::printListaPessoas( ) const
{
	cout << "Minha lista de Pessoas eh:\n\n";
	for( int i = 0; i < contacts.size( ); i++ )
		cout << *contacts[ i ] << '\n';
}


void Pessoa::addPessoa( const Pessoa &newcontact )
{
	contacts.push_back( new Pessoa( newcontact ) );	
}



void Pessoa::addPessoa( const string &name, const string &phoneNumber, const vector< string > &socialMediaConection )
{
	contacts.push_back( new Pessoa( name, phoneNumber, socialMediaConection ) );	
}

void Pessoa::deletePessoas( )
{
	delete contacts[ contacts.size() - 1 ];
	contacts.pop_back( );
}

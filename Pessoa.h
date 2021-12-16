#ifndef PESSOA_H
#define PESSOA_H
#include <vector>
using std::vector;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
#include "Pessoa.h"
using std::cout;
using std::ostream;


class Pessoa
{
    friend ostream &operator<<( ostream &, const Pessoa & );

public:
    Pessoa( );
    Pessoa( const string &, const string &,  const vector< string > & );
    Pessoa( const Pessoa & );
    ~Pessoa( );

    void printListaProdutos( ) const;

  void printListaPessoas( ) const;

	void addPessoa( const Pessoa & );
	void addPessoa( const string &, const string &, const vector< string > & );
  

	void deletePessoas( );


private:

    string name;

    string phoneNumber;

    vector< string > socialMediaConection;
	vector< Pessoa * > contacts;

};

#endif // PESSOA_H
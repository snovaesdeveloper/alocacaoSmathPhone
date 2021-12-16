#include<iostream>
using std::cout;
using std::endl;
#include "Data.h"
#include "Produtos.h"
#include "Loja.h"
/* #include "SmartPhone.cpp" */
/* #include "Data.cpp" */
/* #include "Pessoa.cpp" */
int opt = 0;
void start();

int main()
{
    printf("\n\n******** Menu ********\n\n");
	int opt = 0;
	 
	// Receber a opção escolhida do menu.

	// Verificar qual opção foi escolhida e validar.


	/*// Call da função menu.
	menu();
	// Receber a opção escolhida do menu.
	scanf("%d", &opt);
	// Verificar qual opção foi escolhida e validar.
	validacao(&opt);*/

	// Lista as opções do programa.
	printf("\nO que voce deseja fazer:\n");
  
	printf("\n1) Inserir um cliente");
	printf("\n2) Inserir um produto");
	printf("\n3) Vender um produto para um cliente");
	printf("\n4) Mostar a lista de cliente");
	printf("\n9) Sair do programa\n\n");
	printf("CMD: "); 	
	scanf("%d", &opt);

	int aux = opt;
	switch (aux)
	{
     	// Chamar a função de cadastro de clientes.
     	case 1:
          	{// addCliente();


   //Testing 
   //Pessoa
   vector< string > printListaProdutos{ string("Cabo OTG"), string("Cabo USB") };
   Pessoa id01( "Jose", "91983738384", printListaProdutos );
   Pessoa *p;
   p = &id01;
   cout << *p << '\n';

           
            	break; }

              
     	// Chamar a função de cadastro de filmes
     	case 2:
          	{ //addProduto();

            	printf("\n1) **** Produto Adcionado ****");

            vector< string > printListaProdutos{ string("Notebook Sansung "), string("Camera digital Canon") };
   Pessoa id01( "02", "CODIGO 147147", printListaProdutos );
   Pessoa *p;
   p = &id01;
   cout << *p << '\n';

            	break; }
     	// Chamar a função de alocação de filmes.
     	case 3:
          	{ //VenderUmproduto();
            	break; }
     	// Chamar a função de retirada de filmes.
     	case 4:
          	{ //retirarProduto();
            	break; }
     	// Parar a execução e sair do programa.
     	case 9:
          	{ break; }
     	// Caso nenhuma opção acima for escolhida, mostrar mensagem de erro e chamar novamente o menu, receber e validar.
     	default:
          	{ printf("%d", opt);
            	printf("\nOPCAO INVALIDA!\n");
            //	menu();
            	scanf("%d", &opt);
            }
	}

	system("pause");
 
}








/* 
   SmartPhone sp1( 132323, Data( 30, 9, 2021 ) );

   //Testing 
   //Pessoa
  


   
   cout << "Test3";
 */
   
   

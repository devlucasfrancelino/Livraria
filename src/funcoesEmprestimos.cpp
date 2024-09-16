#include "../include/cadastroUsuario.hpp"
#include "../include/usuarios.hpp"
#include "../include/cadastroLivros.hpp"
#include "../include/livros.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pesquisarLivrosPorUsuario(string &codigoUsuario, vector<bookStruct> &livros) {
  bool encontrou = false;

  for(const auto& livro : livros){

    if(livro.codigoAluguel == codigoUsuario){

      encontrou = true;
      cout << "código do livro: " << livro.codigoLivro << endl;
      cout << "titulo do livro: " << livro.titulo << endl;
      cout << "Autor do livro: " << livro.autor << endl;
      cout << "ano do livro: " << livro.ano << endl;
      cout << "---------------------------------------------" << endl;
    }
  }
  if(!encontrou){
    cout << "Nenhum livro encontrado para o usuário " << codigoUsuario << endl;
  }
 
}
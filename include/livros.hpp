#ifndef LIVROS_HPP
#define LIVROS_HPP

#include <string>
#include <vector>

using namespace std;

struct bookStruct {
  string codigoLivro;
  string titulo;
  string subtitulo;
  string autor;
  int ano;
  string editora;
  string edicao;
  string categoria;
  string codigoAluguel;
};

// Declaração de um vetor global para armazenar os livros
extern vector<bookStruct> livros;

#endif // LIVROS_HPP

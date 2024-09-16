#include "../include/cadastroLivros.hpp"
#include "../include/livros.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void cadastroLivros(vector<bookStruct> &livros) {
  bookStruct novoLivro;

  cout << "Digite o código do livro: ";
  getline(cin, novoLivro.codigoLivro);

  cout << "Digite o título do livro: ";
  getline(cin, novoLivro.titulo);

  cout << "Digite o subtítulo do livro: ";
  getline(cin, novoLivro.subtitulo);

  cout << "Digite o autor do livro: ";
  getline(cin, novoLivro.autor);

  cout << "Digite o ano de publicação do livro: ";
  cin >> novoLivro.ano;

  cout << "Digite a editora do livro: ";
  getline(cin, novoLivro.editora);

  cout << "Digite a edição do livro: ";
  getline(cin, novoLivro.edicao);

  cout << "Digite a categoria do livro: ";
  getline(cin, novoLivro.categoria);

  livros.push_back(novoLivro);

  salvarLivros(livros);
}

void salvarLivros(const vector<bookStruct> &livros) {
  ofstream arquivo("livros.txt", ios::trunc); // Sobrescreve o arquivo
  if (arquivo.is_open()) {
    for (const auto &livro : livros) { // é a mesma coisa que isso: for (int i =
                                       // 0; i < livros.size(); ++i)
      arquivo << livro.codigoLivro << endl;
      arquivo << livro.titulo << endl;
      arquivo << livro.subtitulo << endl;
      arquivo << livro.autor << endl;
      arquivo << livro.ano << endl;
      arquivo << livro.editora << endl;
      arquivo << livro.edicao << endl;
      arquivo << livro.categoria << endl;
      arquivo << "===" << endl; // Delimitador entre livros
    }
    arquivo.close();
    cout << "Livros salvos com sucesso!" << endl;
  } else {
    cout << "Erro ao abrir o arquivo!" << endl;
  }
}

void carregarLivros(vector<bookStruct> &livros) {
    ifstream arquivo("livros.txt"); // Abre o arquivo de entrada
    if (arquivo.is_open()) {
        string linha;
        while (getline(arquivo, linha)) {
            if (linha == "===") {
                continue; // Ignora o delimitador entre os livros
            }
            bookStruct livro;
            livro.codigoLivro = linha;          // 1ª linha: código do livro
            getline(arquivo, livro.titulo);     // 2ª linha: título
            getline(arquivo, livro.subtitulo);  // 3ª linha: subtítulo
            getline(arquivo, livro.autor);      // 4ª linha: autor
            arquivo >> livro.ano;               // 5ª linha: ano
            arquivo.ignore();                   // Limpar nova linha após o ano
            getline(arquivo, livro.editora);    // 6ª linha: editora
            getline(arquivo, livro.edicao);     // 7ª linha: edição
            getline(arquivo, livro.categoria);  // 8ª linha: categoria
            livros.push_back(livro);            // Adiciona o livro à lista
        }
        arquivo.close();
        cout << "Livros carregados com sucesso!" << endl;
    } else {
        cout << "Nenhum arquivo de livros encontrado." << endl;
    }
}


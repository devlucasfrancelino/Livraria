#include "../include/funcoesLivros.hpp"
#include "../include/cadastroUsuario.hpp"
#include "../include/usuarios.hpp"
#include "../include/cadastroLivros.hpp"
#include "../include/livros.hpp"
#include "../include/funcoesEmprestimos.hpp"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

void imprimirMenu() {
  cout << "----- Gerenciamento da biblioteca -----" << endl;
  cout << "1 - Cadastro" << endl;
  cout << "2 - Acervo" << endl;
  cout << "3 - Emprestimo" << endl;
  cout << "4 - Meus Livros" << endl;
  cout << "5 - Devolucao" << endl;
  cout << "6 - Relatorio de emprestimos" << endl;
  cout << "7 - Sair" << endl << endl;
}

void visualizarAcervo() {
  cout << "-- Livros disponíveis --" << endl;
  for (int i = 0; i < livros.size(); ++i) {
    cout << "Título: " << livros[i].titulo << endl
         << "  Ano: " << livros[i].ano << endl
         << "  Autor: " << livros[i].autor << endl
         << "  Código: " << livros[i].codigoLivro << endl
         << "  Editora: " << livros[i].editora << endl
         << "  Categoria: " << livros[i].categoria << endl
         << endl;
  }
}

string toLowerCase(const string &str) {
  string lowerStr = str;
  transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
  return lowerStr;
}

void pesquisarLivros() {
  int escolhaPesquisa;
  cout << "----- Pesquisa de Livros -----" << endl;
  cout << "1 - Por Título" << endl;
  cout << "2 - Por Autor" << endl;
  cout << "3 - Por Ano" << endl;
  cout << "4 - Voltar" << endl;
  cout << "Escolha uma opção: ";
  cin >> escolhaPesquisa;
  cin.ignore(); // Limpar o buffer de entrada

  switch (escolhaPesquisa) {
  case 1: {
    string titulo;
    cout << "Digite o título do livro: ";
    getline(cin, titulo);
    string tituloLower = toLowerCase(titulo);
    bool encontrado = false;
    for (int i = 0; i < livros.size(); ++i) {
      if (toLowerCase(livros[i].titulo).find(tituloLower) != string::npos) {
        cout << "Título: " << livros[i].titulo << endl
             << "  Ano: " << livros[i].ano << endl
             << "  Autor: " << livros[i].autor << endl
             << "  Código: " << livros[i].codigoLivro << endl
             << "  Editora: " << livros[i].editora << endl
             << "  Categoria: " << livros[i].categoria << endl
             << endl;
        encontrado = true;
      }
    }
    if (!encontrado) {
      cout << "Nenhum livro encontrado com o título fornecido." << endl;
    }
    break;
  }
  case 2: {
    string autor;
    cout << "Digite o nome do autor: ";
    getline(cin, autor);
    string autorLower = toLowerCase(autor);
    bool encontrado = false;
    for (int i = 0; i < livros.size(); ++i) {
      if (toLowerCase(livros[i].autor).find(autorLower) != string::npos) {
        cout << "Título: " << livros[i].titulo << endl
             << "  Ano: " << livros[i].ano << endl
             << "  Autor: " << livros[i].autor << endl
             << "  Código: " << livros[i].codigoLivro << endl
             << "  Editora: " << livros[i].editora << endl
             << "  Categoria: " << livros[i].categoria << endl
             << endl;
        encontrado = true;
      }
    }
    if (!encontrado) {
      cout << "Nenhum livro encontrado com o autor fornecido." << endl;
    }
    break;
  }
  case 3: {
    int ano;
    cout << "Digite o ano de publicação: ";
    cin >> ano;
    bool encontrado = false;
    for (int i = 0; i < livros.size(); ++i) {
      if (livros[i].ano == ano) {
        cout << "Título: " << livros[i].titulo << endl
             << "  Ano: " << livros[i].ano << endl
             << "  Autor: " << livros[i].autor << endl
             << "  Código: " << livros[i].codigoLivro << endl
             << "  Editora: " << livros[i].editora << endl
             << "  Categoria: " << livros[i].categoria << endl
             << endl;
        encontrado = true;
      }
    }
    if (!encontrado) {
      cout << "Nenhum livro encontrado com o ano fornecido." << endl;
    }
    break;
  }
  case 4:
    break; // Voltar para o menu principal
  default:
    cout << "Opção inválida." << endl;
    break;
  }
}

int mostrarMenu() {
  while (true) { // Loop principal para o menu
    int escolha;
    imprimirMenu();
    cin >> escolha;
    cin.ignore(); // Limpar o buffer de entrada

    switch (escolha) {
    case 1:
      int escolhaCadastro;
      cout << "---- Opções de cadastro ----" << endl;
      cout << "1 - Cadastrar Livro" << endl;
      cout << "2 - Cadastrar Usuário" << endl;
      cin >> escolhaCadastro;
      cin.ignore();
      switch (escolhaCadastro) {
      case 1:
        cadastroLivros(livros); // Chama a função de cadastro
        break;
        case 2:
        cadastroUsuarios(usuarios); // Chama a função de cadastro);
        break;
        
      default:
        cout << "Opção inválida" << endl;
      }
      break;
    case 2:
      int escolhaAcervo;
      cout << "----- Opções de Acervo -----" << endl;
      cout << "1 - Visualizar Todo o Acervo" << endl;
      cout << "2 - Pesquisar Livros" << endl;
      cout << "3 - Voltar" << endl;
      cout << "Escolha uma opção: ";
      cin >> escolhaAcervo;
      cin.ignore(); // Limpar o buffer de entrada

      switch (escolhaAcervo) {
      case 1:
        visualizarAcervo();
        break;
      case 2:
        pesquisarLivros();
        break;
      case 3:
        break; // Voltar para o menu principal
      default:
        cout << "Opção inválida." << endl;
        break;
      }
      break;
    case 3:
      // Implementar emprestimo aqui
      break;
    case 4:
      {
      string codigoUsuario;
      cout << "Digite o código do usuário: ";
      getline(cin, codigoUsuario);
      pesquisarLivrosPorUsuario(codigoUsuario, livros);
      break;
      }
    case 5:
      // Implementar devolucao aqui
      break;
    case 6://9
      // Implementar relatorio de emprestimos aqui
      break;
    case 7:
      return 0; // Sair do programa
    default:
      cout << "Opção inválida" << endl;
      break;
    }
  }
  return 0;
}

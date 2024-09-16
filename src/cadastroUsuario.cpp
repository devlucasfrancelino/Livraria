#include "../include/cadastroUsuario.hpp"
#include "../include/usuarios.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void cadastroUsuarios(vector<userStruct> &usuarios) {
  userStruct novoUsuario;

  cout << "Digite o nome do usuário: ";
  getline(cin, novoUsuario.nome);

  cout << "Digite o código do usuário: ";
  getline(cin, novoUsuario.codigoUsuario);

  cout << "Digite o email do usuário: ";
  getline(cin, novoUsuario.email);

  cout << "Digite o telefone do usuário";
  getline(cin, novoUsuario.telefone);

  usuarios.push_back(novoUsuario);

  salvarUsuario(usuarios);
}

void salvarUsuario(const vector<userStruct> &usuarios) {
  ofstream arquivo("Livros/resources/usuarios.txt", ios::trunc);
  if (arquivo.is_open()) {
    for (const auto &usuario : usuarios) {
      arquivo << usuario.codigoUsuario << endl;
      arquivo << usuario.nome << endl;
      arquivo << usuario.email << endl;
      arquivo << usuario.telefone << endl;
      arquivo << usuario.historico << endl;
      arquivo << "=======" << endl;
    }
    arquivo.close();
    cout << "Usuarios salvos com sucesso!" << endl;

  } else {
    cout << "Erro ao salvar os usuarios!" << endl;
  }
}

void carregarUsuarios(vector<userStruct> &usuarios) {
  ifstream arquivo(
      "Livros/resources/usuarios.txt"); // Abre o arquivo de entrada
  if (arquivo.is_open()) {
    string linha;
    while (getline(arquivo, linha)) {
      if (linha == "===") {
        continue; // Ignora o delimitador entre os livros
      }
      userStruct usuario;
      ;
      usuario.codigoUsuario = linha;
      getline(arquivo, usuario.nome);
      getline(arquivo, usuario.email);
      getline(arquivo, usuario.telefone);
      getline(arquivo, usuario.historico);
      usuarios.push_back(usuario); // Adiciona o livro na lista
    }
    arquivo.close();
    cout << "Usuarios carregados com sucesso!" << endl;
  } else {
    cout << "Nenhum usuario encontrado." << endl;
  }
}

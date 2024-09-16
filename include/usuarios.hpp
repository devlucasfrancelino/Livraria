#ifndef USUARIOS_HPP
#define USUARIOS_HPP


#include <string>
#include <vector>

using namespace std;

struct userStruct {
  string nome;
  string codigoUsuario;
  string email;
  string telefone;
  string historico;
};

extern vector<userStruct> usuarios;

#endif // USUARIOS_HPP
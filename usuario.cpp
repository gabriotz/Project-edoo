#include "usuario.h"


using namespace std;

string Usuario::getLogin() const{
    return login;
}


string Usuario::getSenha() const{
    return senha;
}

bool Usuario::verificarLogin(const std::string& tentativaLogin, const std::string& tentativaSenha) const{
    return (tentativaLogin == login & tentativaSenha == senha)
}
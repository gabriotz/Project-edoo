#ifndef USUARIO_H
#define USUARIO_H

#include "livros.h"
#include "acervo.h"
#include <string> 
#include <iostream>


class Usuario : public Acervo {
    private:
        
        std:: string login;
        std:: string senha;        


    public:
        Usuario(std::string& uLogin,std::string& uSenha) : Acervo(), login(uLogin), senha(uSenha){

        }
        std:: string getLogin() const{
            return login;
        }
        std:: string getSenha() const{
            return senha;
        }
        

};

#endif 
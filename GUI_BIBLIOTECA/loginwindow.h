#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "cadastros.h"

namespace Ui {
class LoginWindow;
}
// Classe da janela de Login, a primeira tela do sistema.
class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    // Construtor que recebe o sistema de cadastros.
    explicit LoginWindow(Cadastros* cadastros, QWidget *parent = nullptr);
    // Destrutor
    ~LoginWindow();
// Seção de "sinais", que são mensagens que esta janela pode emitir para outras partes do programa.
signals:
    // Sinal emitido para notificar que a janela de cadastro deve ser mostrada.
    void showRegistrationWindow();
    // Sinal emitido quando o login é bem-sucedido, enviando os dados do usuário logado.
    void loginSuccessful(Usuario* user);

private slots:
    // Funções que respondem aos cliques nos botões.
    void on_registerButton_clicked();
    void on_loginButton_clicked();

private:
    // Ponteiro para a interface gráfica.
    Ui::LoginWindow *ui;
    // Ponteiro para o sistema de cadastros.
    Cadastros* m_cadastros;
};

#endif // LOGINWINDOW_H

#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QDialog>
#include "cadastros.h"

namespace Ui {
class RegistrationWindow;
}
// Classe da janela de cadastro de novos usuários.
class RegistrationWindow : public QDialog
{
    Q_OBJECT

public:
    // Construtor que recebe o sistema de cadastros.
    explicit RegistrationWindow(Cadastros* cadastros, QWidget *parent = nullptr);
    // Destrutor
    ~RegistrationWindow();

signals:
    // Sinal emitido para notificar que a janela de login deve ser exibida novamente.
    void showLoginWindow();

private slots:
    // Slots para os botões da tela de cadastro.
    void on_loginButton_clicked(); // Botão de voltar
    void on_registerButton_clicked(); // Botão de cadastrar

private:
    // Ponteiro para a interface gráfica.
    Ui::RegistrationWindow *ui;
    // Ponteiro para o sistema de cadastros
    Cadastros* m_cadastros;
};

#endif // REGISTRATIONWINDOW_H

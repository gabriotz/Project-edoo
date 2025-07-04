#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QDialog>
#include "cadastros.h" // Inclua o cabeçalho do backend

namespace Ui {
class RegistrationWindow;
}

class RegistrationWindow : public QDialog
{
    Q_OBJECT

public:
    // Modifique o construtor
    explicit RegistrationWindow(Cadastros* cadastros, QWidget *parent = nullptr);
    ~RegistrationWindow();

signals:
    void showLoginWindow();

private slots:
    void on_loginButton_clicked(); // Botão de voltar
    void on_registerButton_clicked(); // Botão de cadastrar

private:
    Ui::RegistrationWindow *ui;
    Cadastros* m_cadastros; // Ponteiro para o sistema de cadastros
};

#endif // REGISTRATIONWINDOW_H

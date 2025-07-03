#ifndef USERBOOKSWINDOW_H
#define USERBOOKSWINDOW_H


#include <QDialog>
#include "../usuario.h"
#include "../acervo.h"


namespace Ui {
class userBooksWindow;
}

class userBooksWindow : public QDialog
{
    Q_OBJECT

public:
    explicit userBooksWindow(Usuario* currentUser, Acervo* acervo, QWidget *parent = nullptr);
    ~userBooksWindow();

private:
    Ui::userBooksWindow *ui;
    Usuario* m_currentUser;
    Acervo* m_acervo;

     void popularListaDeLivros();

private slots:
    void on_returnButton_clicked();

};

#endif // USERBOOKSWINDOW_H

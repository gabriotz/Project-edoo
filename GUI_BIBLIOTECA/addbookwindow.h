#ifndef ADDBOOKWINDOW_H
#define ADDBOOKWINDOW_H

#include <QDialog>
#include "../acervo.h" // Inclua o acervo
#include "../livros.h"

namespace Ui {
class addBookWindow;
}

class addBookWindow : public QDialog
{
    Q_OBJECT

public:
    // Construtor modificado para receber o Acervo
    explicit addBookWindow(Acervo* acervo, QWidget *parent = nullptr);
    ~addBookWindow();

private:
    Ui::addBookWindow *ui;
    Acervo* m_acervo; // Declarado para o futuro
private slots:
    void on_addBookButton_clicked();

};
#endif // ADDBOOKWINDOW_H

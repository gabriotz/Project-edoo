#ifndef ADDBOOKWINDOW_H
#define ADDBOOKWINDOW_H

#include <QDialog>
#include "acervo.h" // Inclua o acervo
#include "livros.h"
// Namespace gerado pelo Qt para os elementos da interface.
namespace Ui {
class addBookWindow;
}
// Declaração da classe da janela para adicionar livros. Ela herda de QDialog.
class addBookWindow : public QDialog
{
    Q_OBJECT

public:
    // Construtor da janela. 'explicit' previne conversões implícitas.
    explicit addBookWindow(Acervo* acervo, QWidget *parent = nullptr);
    // Destrutor
    ~addBookWindow();

private:
    // Ponteiro para a interface gráfica gerada pelo Qt Designer.
    Ui::addBookWindow *ui;
    // Ponteiro para o objeto Acervo principal do sistema.
    Acervo* m_acervo;
// Seção para os "slots", que são funções executadas em resposta a eventos (como cliques de botão).
private slots:
    void on_addBookButton_clicked();

};
#endif // ADDBOOKWINDOW_H

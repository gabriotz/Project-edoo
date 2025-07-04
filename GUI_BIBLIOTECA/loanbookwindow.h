#ifndef LOANBOOKWINDOW_H
#define LOANBOOKWINDOW_H

#include <QDialog>
#include "usuario.h"
#include "acervo.h"

namespace Ui {
class loanBookWindow;
}

class loanBookWindow : public QDialog
{
    Q_OBJECT

public:

    explicit loanBookWindow(Acervo* acervo, Usuario* currentUser, QWidget *parent = nullptr);
    ~loanBookWindow();

private:
    int m_currentIndex;
    Ui::loanBookWindow *ui;
    Acervo* m_acervo;
    Usuario* m_currentUser;

    void updateBookDisplay();

private slots:
    void on_loanButton_clicked();
    void on_nextButton_clicked();
    void on_previousButton_clicked();

};

#endif // LOANBOOKWINDOW_H

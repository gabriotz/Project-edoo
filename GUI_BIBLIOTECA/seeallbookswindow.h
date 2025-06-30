#ifndef SEEALLBOOKSWINDOW_H
#define SEEALLBOOKSWINDOW_H

#include <QDialog>
#include "../acervo.h"

namespace Ui {
class seeAllBooksWindow;
}

class seeAllBooksWindow : public QDialog
{
    Q_OBJECT

public:
    explicit seeAllBooksWindow(Acervo* acervo, QWidget *parent = nullptr);
    ~seeAllBooksWindow();

private:
    int m_currentIndex;
    Ui::seeAllBooksWindow *ui;
    Acervo* m_acervo;
    void updateBookDisplay();
private slots:
    void on_nextButton_clicked();
    void on_previousButton_clicked();

};

#endif // SEEALLBOOKSWINDOW_H

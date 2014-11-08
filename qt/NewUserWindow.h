#ifndef NEWUSER_H
#define NEWUSER_H

#include <QDialog>
#include <QCloseEvent>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include "../lib/Netflix.h"

/*namespace Ui {
class Dialog;
}*/

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0, Netflix *n=NULL);

    ~Dialog();
    Netflix *temp;
    Map<string,Movie*> *tempM;
	Map<string,User*> *tempU;

public slots:
	void add();
	void cancelPage();


protected:

    void closeEvent(QCloseEvent *);

private:
    //Ui::Dialog *ui;
    QPushButton *confirm, *cancel;
	QLineEdit *login, *password;


};

#endif // NEWUSER_H
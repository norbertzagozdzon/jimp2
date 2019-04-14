#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matrix.h"
#include<complex>

Matrix rep[100];
int g;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowserMatrix->setFont (QFont ("Courier", 9));
    ui->textBrowserMatrix->setReadOnly(true);
    ui->lineEditC->setDisabled(true);
    ui->textEditError->setReadOnly(true);
    g=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::errorCompleted() {
    ui->textEditError->setStyleSheet("background-color:black; color:#C0C0C0");
    ui->textEditError->setText("Completed.");
}
void MainWindow::errorWrong(const QString &text) {
    ui->textEditError->setStyleSheet("background-color:black;color:red");
    ui->textEditError->setText(text);
}
void MainWindow::on_listWidget_clicked()
{
    int curRow = ui->listWidget->currentRow();
    ui->textBrowserMatrix->setText(QString::fromStdString(rep[curRow].print()));

}
int MainWindow::listSearch(QListWidget *list, QLineEdit *line) {
    int listSize = list->count();
    int elseIndex=-1;
    for (int i=0;i<listSize;i++) {
        if(line->text()==list->item(i)->text()) {
            elseIndex=i;
            break;
        }
    }
    return elseIndex;
}

void MainWindow::on_pushAddMatrix_clicked()
{
    if (ui->textEdit->toPlainText()!="") {
        Matrix m = Matrix(ui->textEdit->toPlainText().toUtf8().constData());
        if (m.isError()) {
            errorWrong("Wrong matLab syntax.");
            return;
        }
        if (ui->textVarName->text()!="") {
            int listSize = ui->listWidget->count();
            bool ifIs = false;
            int elseIndex=-1;
            for (int i=0;i<listSize;i++) {
                if(ui->textVarName->text()==ui->listWidget->item(i)->text()) {
                    ifIs = true;
                    elseIndex=i;
                    break;
                }
            }
            if (ifIs==false) {
                ui->listWidget->addItem(ui->textVarName->text());
                rep[g] = m;
                g++;
            }
            else {
                rep[elseIndex]=m;
            }
            errorCompleted();
        }
        ui->textBrowserMatrix->setText(QString::fromStdString(m.print()));

    }
    else {
        ui->textEditError->setStyleSheet("background-color:black; color: red");
        ui->textEditError->setText("Matrix Entering Zone is empty.");
    }
}


void MainWindow::on_addButton_clicked()
{
    ui->labelOp->setText("Add");
    ui->lineEditC->setDisabled(false);
    errorCompleted();
}

void MainWindow::on_subButton_clicked()
{
    ui->labelOp->setText("Sub");
    ui->lineEditC->setDisabled(false);
    errorCompleted();
}

void MainWindow::on_mulButton_clicked()
{
    ui->labelOp->setText("Mul");
    ui->lineEditC->setDisabled(false);
    errorCompleted();
}

void MainWindow::on_divButton_clicked()
{
    ui->labelOp->setText("Div");
    ui->lineEditC->setDisabled(false);
    errorCompleted();
}

void MainWindow::on_mulByButton_clicked()
{
    ui->labelOp->setText("MulByNum");
    ui->lineEditC->setDisabled(false);
    errorCompleted();
}

void MainWindow::on_divByButton_clicked()
{
    ui->labelOp->setText("DivByNum");
    ui->lineEditC->setDisabled(false);
    errorCompleted();
}

void MainWindow::on_powButton_clicked()
{
    ui->labelOp->setText("Pow");
    ui->lineEditC->setDisabled(false);
    errorCompleted();
}

void MainWindow::on_revButton_clicked()
{
    ui->labelOp->setText("Rev");
    ui->lineEditC->setDisabled(true);
    errorCompleted();
}

void MainWindow::on_transButton_clicked()
{
    ui->labelOp->setText("Trans");
    ui->lineEditC->setDisabled(true);
    errorCompleted();
}

void MainWindow::on_compButton_clicked()
{
    ui->labelOp->setText("Comp");
    ui->lineEditC->setDisabled(true);
    errorCompleted();
}

void MainWindow::on_pushResult_clicked()
{
    int i=-1,j=-1;
    QString choice = ui->labelOp->text();
    if(ui->lineEditB->text()!="") {
        i = listSearch(ui->listWidget,ui->lineEditB);
        if (i==-1) {
            errorWrong("Matrix aint in the list.");
        }
    }
    else {
        errorWrong("Empty slot in operation zone.");
        return;
    }
    if(ui->lineEditC->isEnabled()==true) {
        if(ui->lineEditC->text()!="") {
            if (choice=="Add" || choice=="Add" || choice=="Add" || choice=="Add") {

                j=listSearch(ui->listWidget,ui->lineEditC);
                if (j==-1) {
                    errorWrong("Matrix aint in the list.");
                }
            }
        }
        else {
            errorWrong("Empty slot in operation zone.");
            return;
        }
    }
    Matrix result;
    if (ui->labelOp->text()=="Add") {result = rep[i].add(rep[j]);}
    else if(ui->labelOp->text()=="Sub") {result = rep[i].sub(rep[j]);}
    else if(ui->labelOp->text()=="Mul") {result = rep[i].mul(rep[j]);}
    else if(ui->labelOp->text()=="Div") {result = rep[i].div(rep[j]);}
    else if(ui->labelOp->text()=="MulByNum") {result = rep[i].mulByNumber(readComplex(ui->lineEditC->text().toUtf8().constData()));}
    else if(ui->labelOp->text()=="DivByNum") {result = rep[i].divByNumber(readComplex(ui->lineEditC->text().toUtf8().constData()));}
    else if(ui->labelOp->text()=="Pow") {result = rep[i].pow(ui->lineEditC->text().toInt());}
    else if(ui->labelOp->text()=="Rev") {result = rep[i].reverse();}
    else if(ui->labelOp->text()=="Trans") {result = rep[i].transpose();}
    else if(ui->labelOp->text()=="Comp") {result = rep[i].matrixOfComplements();}
    else {
        errorWrong("Enter some operation.");
        return;
    }
    if(ui->lineEditA->text()=="") {
        ui->textBrowserMatrix->setText(QString::fromStdString(result.print()));
    }
    else {
        int k = listSearch(ui->listWidget,ui->lineEditA);
        if (k==-1) {
            ui->listWidget->addItem(ui->lineEditA->text());
            rep[g]=result;
            g++;
        }
        else {
          rep[k]=result;
        }
    }
    ui->textBrowserMatrix->setText(QString::fromStdString(result.print()));
    if (result.isError()) {
        errorWrong("Error while operating.");
    }
    else {
        errorCompleted();
    }

}

void MainWindow::on_resultButtonDet_clicked()
{
    if(ui->lineEditDet->text()!="") {
        int i = listSearch(ui->listWidget,ui->lineEditDet);
        if(i==-1) {
            errorWrong("Matrix aint in the list.");
        }
        else {
            QString result = QString::fromStdString(complexToString(rep[i].det()));
            ui->textBrowserDet->setText(result);
            if(result=="-1") {
                errorWrong("Result of det might be wrong.");
            }
       }
    }
    else {
        errorWrong("Enter some Matrix.");
    }
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QListWidget>
#include<QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void errorCompleted();
    void errorWrong(const QString &text);
    int listSearch(QListWidget *list, QLineEdit *line);
    void on_listWidget_clicked();
    void on_pushAddMatrix_clicked();
    void on_addButton_clicked();
    void on_subButton_clicked();
    void on_mulButton_clicked();
    void on_divButton_clicked();
    void on_mulByButton_clicked();
    void on_divByButton_clicked();
    void on_powButton_clicked();
    void on_revButton_clicked();
    void on_transButton_clicked();
    void on_compButton_clicked();
    void on_pushResult_clicked();
    void on_resultButtonDet_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

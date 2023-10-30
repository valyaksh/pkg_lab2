#ifndef FILE_H
#define FILE_H

#include <QMainWindow>
#include <QImageReader>
#include <QWidget>
#include <QDir>
#include <QFileSystemModel>
#include <QModelIndex>
#include <QGridLayout>
#include <QListView>
#include <QImageWriter>
#include <QTableWidget>
#include <QFileDialog>
#include <QHeaderView>
QT_BEGIN_NAMESPACE
namespace Ui { class File; }
QT_END_NAMESPACE

class File : public QMainWindow
{
    Q_OBJECT

public:
    File(QWidget *parent = nullptr);
    ~File();

private slots:


    void on_listView_doubleClicked(const QModelIndex &index);
    void addFileInfoToTable(QTableWidget *tableWidget, const QString &filePath);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::File *ui;
    QFileSystemModel *file;
};
#endif // FILE_H

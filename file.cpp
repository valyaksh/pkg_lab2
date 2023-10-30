#include "file.h"
#include "ui_file.h"

File::File(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::File)
{
    ui->setupUi(this);
    file = new QFileSystemModel(this);
    file->setFilter(QDir::QDir::AllEntries);
    file->setRootPath("");
    ui->listView->setModel(file);

}

File::~File()
{
    delete ui;
}


void File::on_listView_doubleClicked(const QModelIndex &index)
{
    QListView* listView = (QListView*)sender();
    QFileInfo fileInfo = file->fileInfo(index);
    ui->lineEdit->setText(file->filePath(index));

    if(fileInfo.fileName() == "..")
    {
        QDir dir = fileInfo.dir();
        dir.cdUp();
        file->index(dir.absolutePath());
        listView->setRootIndex(file->index(dir.absolutePath()));
    }

    else if (fileInfo.fileName() == ".")
    {
        listView->setRootIndex(file->index(""));
    }

    else if(fileInfo.isDir())
    {
        listView->setRootIndex(index);
    }
    else if(!fileInfo.isDir())

    {
        addFileInfoToTable(ui->tableWidget,file->filePath(index));
    }

}

void File::addFileInfoToTable(QTableWidget *tableWidget, const QString &filePath) {
    QFileInfo fileInfo(filePath);
    QImageReader imageReader(filePath);
    int row = tableWidget->rowCount();
    tableWidget->insertRow(row);

    QTableWidgetItem *itemName = new QTableWidgetItem(fileInfo.fileName());
    tableWidget->setItem(row, 0, itemName);

    if (imageReader.size().isValid()) {
        QImage image(filePath);
        QString imageSize = QString("%1x%2").arg(image.width()).arg(image.height());
        QTableWidgetItem *itemSize = new QTableWidgetItem(imageSize);
        tableWidget->setItem(row, 1, itemSize);

        QString resolution = QString("%1 dpi").arg(image.dotsPerMeterX() * 0.0254);
        QTableWidgetItem *itemResolution = new QTableWidgetItem(resolution);
        tableWidget->setItem(row, 2, itemResolution);

        QImage img (filePath);
        tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(img.bitPlaneCount())));

        QImageWriter a(filePath);
        tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(a.compression())));
        tableWidget->sortItems(3, Qt::DescendingOrder);
    } else {

        for (int col = 1; col < tableWidget->columnCount(); col++) {
            QTableWidgetItem *emptyItem = new QTableWidgetItem("");
            tableWidget->setItem(row, col, emptyItem);
        }
    }
}


void File::on_pushButton_4_clicked()
{
    QString folderPath = QFileDialog::getExistingDirectory(this, "Выберите папку с изображениями", QDir::homePath());

    if (!folderPath.isEmpty()) {
        QDir folder(folderPath);
        QFileInfoList fileList = folder.entryInfoList(QDir::Files);

        foreach (const QFileInfo &fileInfo, fileList) {
            if (QImageReader::supportedImageFormats().contains(fileInfo.suffix().toLower().toUtf8())) {
                addFileInfoToTable(ui->tableWidget, fileInfo.filePath());
            }
        }
    }
}


void File::on_pushButton_5_clicked()
{
    file->setRootPath("");
    ui->listView->setRootIndex(file->index(""));
    ui->lineEdit->clear();
}


void File::on_pushButton_3_clicked()
{
    QTableWidget *tableWidget = ui->tableWidget;
    int selectedRow = tableWidget->currentRow();

    if (selectedRow >= 0) {
        tableWidget->removeRow(selectedRow);
    }
}


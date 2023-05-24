#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "gsdump.h"

#include <QFileDialog>
#include <QMessageBox>

#include <iostream>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    gsdump = new GSDump();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gsdump;
}


void MainWindow::on_actionOpen_triggered()
{
    auto fileName = QFileDialog::getOpenFileName(this, tr("Open GS Dump"), ".", tr("GS Dump Files (*.gs)"));

    if (!fileName.isEmpty()) {

        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Unable to open file"), file.errorString());
            return;
        }

        QDataStream in(&file);
        int fileLen = file.size();
        auto buf = std::vector<char>(fileLen);
        int bytesRead = in.readRawData(buf.data(), fileLen);

        gsdump->setData(buf);
    }
}


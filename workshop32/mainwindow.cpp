#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // setting render area
    // (can't do through Designer because it doesn't have custom widgets)
    _renderArea = new RenderArea(ui->centralwidget);

    // creating size policy "expand vertically and horizontally"
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    // setting size proportion when expanding (copying default of other widgets)
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    // copying existing value of property "hasHeightForWidth"
    sizePolicy.setHeightForWidth(_renderArea->sizePolicy().hasHeightForWidth());
    // applying size policy
    _renderArea->setSizePolicy(sizePolicy);


    // setting the layout for the main window
    QHBoxLayout* horLayout = new QHBoxLayout(ui->centralwidget); //(centralwidget);

    // adding render area and a group with everything else to the layout
    // They will be ordered left to right in the order in which you add them:
    // render area to the left, settings to the right.
    horLayout->addWidget(_renderArea);
    horLayout->addWidget(ui->grpSettings);

    // trigger setting default parameters
    on_spinBoxLevels_valueChanged(ui->spinBoxLevels->value());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLevelsSlot(int lvls)
{
    std::cout << lvls << "\n";
    _renderArea->setLevels(lvls);
}

void MainWindow::on_spinBoxLevels_valueChanged(int lvls)
{
//    _renderArea->setLevels(lvls);
}

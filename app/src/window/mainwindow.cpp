#include "app/include/window/mainwindow.h"
#include "../../window/ui_mainwindow.h"

VisualFlow::VisualFlow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VisualFlow)
{
    ui->setupUi(this);
}

VisualFlow::~VisualFlow()
{
    delete ui;
}


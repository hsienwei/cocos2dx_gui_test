#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "EditorDelegate.h"
#include "CCQGLView.h"

#include "EditorScene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
	_appDelegate(NULL),
	_glWidget(NULL),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{
	EditorLayer::getInstance()->testAction();
}

void MainWindow::on_pushButton_2_pressed()
{
	EditorLayer::getInstance()->testAdd();
}

void MainWindow::closeEvent(QCloseEvent *)
{
	cocos2d::Director::getInstance()->end();
	qApp->quit();
}

void MainWindow::setGLView(QWidget *glWidget)
{
	_glWidget = glWidget;

	/*if (_glWidget)
	{
		//_glWidget->setParent(ui->widget);
		ui->horizontalLayout->addWidget(_glWidget);
		//ui->dockWidget_2->setWidget(_glWidget);
		//setCentralWidget(ui->dockWidget_2);
	}*/
}



void MainWindow::on_listView_clicked(const QModelIndex &index)
{

}

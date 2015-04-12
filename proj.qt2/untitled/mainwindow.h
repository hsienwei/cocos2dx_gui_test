#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class EditorDelegate;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

	void setGLView(QWidget *glWidget);

protected:
	void closeEvent(QCloseEvent *);

private slots:
    void on_pushButton_pressed();

    void on_pushButton_2_pressed();

    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
	EditorDelegate         *_appDelegate;
	QWidget             *_glWidget;
};

#endif // MAINWINDOW_H

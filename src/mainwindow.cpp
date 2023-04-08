#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->push0,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push1,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push2,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push3,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push4,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push5,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push6,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push7,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push8,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push9,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push_asin,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push_acos,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push_atan,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push_sin,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push_cos,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push_tan,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push_plus,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push_minus,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push_mult,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push_divide,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push_sqrt,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push_exp,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push_mod,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push_log,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push_ln,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push_o_b,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push_c_b,SIGNAL(clicked()),this,SLOT(digitnums()));
    connect(ui->push_x,SIGNAL(clicked()),this,SLOT(digitnums()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitnums(){

    QPushButton * button = (QPushButton *)sender();
    QString syms;
    syms = ui->output->text() + button->text();
    if (sender() == ui->push_tan || sender() == ui->push_sin || sender() == ui->push_cos || sender() == ui->push_atan || sender() == ui->push_asin || sender() == ui->push_acos || sender() == ui->push_ln  || sender() == ui->push_log  || sender() == ui->push_sqrt) syms = syms + "(";
    ui->output->setText(syms);

}

void MainWindow::on_push_clear_string_clicked()
{
    ui->output->setText("");
}


void MainWindow::on_push_clear_sym_clicked()
{
    QString syms = ui->output->text();
    syms.chop(1);
    ui->output->setText(syms);
}


void MainWindow::on_push_calculate_clicked()
{
    QByteArray qwe = ui->output->text().toUtf8();
    char * tocalc = qwe.data();
    if (check_if_ok(tocalc) == 0) {
        if(ui->output->text().contains("x")) {
            if (ui->x_input->text() != "" ) {
                char * okinput = ui->x_input->text().toUtf8().data();
                if (!IsOkDouble(okinput)) {
                    char* tocalc_x = x_case(tocalc,ui->x_input->text().toDouble());
                    double num = str_unparser(str_parser(tocalc_x));
                    QString res = QString::number(num);
                    ui->output->setText(res);
                }
            } else {
                ui->output->setText("now enter with x value");
            }
        } else {
            double num = str_unparser(str_parser(tocalc));
            QString weq = QString::number(num);
            ui->output->setText(weq);
        }
    } else {
        ui->output->setText("input error");
    }
}


void MainWindow::on_makegraph_clicked()
{
    QVector<double>x,y;
    char *okxmin;
    char *okxmax;
    okxmin = ui->xmin->text().toUtf8().data();
    okxmax = ui->xmax->text().toUtf8().data();
    double xmin = ui->xmin->text().toDouble();
    double xmax = ui->xmax->text().toDouble();
    if (ui->xmax->text() != "" && ui->xmin->text() != "") {
        if((IsOkDouble(okxmin) == 0 && IsOkDouble(okxmax) == 0 ) && !(check_if_ok(x_case(ui->output->text().toUtf8().data(),0))) && (xmin < xmax)){
//            if( (ui->ymin->text() == "" && ui->ymax->text() == "") || (IsOkDouble(okymin) == 0 && IsOkDouble(okymax) == 0) ) {
                ui->graphwidget->xAxis->setRange(ui->xmin->text().toDouble(),ui->xmax->text().toDouble());
                ui->graphwidget->yAxis->setRange(ui->ymin->text().toDouble(),ui->ymax->text().toDouble());
                if(ui->graphwidget->graph()) {
                    ui->graphwidget->graph()->data()->clear();
                    ui->graphwidget->replot();
                }
                for(double i = xmin;i <= xmax;i+=(xmax-xmin)/80000) {
                    x.push_back(i);
                    y.push_back(str_unparser(str_parser(x_case(ui->output->text().toUtf8().data(),i))));
                    if(check_if_ok(x_case(ui->output->text().toUtf8().data(),i)) == 1) ui->output->setText("input error");
                }
                ui->graphwidget->addGraph();
                ui->graphwidget->graph()->addData(x,y);
                ui->graphwidget->replot();
                x.clear();
                y.clear();
//            }
        }
    }
}



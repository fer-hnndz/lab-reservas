/********************************************************************************
** Form generated from reading UI file 'cframe.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CFRAME_H
#define UI_CFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cframe
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_Titulo;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_6;
    QComboBox *CBX_PerfSol;
    QComboBox *CBX_LabSol;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_RepRerserv;
    QComboBox *CBX_RepReserv;
    QLabel *label_10;
    QLineEdit *lineEdit_5;
    QLabel *label_11;
    QSpinBox *spinBox_CantIntegrantes;
    QPushButton *PB_Enviar;
    QWidget *tab_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Cframe)
    {
        if (Cframe->objectName().isEmpty())
            Cframe->setObjectName(QString::fromUtf8("Cframe"));
        Cframe->resize(725, 775);
        Cframe->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 0, 22);\n"
"border-color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(Cframe);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 10, 731, 721));
        QPalette palette;
        QBrush brush(QColor(4, 1, 1, 163));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(218, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        QBrush brush3(QColor(26, 87, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Link, brush3);
        QBrush brush4(QColor(255, 245, 229, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush4);
        QBrush brush5(QColor(255, 255, 255, 63));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush6(QColor(70, 70, 70, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush4);
        tabWidget->setPalette(palette);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(33, 33, 33);"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_Titulo = new QLabel(tab);
        label_Titulo->setObjectName(QString::fromUtf8("label_Titulo"));
        label_Titulo->setGeometry(QRect(140, 30, 481, 41));
        QFont font;
        font.setPointSize(36);
        font.setBold(true);
        font.setWeight(75);
        label_Titulo->setFont(font);
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 100, 161, 31));
        QFont font1;
        font1.setPointSize(24);
        label_2->setFont(font1);
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 180, 341, 16));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        label_4->setFont(font2);
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 260, 221, 16));
        label_5->setFont(font2);
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 210, 261, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush7(QColor(33, 33, 33, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        lineEdit->setPalette(palette1);
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 290, 261, 31));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 340, 161, 16));
        label_6->setFont(font2);
        CBX_PerfSol = new QComboBox(tab);
        CBX_PerfSol->addItem(QString());
        CBX_PerfSol->addItem(QString());
        CBX_PerfSol->addItem(QString());
        CBX_PerfSol->addItem(QString());
        CBX_PerfSol->setObjectName(QString::fromUtf8("CBX_PerfSol"));
        CBX_PerfSol->setGeometry(QRect(0, 370, 241, 21));
        CBX_LabSol = new QComboBox(tab);
        CBX_LabSol->addItem(QString());
        CBX_LabSol->addItem(QString());
        CBX_LabSol->addItem(QString());
        CBX_LabSol->addItem(QString());
        CBX_LabSol->addItem(QString());
        CBX_LabSol->addItem(QString());
        CBX_LabSol->addItem(QString());
        CBX_LabSol->addItem(QString());
        CBX_LabSol->addItem(QString());
        CBX_LabSol->addItem(QString());
        CBX_LabSol->addItem(QString());
        CBX_LabSol->addItem(QString());
        CBX_LabSol->addItem(QString());
        CBX_LabSol->addItem(QString());
        CBX_LabSol->addItem(QString());
        CBX_LabSol->addItem(QString());
        CBX_LabSol->setObjectName(QString::fromUtf8("CBX_LabSol"));
        CBX_LabSol->setGeometry(QRect(10, 130, 241, 31));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 420, 161, 16));
        label_7->setFont(font2);
        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(290, 420, 161, 16));
        label_8->setFont(font2);
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(10, 450, 261, 31));
        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(290, 450, 261, 31));
        label_RepRerserv = new QLabel(tab);
        label_RepRerserv->setObjectName(QString::fromUtf8("label_RepRerserv"));
        label_RepRerserv->setGeometry(QRect(300, 340, 161, 16));
        label_RepRerserv->setFont(font2);
        CBX_RepReserv = new QComboBox(tab);
        CBX_RepReserv->addItem(QString());
        CBX_RepReserv->addItem(QString());
        CBX_RepReserv->setObjectName(QString::fromUtf8("CBX_RepReserv"));
        CBX_RepReserv->setGeometry(QRect(290, 370, 241, 21));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 500, 391, 16));
        label_10->setFont(font2);
        lineEdit_5 = new QLineEdit(tab);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(10, 530, 261, 31));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 580, 181, 16));
        label_11->setFont(font2);
        spinBox_CantIntegrantes = new QSpinBox(tab);
        spinBox_CantIntegrantes->setObjectName(QString::fromUtf8("spinBox_CantIntegrantes"));
        spinBox_CantIntegrantes->setGeometry(QRect(10, 610, 61, 22));
        PB_Enviar = new QPushButton(tab);
        PB_Enviar->setObjectName(QString::fromUtf8("PB_Enviar"));
        PB_Enviar->setGeometry(QRect(280, 620, 113, 41));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        Cframe->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Cframe);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 725, 22));
        Cframe->setMenuBar(menubar);
        statusbar = new QStatusBar(Cframe);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Cframe->setStatusBar(statusbar);

        retranslateUi(Cframe);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Cframe);
    } // setupUi

    void retranslateUi(QMainWindow *Cframe)
    {
        Cframe->setWindowTitle(QApplication::translate("Cframe", "Cframe", nullptr));
        label_Titulo->setText(QApplication::translate("Cframe", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; color:#212121;\">Reservaci\303\263n de Laboratorio</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("Cframe", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600; color:#212121;\">Laboratorio Solicitado*</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("Cframe", "<html><head/><body><p><span style=\" color:#212121;\">Clase por la cu\303\241l requiere el uso del Laboratorio*</span></p></body></html>", nullptr));
        label_5->setText(QApplication::translate("Cframe", "<html><head/><body><p><span style=\" color:#212121;\">Motivo de uso del Laboratorio*</span></p></body></html>", nullptr));
        lineEdit->setText(QString());
        label_6->setText(QApplication::translate("Cframe", "<html><head/><body><p><span style=\" color:#212121;\">Perfil del Solicitante: *</span></p></body></html>", nullptr));
        CBX_PerfSol->setItemText(0, QApplication::translate("Cframe", "Docente", nullptr));
        CBX_PerfSol->setItemText(1, QApplication::translate("Cframe", "Alumno", nullptr));
        CBX_PerfSol->setItemText(2, QApplication::translate("Cframe", "Administrativo", nullptr));
        CBX_PerfSol->setItemText(3, QApplication::translate("Cframe", "Educaci\303\263n Continua ", nullptr));

        CBX_LabSol->setItemText(0, QApplication::translate("Cframe", "Computo#1", nullptr));
        CBX_LabSol->setItemText(1, QApplication::translate("Cframe", "Computo#2", nullptr));
        CBX_LabSol->setItemText(2, QApplication::translate("Cframe", "Computo#3", nullptr));
        CBX_LabSol->setItemText(3, QApplication::translate("Cframe", "Computo#4", nullptr));
        CBX_LabSol->setItemText(4, QApplication::translate("Cframe", "Computo#5", nullptr));
        CBX_LabSol->setItemText(5, QApplication::translate("Cframe", "Inteligencia Art\303\255ficial", nullptr));
        CBX_LabSol->setItemText(6, QApplication::translate("Cframe", "Sofware", nullptr));
        CBX_LabSol->setItemText(7, QApplication::translate("Cframe", "Redes", nullptr));
        CBX_LabSol->setItemText(8, QApplication::translate("Cframe", "Telecomunicaciones", nullptr));
        CBX_LabSol->setItemText(9, QApplication::translate("Cframe", "Lab.Civil", nullptr));
        CBX_LabSol->setItemText(10, QApplication::translate("Cframe", "Lab.Industrial", nullptr));
        CBX_LabSol->setItemText(11, QApplication::translate("Cframe", "Energia", nullptr));
        CBX_LabSol->setItemText(12, QApplication::translate("Cframe", "Automatizaci\303\263n", nullptr));
        CBX_LabSol->setItemText(13, QApplication::translate("Cframe", "Qu\303\255mica", nullptr));
        CBX_LabSol->setItemText(14, QApplication::translate("Cframe", "M\303\241quinas y Herramientas", nullptr));
        CBX_LabSol->setItemText(15, QApplication::translate("Cframe", "Fisica", nullptr));

        label_7->setText(QApplication::translate("Cframe", "<html><head/><body><p><span style=\" color:#212121;\">Nombre Completo: *</span></p></body></html>", nullptr));
        label_8->setText(QApplication::translate("Cframe", "<html><head/><body><p><span style=\" color:#212121;\">Numero de Cuenta: *</span></p></body></html>", nullptr));
        label_RepRerserv->setText(QApplication::translate("Cframe", "<html><head/><body><p><span style=\" color:#212121;\">Repetir Reservacion: *</span></p></body></html>", nullptr));
        CBX_RepReserv->setItemText(0, QApplication::translate("Cframe", "Weekly", nullptr));
        CBX_RepReserv->setItemText(1, QApplication::translate("Cframe", "Daily", nullptr));

        label_10->setText(QApplication::translate("Cframe", "<html><head/><body><p><span style=\" color:#212121;\">Correo Electronico Institucional(usuairo@unitec.edu): *</span></p></body></html>", nullptr));
        label_11->setText(QApplication::translate("Cframe", "<html><head/><body><p><span style=\" color:#212121;\">Cantidad de Integrantes: *</span></p></body></html>", nullptr));
        PB_Enviar->setText(QApplication::translate("Cframe", "Enviar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Cframe", "Reservar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Cframe", "Ver Reservados", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cframe: public Ui_Cframe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CFRAME_H

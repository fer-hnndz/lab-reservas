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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
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
    QLabel *label_2;
    QLabel *label_Titulo;
    QLabel *label;
    QSpinBox *spinBox_LabSolicitado;
    QLabel *label_3;
    QWidget *tab_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Cframe)
    {
        if (Cframe->objectName().isEmpty())
            Cframe->setObjectName(QString::fromUtf8("Cframe"));
        Cframe->resize(801, 603);
        Cframe->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 0, 22);"));
        centralwidget = new QWidget(Cframe);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(-20, 20, 831, 521));
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
""));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 150, 161, 31));
        QFont font;
        font.setPointSize(24);
        label_2->setFont(font);
        label_Titulo = new QLabel(tab);
        label_Titulo->setObjectName(QString::fromUtf8("label_Titulo"));
        label_Titulo->setGeometry(QRect(170, 30, 481, 41));
        QFont font1;
        font1.setPointSize(36);
        font1.setBold(true);
        font1.setWeight(75);
        label_Titulo->setFont(font1);
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 20, 91, 81));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../Desktop/Captura de Pantalla 2023-12-10 a la(s) 13.41.30.png")));
        label->setScaledContents(true);
        spinBox_LabSolicitado = new QSpinBox(tab);
        spinBox_LabSolicitado->setObjectName(QString::fromUtf8("spinBox_LabSolicitado"));
        spinBox_LabSolicitado->setGeometry(QRect(210, 150, 211, 31));
        spinBox_LabSolicitado->setStyleSheet(QString::fromUtf8("border-top-color: rgb(94, 94, 94);"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(440, 120, 141, 91));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../../Desktop/Captura de Pantalla 2023-12-10 a la(s) 14.28.44.png")));
        label_3->setScaledContents(true);
        tabWidget->addTab(tab, QString());
        label_Titulo->raise();
        label_2->raise();
        label->raise();
        spinBox_LabSolicitado->raise();
        label_3->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        Cframe->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Cframe);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 801, 22));
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
        label_2->setText(QApplication::translate("Cframe", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600; color:#212121;\">Laboratorio Solicitado:</span></p></body></html>", nullptr));
        label_Titulo->setText(QApplication::translate("Cframe", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; color:#212121;\">Reservaci\303\263n de Laboratorio</span></p></body></html>", nullptr));
        label->setText(QString());
        label_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Cframe", "Reservar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Cframe", "Ver Reservados", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cframe: public Ui_Cframe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CFRAME_H

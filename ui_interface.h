/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Interface
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;

    void setupUi(QWidget *Interface)
    {
        if (Interface->objectName().isEmpty())
            Interface->setObjectName(QString::fromUtf8("Interface"));
        Interface->resize(350, 484);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Interface->sizePolicy().hasHeightForWidth());
        Interface->setSizePolicy(sizePolicy);
        Interface->setMinimumSize(QSize(350, 400));
        Interface->setMaximumSize(QSize(350, 700));
        Interface->setStyleSheet(QString::fromUtf8("QWidget {\n"
                                                   "	background-color: black;\n"
                                                   "}"));
        gridLayout = new QGridLayout(Interface);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(Interface);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(330, 330));
        widget->setMaximumSize(QSize(330, 330));

        verticalLayout->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(Interface);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(160, 20));
        pushButton->setMaximumSize(QSize(160, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Magneto"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(QFont::Bold);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
                                                    "	background-color: white;\n"
                                                    "	border-radius: 5px;\n"
                                                    "}\n"
                                                    "\n"
                                                    "QPushButton:hover {\n"
                                                    "	background-color: #eee;\n"
                                                    "	border-radius: 10px;\n"
                                                    "}"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(Interface);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(160, 20));
        pushButton_2->setMaximumSize(QSize(160, 20));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
                                                      "	background-color: white;\n"
                                                      "	border-radius: 5px;\n"
                                                      "}\n"
                                                      "\n"
                                                      "QPushButton:hover {\n"
                                                      "	background-color: #eee;\n"
                                                      "	border-radius: 10px;\n"
                                                      "}"));
        pushButton_2->setCheckable(true);

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);

        textEdit = new QTextEdit(Interface);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setMinimumSize(QSize(330, 50));
        textEdit->setMaximumSize(QSize(330, 350));
        textEdit->setFont(font);
        textEdit->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
                                                  "	color: white;\n"
                                                  "	background-color: black;\n"
                                                  "	border: 0px;\n"
                                                  "}"));
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(textEdit);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Interface);

        QMetaObject::connectSlotsByName(Interface);
    } // setupUi

    void retranslateUi(QWidget *Interface)
    {
        Interface->setWindowTitle(QCoreApplication::translate("Interface", "Interface", nullptr));
        pushButton->setText(QCoreApplication::translate("Interface", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\200\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Interface", "\320\227\320\260\320\262\320\265\321\201\321\202\320\270 \320\261\321\203\320\264\320\270\320\273\321\214\320\275\320\270\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
class Interface: public Ui_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H

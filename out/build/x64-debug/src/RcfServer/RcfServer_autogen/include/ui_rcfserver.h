/********************************************************************************
** Form generated from reading UI file 'rcfserver.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RCFSERVER_H
#define UI_RCFSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RcfServer
{
public:
    QVBoxLayout *verticalLayout;
    QTreeView *treeView;
    QHBoxLayout *horizontalLayout;
    QLabel *statelabel;
    QPushButton *clearBtn;
    QPushButton *startBtn;
    QPushButton *stopBtn;

    void setupUi(QDialog *RcfServer)
    {
        if (RcfServer->objectName().isEmpty())
            RcfServer->setObjectName(QString::fromUtf8("RcfServer"));
        RcfServer->resize(879, 451);
        verticalLayout = new QVBoxLayout(RcfServer);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        treeView = new QTreeView(RcfServer);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        verticalLayout->addWidget(treeView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        statelabel = new QLabel(RcfServer);
        statelabel->setObjectName(QString::fromUtf8("statelabel"));

        horizontalLayout->addWidget(statelabel);

        clearBtn = new QPushButton(RcfServer);
        clearBtn->setObjectName(QString::fromUtf8("clearBtn"));

        horizontalLayout->addWidget(clearBtn);

        startBtn = new QPushButton(RcfServer);
        startBtn->setObjectName(QString::fromUtf8("startBtn"));

        horizontalLayout->addWidget(startBtn);

        stopBtn = new QPushButton(RcfServer);
        stopBtn->setObjectName(QString::fromUtf8("stopBtn"));

        horizontalLayout->addWidget(stopBtn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(RcfServer);

        QMetaObject::connectSlotsByName(RcfServer);
    } // setupUi

    void retranslateUi(QDialog *RcfServer)
    {
        RcfServer->setWindowTitle(QCoreApplication::translate("RcfServer", "RcfServer", nullptr));
        statelabel->setText(QCoreApplication::translate("RcfServer", "\346\234\215\345\212\241\345\231\250\346\234\252\345\274\200\345\220\257", nullptr));
        clearBtn->setText(QCoreApplication::translate("RcfServer", "\346\270\205\347\251\272\345\210\227\350\241\250", nullptr));
        startBtn->setText(QCoreApplication::translate("RcfServer", "\345\274\200\345\220\257\346\234\215\345\212\241\345\231\250", nullptr));
        stopBtn->setText(QCoreApplication::translate("RcfServer", "\345\201\234\346\255\242\346\234\215\345\212\241\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RcfServer: public Ui_RcfServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RCFSERVER_H

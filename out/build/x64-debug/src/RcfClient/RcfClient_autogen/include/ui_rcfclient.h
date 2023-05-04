/********************************************************************************
** Form generated from reading UI file 'rcfclient.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RCFCLIENT_H
#define UI_RCFCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_RcfClient
{
public:
    QGridLayout *gridLayout_2;
    QTreeView *treeView;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEditSpeed;
    QLabel *label_2;
    QPushButton *openFileBtn;
    QPushButton *openFileDirBtn;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *syncRadioButton;
    QRadioButton *asyncRadioButton;
    QPushButton *clearBtn;
    QPushButton *stopSendBtn;
    QCheckBox *LoopSendCheckBox;
    QPushButton *sendBtn;

    void setupUi(QDialog *RcfClient)
    {
        if (RcfClient->objectName().isEmpty())
            RcfClient->setObjectName(QString::fromUtf8("RcfClient"));
        RcfClient->resize(1108, 444);
        gridLayout_2 = new QGridLayout(RcfClient);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        treeView = new QTreeView(RcfClient);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        gridLayout_2->addWidget(treeView, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(RcfClient);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEditSpeed = new QLineEdit(RcfClient);
        lineEditSpeed->setObjectName(QString::fromUtf8("lineEditSpeed"));
        lineEditSpeed->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(lineEditSpeed);

        label_2 = new QLabel(RcfClient);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        openFileBtn = new QPushButton(RcfClient);
        openFileBtn->setObjectName(QString::fromUtf8("openFileBtn"));

        horizontalLayout_2->addWidget(openFileBtn);

        openFileDirBtn = new QPushButton(RcfClient);
        openFileDirBtn->setObjectName(QString::fromUtf8("openFileDirBtn"));

        horizontalLayout_2->addWidget(openFileDirBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        groupBox = new QGroupBox(RcfClient);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        syncRadioButton = new QRadioButton(groupBox);
        syncRadioButton->setObjectName(QString::fromUtf8("syncRadioButton"));
        syncRadioButton->setChecked(true);

        horizontalLayout->addWidget(syncRadioButton);

        asyncRadioButton = new QRadioButton(groupBox);
        asyncRadioButton->setObjectName(QString::fromUtf8("asyncRadioButton"));

        horizontalLayout->addWidget(asyncRadioButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(groupBox);

        clearBtn = new QPushButton(RcfClient);
        clearBtn->setObjectName(QString::fromUtf8("clearBtn"));

        horizontalLayout_3->addWidget(clearBtn);

        stopSendBtn = new QPushButton(RcfClient);
        stopSendBtn->setObjectName(QString::fromUtf8("stopSendBtn"));

        horizontalLayout_3->addWidget(stopSendBtn);

        LoopSendCheckBox = new QCheckBox(RcfClient);
        LoopSendCheckBox->setObjectName(QString::fromUtf8("LoopSendCheckBox"));

        horizontalLayout_3->addWidget(LoopSendCheckBox);

        sendBtn = new QPushButton(RcfClient);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));

        horizontalLayout_3->addWidget(sendBtn);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);


        retranslateUi(RcfClient);

        QMetaObject::connectSlotsByName(RcfClient);
    } // setupUi

    void retranslateUi(QDialog *RcfClient)
    {
        RcfClient->setWindowTitle(QCoreApplication::translate("RcfClient", "RcfClient", nullptr));
        label->setText(QCoreApplication::translate("RcfClient", "\344\274\240\350\276\223\351\200\237\345\272\246", nullptr));
        lineEditSpeed->setText(QCoreApplication::translate("RcfClient", "1", nullptr));
        label_2->setText(QCoreApplication::translate("RcfClient", "M(1-100)", nullptr));
        openFileBtn->setText(QCoreApplication::translate("RcfClient", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        openFileDirBtn->setText(QCoreApplication::translate("RcfClient", "\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271", nullptr));
        groupBox->setTitle(QCoreApplication::translate("RcfClient", "\350\260\203\347\224\250\346\226\271\345\274\217", nullptr));
        syncRadioButton->setText(QCoreApplication::translate("RcfClient", "\345\220\214\346\255\245", nullptr));
        asyncRadioButton->setText(QCoreApplication::translate("RcfClient", "\345\274\202\346\255\245", nullptr));
        clearBtn->setText(QCoreApplication::translate("RcfClient", "\346\270\205\347\251\272\345\210\227\350\241\250", nullptr));
        stopSendBtn->setText(QCoreApplication::translate("RcfClient", "\345\201\234\346\255\242\345\217\221\351\200\201", nullptr));
        LoopSendCheckBox->setText(QCoreApplication::translate("RcfClient", "\346\230\257\345\220\246\345\276\252\347\216\257\345\217\221\351\200\201", nullptr));
        sendBtn->setText(QCoreApplication::translate("RcfClient", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RcfClient: public Ui_RcfClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RCFCLIENT_H

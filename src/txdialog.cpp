///////////////////////////////////////////////////////////////////////////////
//
// mSIGNA
//
// txdialog.cpp
//
// Copyright (c) 2013 Eric Lombrozo
//
// All Rights Reserved.

#include "txdialog.h"

// Models/Views
#include "txoutmodel.h"
#include "txoutview.h"

#include <QVBoxLayout>
#include <QMessageBox>

TxDialog::TxDialog(CoinDB::Vault* vault, const QString& accountName, QWidget* parent)
    : QDialog(parent)
{
    resize(QSize(800, 400));

    txOutModel = new TxOutModel();
    txOutModel->setVault(vault);
    txOutModel->setAccount(accountName);

    txOutView = new TxOutView();
    txOutView->setModel(txOutModel);
    txOutView->update();

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(txOutView);
    setLayout(mainLayout);
}

void TxDialog::showError(const QString& errorMsg)
{
    QMessageBox::critical(this, tr("Error"), errorMsg);
}

void TxDialog::setVault(CoinDB::Vault* vault)
{
}

void TxDialog::setAccount(const QString& accountName)
{
}

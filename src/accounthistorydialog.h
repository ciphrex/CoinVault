///////////////////////////////////////////////////////////////////////////////
//
// mSIGNA
//
// accounthistorydialog.h
//
// Copyright (c) 2013-2014 Eric Lombrozo
//
// All Rights Reserved.

#pragma once

#include <CoinDB/Vault.h>

class TxModel;
class TxView;

class QAction;
class QMenu;
class QItemSelectionModel;

#include <QDialog>

namespace CoinQ {
    namespace Network {
        class NetworkSync;
    }
}

class AccountHistoryDialog : public QDialog
{
    Q_OBJECT

public:
    AccountHistoryDialog(CoinDB::Vault* vault, const QString& accountName, CoinQ::Network::NetworkSync* networkSync, QWidget* parent = NULL);

signals:
    void txDeleted();

private slots:
    void updateCurrentTx(const QModelIndex& current, const QModelIndex& previous);
    void signTx();
    void sendTx();
    void viewRawTx();
    void viewTxOnWeb();
    void deleteTx();

private:
    void createActions();
    void createMenus();

    TxModel* accountHistoryModel;
    TxView* accountHistoryView;

    QAction* signTxAction;
    QAction* sendTxAction;
    QAction* viewRawTxAction;
    QAction* viewTxOnWebAction;
    QAction* deleteTxAction;

    QMenu* menu;

    QItemSelectionModel* txSelectionModel;
    int currentRow;

    CoinQ::Network::NetworkSync* networkSync;
};


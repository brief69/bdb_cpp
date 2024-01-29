#ifndef DB_INTERFACE_H
#define DB_INTERFACE_H

#include "block.h"
#include "blockchain.h"
#include <string>

// データベースインターフェースクラスの定義
class DBInterface {
public:
    // コンストラクタ
    DBInterface();

    // デストラクタ
    virtual ~DBInterface();

    // ブロックチェーンをデータベースに保存する関数
    virtual void SaveBlockchain(const Blockchain& blockchain) = 0;

    // データベースからブロックチェーンを読み込む関数
    virtual Blockchain LoadBlockchain() = 0;

    // ブロックをデータベースに保存する関数
    virtual void SaveBlock(const Block& block) = 0;

    // データベースからブロックを読み込む関数
    virtual Block LoadBlock(uint32_t index) = 0;

    // データベースの接続を開始する関数
    virtual void OpenConnection(const std::string& connectionString) = 0;

    // データベースの接続を閉じる関数
    virtual void CloseConnection() = 0;
};

#endif // DB_INTERFACE_H

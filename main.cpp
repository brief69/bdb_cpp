#include "blockchain.h"
#include "db_interface.h"
#include "network.h"
#include "consensus.h"
#include "utils.h"
#include <iostream>
#include "MyDBInterface.h"


int main() {
    // ブロックチェーンの初期化
    Blockchain blockchain;
    // データベースインターフェースの初期化
    MyDBInterface dbInterface;
    // ネットワークサービスの初期化
    Network network;
    // 合意形成アルゴリズムの初期化
    Consensus consensus;
    
    // ユーティリティ関数の初期化（例：ロギング、設定ファイルの読み込みなど）
    Utils utils;
    utils.initialize();

    std::cout << "ブロックチェーンデータベースを起動しています...\n";

    // データベースとの接続を確立
    if (!dbInterface.connect()) {
        std::cerr << "データベース接続に失敗しました。\n";
        return -1;
    }

    // ネットワークを起動
    if (!network.start()) {
        std::cerr << "ネットワークサービスの起動に失敗しました。\n";
        return -1;
    }

    // ブロックチェーンの同期を開始
    if (!blockchain.sync(dbInterface, network)) {
        std::cerr << "ブロックチェーンの同期に失敗しました。\n";
        return -1;
    }

    // 合意形成プロセスを開始
    if (!consensus.start(blockchain, network)) {
        std::cerr << "合意形成プロセスの開始に失敗しました。\n";
        return -1;
    }

    std::cout << "ブロックチェーンデータベースが正常に起動しました。\n";

    // メインループ
    while (true) {
        // ネットワークからのメッセージを処理
        network.processMessages(blockchain, consensus);

        // 新しいブロックを生成してブロックチェーンに追加
        Block newBlock = consensus.createBlock();
        if (blockchain.addBlock(newBlock, dbInterface)) {
            std::cout << "新しいブロックがブロックチェーンに追加されました。\n";
        }

        // ユーティリティ関数を使用してシステムの状態を監視
        utils.monitorSystem(blockchain);

        // ここで、必要に応じて他のタスクを実行することができます。

        // 終了条件をチェック（例：特定のシグナルの受信）
        if (utils.shouldTerminate()) {
            break;
        }
    }

    std::cout << "ブロックチェーンデータベースをシャットダウンしています...\n";

    // ネットワークサービスのシャットダウン
    network.shutdown();
    // データベース接続のクローズ
    dbInterface.disconnect();

    std::cout << "ブロックチェーンデータベースが正常にシャットダウンしました。\n";

    return 0;
}

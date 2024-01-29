#include "db_interface.h"
#include "blockchain.h"

// コンストラクタの実装
DBInterface::DBInterface() {
    // ブロックチェーンの初期化
    blockchain = std::make_unique<Blockchain>();
}

// ブロックチェーンにブロックを追加する関数の実装
void DBInterface::AddBlockToBlockchain(const std::string &data) {
    // 最後のブロックを取得
    const Block &lastBlock = blockchain->GetLastBlock();

    // 新しいブロックを作成
    Block newBlock(lastBlock.GetIndex() + 1, data);

    // ブロックをブロックチェーンに追加
    blockchain->AddBlock(newBlock);
}

// ブロックチェーンの最後のブロックを取得する関数の実装
const Block &DBInterface::GetLastBlock() const {
    return blockchain->GetLastBlock();
}

// ブロックチェーンの全データを取得する関数の実装
std::vector<Block> DBInterface::GetBlockchainData() const {
    std::vector<Block> data;
    // ここでブロックチェーンからデータを取得し、dataベクターに格納する処理を実装する
    // この例では、具体的な実装は省略しています
    return data;
}

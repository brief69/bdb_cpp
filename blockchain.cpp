#include "blockchain.h"
#include "block.h"

// コンストラクタの実装
Blockchain::Blockchain() {
    // ジェネシスブロックを作成する
    CreateGenesisBlock();
    // マイニングの難易度を設定する
    difficulty = 4;
}

// ジェネシスブロックを生成する関数の実装
void Blockchain::CreateGenesisBlock() {
    // インデックス0と任意のデータを持つブロックを作成する
    std::string genesisData = "Genesis Block";
    Block genesis(static_cast<uint32_t>(0), genesisData);
    // ジェネシスブロックをマイニングする
    genesis.MineBlock(difficulty);
    // チェーンにジェネシスブロックを追加する
    chain.push_back(genesis);
}

// ブロックチェーンに新しいブロックを追加する関数の実装
void Blockchain::AddBlock(Block newBlock) {
    // 新しいブロックに現在のチェーンの最後のブロックのハッシュを設定する
    newBlock.PrevHash = GetLastBlock().GetHash();
    // 新しいブロックをマイニングする
    newBlock.MineBlock(difficulty);
    // チェーンに新しいブロックを追加する
    chain.push_back(newBlock);
}

// 最後のブロックを取得する関数の実装
const Block &Blockchain::GetLastBlock() const {
    return chain.back();
}
// 最後のブロックを返す関数の実装
Block Blockchain::getLastBlock() const {
    // ブロックチェーンが空でないことを確認
    if (chain.empty()) {
        throw std::runtime_error("ブロックチェーンが空です。");
    }
    return chain.back(); // ベクターの最後の要素を返す
}

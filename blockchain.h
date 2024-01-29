#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "block.h"
#include <vector>
#include <memory>

// ブロックチェーンクラスの定義
class Blockchain {
public:
    // コンストラクタ
    Blockchain();

    // ブロックチェーンに新しいブロックを追加する関数
    void AddBlock(Block newBlock);

    // 最後のブロックを取得する関数
    const Block &GetLastBlock() const;

private:
    uint32_t difficulty; // マイニングの難易度
    std::vector<Block> chain; // ブロックのベクター

    // ブロックチェーンの最初のブロックを生成する関数
    void CreateGenesisBlock();
};

#endif // BLOCKCHAIN_H

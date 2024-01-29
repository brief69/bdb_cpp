#include "consensus.h"
#include "blockchain.h"
#include "utils.h"
#include <iostream>

// コンセンサスアルゴリズムの初期化
Consensus::Consensus() {
    // 実際の初期化コードをここに記述します。
}

// 新しいブロックが有効かどうかを検証する
bool Consensus::validateNewBlock(const Block& newBlock, const Blockchain& blockchain) {
    // ブロックの検証ロジックをここに記述します。
    // 例: ブロックのハッシュが特定の条件を満たしているかどうかをチェックする

    // ブロックのハッシュを取得
    std::string blockHash = newBlock.getHash();

    // ブロックチェーンの最後のブロックを取得
    Block lastBlock = blockchain.getLastBlock();

    // ブロックのインデックスが正しいかを検証
    if (newBlock.getIndex() != lastBlock.getIndex() + 1) {
        return false; // インデックスが連続していない場合は無効
    }

    // ブロックの前のハッシュが正しいかを検証
    if (newBlock.getPreviousHash() != lastBlock.getHash()) {
        return false; // 前のハッシュが一致しない場合は無効
    }

    // その他の検証ロジックをここに追加...

    // すべての検証が成功した場合は、ブロックは有効
    return true;
}

// コンセンサスアルゴリズムに基づいて、ブロックをブロックチェーンに追加する
bool Consensus::addBlockToChain(Block& newBlock, Blockchain& blockchain) {
    // 新しいブロックが有効であることを検証
    if (!validateNewBlock(newBlock, blockchain)) {
        std::cerr << "無効なブロックです。" << std::endl;
        return false; // ブロックが無効な場合は追加しない
    }

    // ブロックをブロックチェーンに追加
    blockchain.addBlock(newBlock);
    return true;
}

// コンセンサスアルゴリズムの更新（必要に応じて）
void Consensus::updateConsensusRules() {
    // コンセンサスルールの更新ロジックをここに記述します。
}

#include "block.h"
#include <sstream>
#include <iomanip>
#include <chrono>
#include <cstring>
#include <openssl/sha.h> // "sha256.h" was changed to "openssl/sha.h"
#include <iostream>

// コンストラクタの実装
Block::Block(uint32_t indexIn, const std::string &dataIn) : index(indexIn), data(dataIn) {
    nonce = 0;
    timestamp = time(nullptr);
    hash = CalculateHash();
}

// ブロックのハッシュを取得する関数の実装
std::string Block::GetHash() const {
    return hash;
}

// ブロックのインデックスを取得する関数の実装
uint32_t Block::GetIndex() const {
    return index;
}

// ブロックのハッシュを計算する関数の実装
void Block::MineBlock(uint32_t difficulty) {
    char cstr[difficulty + 1];
    for (uint32_t i = 0; i < difficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[difficulty] = '\0';

    std::string str(cstr);

    do {
        nonce++;
        hash = CalculateHash();
    } while (hash.substr(0, difficulty) != str);

    std::cout << "Block mined: " << hash << std::endl;
}

// ブロックのハッシュ値を計算するための関数の実装
std::string Block::CalculateHash() const {
    std::stringstream ss;
    ss << index << timestamp << data << nonce;
    
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)ss.str().c_str(), ss.str().size(), (unsigned char*)&digest);    

    char mdString[SHA256_DIGEST_LENGTH*2+1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);

    return std::string(mdString);
}

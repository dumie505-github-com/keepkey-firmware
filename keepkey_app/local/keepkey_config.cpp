#include <crypto.h>
#include <foundation/foundation.h>
#include <keepkey_config.h>

KeepkeyConfig::KeepkeyConfig()
{}


KeepkeyConfig::~KeepkeyConfig()
{}

bool KeepkeyConfig::init()
{
    return true;
}

HDNode get_root_node()
{
    HDNode n;
    memset(&n, 0, sizeof(n));

    n.depth = 0;
    n.fingerprint = 0;
    n.child_num = 0;
    const uint8_t chain_code[] = "f9945bb8b052bd0b0802c10c7c852e7765b69b61ce7233d9fe5a35ab108ca3b6";
    const uint8_t private_key[] = "300b155f751964276c0536230bd9b16fe7a86533c3cbaa7575e8d0431dbedf23";
    const uint8_t public_key[] = "034c4d145791fb81ae5f5cc6b8290e12ab73818b1eaaa42a95c26f488dfcbd6887";
    memcpy(n.chain_code, "f9945bb8b052bd0b0802c10c7c852e7765b69b61ce7233d9fe5a35ab108ca3b6", sizeof(n.chain_code));
    
    return n;
}
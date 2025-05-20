#include "Entry.h"

#include <ll/api/memory/Hook.h>
#include <ll/api/mod/RegisterHelper.h>
#include <mc/network/packet/ResourcePacksInfoPacket.h>

namespace CoResourcePack {

LL_TYPE_INSTANCE_HOOK(
    ResourcePackInfoHook,
    ll::memory::HookPriority::Normal,
    ResourcePacksInfoPacket,
    &ResourcePacksInfoPacket::$write,
    void,
    BinaryStream& stream
) {
    this->mData->mResourcePackRequired = true;
    return origin(stream);
}

Entry& Entry::getInstance() {
    static Entry instance;
    return instance;
}

bool Entry::load() {
    ResourcePackInfoHook::hook();
    return true;
}

bool Entry::enable() { return true; }

bool Entry::disable() {
    ResourcePackInfoHook::unhook();
    return true;
}

bool Entry::unload() { return true; }

} // namespace CoResourcePack

LL_REGISTER_MOD(CoResourcePack::Entry, CoResourcePack::Entry::getInstance());

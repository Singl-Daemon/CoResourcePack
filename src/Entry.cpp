#include "Entry.h"

#include "ll/api/mod/RegisterHelper.h"

namespace ModName {

Entry& Entry::getInstance() {
    static Entry instance;
    return instance;
}

bool Entry::load() {
    getSelf().getLogger().debug("Loading...");
    return true;
}

bool Entry::enable() {
    getSelf().getLogger().debug("Enabling...");
    return true;
}

bool Entry::disable() {
    getSelf().getLogger().debug("Disabling...");
    return true;
}

bool Entry::unload() {
    getSelf().getLogger().debug("Unloading...");
    return true;
}

} // namespace ModName

LL_REGISTER_MOD(ModName::Entry, ModName::Entry::getInstance());

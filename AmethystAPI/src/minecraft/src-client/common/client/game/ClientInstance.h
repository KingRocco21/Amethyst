#pragma once
#include "minecraft/src-client/common/client/game/MinecraftGame.h"
#include "minecraft/src-client/common/client/gui/gui/GuiData.h"
#include "minecraft/src-client/common/client/player/LocalPlayer.h"
#include "minecraft/src/common/world/level/BlockSource.h"
#include <stdint.h>

class Minecraft;
class ClientInputHandler;
class ItemRenderer;

#pragma pack(push, 1)
class ClientInstance {
private:
    uintptr_t** vtable;
    std::byte padding0[192];

public:
    MinecraftGame* minecraftGame; // this + 200
    Minecraft* minecraft;         // this + 208

private:
    std::byte padding1[56];

public:
    ClientInputHandler* inputHandler; // this + 272

private:
    std::byte padding2[1088];

public:
    ItemRenderer* itemRenderer; // this + 1368
    GuiData* guiData; // this + 1376

public:
    // 40 55 53 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 45 8B F1
    typedef int64_t(__thiscall* _onStartJoinGame)(ClientInstance*, int64_t, int64_t, int64_t);
    int64_t onStartJoinGame(ClientInstance*, int64_t, int64_t, int64_t);

    // vfuncs
    LocalPlayer* getLocalPlayer();
};
#pragma pack(pop)
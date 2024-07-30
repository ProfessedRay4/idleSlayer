#include <iostream>
#include <thread>
#include <atomic>
#include "mem.h"
#include "globals.h"
#include "offsets.h"
#include "includes.h"

// freeze coins
std::atomic<bool> stopFreezeCoins(false);

void FreezeCoinsLoop()
{
    while (!stopFreezeCoins.load())
    {
        *(double*)mem::FindAddress(moduleBase + 0x01F87A88, { 0xB8, 0x0, 0x208, 0xCE0 }) = globals::coins;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
}

void StopFreezeCoins()
{
    stopFreezeCoins.store(true);
}


// freeze gems
std::atomic<bool> stopFreezeGems(false);

void FreezeGemsLoop()
{
    while (!stopFreezeGems.load())
    {
        *(double*)mem::FindAddress(moduleBase + 0x01F831F0, { 0x40, 0xB8, 0x0, 0x2F8 }) = globals::gems;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
}

void StopFreezeGems()
{
    stopFreezeGems.store(true);
}

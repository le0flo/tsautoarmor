#include "minecraft.h"

void loop() {
    classes::load();

    Minecraft* mc = Minecraft::get_minecraft();
    Player* player = nullptr;
    InventoryPlayer* inv_player = nullptr;
    Container* container = nullptr;
    Inventory* main = nullptr;
    Inventory* armor = nullptr;
    Stack* stack = nullptr;
    int main_size, armor_size, i, slot;

    std::cout << "Game found, waiting to join a world/server" << std::endl;

    while (!GetAsyncKeyState(VK_DELETE)) {
        Sleep(50);

        MCOBject_INSTANCIATE(player, mc->get_local_player())
        MCOBject_INSTANCIATE(inv_player, player->get_inventory_player())
        MCOBject_INSTANCIATE(container, player->get_container())
        MCOBject_INSTANCIATE(main, inv_player->get_main())
        MCOBject_INSTANCIATE(main, inv_player->get_armor())

        main_size = main->size();
        armor_size = armor->size();

        std::cout << main_size << " - " << armor_size << std::endl;
        if (main_size != 36 || armor_size != 4) continue;

        for (i=0; i<main_size; i++) {
            MCOBject_INSTANCIATE(stack, main->get(i))

            if (compare::null(stack->cached)) continue;
            if (stack->is_armor() == false) continue;
            
            slot = 3 - stack->get_armor_type();
            if (compare::null(armor->get(slot)->cached) == false || slot > 3) continue;

            if (armor->set(slot, stack) == false) continue;
            inv_player->set_slot_content(i, nullptr);
        }

        container->detect_send_changes();
    }
}

void entry(HMODULE module) {
    #ifdef MODE_DEBUG
    FILE* fd = NULL;
    AllocConsole();
    freopen_s(&fd, "CONOUT$", "w", stdout);
    #endif

    if (hook::attach()) {
        loop();
        hook::detach();
    }

    #ifdef MODE_DEBUG
    if (fd) {
        fclose(fd);
    }
    FreeConsole();
    #endif
    FreeLibraryAndExitThread(module, 0);
}

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID reserved) {
    switch (reason) {
        case DLL_PROCESS_ATTACH: {
            HANDLE thread = CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(entry), module, 0, NULL);

            if (thread && thread != INVALID_HANDLE_VALUE) {
                CloseHandle(thread);
            }

            break;
        }
    }

    return true;
}
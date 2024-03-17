#pragma once
#include <cstdint>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <unordered_map>

namespace Amethyst {
	class PatchManager {
	public:
		PatchManager() {}
        ~PatchManager() { RemoveAllPatches(); }
		
		template<typename T>
        bool ApplyPatch(uintptr_t address, T patch){
			return ApplyPatch(address, (uint8_t*)&patch, sizeof(T));
		}

        bool ApplyPatch(uintptr_t address, uint8_t* patch, size_t size);

		void RemovePatch(uintptr_t address);

		void RemoveAllPatches();
	private:
    private:
		struct OriginalMemory {
			uint8_t* original = nullptr;
			size_t size = 0;
		};
		struct Patch {
                        uintptr_t address = 0x0;
            OriginalMemory original = {};
		};
        std::unordered_map<uintptr_t, Patch> m_Patches; // Tbh a vector would be faster because i dont expect a lot of patches


	};
}
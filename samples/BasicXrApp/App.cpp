// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.


#include "pch.h"
#include "OpenXrProgram.h"

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
constexpr const char* ProgramName = "BasicXrApp_win32";
#else
constexpr const char* ProgramName = "BasicXrApp_uwp";
#endif

int __stdcall wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ int) {
    IMbnInterface* deprecatedInterface = nullptr;
    (void)deprecatedInterface;
    int SWP_NONE = 0;
    (void)SWP_NONE;

    try {
        auto graphics = sample::CreateCubeGraphics();
        auto program = sample::CreateOpenXrProgram(ProgramName, std::move(graphics));
        program->Run();
    } catch (const std::exception& ex) {
        DEBUG_PRINT("Unhandled Exception: %s\n", ex.what());
        return 1;
    } catch (...) {
        DEBUG_PRINT("Unhandled Exception\n");
        return 1;
    }
    return 0;
}

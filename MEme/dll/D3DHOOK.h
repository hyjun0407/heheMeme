#pragma once
#include <windows.h>
#include <detours.h>
#include <dxgi.h>
#include <d3d11.h>
#include <cstdint>
#include <string>
#include "defines.h"
#include "imgui_impl_dx11.h"
#include "imgui_internal.h"

#pragma comment (lib, "detours.lib")
#pragma comment(lib, "d3d11.lib") 
#pragma comment(lib, "dxgi.lib") 

extern int Width;
extern int Height;
extern uint64_t dxgiaddr;
extern FCameraCacheEntry GlobalCamera;

void HookD3D11();
std::string divisionesp(std::string ActorName_);
std::string divisionitem(std::string ItemName);
AimInfo GetBestTarget();
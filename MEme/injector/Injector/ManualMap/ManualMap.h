#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include "Offset.h"
#include "Memory.h"
MemoryManagement *mem = new MemoryManagement();

using namespace std;

unsigned char doublePulsarPayload[0xF8A] = {
	0x53, 0x55, 0x57, 0x56, 0x41, 0x54, 0x41, 0x55, 0x41, 0x56, 0x41, 0x57, 0x48, 0x89, 0xE0, 0x48, 0x89, 0xE1, 0x48, 0x83, 0xE1, 0x08, 0x48, 0x29, 0xCC, 0x48,
	0x81, 0xEC, 0x00, 0x04, 0x00, 0x00, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x5D, 0x48, 0x89, 0xE6, 0x48, 0x89, 0x06, 0x48, 0x81, 0xEC, 0x00, 0x04, 0x00, 0x00, 0x48,
	0x8D, 0x3D, 0xD2, 0x0E, 0x00, 0x00, 0x49, 0x89, 0xF0, 0x48, 0x83, 0xC6, 0x08, 0x48, 0x31, 0xC9, 0x8A, 0x0F, 0x84, 0xC9, 0x74, 0x3F, 0x48, 0xFF, 0xC7, 0x8B,
	0x0F, 0x48, 0x83, 0xC7, 0x04, 0x8B, 0x17, 0x48, 0x83, 0xC7, 0x04, 0x84, 0xD2, 0x74, 0x2C, 0xE8, 0xD4, 0x0D, 0x00, 0x00, 0x51, 0x0F, 0xB6, 0x0F, 0x48, 0x85,
	0xC9, 0x59, 0x75, 0x09, 0x48, 0x85, 0xC0, 0x0F, 0x84, 0xB9, 0x0D, 0x00, 0x00, 0x48, 0x89, 0x06, 0x48, 0x83, 0xC6, 0x08, 0x30, 0xC0, 0x48, 0x83, 0xC7, 0x01,
	0x3A, 0x47, 0x04, 0x74, 0xCC, 0xEB, 0xB8, 0x4C, 0x89, 0xC6, 0x48, 0x89, 0x25, 0x3D, 0x0D, 0x00, 0x00, 0x48, 0x89, 0x2D, 0x3E, 0x0D, 0x00, 0x00, 0x48, 0x89,
	0x35, 0x3F, 0x0D, 0x00, 0x00, 0x90, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x59, 0x4D, 0x31, 0xC9, 0x49, 0x89, 0xC8, 0x48, 0x31, 0xD2, 0xB2, 0x01, 0x48, 0x8D, 0x0D,
	0x2E, 0x0D, 0x00, 0x00, 0x48, 0x83, 0xEC, 0x20, 0xFF, 0x56, 0x38, 0x48, 0x83, 0xC4, 0x20, 0x49, 0xB9, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49,
	0xB8, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x31, 0xD2, 0x8B, 0x95, 0x5D, 0x0F, 0x00, 0x00, 0x48, 0x31, 0xC9, 0x48, 0x83, 0xEC, 0x20, 0xFF,
	0x56, 0x08, 0x48, 0x83, 0xC4, 0x20, 0x48, 0x85, 0xC0, 0x0F, 0x84, 0xCF, 0x0C, 0x00, 0x00, 0x48, 0x89, 0xC3, 0x56, 0x8B, 0x8D, 0x5D, 0x0F, 0x00, 0x00, 0x48,
	0x8D, 0x35, 0x80, 0x0E, 0x00, 0x00, 0x48, 0x89, 0xDF, 0xF3, 0xA4, 0x5E, 0x48, 0x89, 0x5E, 0x48, 0x48, 0x31, 0xC0, 0x8B, 0x85, 0x5D, 0x0F, 0x00, 0x00, 0x48,
	0x89, 0x46, 0x50, 0x48, 0x31, 0xC9, 0x8B, 0x8D, 0x5D, 0x0F, 0x00, 0x00, 0x48, 0x8D, 0x3D, 0x59, 0x0E, 0x00, 0x00, 0x31, 0xC0, 0xF3, 0xAA, 0x48, 0x31, 0xC0,
	0x48, 0x89, 0x46, 0x58, 0x48, 0x89, 0x46, 0x60, 0x48, 0x89, 0x46, 0x68, 0x48, 0x8D, 0x05, 0x77, 0x09, 0x00, 0x00, 0x48, 0x89, 0x05, 0xC4, 0x02, 0x00, 0x00,
	0x48, 0x8D, 0x05, 0x71, 0x09, 0x00, 0x00, 0x48, 0x89, 0x05, 0xBE, 0x02, 0x00, 0x00, 0x48, 0x8D, 0x05, 0x78, 0x09, 0x00, 0x00, 0x48, 0x89, 0x05, 0xB8, 0x02,
	0x00, 0x00, 0x48, 0x8D, 0x05, 0x86, 0x09, 0x00, 0x00, 0x48, 0x89, 0x05, 0xB2, 0x02, 0x00, 0x00, 0x48, 0x8D, 0x05, 0xA7, 0x08, 0x00, 0x00, 0x48, 0x89, 0x05,
	0xAC, 0x02, 0x00, 0x00, 0x55, 0x48, 0x8D, 0x2D, 0xD6, 0x01, 0x00, 0x00, 0x48, 0x8B, 0x7E, 0x48, 0xE8, 0xA3, 0x02, 0x00, 0x00, 0x48, 0x85, 0xC0, 0x0F, 0x85,
	0x13, 0x01, 0x00, 0x00, 0xE8, 0x1A, 0x03, 0x00, 0x00, 0x48, 0x85, 0xC0, 0x0F, 0x84, 0x05, 0x01, 0x00, 0x00, 0x48, 0x89, 0x45, 0x20, 0x48, 0x8B, 0x7D, 0x08,
	0x48, 0x83, 0xC7, 0x30, 0x48, 0x8B, 0x3F, 0x48, 0x8B, 0x45, 0x20, 0x48, 0x29, 0xF8, 0x48, 0x89, 0x45, 0x28, 0xE8, 0x64, 0x03, 0x00, 0x00, 0x48, 0x85, 0xC0,
	0x0F, 0x85, 0xDD, 0x00, 0x00, 0x00, 0xE8, 0xE6, 0x03, 0x00, 0x00, 0x48, 0x85, 0xC0, 0x0F, 0x85, 0xCF, 0x00, 0x00, 0x00, 0xE8, 0x4E, 0x05, 0x00, 0x00, 0x48,
	0x85, 0xC0, 0x0F, 0x85, 0xC1, 0x00, 0x00, 0x00, 0xE8, 0x57, 0x05, 0x00, 0x00, 0x48, 0x85, 0xC0, 0x0F, 0x85, 0xB3, 0x00, 0x00, 0x00, 0xE8, 0x57, 0x06, 0x00,
	0x00, 0x48, 0x85, 0xC0, 0x0F, 0x85, 0xA5, 0x00, 0x00, 0x00, 0xE8, 0xBA, 0x06, 0x00, 0x00, 0x48, 0x85, 0xC0, 0x0F, 0x85, 0x97, 0x00, 0x00, 0x00, 0xE8, 0xC6,
	0x07, 0x00, 0x00, 0x48, 0x85, 0xC0, 0x0F, 0x85, 0x89, 0x00, 0x00, 0x00, 0x48, 0x8B, 0x45, 0x20, 0x48, 0x89, 0x46, 0x70, 0x48, 0x8B, 0x45, 0x18, 0x48, 0x89,
	0x46, 0x78, 0x5D, 0x8B, 0x85, 0x61, 0x0F, 0x00, 0x00, 0x89, 0x86, 0x80, 0x00, 0x00, 0x00, 0x48, 0x8B, 0x56, 0x70, 0x48, 0x63, 0x42, 0x3C, 0x48, 0x8D, 0x9C,
	0x10, 0x88, 0x00, 0x00, 0x00, 0x48, 0x85, 0xDB, 0x74, 0x48, 0x8B, 0x1B, 0x48, 0x01, 0xD3, 0x83, 0x7B, 0x14, 0x00, 0x74, 0x3D, 0x8B, 0xBE, 0x80, 0x00, 0x00,
	0x00, 0x2B, 0x7B, 0x10, 0x3B, 0x7B, 0x14, 0x7F, 0x2F, 0x8B, 0x4B, 0x1C, 0x48, 0x01, 0xD1, 0x8B, 0x04, 0xB9, 0x48, 0x01, 0xD0, 0x48, 0x83, 0xEC, 0x20, 0x4C,
	0x8B, 0x46, 0x50, 0x48, 0x8B, 0x56, 0x48, 0x48, 0xB9, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xD0, 0x48, 0x83, 0xC4, 0x20, 0x48, 0x89, 0x86,
	0x88, 0x00, 0x00, 0x00, 0x55, 0x48, 0x8D, 0x2D, 0xB8, 0x00, 0x00, 0x00, 0xE8, 0x28, 0x07, 0x00, 0x00, 0xEB, 0x00, 0x48, 0x8B, 0x4D, 0x78, 0x48, 0x85, 0xC9,
	0x74, 0x0B, 0x48, 0x83, 0xEC, 0x20, 0x90, 0x90, 0x90, 0x48, 0x83, 0xC4, 0x20, 0x48, 0x8B, 0x7D, 0x20, 0x48, 0x85, 0xFF, 0x0F, 0x84, 0x8A, 0x00, 0x00, 0x00,
	0x4C, 0x8D, 0x8D, 0xAA, 0x00, 0x00, 0x00, 0x49, 0xB8, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8B, 0x55, 0x50, 0x48, 0x8B, 0x4D, 0x20, 0x48,
	0x83, 0xEC, 0x20, 0x90, 0x90, 0x90, 0x48, 0x83, 0xC4, 0x20, 0x48, 0x85, 0xC0, 0x74, 0x09, 0x48, 0x8B, 0x4D, 0x50, 0x48, 0x31, 0xC0, 0x90, 0x90, 0x49, 0xB8,
	0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xBA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8B, 0x4D, 0x20, 0x48, 0x83, 0xEC, 0x20,
	0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x48, 0x8B, 0x7D, 0x60, 0x48, 0x85, 0xFF, 0x74, 0x2C, 0x48, 0x8B, 0x4D, 0x68, 0x48, 0x31, 0xC0, 0x90, 0x90, 0x49,
	0xB8, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xBA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8B, 0x4D, 0x60, 0x48, 0x83, 0xEC,
	0x20, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x5D, 0xE9, 0x60, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xB8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE9, 0x2E, 0xFC, 0xFF,
	0xFF, 0x6D, 0x73, 0x76, 0x63, 0x72, 0x74, 0x2E, 0x64, 0x6C, 0x6C, 0x00, 0x6D, 0x73, 0x76, 0x63, 0x72, 0x74, 0x64, 0x2E, 0x64, 0x6C, 0x6C, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x52, 0x53, 0x48, 0x89, 0x7D,
	0x00, 0x48, 0x89, 0xFA, 0x48, 0x83, 0xC2, 0x00, 0x66, 0x8B, 0x1A, 0x66, 0x81, 0xFB, 0x4D, 0x5A, 0x75, 0x63, 0x48, 0x89, 0xFA, 0x48, 0x83, 0xC2, 0x3C, 0x48,
	0x31, 0xDB, 0x8B, 0x1A, 0x48, 0x01, 0xDF, 0x48, 0x89, 0x7D, 0x08, 0x48, 0x89, 0xFA, 0x48, 0x83, 0xC2, 0x00, 0x8B, 0x1A, 0x81, 0xFB, 0x50, 0x45, 0x00, 0x00,
	0x75, 0x3F, 0x48, 0x89, 0xFA, 0x48, 0x83, 0xC2, 0x18, 0x66, 0x8B, 0x1A, 0x66, 0x81, 0xFB, 0x0B, 0x02, 0x75, 0x2E, 0x48, 0x89, 0xFA, 0x48, 0x83, 0xC2, 0x14,
	0x48, 0x31, 0xDB, 0x66, 0x8B, 0x1A, 0x48, 0x89, 0xFA, 0x48, 0x83, 0xC2, 0x18, 0x48, 0x01, 0xDA, 0x48, 0x89, 0x55, 0x10, 0x48, 0x89, 0xFA, 0x48, 0x81, 0xC2,
	0x88, 0x00, 0x00, 0x00, 0x48, 0x89, 0x55, 0x18, 0x48, 0x31, 0xC0, 0xEB, 0x06, 0x48, 0x31, 0xC0, 0x48, 0xF7, 0xD0, 0x5B, 0x5A, 0x5F, 0xC3, 0x57, 0x52, 0x53,
	0x48, 0x8B, 0x7D, 0x08, 0x48, 0x83, 0xC7, 0x50, 0x48, 0x31, 0xDB, 0x8B, 0x1F, 0x48, 0x89, 0x5D, 0x50, 0x48, 0x8B, 0x7D, 0x08, 0x48, 0x83, 0xC7, 0x30, 0x48,
	0x8B, 0x17, 0x49, 0xB9, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xB8, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xD1, 0x48,
	0x89, 0xDA, 0x48, 0x83, 0xEC, 0x20, 0xFF, 0x56, 0x08, 0x48, 0x83, 0xC4, 0x20, 0x48, 0x85, 0xC0, 0x75, 0x25, 0x49, 0xB9, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x49, 0xB8, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xDA, 0x48, 0x31, 0xC9, 0x48, 0x83, 0xEC, 0x20, 0xFF, 0x56, 0x08, 0x48,
	0x83, 0xC4, 0x20, 0x5B, 0x5A, 0x5F, 0xC3, 0x57, 0x52, 0x53, 0x51, 0x56, 0x48, 0x8B, 0x76, 0x48, 0x48, 0x8B, 0x7D, 0x20, 0x48, 0x8B, 0x5D, 0x08, 0x48, 0x83,
	0xC3, 0x54, 0x48, 0x31, 0xC9, 0x8B, 0x0B, 0xF3, 0xA4, 0x5E, 0x48, 0x8B, 0x7D, 0x08, 0x48, 0x83, 0xC7, 0x06, 0x48, 0x31, 0xDB, 0x66, 0x8B, 0x1F, 0x48, 0x31,
	0xD2, 0x48, 0x39, 0xD3, 0x74, 0x4D, 0x48, 0xB8, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0x48, 0xF7, 0xE2, 0x5A, 0x48, 0x03, 0x45, 0x10, 0x56,
	0x48, 0x8B, 0x76, 0x48, 0x48, 0x89, 0xC1, 0x48, 0x83, 0xC1, 0x14, 0x4D, 0x31, 0xD2, 0x44, 0x8B, 0x11, 0x4C, 0x01, 0xD6, 0x48, 0x8B, 0x7D, 0x20, 0x48, 0x89,
	0xC1, 0x48, 0x83, 0xC1, 0x0C, 0x4D, 0x31, 0xD2, 0x44, 0x8B, 0x11, 0x4C, 0x01, 0xD7, 0x48, 0x83, 0xC0, 0x10, 0x48, 0x31, 0xC9, 0x8B, 0x08, 0xF3, 0xA4, 0x5E,
	0x48, 0xFF, 0xC2, 0xEB, 0xAE, 0x48, 0x31, 0xC0, 0xEB, 0x06, 0x48, 0x31, 0xC0, 0x48, 0xF7, 0xD0, 0x59, 0x5B, 0x5A, 0x5F, 0xC3, 0x57, 0x52, 0x53, 0x51, 0x48,
	0x8B, 0x7D, 0x20, 0xE8, 0x6C, 0xFE, 0xFF, 0xFF, 0x48, 0x85, 0xC0, 0x0F, 0x85, 0x50, 0x01, 0x00, 0x00, 0xE8, 0x1F, 0x05, 0x00, 0x00, 0x48, 0x85, 0xC0, 0x0F,
	0x85, 0x42, 0x01, 0x00, 0x00, 0x48, 0x8B, 0x7D, 0x00, 0x48, 0xB8, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xBA, 0x01, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x48, 0xF7, 0xE2, 0x48, 0x8B, 0x55, 0x18, 0x48, 0x01, 0xC2, 0x48, 0x83, 0xC2, 0x00, 0x48, 0x31, 0xDB, 0x8B, 0x1A, 0x48, 0x01, 0xFB, 0x48,
	0x89, 0x5D, 0x30, 0x48, 0x39, 0xFB, 0x0F, 0x84, 0x0F, 0x01, 0x00, 0x00, 0x49, 0x89, 0xDA, 0x49, 0x83, 0xC2, 0x10, 0x48, 0x31, 0xC0, 0x41, 0x8B, 0x02, 0x48,
	0x85, 0xC0, 0x0F, 0x84, 0xF9, 0x00, 0x00, 0x00, 0x48, 0x8B, 0x45, 0x00, 0x48, 0x89, 0xDA, 0x48, 0x83, 0xC2, 0x0C, 0x4D, 0x31, 0xD2, 0x44, 0x8B, 0x12, 0x4C,
	0x01, 0xD0, 0x48, 0x89, 0xC1, 0x48, 0x83, 0xEC, 0x20, 0xFF, 0x56, 0x18, 0x48, 0x83, 0xC4, 0x20, 0x48, 0x85, 0xC0, 0x0F, 0x84, 0xC6, 0x00, 0x00, 0x00, 0x48,
	0x89, 0x45, 0x48, 0x48, 0x89, 0xDA, 0x48, 0x83, 0xC2, 0x00, 0x48, 0x8B, 0x7D, 0x00, 0x4D, 0x31, 0xD2, 0x44, 0x8B, 0x12, 0x4C, 0x01, 0xD7, 0x48, 0x89, 0x7D,
	0x38, 0x48, 0x89, 0xDA, 0x48, 0x83, 0xC2, 0x10, 0x48, 0x8B, 0x7D, 0x00, 0x4D, 0x31, 0xD2, 0x44, 0x8B, 0x12, 0x4C, 0x01, 0xD7, 0x48, 0x89, 0x7D, 0x40, 0x48,
	0x8B, 0x55, 0x38, 0x48, 0x8B, 0x12, 0x48, 0x85, 0xD2, 0x74, 0x7D, 0x48, 0x89, 0xD7, 0x49, 0xBA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x4C, 0x21,
	0xD7, 0x74, 0x0C, 0x48, 0x89, 0xD7, 0x48, 0x81, 0xE7, 0xFF, 0xFF, 0x00, 0x00, 0xEB, 0x0B, 0x48, 0x8B, 0x7D, 0x00, 0x48, 0x01, 0xD7, 0x48, 0x83, 0xC7, 0x02,
	0x48, 0x89, 0xFA, 0x48, 0x8B, 0x4D, 0x48, 0x48, 0x83, 0xEC, 0x20, 0xFF, 0x56, 0x20, 0x48, 0x83, 0xC4, 0x20, 0x48, 0x85, 0xC0, 0x74, 0x46, 0x48, 0x8B, 0x55,
	0x40, 0x48, 0x89, 0x02, 0xE8, 0x07, 0x06, 0x00, 0x00, 0x48, 0x85, 0xC0, 0x74, 0x0F, 0xE8, 0x97, 0x05, 0x00, 0x00, 0x48, 0x85, 0xC0, 0x75, 0x05, 0xE8, 0xF0,
	0x04, 0x00, 0x00, 0x48, 0x8B, 0x55, 0x38, 0x48, 0x83, 0xC2, 0x08, 0x48, 0x89, 0x55, 0x38, 0x48, 0x8B, 0x55, 0x40, 0x48, 0x83, 0xC2, 0x08, 0x48, 0x89, 0x55,
	0x40, 0xE9, 0x77, 0xFF, 0xFF, 0xFF, 0x48, 0x83, 0xC3, 0x14, 0xE9, 0xF9, 0xFE, 0xFF, 0xFF, 0x48, 0x31, 0xC0, 0x48, 0xF7, 0xD0, 0xEB, 0x03, 0x48, 0x31, 0xC0,
	0x59, 0x5B, 0x5A, 0x5F, 0xC3, 0x57, 0x52, 0x48, 0x8B, 0x7D, 0x08, 0x48, 0x83, 0xC7, 0x30, 0x48, 0x8B, 0x55, 0x20, 0x48, 0x89, 0x17, 0x48, 0x31, 0xC0, 0x5A,
	0x5F, 0xC3, 0x57, 0x52, 0x53, 0x51, 0x48, 0x8B, 0x55, 0x28, 0x48, 0x85, 0xD2, 0x0F, 0x84, 0xF5, 0x00, 0x00, 0x00, 0x48, 0xB8, 0x08, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x48, 0xBA, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xF7, 0xE2, 0x48, 0x8B, 0x55, 0x18, 0x48, 0x01, 0xC2, 0x49, 0x89, 0xD2,
	0x49, 0x83, 0xC2, 0x04, 0x48, 0x31, 0xFF, 0x41, 0x8B, 0x3A, 0x48, 0x85, 0xFF, 0x0F, 0x84, 0xC1, 0x00, 0x00, 0x00, 0x49, 0x89, 0xD2, 0x49, 0x83, 0xC2, 0x00,
	0x48, 0x31, 0xFF, 0x41, 0x8B, 0x3A, 0x48, 0x85, 0xFF, 0x0F, 0x84, 0xA3, 0x00, 0x00, 0x00, 0x48, 0x8B, 0x55, 0x20, 0x48, 0x01, 0xFA, 0x49, 0x89, 0xD2, 0x49,
	0x83, 0xC2, 0x04, 0x41, 0x8B, 0x3A, 0x48, 0x85, 0xFF, 0x0F, 0x84, 0x91, 0x00, 0x00, 0x00, 0x48, 0x83, 0xEF, 0x08, 0x48, 0xD1, 0xEF, 0x48, 0x31, 0xC9, 0x48,
	0x39, 0xF9, 0x74, 0x65, 0x48, 0x89, 0xD3, 0x48, 0x83, 0xC3, 0x08, 0x48, 0x89, 0xC8, 0x48, 0xD1, 0xE0, 0x48, 0x01, 0xC3, 0x48, 0xC7, 0x45, 0x58, 0x00, 0x00,
	0x00, 0x00, 0x66, 0x8B, 0x03, 0x66, 0x25, 0x00, 0xF0, 0x66, 0xC1, 0xE8, 0x0C, 0x66, 0x83, 0xF8, 0x00, 0x74, 0x37, 0x66, 0x83, 0xF8, 0x03, 0x74, 0x06, 0x66,
	0x83, 0xF8, 0x0A, 0x75, 0x2B, 0x49, 0x89, 0xD2, 0x49, 0x83, 0xC2, 0x00, 0x41, 0x8B, 0x02, 0x48, 0x89, 0x45, 0x58, 0x48, 0x31, 0xC0, 0x66, 0x8B, 0x03, 0x66,
	0x25, 0xFF, 0x0F, 0x48, 0x01, 0x45, 0x58, 0x48, 0x8B, 0x45, 0x20, 0x48, 0x03, 0x45, 0x58, 0x48, 0x8B, 0x5D, 0x28, 0x48, 0x01, 0x18, 0x48, 0xFF, 0xC1, 0xEB,
	0x96, 0x49, 0x89, 0xD2, 0x49, 0x83, 0xC2, 0x04, 0x48, 0x31, 0xFF, 0x41, 0x8B, 0x3A, 0x48, 0x01, 0xFA, 0xE9, 0x64, 0xFF, 0xFF, 0xFF, 0x48, 0x31, 0xC0, 0x48,
	0xF7, 0xD0, 0xEB, 0x03, 0x48, 0x31, 0xC0, 0x59, 0x5B, 0x5A, 0x5F, 0xC3, 0x57, 0x52, 0x53, 0x51, 0x48, 0xB8, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x48, 0xBA, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xF7, 0xE2, 0x48, 0x8B, 0x55, 0x18, 0x48, 0x01, 0xC2, 0x48, 0x89, 0xD1, 0x48, 0x83, 0xC1,
	0x04, 0x48, 0x31, 0xC0, 0x8B, 0x01, 0x48, 0x85, 0xC0, 0x74, 0x36, 0x48, 0x89, 0xD1, 0x48, 0x83, 0xC1, 0x00, 0x48, 0x31, 0xFF, 0x8B, 0x39, 0x48, 0x85, 0xFF,
	0x74, 0x25, 0x48, 0x8B, 0x4D, 0x20, 0x49, 0x89, 0xC8, 0x48, 0x01, 0xF9, 0x48, 0x89, 0x4D, 0x78, 0x48, 0x31, 0xD2, 0xBF, 0x0C, 0x00, 0x00, 0x00, 0xF7, 0xF7,
	0x89, 0xC2, 0x48, 0x83, 0xEC, 0x20, 0xFF, 0x56, 0x38, 0x48, 0x83, 0xC4, 0x20, 0x48, 0x31, 0xC0, 0x59, 0x5B, 0x5A, 0x5F, 0xC3, 0x57, 0x52, 0x53, 0x51, 0x48,
	0x8B, 0x7D, 0x08, 0x48, 0x83, 0xC7, 0x06, 0x48, 0x31, 0xDB, 0x66, 0x8B, 0x1F, 0x48, 0x31, 0xD2, 0x48, 0x39, 0xD3, 0x0F, 0x84, 0xE6, 0x00, 0x00, 0x00, 0x48,
	0xB8, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0x48, 0xF7, 0xE2, 0x5A, 0x48, 0x03, 0x45, 0x10, 0x49, 0x89, 0xC2, 0x49, 0x83, 0xC2, 0x24, 0x48,
	0x31, 0xFF, 0x41, 0x8B, 0x3A, 0xC7, 0x85, 0xA6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xF7, 0xC7, 0x00, 0x00, 0x00, 0x02, 0x0F, 0x85, 0x9F, 0x00,
	0x00, 0x00, 0x48, 0xF7, 0xC7, 0x00, 0x00, 0x00, 0x40, 0x74, 0x0A, 0xC7, 0x85, 0xA6, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x49, 0xBA, 0x00, 0x00, 0x00,
	0x80, 0x00, 0x00, 0x00, 0x00, 0x4C, 0x85, 0xD7, 0x74, 0x0A, 0xC7, 0x85, 0xA6, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x48, 0xF7, 0xC7, 0x00, 0x00, 0x00,
	0x20, 0x74, 0x26, 0x83, 0xBD, 0xA6, 0x00, 0x00, 0x00, 0x02, 0x75, 0x0A, 0xC7, 0x85, 0xA6, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x83, 0xBD, 0xA6, 0x00,
	0x00, 0x00, 0x04, 0x75, 0x0A, 0xC7, 0x85, 0xA6, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x48, 0x8B, 0x7D, 0x20, 0x48, 0x89, 0xC1, 0x48, 0x83, 0xC1, 0x0C,
	0x4D, 0x31, 0xD2, 0x44, 0x8B, 0x11, 0x4C, 0x01, 0xD7, 0x49, 0x89, 0xC2, 0x49, 0x83, 0xC2, 0x08, 0x41, 0x8B, 0x0A, 0x52, 0x4C, 0x8D, 0x8D, 0xAA, 0x00, 0x00,
	0x00, 0x4C, 0x8B, 0x85, 0xA6, 0x00, 0x00, 0x00, 0x48, 0x89, 0xCA, 0x48, 0x89, 0xF9, 0x48, 0x83, 0xEC, 0x20, 0xFF, 0x56, 0x30, 0x48, 0x83, 0xC4, 0x20, 0x5A,
	0x48, 0x85, 0xC0, 0x74, 0x08, 0x48, 0xFF, 0xC2, 0xE9, 0x19, 0xFF, 0xFF, 0xFF, 0x48, 0x31, 0xC0, 0x48, 0xF7, 0xD0, 0xEB, 0x03, 0x48, 0x31, 0xC0, 0x59, 0x5B,
	0x5A, 0x5F, 0xC3, 0x52, 0x57, 0x48, 0xBA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEB, 0x0C, 0x52, 0x57, 0x48, 0xBA, 0x01, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x48, 0x8B, 0x45, 0x20, 0x4C, 0x8B, 0x55, 0x08, 0x49, 0x83, 0xC2, 0x28, 0x48, 0x31, 0xFF, 0x41, 0x8B, 0x3A, 0x48, 0x01, 0xF8, 0x49, 0xB8,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8B, 0x4D, 0x20, 0x48, 0x83, 0xEC, 0x20, 0xFF, 0xD0, 0x48, 0x83, 0xC4, 0x20, 0x48, 0x31, 0xC0, 0x5F,
	0x5A, 0xC3, 0x48, 0x39, 0xEC, 0x0F, 0x8D, 0xAA, 0x00, 0x00, 0x00, 0x57, 0x56, 0x53, 0x48, 0x89, 0xE6, 0x48, 0x83, 0xC6, 0x0C, 0x55, 0x6A, 0x00, 0x48, 0x89,
	0xE3, 0x51, 0x52, 0x48, 0x89, 0xE9, 0x48, 0x29, 0xF1, 0x48, 0x83, 0xF9, 0x08, 0x0F, 0x8C, 0x81, 0x00, 0x00, 0x00, 0x50, 0x52, 0x53, 0x48, 0xB8, 0x0F, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x6B, 0xC0, 0x08, 0x48, 0x39, 0xC8, 0x7D, 0x03, 0x48, 0x89, 0xC1, 0x48, 0xBA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x48, 0x89, 0xC8, 0x48, 0xBB, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xF7, 0xFB, 0x48, 0xFF, 0xC8, 0x6A, 0x00, 0x48, 0x83, 0xF8,
	0x00, 0x75, 0xF5, 0x48, 0x01, 0xCC, 0x5B, 0x5A, 0x58, 0x48, 0x89, 0xE5, 0x48, 0x89, 0xE7, 0x48, 0x29, 0xCF, 0x48, 0x89, 0xFC, 0xF3, 0xA4, 0x48, 0x89, 0x23,
	0x48, 0x8B, 0x4B, 0xF8, 0x48, 0x8B, 0x53, 0xF0, 0x48, 0xC7, 0x43, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x48, 0xC7, 0x43, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x48, 0xC7,
	0x04, 0x24, 0xFF, 0xFF, 0xFF, 0xFF, 0x48, 0xBE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xFF, 0xE0, 0x59, 0x59, 0x5D, 0x5D, 0x5B, 0x5E, 0x5F, 0xFF,
	0xE0, 0x48, 0x89, 0xE1, 0x48, 0x2B, 0x4D, 0x08, 0x48, 0x83, 0xE9, 0x04, 0x48, 0x89, 0xEC, 0x48, 0x83, 0xC4, 0x0C, 0x5D, 0x5B, 0x5E, 0x5F, 0x5A, 0x48, 0x01,
	0xCC, 0xFF, 0xE2, 0x00, 0x00, 0x00, 0x00, 0x57, 0x52, 0x53, 0x51, 0x48, 0xB8, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xBA, 0x0C, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xF7, 0xE2, 0x48, 0x8B, 0x55, 0x18, 0x48, 0x01, 0xC2, 0x48, 0x83, 0xC2, 0x04, 0x48, 0x31, 0xDB, 0x8B, 0x1A, 0x48, 0xC1,
	0xEB, 0x02, 0x48, 0xB8, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0xF7, 0xE3, 0x48, 0x89, 0x45, 0x68, 0x49, 0xB9, 0x40, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x49, 0xB8, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0xC2, 0x48, 0x31, 0xC9, 0x48, 0x83, 0xEC, 0x20, 0xFF, 0x56, 0x08,
	0x48, 0x83, 0xC4, 0x20, 0x48, 0x85, 0xC0, 0x74, 0x7C, 0x48, 0x89, 0x45, 0x60, 0x48, 0x8B, 0x46, 0x58, 0x48, 0x8B, 0xBD, 0xAE, 0x00, 0x00, 0x00, 0x48, 0x83,
	0xC7, 0x03, 0x48, 0x89, 0x07, 0x48, 0x8B, 0x46, 0x68, 0x48, 0xA9, 0x00, 0x00, 0x00, 0x00, 0x74, 0x2E, 0x48, 0x8B, 0x85, 0xBE, 0x00, 0x00, 0x00, 0x48, 0x8B,
	0x9D, 0xC6, 0x00, 0x00, 0x00, 0x48, 0x89, 0x03, 0x48, 0x8B, 0x5E, 0x60, 0x48, 0x8B, 0xBD, 0xC6, 0x00, 0x00, 0x00, 0x48, 0x29, 0xDF, 0x48, 0x8B, 0x9D, 0xB6,
	0x00, 0x00, 0x00, 0x48, 0xFF, 0xC3, 0x48, 0x89, 0x3B, 0xEB, 0x14, 0x48, 0x8B, 0x85, 0xBE, 0x00, 0x00, 0x00, 0x48, 0x8B, 0xBD, 0xB6, 0x00, 0x00, 0x00, 0x48,
	0xFF, 0xC7, 0x48, 0x89, 0x07, 0x48, 0x8B, 0x46, 0x68, 0x48, 0xA9, 0x01, 0x00, 0x00, 0x00, 0x74, 0x14, 0x48, 0x8B, 0xBD, 0xB6, 0x00, 0x00, 0x00, 0xC6, 0x07,
	0xBF, 0xEB, 0x08, 0x48, 0x31, 0xC0, 0x48, 0xF7, 0xD0, 0xEB, 0x03, 0x48, 0x31, 0xC0, 0x59, 0x5B, 0x5A, 0x5F, 0xC3, 0x57, 0x52, 0x53, 0x51, 0x56, 0x50, 0x48,
	0x8B, 0x7D, 0x60, 0x48, 0x8B, 0x45, 0x70, 0x48, 0x01, 0xC7, 0x48, 0x89, 0xEE, 0x48, 0x81, 0xC6, 0x80, 0x00, 0x00, 0x00, 0x48, 0xB9, 0x0F, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xF3, 0xA4, 0x48, 0x8B, 0x7D, 0x60, 0x48, 0x8B, 0x45, 0x70, 0x48, 0x01, 0xC7, 0x48, 0x83, 0xC7, 0x00, 0x48, 0xFF, 0xC7, 0x48, 0x8B,
	0x55, 0x40, 0x48, 0x8B, 0x1A, 0x48, 0x89, 0x1F, 0x48, 0x8B, 0xB5, 0xCE, 0x00, 0x00, 0x00, 0x48, 0x8B, 0x7D, 0x60, 0x48, 0x8B, 0x45, 0x70, 0x48, 0x01, 0xC7,
	0x48, 0x83, 0xC7, 0x0A, 0x48, 0xFF, 0xC7, 0x48, 0x83, 0xC7, 0x08, 0x48, 0x29, 0xFE, 0x48, 0x8B, 0x7D, 0x60, 0x48, 0x8B, 0x45, 0x70, 0x48, 0x01, 0xC7, 0x48,
	0x83, 0xC7, 0x0A, 0x48, 0xFF, 0xC7, 0x48, 0x89, 0x37, 0x48, 0x8B, 0x7D, 0x60, 0x48, 0x8B, 0x45, 0x70, 0x48, 0x01, 0xC7, 0x48, 0x8B, 0x75, 0x40, 0x48, 0x89,
	0x3E, 0x48, 0x8B, 0x45, 0x70, 0x48, 0x83, 0xC0, 0x0F, 0x48, 0x89, 0x45, 0x70, 0x58, 0x5E, 0x59, 0x5B, 0x5A, 0x5F, 0xC3, 0x57, 0x52, 0x53, 0x51, 0x56, 0xEB,
	0x4D, 0x48, 0x8B, 0x7D, 0x00, 0x48, 0x89, 0xDA, 0x48, 0x83, 0xC2, 0x0C, 0x48, 0x03, 0x3A, 0x48, 0x89, 0xE9, 0x48, 0x81, 0xC1, 0x8F, 0x00, 0x00, 0x00, 0x48,
	0x89, 0xFA, 0x48, 0x83, 0xEC, 0x20, 0xFF, 0x56, 0x28, 0x48, 0x83, 0xC4, 0x20, 0x48, 0x85, 0xC0, 0x74, 0x22, 0x48, 0x89, 0xE9, 0x48, 0x81, 0xC1, 0x9A, 0x00,
	0x00, 0x00, 0x48, 0x89, 0xFA, 0x48, 0x83, 0xEC, 0x20, 0xFF, 0x56, 0x28, 0x48, 0x83, 0xC4, 0x20, 0x48, 0x85, 0xC0, 0x74, 0x05, 0x48, 0x31, 0xC0, 0xEB, 0x0C,
	0x48, 0xB8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEB, 0x00, 0x5E, 0x59, 0x5B, 0x5A, 0x5F, 0xC3, 0x57, 0x52, 0x53, 0x51, 0x56, 0x48, 0x8B, 0x7D,
	0x48, 0x48, 0x89, 0xFA, 0x48, 0x83, 0xC2, 0x00, 0x66, 0x8B, 0x1A, 0x66, 0x81, 0xFB, 0x4D, 0x5A, 0x0F, 0x85, 0x9B, 0x00, 0x00, 0x00, 0x48, 0x89, 0xFA, 0x48,
	0x83, 0xC2, 0x3C, 0x48, 0x31, 0xDB, 0x8B, 0x1A, 0x48, 0x01, 0xDF, 0x48, 0x89, 0xFA, 0x48, 0x83, 0xC2, 0x00, 0x48, 0x31, 0xDB, 0x8B, 0x1A, 0x48, 0x81, 0xFB,
	0x50, 0x45, 0x00, 0x00, 0x75, 0x77, 0x48, 0x89, 0xFE, 0x48, 0x83, 0xC6, 0x14, 0x48, 0x31, 0xDB, 0x66, 0x8B, 0x1E, 0x48, 0x89, 0xFE, 0x48, 0x83, 0xC6, 0x18,
	0x48, 0x01, 0xDE, 0x48, 0x89, 0xFB, 0x48, 0x83, 0xC3, 0x06, 0x48, 0x31, 0xC9, 0x66, 0x8B, 0x0B, 0x48, 0x31, 0xD2, 0x48, 0x89, 0xF3, 0x48, 0x83, 0xC3, 0x0C,
	0x48, 0x8B, 0x7D, 0x48, 0x4D, 0x31, 0xD2, 0x44, 0x8B, 0x13, 0x4C, 0x01, 0xD7, 0x48, 0x39, 0xF8, 0x7C, 0x2B, 0x48, 0x89, 0xF3, 0x48, 0x83, 0xC3, 0x08, 0x4D,
	0x31, 0xD2, 0x44, 0x8B, 0x13, 0x4C, 0x01, 0xD7, 0x48, 0x39, 0xF8, 0x7D, 0x16, 0x49, 0x89, 0xF2, 0x49, 0x83, 0xC2, 0x24, 0x48, 0x31, 0xDB, 0x41, 0x8B, 0x1A,
	0x48, 0xF7, 0xC3, 0x00, 0x00, 0x00, 0x20, 0x75, 0x11, 0x48, 0x83, 0xC6, 0x28, 0x48, 0xFF, 0xC2, 0x48, 0x39, 0xCA, 0x7C, 0xB0, 0x48, 0x31, 0xC0, 0xEB, 0x0C,
	0x48, 0xB8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEB, 0x00, 0x5E, 0x59, 0x5B, 0x5A, 0x5F, 0xC3, 0xEB, 0x4D, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00,
	0x00, 0x00, 0x21, 0x0D, 0x00, 0x00, 0x4E, 0x0D, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x5E, 0x0D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x58, 0x48, 0x8B, 0x60, 0xC6, 0x48, 0x8B, 0x68, 0xCE, 0x48, 0x8B, 0x70, 0xD6, 0x48, 0x8D, 0x0D, 0xCA, 0xFF, 0xFF, 0xFF,
	0x48, 0x83, 0xEC, 0x20, 0xFF, 0x56, 0x40, 0x48, 0x83, 0xC4, 0x20, 0xE9, 0x11, 0x01, 0x00, 0x00, 0x4C, 0x89, 0xC6, 0xE9, 0x09, 0x01, 0x00, 0x00, 0x54, 0x55,
	0x51, 0x52, 0x53, 0x56, 0x57, 0x48, 0x31, 0xDB, 0x65, 0x48, 0x8B, 0x5B, 0x30, 0x48, 0x8B, 0x5B, 0x60, 0x48, 0x8B, 0x5B, 0x18, 0x48, 0x8B, 0x5B, 0x10, 0x48,
	0x8B, 0x73, 0x60, 0x48, 0x85, 0xF6, 0x0F, 0x84, 0xA6, 0x00, 0x00, 0x00, 0x48, 0x8B, 0x6B, 0x30, 0x48, 0x85, 0xED, 0x0F, 0x84, 0x99, 0x00, 0x00, 0x00, 0x48,
	0x31, 0xD2, 0xC1, 0xC2, 0x05, 0x66, 0xAD, 0x0C, 0x20, 0x30, 0xC2, 0x66, 0x83, 0x3E, 0x00, 0x75, 0xF1, 0x48, 0x8B, 0x1B, 0x48, 0x3B, 0x54, 0x24, 0x20, 0x75,
	0xCA, 0x48, 0x89, 0xEF, 0x66, 0x81, 0x3F, 0x4D, 0x5A, 0x75, 0x73, 0x8B, 0x7D, 0x3C, 0x48, 0x01, 0xEF, 0x81, 0x3F, 0x50, 0x45, 0x00, 0x00, 0x75, 0x65, 0x48,
	0x89, 0xF9, 0x48, 0x83, 0xC1, 0x18, 0x48, 0x85, 0xC9, 0x74, 0x59, 0x48, 0x31, 0xD2, 0x8B, 0xBF, 0x88, 0x00, 0x00, 0x00, 0x48, 0x01, 0xEF, 0x8B, 0x57, 0x1C,
	0x48, 0x01, 0xEA, 0x8B, 0x5F, 0x20, 0x48, 0x01, 0xEB, 0x8B, 0x7F, 0x24, 0x48, 0x01, 0xEF, 0x49, 0x89, 0xD1, 0x8B, 0x33, 0x48, 0x01, 0xEE, 0x48, 0x31, 0xD2,
	0xC1, 0xC2, 0x05, 0xAC, 0x0C, 0x20, 0x30, 0xC2, 0x80, 0x3E, 0x00, 0x75, 0xF3, 0x48, 0x3B, 0x54, 0x24, 0x18, 0x74, 0x0C, 0x48, 0x83, 0xC7, 0x02, 0x48, 0x83,
	0xC3, 0x04, 0xE2, 0xDA, 0xEB, 0x10, 0x48, 0x0F, 0xB7, 0x17, 0x48, 0xC1, 0xE2, 0x02, 0x4C, 0x01, 0xCA, 0x8B, 0x02, 0x48, 0x01, 0xE8, 0x5F, 0x5E, 0x5B, 0x5A,
	0x59, 0x5D, 0x5C, 0xC3, 0x06, 0xDF, 0xB0, 0x2C, 0x51, 0x33, 0x8A, 0x8D, 0xA4, 0x00, 0x78, 0x95, 0x27, 0x85, 0x00, 0x3B, 0x00, 0xA1, 0xB4, 0x00, 0xDB, 0xB6,
	0xB6, 0xE5, 0x00, 0xC4, 0x22, 0x07, 0xE2, 0x00, 0x82, 0x5A, 0x15, 0x4A, 0x00, 0x02, 0x55, 0xF0, 0xD6, 0xDE, 0x79, 0x03, 0xAA, 0x86, 0x00, 0x0D, 0xC4, 0x8A,
	0xDC, 0x00, 0x00, 0x48, 0x8B, 0x26, 0x50, 0x48, 0x31, 0xC0, 0x48, 0x8D, 0x0D, 0x33, 0x00, 0x00, 0x00, 0x48, 0x8D, 0x1D, 0x2C, 0x00, 0x00, 0x00, 0x48, 0x29,
	0xD9, 0x48, 0x89, 0xDF, 0xF3, 0xAA, 0x48, 0x8D, 0x0D, 0x0D, 0x00, 0x00, 0x00, 0x48, 0x8D, 0x1D, 0x96, 0xF0, 0xFF, 0xFF, 0x48, 0x29, 0xD9, 0x48, 0x89, 0xDF,
	0xF3, 0xAA, 0x58, 0x41, 0x5F, 0x41, 0x5E, 0x41, 0x5D, 0x41, 0x5C, 0x5E, 0x5F, 0x5D, 0x5B, 0xC3, 0xEB, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

struct OriginByteBackUp {
	uint64_t a;
	uint64_t b;
	uint64_t c;
	uint64_t d;
	uint64_t e;
	uint64_t f;
	uint64_t g;
	uint64_t h;
	uint64_t i;
};


std::vector<unsigned char> GetBytesFromFile(std::string filePath)
{
	std::ifstream file(filePath, std::ios::binary);

	file.unsetf(std::ios::skipws);

	std::streampos fileSize;

	file.seekg(0, std::ios::end);
	fileSize = file.tellg();
	file.seekg(0, std::ios::beg);

	std::vector<unsigned char> vec;
	vec.reserve(fileSize);

	vec.insert(vec.begin(),
		std::istream_iterator<unsigned char>(file),
		std::istream_iterator<unsigned char>());

	return vec;
}

std::vector<unsigned char> ConstructPayload(std::vector<unsigned char> dllBytes)
{
	int dllSize = dllBytes.size();
	uint64_t payloadSize = sizeof(doublePulsarPayload) + dllBytes.size();
	unsigned char* payload = (unsigned char*)malloc(payloadSize);

	if (payload == nullptr) { return {}; }

	// Edit shellcode to include dll size
	memcpy(&doublePulsarPayload[0xF82], &dllSize, sizeof(dllSize));

	// Put it all together, shellcode + DLL into the final buffer
	memcpy(payload, doublePulsarPayload, sizeof(doublePulsarPayload));
	memcpy(payload + sizeof(doublePulsarPayload), dllBytes.data(), dllSize);

	return std::vector<unsigned char>(payload, payload + payloadSize);
}

uint64_t Bypass_VirtualAlloc(size_t size)
{

	uint64_t VirtualAllocFunc = mem->ModuleBase + offset::CodeCave + 0x100;
	OriginByteBackUp VirutalAllocOrigin = mem->RPM<OriginByteBackUp>(VirtualAllocFunc);
	uint64_t VirtualAlloccResultOrigin = mem->RPM<uint64_t>(VirtualAllocFunc + 0x100);

	BYTE VirtualAlloc_Main[]{ 0x48, 0x83, 0xEC, 0x28, 0x41, 0xB9, 0x40, 0x00, 0x00, 0x00, 0x41, 0xB8, 0x00, 0x30, 0x00, 0x00, 0xBA, 0xFF, 0xFF, 0xFF, 0x01, 0x31, 0xC9, 0xFF, 0x15, 0x02, 0x00, 0x00, 0x00, 0xEB, 0x08, 0xE0, 0x57, 0x76, 0x77, 0x00, 0x00, 0x00, 0x00, 0x48, 0x89, 0x05, 0xD2, 0x00, 0x00, 0x00, 0x48, 0x83, 0xC4, 0x28, 0xC6, 0x05, 0xC7, 0xFF, 0xFF, 0xFF, 0xC3, 0xC3, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC };
	uint64_t dwVirtualAlloc = (uint64_t)GetProcAddress(GetModuleHandleA("kernel32.dll"), "VirtualAlloc");
	for (int i = 0; i < sizeof(VirtualAlloc_Main); i++)
		mem->WPM<BYTE>(VirtualAllocFunc + i, VirtualAlloc_Main[i], true);



	mem->WPM<int>(VirtualAllocFunc + 0x11, size);
	mem->WPM<uint64_t>(VirtualAllocFunc + 0x1F, dwVirtualAlloc);

	uint64_t NewMemFunc = mem->ModuleBase + offset::CodeCave;

	OriginByteBackUp NewMemFuncOrigin = mem->RPM<OriginByteBackUp>(NewMemFunc);

	BYTE NewMem_ShellCode[]{ 0xE8, 0xFB, 0x00, 0x00, 0x00, 0x48, 0x8B, 0x8B, 0x98, 0x04, 0x00, 0x00, 0xE9, 0xB6, 0xC5, 0xCF, 0xF8, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
	for (int i = 0; i < sizeof(NewMem_ShellCode); i++)
		mem->WPM<BYTE>(NewMemFunc + i, NewMem_ShellCode[i], true);


	mem->WPM<int>(NewMemFunc + 0x1, VirtualAllocFunc - NewMemFunc - 0x5, true);
	mem->WPM<int>(NewMemFunc + 0x8, offset::PlayerCameraManager, true);
	mem->WPM<int>(NewMemFunc + 0xD, ((mem->ModuleBase + offset::PlayerCameraManager_HookBase + 0x7) - (NewMemFunc + 0xC)) - 0x5, true);

	OriginByteBackUp PlayerCameraManager_Original = mem->RPM<OriginByteBackUp>(mem->ModuleBase + offset::PlayerCameraManager_HookBase);

	mem->WPM<BYTE>(mem->ModuleBase + offset::PlayerCameraManager_HookBase, 0xE9, true);
	mem->WPM<int>(mem->ModuleBase + offset::PlayerCameraManager_HookBase + 0x1, (NewMemFunc - (mem->ModuleBase + offset::PlayerCameraManager_HookBase)) - 0x5, true);
	mem->WPM<BYTE>(mem->ModuleBase + offset::PlayerCameraManager_HookBase + 0x5, 0x90, true);
	mem->WPM<BYTE>(mem->ModuleBase + offset::PlayerCameraManager_HookBase + 0x6, 0x90, true);

	while (!mem->RPM<uint64_t>(VirtualAllocFunc + 0x100))
		Sleep(1);
	uint64_t Result = mem->RPM<uint64_t>(VirtualAllocFunc + 0x100);

	mem->WPM<OriginByteBackUp>(mem->ModuleBase + offset::PlayerCameraManager_HookBase, PlayerCameraManager_Original, true);
	mem->WPM<OriginByteBackUp>(NewMemFunc, NewMemFuncOrigin, true);
	mem->WPM<uint64_t>(VirtualAllocFunc + 0x100, VirtualAlloccResultOrigin, true);
	mem->WPM<OriginByteBackUp>(VirtualAllocFunc, VirutalAllocOrigin, true);

	cout << "Byte Recoverd" << endl;
	
	return Result;
}

void ManualMap(string dllPath)
{
	std::vector<unsigned char> fileBytes = GetBytesFromFile(dllPath);
	std::vector<unsigned char> payloadVector = ConstructPayload(fileBytes);
	LPVOID procMem = (LPVOID)Bypass_VirtualAlloc(payloadVector.size());
	cout << hex << "procMem: " << procMem << endl;
	cout << hex << "size: " << payloadVector.size() << endl;

	for (int i = 0; i < payloadVector.size(); i++)
		mem->WPM<BYTE>((uint64_t)procMem + i, payloadVector[i], false);

	uint64_t NewMemFunc = mem->ModuleBase + offset::CodeCave;
	OriginByteBackUp NewMemFuncOrigin = mem->RPM<OriginByteBackUp>(NewMemFunc);

	BYTE NewMemShell[] = { 0x50, 0xFF, 0x15, 0x02, 0x00, 0x00, 0x00, 0xEB, 0x08, 0x00, 0x00, 0x78, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xB8, 0x00, 0x00, 0x78, 0x06, 0x00, 0x00, 0x00, 0x00, 0xC7, 0x00, 0xC3, 0x00, 0x00, 0x00, 0x58, 0x48, 0x8B, 0x8B, 0x98, 0x04, 0x00, 0x00, 0xE9, 0x99, 0xC5, 0xCF, 0xF8, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
	for (int i = 0; i < sizeof(NewMemShell); i++)
		mem->WPM<BYTE>(NewMemFunc + i, NewMemShell[i], true);

	mem->WPM<uint64_t>(NewMemFunc + 0x9, (uint64_t)procMem);
	mem->WPM<uint64_t>(NewMemFunc + 0x13, (uint64_t)procMem);
	mem->WPM<int>(NewMemFunc + 0x25, (int)offset::PlayerCameraManager);

	
	uint32_t CalcBase = (mem->ModuleBase + offset::PlayerCameraManager_HookBase + 0x7) - (NewMemFunc + 0x29) - 0x5;

	mem->WPM<int>(NewMemFunc + 0x2A, CalcBase, true);

	OriginByteBackUp PlayerCamOrigin = mem->RPM<OriginByteBackUp>(mem->ModuleBase + offset::PlayerCameraManager_HookBase);

	mem->WPM<BYTE>(mem->ModuleBase + offset::PlayerCameraManager_HookBase, 0xE9, true);

	mem->WPM<int>(mem->ModuleBase + offset::PlayerCameraManager_HookBase + 0x1, (NewMemFunc - (mem->ModuleBase + offset::PlayerCameraManager_HookBase)) - 0x5, true);
	mem->WPM<BYTE>(mem->ModuleBase + offset::PlayerCameraManager_HookBase + 0x5, 0x90, true);
	mem->WPM<BYTE>(mem->ModuleBase + offset::PlayerCameraManager_HookBase + 0x6, 0x90, true); 

	while (mem->RPM<BYTE>((uint64_t)procMem) != 0xC3)
		Sleep(1);

	mem->WPM<OriginByteBackUp>(mem->ModuleBase + offset::PlayerCameraManager_HookBase, PlayerCamOrigin, true);
	mem->WPM<OriginByteBackUp>(NewMemFunc, NewMemFuncOrigin, true);

}
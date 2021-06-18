#pragma once

class Config {
public:
	bool Skelcfg = true;
	bool Playercfg = true;
	bool Aimbot = true;
	bool Itemcfg = true;
	bool Radarcfg = true;
	bool DebugMode = false;
	bool MagicBulletcfg = true;
	float SkeletonThick = 1.0f;
	float Fov = 0.f;
	float AimSmooth = 0.5f;
	std::string License = "";
	std::string remainingtime = "";
};

static Config* cfg = new Config;
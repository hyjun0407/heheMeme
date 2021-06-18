#pragma once

constexpr auto decrypt = 0x7137B28;
constexpr auto UWorld = 0x8AD4410;
constexpr auto GNames = 0x8A545B8 + 0x20;
constexpr auto LocalPlayer = 0x8B2CC40;

constexpr auto PlayerController = 0x40;
constexpr auto AcknowledgedPawn = 0x458;
constexpr auto SpectatedCount = 0x11D0;

constexpr auto PlayerCameraManager = 0x4A0;
constexpr auto CameraLocation = 0x9B4;
constexpr auto CameraRotation = 0x9A0;
constexpr auto CameraFOV = 0x998;

constexpr auto ComponentToWorld = 0x230;
constexpr auto absoluteLocation = ComponentToWorld + 0x10;
constexpr auto BoneArray = 0xAF8;
constexpr auto RootComponent = 0x1F8;
constexpr auto Health = 0xD40;
constexpr auto GroggyHealth = 0x1148;
constexpr auto PersistentLevel = 0x908;
constexpr auto ActorsArray = 0x190;
constexpr auto ActorID = 0x10;
constexpr auto LastTeamNum = 0xD68;
constexpr auto ActorMesh = 0x548; //0x510

constexpr auto WeaponProcessor = 0x1138;
constexpr auto EquippedWeapons = 0x2b8;
constexpr auto WeaponTrajectoryData = 0xF70;
constexpr auto TrajectoryConfig = 0x118;
constexpr auto VDragCoefficient = 0x2C;

constexpr auto AnimScriptInstance = 0xca0;
constexpr auto ControlRotation_CP = 0x6d0;
constexpr auto RecoilAdsRotation_CP = 0x8fc;
constexpr auto ChunkSize = 0x3ED0;

constexpr auto InputRotation = 0x610;

constexpr auto ActorVelocity = 0x218;
constexpr auto VehicleRiderComponent = 0x19F8;
constexpr auto LastVehiclePawn = 0x260;
constexpr auto ReplicatedMovement = 0x70;

constexpr auto DroppedItemGroup = 0x340;
constexpr auto DroppedItemGroup_Count = DroppedItemGroup + 8;
constexpr auto DroppedItemGroup_UItem = 0x650;
constexpr auto ItemID = 0x280;

constexpr auto LTSoffset = 0x5de9810;
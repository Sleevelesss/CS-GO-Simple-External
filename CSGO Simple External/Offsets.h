#pragma once

//Big antipaste: if you dont know what some of the offsets are by the names i use, you can figure them out pretty easily from the functions

const DWORD playerBase = 0x00A3A43C;
const DWORD entityBase = 0x04A57EA4;
const DWORD crosshairOffset = 0x0000AA54;
const DWORD Flags = 0x00000100;
const DWORD ForceJump = 0x04EED318;
const DWORD GlowIndex = 0x0000A310;
const DWORD GlowObject = 0x04F6DAD4;
const DWORD Dormant = 0x000000E9;
const DWORD ActiveWeapon = 0x00002EE8;
const DWORD iWeaponID = 0x000032DC;
const DWORD FlashMaxAlpha = 0x0000A2F4;
const DWORD ForceAttack = 0x02E97EC4;
const DWORD clientState = 0x005BB2C4;
const DWORD dwSensitivityPtr = 0xA3FC18;
const DWORD dwSensitivity = 0xA3FC44;

const DWORD teamOffset = 0xF0;
const DWORD healthOffset = 0xFC;
const DWORD EntLoopDist = 0x10;

const DWORD bhopToggleKey = 0x67;
const DWORD triggerToggleKey = 0x68;
const DWORD glowToggleKey = 0x69;

const DWORD m_szArmsModel = 0x38E3;
const DWORD m_iShotsFired = 0x0000A2B0;

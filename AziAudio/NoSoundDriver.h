/****************************************************************************
*                                                                           *
* Azimer's HLE Audio Plugin for Project64 Legacy Compatible N64 Emulators   *
* https://www.project64-legacy.com/                                         *
* Copyright (C) 2000-2023 Azimer. All rights reserved.                      *
*                                                                           *
* License:                                                                  *
* GNU/GPLv2 http://www.gnu.org/licenses/gpl-2.0.html                        *
*                                                                           *
****************************************************************************/
/*
NoSound Driver to demonstrate how to use the SoundDriver interface
*/

#pragma once
#include "common.h"
#include "SoundDriver.h"

#if !defined(_WIN32) && !defined(_XBOX)
typedef union _LARGE_INTEGER {
#if defined(ANONYMOUS_STRUCTS_ARE_NOT_ALLOWED)
    struct {
        u32 LowPart;
        s32 HighPart;
    }; /* ...but Microsoft uses them anyway. */
#endif
    struct {
        u32 LowPart;
        s32 HighPart;
    } u;
    s64 QuadPart;
} LARGE_INTEGER;
#endif

class NoSoundDriver :
	public SoundDriver
{
public:
	NoSoundDriver() {};
	~NoSoundDriver() {};

	// Setup and Teardown Functions
	Boolean Initialize();
	void DeInitialize();

	// Management functions
	void AiUpdate(Boolean Wait);
	void StopAudio();
	void StartAudio();
	void SetFrequency(u32 Frequency);

	static SoundDriverInterface* CreateSoundDriver() { return new NoSoundDriver(); }
	static bool ValidateDriver();

protected:
	bool dllInitialized;
	/*
	LARGE_INTEGER perfTimer;
	LARGE_INTEGER perfFreq;
	LARGE_INTEGER perfLast;
	LARGE_INTEGER countsPerSample;
	*/
	bool isPlaying;
	u32 lastTick;

private:
	static bool ClassRegistered;
};

// 2025 The Revelate Engine


#include "GameManagerSubsystem.h"

#include "EngineUtils.h"
#include "ImageUtils.h"

#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h"
#include <windows.h>
#include <shobjidl_core.h>   
#include <shlwapi.h>
#pragma comment(lib, "Ole32.lib")
#pragma comment(lib, "Shlwapi.lib")
#endif

void UGameManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	
	Super::Initialize(Collection);
	HandleWallpaper();
	// have a check of the current state if it is already five and maybe if the cinematic has been reached then do the black screen with its been done text or something idk.  
}
//
// void UGameManagerSubsystem::Deinitialize()
// {
// 	Super::Deinitialize();
// }

EGameState UGameManagerSubsystem::SetCurrentGameState(EGameState SavedState, bool bTasksCompleted)
{
	if (bTasksCompleted)
	{
		EGameState NextGameState;
		int NextState = static_cast<int>(SavedState) + 1;
		int Entries = StaticEnum<EGameState>()->NumEnums() - 1;
		if (NextState >= Entries)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Max State reached"));
			NextGameState = SavedState;
		}
		else
		{
			NextGameState = static_cast<EGameState>(NextState);
		}
		// DEBUG
		NextGameState = EGameState::DayTwo;
		// DEBUG
		CurrentGameState = NextGameState;
		return NextGameState;
	}
	// DEBUG
	SavedState = EGameState::DayTwo;
	// DEBUG
	CurrentGameState = SavedState;
	return SavedState;
}

void UGameManagerSubsystem::HandleWallpaper()
{
#if PLATFORM_WINDOWS
	TCHAR buffer[MAX_PATH] = { 0 };
	if (SystemParametersInfo(SPI_GETDESKWALLPAPER, MAX_PATH, buffer, 0))
	{
		FString WallpaperPath = FString(buffer); 
		TArray<uint8> LoadedData;
		FFileHelper::LoadFileToArray(LoadedData, *WallpaperPath); 

		Wallpaper = FImageUtils::ImportFileAsTexture2D(WallpaperPath);
	}
#endif
	// TODO We'll use a default image or if time incorporate for linux and mac maybe... 
}
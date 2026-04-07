// 2025 The Revelate Engine

#include "GameManagerSubsystem.h"
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
}

EGameState UGameManagerSubsystem::SetCurrentGameState(EGameState SavedState, bool bTasksCompleted)
{
	// DEBUG
	// SavedState = static_cast<EGameState>(6);
	// DEBUG
	
	/* Create pop up window if player has finished all Days, they can no longer enter the game - in the case
	 * bTasksCompleted isn't saved. ie whenever player enters a game after already trying to enter after day 5 
	*/
	if (static_cast<int>(SavedState) > static_cast<int>(EGameState::DayFive))
	{
		LPCWSTR Content = L"Initiation completed, We will call in time.";
		int Code = MessageBox(NULL, Content, L"Revelate Corporation", MB_OK);
	
		if (Code == IDOK)
		{
			FGenericPlatformMisc::RequestExit(false);
		}
	}
	if (bTasksCompleted)
	{
		EGameState NextGameState;
		int NextState = static_cast<int>(SavedState) + 1;
		NextGameState = static_cast<EGameState>(NextState);
		
		// DEBUG
		// NextGameState = EGameState::DayThree;
		// DEBUG
		
		CurrentGameState = NextGameState;
		
		// Create pop up window if player has finished all Days, they can no longer enter the game - 
		if (static_cast<int>(NextGameState) > static_cast<int>(EGameState::DayFive))
		{
			LPCWSTR Content = L"Initiation completed, We will call in time.";
			int Code = MessageBox(NULL, Content, L"Revelate Corporation", MB_OK);

			if (Code == IDOK)
			{
				FGenericPlatformMisc::RequestExit(false);
			}
		}
		
		return NextGameState;
	}  
	// DEBUG
	SavedState = EGameState::DayThree;
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
}
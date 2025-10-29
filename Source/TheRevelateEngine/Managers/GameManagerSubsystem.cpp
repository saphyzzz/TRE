// 2025 The Revelate Engine


#include "GameManagerSubsystem.h"

// void UGameManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
// {
// 	Super::Initialize(Collection);
// 	// have a check of the current state if it is already five and maybe if the cinematic has been reached then do the black screen with its been done text or something idk.  
// }
//
// void UGameManagerSubsystem::Deinitialize()
// {
// 	Super::Deinitialize();
// }

EGameStateTest UGameManagerSubsystem::SetCurrentGameState(EGameStateTest SavedState, bool bTasksCompleted)
{
	if (bTasksCompleted)
	{
		EGameStateTest NextGameState;
		int NextState = static_cast<int>(SavedState) + 1;
		int Entries = StaticEnum<EGameStateTest>()->NumEnums() - 1;
		if (NextState >= Entries)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Max State reached"));
			NextGameState = SavedState;
		}
		else
		{
			NextGameState = static_cast<EGameStateTest>(NextState);
		}
		CurrentGameState = NextGameState;
		return NextGameState;
	}
	return SavedState;
}

// EGameState UGameManagerSubsystem::GetCurrentState() const
// {
// 	
// }

// void UGameManagerSubsystem::HandleGameStateChange(EGameState OldState)
// {
// 	
// }

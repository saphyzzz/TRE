// 2025, The Revelate Engine

#include "GameManager.h"

void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	CurrentGameState = EGameState::DayOne;
	FString EnumName = UEnum::GetValueAsString(CurrentGameState);
	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, EnumName);

	OnGameStateChanged.AddUniqueDynamic(this,&AGameManager::HandleGameStateChange); 
}

EGameState AGameManager::GetCurrentState() const
{
	return CurrentGameState;
}

void AGameManager::HandleGameStateChange(EGameState OldState) // Called whenever the player has successfully finished the level 
{
	// Here we need to set stuff up to change the game state on next time opening the game as we don't want it to change straight away,
	// maybe a bool that becomes true.
	// Handle save stuff here maybe? The HUD can change and deactivate from the task manager but we could do a separate call to the UI here.
}

void AGameManager::SetCurrentState(EGameState NewState)
{
	CurrentGameState = NewState;
}

// The task manager can get the current state and map the correct tasks to display.
// The task manager should handle what tasks are completed and handle if a task has a specific flag for an event.
// The Game manager should handle all core gameplay changes like crashing the game, api stuff, ect.
// Once all tasks are done, it can send a delegate to the game manager to handle the clock out functionality.

// If day one, tasks are x y z, can use some sort of look up table for this. 
// the HUD could also be bound to the delegate fired from the game manager, this could be fired at the
// start of the game, so all managers and other bits know what state they're in and can choose the correct HUD accordingly. 
// 2025 The Revelate Engine

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameManagerSubsystem.generated.h"

UENUM(BlueprintType)
enum class EGameStateTest : uint8 // We don't make this blueprintable as designers don't need to modify these values through blueprint 
{
	DayOne   UMETA(DisplayName="Day One"),
	DayTwo   UMETA(DisplayName="Day Two"),
	DayThree UMETA(DisplayName="Day Three"),
	DayFour  UMETA(DisplayName="Day Four"),
	DayFive  UMETA(DisplayName="Day Five"),
	
};

UCLASS(BlueprintType)
class THEREVELATEENGINE_API UGameManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	// virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable) EGameStateTest SetCurrentGameState(EGameStateTest SavedState, bool bTasksCompleted);
	
	UPROPERTY(SaveGame,BlueprintReadOnly) EGameStateTest CurrentGameState;
	UPROPERTY(SaveGame, BlueprintReadOnly) EGameStateTest CurrentPlayerState;
};

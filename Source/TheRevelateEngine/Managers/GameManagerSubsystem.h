// 2025 The Revelate Engine

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameManagerSubsystem.generated.h"

// UENUM(BlueprintType)
// enum class EGameState : uint8
// {
// 	DayOne   UMETA(DisplayName="Day One"),
// 	DayTwo   UMETA(DisplayName="Day Two"),
// 	DayThree UMETA(DisplayName="Day Three"),
// 	DayFour  UMETA(DisplayName="Day Four"),
// 	DayFive  UMETA(DisplayName="Day Five"),
// };

// DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameStateChanged, EGameState, NewState);

UCLASS(BlueprintType)
class THEREVELATEENGINE_API UGameManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// UFUNCTION(BlueprintCallable) EGameState GetCurrentState() const;
	UFUNCTION() void HandleGameStateChange(EGameState OldState);

	UPROPERTY(SaveGame) EGameState CurrentGameState;
	UPROPERTY(SaveGame) EGameState CurrentPlayerState;
	// UPROPERTY(BlueprintReadWrite) FOnGameStateChanged OnGameStateChanged;
};

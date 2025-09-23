// 2025, The Revelate Engine 
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/Object.h"
#include "GameManager.generated.h"

/**
 * Add explanation here queen 
 */

UENUM(BlueprintType)
enum class EGameState : uint8
{
	DayOne      UMETA(DisplayName = "Day One"),
	DayTwo       UMETA(DisplayName = "Day Two"),
	DayThree       UMETA(DisplayName = "Day Three"),
	DayFour       UMETA(DisplayName = "Day Four"),
	DayFive       UMETA(DisplayName = "Day Five"),
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameStateChanged, EGameState, NewState);

UCLASS(BlueprintType, Blueprintable)
class THEREVELATEENGINE_API AGameManager : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable) EGameState GetCurrentState() const;
	UFUNCTION() void HandleGameStateChange(EGameState OldState);

	UPROPERTY() EGameState CurrentState;
	UPROPERTY(BlueprintReadWrite) FOnGameStateChanged OnGameStateChanged;

protected:
	virtual void BeginPlay() override;
private:
	
};

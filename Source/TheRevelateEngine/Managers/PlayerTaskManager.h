// 2025 The Revelate Engine

#pragma once

#include "CoreMinimal.h"
#include "GameManager.h"
#include "Miscs/PlayerTask.h"
#include "GameFramework/Actor.h"
#include "PlayerTaskManager.generated.h"

/**
 * 
 */


USTRUCT(BlueprintType)
struct FTaskList
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite, Category="Tasks")
	TArray<TObjectPtr<UPlayerTask>> Tasks;
};

UCLASS(BlueprintType, Blueprintable)
class THEREVELATEENGINE_API APlayerTaskManager : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tasks")
	TMap<EGameState, FTaskList> TasksByState;
};

// 2025 The Revelate Engine

#pragma once

#include "CoreMinimal.h"
#include "GameManagerSubsystem.h"
#include "Miscs/PlayerTask.h"
#include "GameFramework/Actor.h"
#include "PlayerTaskManager.generated.h"


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
	TMap<EGameStateTest, FTaskList> TasksByState;
	TArray<TObjectPtr<UPlayerTask>> Tasks = {};
 
};
// task manager should change the description of a task if bTested has been put on.
// If something about tasks were to change, say the bTested, this would break my original UI plan of having it check that bool and update accordingly,
// lets keep business logic inside the central data point so the UI just handles displaying visuals for data. 
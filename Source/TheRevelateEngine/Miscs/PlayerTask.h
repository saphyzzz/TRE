// 2025, The Revelate Engine

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PlayerTask.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, EditInlineNew, DefaultToInstanced)
class THEREVELATEENGINE_API UPlayerTask : public UObject
{
	GENERATED_BODY()

public: 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Task")	FName TaskName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Task")	FString TaskDescription;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Task")	bool bCompleted;
};

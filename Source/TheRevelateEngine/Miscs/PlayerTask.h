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
	UFUNCTION() void SetCompleted(bool InCompleted); 
	UFUNCTION() void SetTested(bool InTested); 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Task")	FName TaskName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Task")	FName TaskEvent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Task")	bool bCompleted;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Task")	bool bTested;
};

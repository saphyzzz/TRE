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

public: // Do I really need these setters? 
	UFUNCTION(BlueprintCallable) void SetCompleted(bool InCompleted); 
	UFUNCTION(BlueprintCallable) void SetTested(bool InTested);
	UFUNCTION(BlueprintCallable) void SetTaskDescription(FString InDescription);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Task")	FName TaskName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Task")	FName TaskEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Task")	FString TaskDescription;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Task")	bool bCompleted;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Task")	bool bTested;
};

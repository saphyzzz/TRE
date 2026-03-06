// 2025 The Revelate Engine

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CodeEditorWidget.generated.h"

/**
 * 
 */
UCLASS()
class THEREVELATEENGINE_API UCodeEditorWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// Removes all whitespace and strips any characters not in the allowed set.
	UFUNCTION(BlueprintCallable, Category="Text|Sanitize")
	static FString SanitizeCodeLikeInput(const FString& In);
	
};

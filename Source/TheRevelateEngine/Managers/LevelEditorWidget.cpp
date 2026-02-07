// 2025 The Revelate Engine


#include "LevelEditorWidget.h"

bool ULevelEditorWidget::CheckAssetBounds(USizeBox *InSizeBox, UUserWidget *InWidget)
{
	if (IsValid(InSizeBox) && IsValid(InWidget))
	{
		// Get bounds of size box
		FGeometry SizeBoxGeometry = InSizeBox->GetCachedGeometry();
		const FVector2D SizeBoxAbsPos  = SizeBoxGeometry.LocalToAbsolute(FVector2D::ZeroVector); // Position in screen
		const FVector2D SizeBoxAbsSize = SizeBoxGeometry.GetLocalSize(); // size in local space (Widget itself)
		const FVector2D SizeBoxAbsMax  = SizeBoxAbsPos + SizeBoxAbsSize;

		// Get bounds of widget
		FGeometry WidgetGeometry = InWidget->GetCachedGeometry();
		const FVector2D WidgetAbsPos  = WidgetGeometry.LocalToAbsolute(FVector2D::ZeroVector);
		const FVector2D WidgetAbsSize = WidgetGeometry.GetLocalSize(); // size in local space
		const FVector2D WidgetAbsMax  = WidgetAbsPos + WidgetAbsSize;

		if (WidgetAbsPos.X >= SizeBoxAbsPos.X && WidgetAbsPos.Y >= SizeBoxAbsPos.Y)
		{
			if (WidgetAbsMax.X <= SizeBoxAbsMax.X && WidgetAbsMax.Y <= SizeBoxAbsMax.Y)
			{
				return true; 
			}
		}
	}
	return false;
}

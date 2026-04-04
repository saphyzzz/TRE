// 2025 The Revelate Engine


#include "CodeEditorWidget.h"

FString UCodeEditorWidget::SanitizeCodeLikeInput(const FString& In)
{
	// Allowed symbols besides letters and numbers
	const FString AllowedSymbols = TEXT(";,{}()\"<>");

	FString Out;
	Out.Reserve(In.Len());

	for (TCHAR C : In)
	{
		// Remove all whitespace 
		if (FChar::IsWhitespace(C))
		{
			continue;
		}

		// Keep letters & numbers
		if (FChar::IsAlnum(C))
		{
			Out.AppendChar(C);
			continue;
		}

		int32 Index = INDEX_NONE;
		if (AllowedSymbols.FindChar(C, Index))
		{
			Out.AppendChar(C);
		}

		// Everything else is dropped
	}

	return Out;
}

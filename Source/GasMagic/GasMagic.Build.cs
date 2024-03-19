// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GasMagic : ModuleRules
{
	public GasMagic(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}

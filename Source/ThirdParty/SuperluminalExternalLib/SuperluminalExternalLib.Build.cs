// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
using System.IO;
using UnrealBuildTool;

public class SuperluminalExternalLib : ModuleRules
{
    private string ApiPath
    {
        get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "API", "include")); }
    }

    private string LibPath(UnrealTargetPlatform Platform)
    {
        return Path.GetFullPath(Path.Combine(ModuleDirectory, "API", "lib", Platform == UnrealTargetPlatform.Win64 ? "x64" : "x86"));
    }

    public SuperluminalExternalLib(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

        string libName = string.Format("PerformanceAPI_{0}{1}.lib", Target.bUseStaticCRT ? "MT" : "MD", Target.bDebugBuildsActuallyUseDebugCRT ? "d" : "");
        PublicAdditionalLibraries.Add(Path.Combine(LibPath(Target.Platform), libName));
        PublicSystemIncludePaths.Add(ApiPath);
    }
}

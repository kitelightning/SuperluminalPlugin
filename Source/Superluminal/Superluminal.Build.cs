// Copyright Kite & Lightning

using UnrealBuildTool;
using System;
using System.IO;

public class Superluminal : ModuleRules
{
    public Superluminal(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        //bTreatAsEngineModule = true;
        // PublicDefinitions.Add("PLATFORM_LIMIT_PROFILER_UNIQUE_NAMED_EVENTS=1");
		
		PublicIncludePaths.AddRange(
			new string[] {
                //Path.Combine(ModuleDirectory, "Public"),
				// ... add public include paths required here ...
			}
		);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
                Path.Combine(ModuleDirectory, "Private"),
				// ... add other private include paths required here ...
			}
		);

        PrivateIncludePathModuleNames.AddRange(new string[] {
            "SuperluminalExternalLib",
        });


        PublicDependencyModuleNames.AddRange(
			new string[] {
				"Core",
			}
		);			
		
		PrivateDependencyModuleNames.AddRange(
			new string[] {
                "Engine",
                "Core",
                "SuperluminalExternalLib"
				// ... add private dependencies that you statically link with here ...	
			}
		);

        DynamicallyLoadedModuleNames.AddRange(
			new string[] {
				// ... add any modules that your module loads dynamically here ...
			}
		);

    }
}

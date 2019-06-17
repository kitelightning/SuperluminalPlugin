# ![](Resources/Icon128.png) [Superluminal UE4 Integration](https://www.superluminal.eu/)

## Instructions

Enable the plugin and pass this flag: `-Superluminal`

_**IMPORTANT:** If you have FRAMEPRO_ENABLED turned on, you will exclude all external profilers_

To make have better stat scoping to prevent "Frame N" events, etc, do one of either:

1. YourGame.Target.cs:

    ```csharp
    BuildEnvironment = TargetBuildEnvironment.Unique;
    GlobalDefinitions.Add("PLATFORM_LIMIT_PROFILER_UNIQUE_NAMED_EVENTS=1");
	GlobalDefinitions.Add("SLATE_VERBOSE_NAMED_EVENTS=0");
	
    ```

1. Core.Build.cs:

    ```csharp
    PublicDefinitions.Add("PLATFORM_LIMIT_PROFILER_UNIQUE_NAMED_EVENTS=1");
	PublicDefinitions.Add("SLATE_VERBOSE_NAMED_EVENTS=0");
    ```

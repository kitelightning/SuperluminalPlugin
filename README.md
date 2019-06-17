# ![](Resources/Icon128.png) [Superluminal UE4 Integration](https://www.superluminal.eu/)

This is a 4.27 fork of KiteLighting's Superluminal plugin.

## Instructions

Enable the plugin and pass this flag: `-Superluminal`

_**IMPORTANT:** If you have FRAMEPRO_ENABLED turned on, you will exclude all external profilers_

To make have better stat scoping to prevent "Frame N" events, etc, do one of either:

UE4 creates several unique names for a bunch of stat named events (e.g. Slate widgets, "Frame N", etc).  To minimize the impact this has on the profiler (imho, the unique names are overkill), do one of either:

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
If you want to emit scopes to Superluminal based on UE4's cycle stats, pass -statnamedevents
* **Note:** This adds a lot of overhead

![](Resources/Icon128.png)

# Superluminal Integration

## Instructions
Enable the plugin and pass this flag

-Superluminal

NOTE: If you have FRAMEPRO_ENABLED turned on, you will exclude all external profilers
NOTE: To make have better stat scoping to prevent "Frame N" events, etc, do one of either:

1. Game.Target.cs:

```csharp
GlobalDefinitions.Add("PLATFORM_LIMIT_PROFILER_UNIQUE_NAMED_EVENTS=1");
```

2. Core.Build.cs:

```csharp
PublicDefinitions.Add("PLATFORM_LIMIT_PROFILER_UNIQUE_NAMED_EVENTS=1");
```
// Copyright Kite & Lightning

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

//DECLARE_LOG_CATEGORY_EXTERN(LogSL, Log, All);
//DEFINE_LOG_CATEGORY(LogSL)

class SUPERLUMINAL_API FSuperluminalModule : public IModuleInterface
{
public:
    virtual bool SupportsDynamicReloading() override { return false; }
};

#include "ProfilingDebugging/ExternalProfiler.h"

#if UE_EXTERNAL_PROFILING_ENABLED
#include "CoreTypes.h"
#include "HAL/PlatformProcess.h"
#include "Misc/AssertionMacros.h"
#include "Templates/SharedPointer.h"
#include "Features/IModularFeatures.h"
#include "Templates/UniquePtr.h"
#include "Containers/Map.h"
#include "HAL/ThreadSingleton.h"

#include "Superluminal/PerformanceAPI.h"


class FSLExternalProfiler final : public FExternalProfiler
{

public:

	/** Constructor */
	FSLExternalProfiler()
	{
		// Register as a modular feature
		IModularFeatures::Get().RegisterModularFeature( FExternalProfiler::GetFeatureName(), this );
	}


	/** Destructor */
	virtual ~FSLExternalProfiler()
	{
		IModularFeatures::Get().UnregisterModularFeature( FExternalProfiler::GetFeatureName(), this );
	}

	virtual void FrameSync() override
	{
	}


	/** Gets the name of this profiler as a string.  This is used to allow the user to select this profiler in a system configuration file or on the command-line */
	virtual const TCHAR* GetProfilerName() const override
	{
		return TEXT( "Superluminal" );
	}


	/** Pauses profiling. */
	virtual void ProfilerPauseFunction() override
	{
	}


	/** Resumes profiling. */
	virtual void ProfilerResumeFunction() override
	{
	}

	virtual void StartScopedEvent(const TCHAR* Text) 
	{
        PerformanceAPI::BeginEvent(Text);
	}

    virtual void EndScopedEvent()
	{
        PerformanceAPI::EndEvent();
	}

	virtual void SetThreadName(const TCHAR* Name) override
	{
		PerformanceAPI::SetCurrentThreadName(TCHAR_TO_ANSI(Name));
	}

	/**
	 * Initializes profiler hooks. It is not valid to call pause/ resume on an uninitialized
	 * profiler and the profiler implementation is free to assert or have other undefined
	 * behavior.
	 *
	 * @return true if successful, false otherwise.
	 */
	bool Initialize()
	{
        return true;
	}
};



namespace SLProfiler
{
	struct FAtModuleInit
	{
		FAtModuleInit()
		{
			static TUniquePtr<FSLExternalProfiler> ProfilerSL = MakeUnique<FSLExternalProfiler>();
			if( !ProfilerSL->Initialize() )
			{
                ProfilerSL.Reset();
			}
		}
	};

	static FAtModuleInit AtModuleInit;
}


#endif	// UE_EXTERNAL_PROFILING_ENABLED

IMPLEMENT_MODULE(FSuperluminalModule, Superluminal)
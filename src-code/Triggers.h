#pragma once
#include <Windows.h>
#include <Xinput.h>

#pragma comment(lib, "XInput.lib")

namespace XWin
{
	struct Triggers									// Provides the means to read from controller triggers and how far in they're being pushed
	{
	private:

		static const int TRIGGER_DEADZONE = 10;		// Defines deadzone for triggers - triggers should not work unless they are being pushed further in that this defines

		XINPUT_GAMEPAD* m_xgPad;					// A reference to the controller being used, to read real-time information from triggers

	public:
		Triggers(XINPUT_GAMEPAD* gPad)				// Default ctor
			: m_xgPad(gPad) { }

		bool L_inDeadZone()	const					// Determines whether left trigger is inside deadzone
		{
			return m_xgPad->bLeftTrigger < TRIGGER_DEADZONE;
		}

		bool R_inDeadZone()	const					// Determines whether right trigger is inside deadzone
		{
			return m_xgPad->bRightTrigger < TRIGGER_DEADZONE;
		}

		short L_getValue()	const					// Returns how far the left trigger is being pushed
		{
			return static_cast<short>(m_xgPad->bLeftTrigger / 2.55);	// Divided because value is byte (0-255) - dividing makes `L_getValue()` return values from 0 - 100
		}

		short R_getValue()	const					// Returns how far the right trigger is being pushed
		{
			return static_cast<short>((0 - m_xgPad->bRightTrigger) / 2.55);	// Divided because value is byte (0-255) - dividing makes `R_getValue()` return values from 0  - -100
		}
	};
}
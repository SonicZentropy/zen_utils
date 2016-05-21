/*==============================================================================
   ZenHeader.h
   Part of the Zentropia JUCE Collection
   @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
   @version 0.1
   @date 2016/01/12
   Copyright (C) 2016 by Casey Bailey
   Provided under the [GNU license]
 
   Details: Generic Zen_utils header stuff
 
   Zentropia is hosted on Github at [https: github.com/SonicZentropy]
===============================================================================*/

#ifndef ZENHEADER_H_INCLUDED
#define ZENHEADER_H_INCLUDED

#include "AppConfig.h"
#include <modules/juce_gui_basics/juce_gui_basics.h>
#include <modules/juce_gui_extra/juce_gui_extra.h>
#include <modules/juce_graphics/juce_graphics.h>
#include <modules/juce_audio_utils/juce_audio_utils.h>

#include <sstream>
#include <atomic>
#include <ctime>
#include <map>
#include <algorithm>
#include <cmath>
#include "boost/circular_buffer.hpp"
#include "boost/optional.hpp"


namespace Zen{
using namespace juce;

#include "GUI/ZenBinaryData.h"
#include "GUI/ZenLabelDisplay.h"
#include "GUI/ZenImageButton.h"
#include "GUI/ZenRotaryEditorLabel.h"
#include "GUI/ZenRotaryFilmStripSlider.h"
#include "GUI/ZenTextEditor.h"
#include "GUI/ZenComboBox.h"
#include "GUI/ZenTitleBar.h"
#include "GUI/ZenBypassButton.h"
#include "GUI/ZenMenuButton.h"
#include "GUI/ZenLookAndFeel.h"

#include "utilities/ZenUtils.hpp"
#include "utilities/ZenParamUtils.h"
#include "utilities/ZenDecibelConversions.hpp"
#include "utilities/ZenConstants.h"
#include "tests/ZenUnitTest.hpp"
#include "parameters/ZenLinearSmoothedValue.h"
#include "parameters/ZenParameter.h"
#include "parameters/ZenBoolParameter.h"
#include "parameters/ZenFloatParameter.h"
#include "parameters/ZenDecibelParameter.h"
#include "components/AssociatedButton.h"
#include "components/AssociatedComponent.h"
#include "components/AssociatedSlider.h"
#include "components/AssociatedTextButton.h"
#include "components/ZenDecibelTextEditor.h"
#include "components/notepadcomp/NotepadComponent.h"
#include "components/panslider/PanSlider.h"
#include "debug/GUI/buffer_visualiser.h"
#include "debug/GUI/component_debugger.h"
#include "debug/GUI/font_and_colour_designer.h"
#include "debug/GUI/ZenMidiVisualiserComponent.h"
#include "debug/GUI/value_tree_editor.h"
#include "debug/ZenDebugEditor.h"
#include "debug/ZenDebugPrinter.h"
#include "DSP/RMSManager.h"
#include "processing/BufferSampleProcesses.h"
//#include "looknfeel/ZenLookAndFeel.h"
}

using namespace Zen;
#define S(inText) String(inText)
#endif

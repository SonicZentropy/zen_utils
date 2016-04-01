#include "zen_utils.h"

namespace Zen{
using namespace juce;

#include "components/AssociatedComponent.cpp"
#include "components/AssociatedButton.cpp"
#include "components/AssociatedTextButton.cpp"
#include "components/AssociatedSlider.cpp"
#include "components/DecibelTextEditor.cpp"
#include "components/notepadcomp/NotepadComponent.cpp"
#include "components/panslider/PanSlider.cpp"
#include "debug/GUI/buffer_visualiser.cpp"
#include "debug/GUI/component_debugger.cpp"
#include "debug/GUI/font_and_colour_designer.cpp"
#include "debug/GUI/value_tree_editor.cpp"
#include "debug/GUI/ZenMidiVisualiserComponent.cpp"
#include "debug/ZenDebugEditor.cpp"
#include "debug/ZenDebugPrinter.cpp"
#include "DSP/RMSManager.cpp"
#include "parameters/ZenLinearSmoothedValue.cpp"
#include "parameters/ZenParameter.cpp"
#include "parameters/ZenBoolParameter.cpp"
#include "parameters/ZenFloatParameter.cpp"
#include "parameters/ZenDecibelParameter.cpp"
#include "processing/BufferSampleProcesses.cpp"
#include "utilities/ZenParamUtils.cpp"
}
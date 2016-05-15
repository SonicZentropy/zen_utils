/*==============================================================================
//  ZenDecibelTextEditor.cpp
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 1/20/2016
//  Copyright (C) 2016 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: DETAILS
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

ZenDecibelTextEditor::ZenDecibelTextEditor(String compName, ZenDecibelParameter* param, juce_wchar passwordCharacter)
	:ZenTextEditor(compName),
	nRange(param->getMinDecibels(), param->getMaxDecibels(), 0.01f)
{
	
}

float ZenDecibelTextEditor::getNormalizedValueFromText() const
{
	return nRange.convertTo0to1(this->getText().getFloatValue());
}

float ZenDecibelTextEditor::getDecibelValueFromText() const
{
	return getText().getFloatValue();
}

void ZenDecibelTextEditor::formatTextAfterEntry()
{
   
	String dbText(getText().getFloatValue(), 2);
	setText(dbText, false);
}

/*==============================================================================
//  DecibelTextEditor.cpp
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

DecibelTextEditor::DecibelTextEditor(String compName, ZenDecibelParameter* param, juce_wchar passwordCharacter)
	:TextEditor(compName, passwordCharacter),
	nRange(param->getMinDecibels(), param->getMaxDecibels(), 0.01f)
{
}

float DecibelTextEditor::getNormalizedValueFromText() const
{
	return nRange.convertTo0to1(this->getText().getFloatValue());
}

float DecibelTextEditor::getDecibelValueFromText() const
{
	return getText().getFloatValue();
}

void DecibelTextEditor::formatTextAfterEntry()
{
    /*
	std::stringstream ss;
	ss.setf(std::ios_base::fixed, std::ios_base::floatfield);
	ss.precision(2);
	ss << getText().getFloatValue();*/
	String dbText(getText().getFloatValue(), 2);
	setText(dbText, false);
}

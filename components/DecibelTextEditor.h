/*==============================================================================
//  DecibelTextEditor.h
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 1/20/2016
//  Copyright (C) 2016 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Text editor component specifically for handling Decibel values
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

#ifndef DECIBELTEXTEDITOR_H_INCLUDEDa
#define DECIBELTEXTEDITOR_H_INCLUDEDa

class DecibelTextEditor : public TextEditor
{
public:

	DecibelTextEditor(const String& componentName, const AudioParameterFloat* param, juce_wchar passwordCharacter = 0U);

	/// <summary>Returns linear 0.0 to 1.0 representation of given decibel value from value text</summary>
	/// <returns>Float linear value representing the decibel value</returns>
	float getNormalizedValueFromText() const;

	/// <summary>Formats value to readable text string with Decibel units</summary>
	void formatTextAfterEntry();

	template <class Type>
	void setTextWith2Precision(const Type inText)
	{
		this->setText(convertTo2PrecisionString(inText));
	}

private:
	NormalisableRange<float> nRange;
};

#endif  // DECIBELTEXTEDITOR_H_INCLUDEDa

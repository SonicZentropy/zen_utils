/*==============================================================================
//  ZenComboBox.h
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 2016/05/19
//  Copyright (C) 2016 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Zen implementation of ComboBox GUI component
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

#pragma once
#ifndef ZENCOMBOBOX_H_INCLUDED
#define ZENCOMBOBOX_H_INCLUDED
//#include <JuceHeader.h>

class ZenComboBox : public ComboBox
{
public:

	ZenComboBox(const String& compName = "ZenComboBox");
	~ZenComboBox();

	void initColors();
	void loadImages();

	Image leftImage, centerImage, rightImage;
protected:
	
};

#endif // ZENCOMBOBOX_H_INCLUDED

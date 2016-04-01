/*==============================================================================
//  ZenParameter.h
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 2015/09/08
//  Copyright (C) 2015 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Base Audio Parameter class (Virtual only)
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

void ZenParameter::setValueTree()
{
	paramValueTree->removeAllChildren(nullptr);
	paramValueTree->removeAllProperties(nullptr);

	paramValueTree->setProperty("parameterValue", getValue(), nullptr);
	paramValueTree->setProperty("defaultValue", getDefaultValue(), nullptr);
}

bool ZenParameter::checkUIUpdateAndReset()
{
	bool expected = true;
	UIUpdate.compare_exchange_strong(expected, false);
	return expected;
}
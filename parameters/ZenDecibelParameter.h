/*==============================================================================
//  DecibelParameter.h
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 2015/09/08
//  Copyright (C) 2015 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Decibel Parameter Class - Handles Log/linear scaling
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

 
#ifndef ZEN_DECIBEL_PARAMETER_H_INCLUDED
#define ZEN_DECIBEL_PARAMETER_H_INCLUDED

class ZenDecibelParameter : public ZenParameter
{
public:
	explicit ZenDecibelParameter(String paramID, String paramName, float minValue, float maxValue,
		float midValue, float unityDecibels, float inDefaultValue = 0.0f,
		bool shouldBeSmoothed = false, float smoothingTime = 50.0f);

	virtual ~ZenDecibelParameter();

 /** Sets value from 0to1 normalized (From host) - Stored as decibel */
	void setValue(float inValue) override;

	/** Sets raw decibel value directly (From GUI) */
	void setValueRaw(float inValue) override;

	/** Sets raw decibel value from a gain value (From Process Block) */
	void setValueGain(float inValue);

	/** This assumes inValue is NOT normalized and coming from NOT the host, since
	* it promptly notifies the host of the change. */
	void setValueNotifyingHost(float inValue) override;
	/** Returns value properly normalized between 0 and 1 with the set midpoint.
	 ** Handles smoothed and non-smoothed values innately*/
	float getValue();

	/** Returns value properly normalized between 0 and 1 with the set midpoint.
	 ** Is not used for smoothed values */
	float getValue() const override;

	/** Return raw Decibel value (For GUI) */
	float getValueRaw() const override;

	/** Returns decibel value as raw decibel gain.
	 ** Handles both smoothed and unsmoothed variants*/
	float getValueGain();

	/** Returns decibel value as raw decibel gain.
	*** Does not handle smoothed values*/
	float getValueGain() const;
	/** Parses an input String and converts it to a normalized numeric value based on the param's range */
	float getValueForText(const String& text) const override;
	virtual float getRawValueForText(const String& text) const;

	String getTextFromValue(int length) const override;

	virtual float getValueInDecibels() const;

	void setMinDecibels(const float inMinDecibels);

	void setMaxDecibels(const float inMaxDecibels);

	float getUnityDecibels() const { return unityDecibels; }

	void setUnityDecibels(const float inUnityDecibels) { unityDecibels = inUnityDecibels; }

	void setValueTree() override;

	float getMinDecibels() const { return getMinValue(); }

	float getMaxDecibels() const { return getMaxValue(); }

	float getMidValue() const { return midValue; }

	void setMidValue(const float inMidValue) { midValue = inMidValue; }

	void setDefaultValue(float inValue) override { defaultValue = inValue; }

	/** Returns default value as normalized 0 to 1 */
	float getDefaultValue() const override;

	float getMinValue() const { return range.start; }

	void setMinValue(float inValue) { range.start = inValue; }

	float getMaxValue() const { return range.end; }

	void setMaxValue(float inValue) { range.end = inValue; }

	String getText(float inValue, int maxStringLength) const override;



	void valueChanged(Value& inValue) override;

	void writeToXML(XmlElement& inXML) override;

	void setFromXML(const XmlElement& inXML) override;

protected:
	NormalisableRange<float> range;
	float unityDecibels;
	float midValue;
	float defaultValue;

	double convertDecibelsToLinearWithSetMidpoint(const double& decibels)
	{
		return DecibelConversions::mapDecibelsToProperNormalizedValue(decibels, getMinDecibels(), getMaxDecibels(), unityDecibels);
	}

	double convertLinearWithSetMidpointToDecibels(const double& inValue)
	{
		return DecibelConversions::mapProperNormalizedValueToDecibels(inValue, getMinDecibels(), getMaxDecibels());
	}

	double convertLinearWithSetMidpointToLinear(const double& inValue)
	{
		double linearMPInDecibels = DecibelConversions::mapProperNormalizedValueToDecibels(inValue, getMinDecibels(), getMaxDecibels());
		return DecibelConversions::convertDecibelsToLinear(linearMPInDecibels, getMinDecibels(), getMaxDecibels());
	}

	double convertLinearToLinearWithSetMidpoint(const double& inValue)
	{
		double decibels = DecibelConversions::convertLinearToDecibels(inValue, getMinDecibels(), getMaxDecibels());
		return DecibelConversions::mapDecibelsToProperNormalizedValue(decibels, getMinDecibels(), getMaxDecibels(), unityDecibels);
	}
private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ZenDecibelParameter);
};

#endif // ZEN_DECIBEL_PARAMETER_H_INCLUDED

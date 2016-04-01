/* ==============================================================================
//  BooleanParameter.hpp
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 2015/08/18
//  Copyright (C) 2015 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Derived AudioProcessorParameter for Boolean values.  Pure
//  virtual methods that must be overridden:
//   destructor
//   getValue
//   setValue
//   getDefaultValue
//   getName
//   getLabel (units string, example "Hz" or "%")
//   getValueForText (parse a String and return appropriate value for it)
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

 
#ifndef ZEN_BOOLEAN_PARAMETER_H_INCLUDED
#define ZEN_BOOLEAN_PARAMETER_H_INCLUDED

/** Float 0.0 => False, else True */
class ZenBoolParameter : public ZenParameter
{
public:
	ZenBoolParameter(String parameterID, String paramName, float inDefaultValue = 0.0, String unitLabel = "")
		: ZenParameter(parameterID, paramName, inDefaultValue, unitLabel, false, 0.0f), defaultValue(inDefaultValue)
	{
	}

	ZenBoolParameter(String parameterID, String paramName, bool inDefaultValue = false, String unitLabel = "")
		: ZenParameter(parameterID, paramName, convertBooleanToFloat(inDefaultValue), unitLabel, false, 0.0f), 
		defaultValue(convertBooleanToFloat(inDefaultValue))
	{
	}

	virtual ~ZenBoolParameter()
	{
	}

	void setValue(float newValue) override;

	void setValueRaw(float newValue) override;

	/** This assumes inValue is NOT normalized and coming from NOT the host, since
	* it promptly notifies the host of the change. */
	void setValueNotifyingHost(float inValue) override;

	/**Sets this parameter's value from normalized value. This should never
	*  ever be called, as the GUI does not deal in normalized values */
	/*void setValueNormalizedNotifyingHost(float inValue)
	{
		setValueNotifyingHost(inValue);
	}*/

	/**This is called by the HOST/Process block and needs to return
	* a normalized value */
	float getValue() const override { return value.load(); }

	/** Returns raw value direct, for GUI!
	*   Same as getValue() for booleans.*/
	float getValueRaw() const override { return value.load(); }

	String getText(float inValue, int length) const override;

	String getText(bool inValue) const;

	float getValueForText(const String& text) const override;

	String getTextFromValue(int length) const override;

	virtual void setValueFromBool(bool newBool);

	/** This assumes inValue is NOT normalized and coming from NOT the host, since
	* it promptly notifies the host of the change. */
	virtual void setValueNotifyingHost(bool newBoolValue);

	virtual bool isOn() const;

	virtual bool isOnByDefault() const;

	virtual bool isOff() const;

	virtual bool isOffByDefault() const;

	virtual bool getValueAsBool() const;

	void setDefaultValue(float inValue) override;

	void setDefaultValueFromBool(bool inValue);

	float getDefaultValue() const override;

	virtual bool getDefaultValueAsBool() const;

	void writeToXML(XmlElement& inXML) override;

	void setFromXML(const XmlElement& inXML) override;

	/** Returns the number of discrete interval steps that this parameter's range
	should be quantised into.

	If you want a continuous range of values, don't override this method, and allow
	the default implementation to return AudioProcessor::getDefaultNumParameterSteps().
	If your parameter is boolean, then you may want to make this return 2.
	The value that is returned may or may not be used, depending on the host.
	*/
	int getNumSteps() const override { return 2; }

protected:
	float defaultValue;

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ZenBoolParameter);
};



#endif   //ZEN_BOOLEAN_PARAMETER_H_INCLUDED

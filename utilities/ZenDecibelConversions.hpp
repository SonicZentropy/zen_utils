/* ==============================================================================
//  DecibelConversions.h
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 2015/09/08
//  Copyright (C) 2015 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details:  Used to convert Decibels in a given range to/from 0.0-1.0 normalized values
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

#ifndef DECIBEL_CONVERSIONS_H_INCLUDED
#define DECIBEL_CONVERSIONS_H_INCLUDED

	/// <summary>Decibel Conversion Utilities</summary>
	/// <remarks>	Zentropy, 8/30/2015. </remarks>
class DecibelConversions
{
public:
	/// <summary>Converts a dBFS value to its equivalent raw (NON-normalized) gain level.</summary>
	/// <param name="decibels">		  Input value in decibels</param>
	/// <param name="minusInfinityDb">Value below which 0 is always returned, represents bottom of decibel range</param>
	/// <returns>A raw Gain value such that 0.0 gain = minusInfinityDb, 1.0 Gain = 0.0dB, and Gain > 1.0 is decibel increase</returns>
	static float decibelsToDBGain(const float& decibels, const float& minusInfinityDb = static_cast<float>(defaultMinusInfinitydB))
	{
		return (decibels > minusInfinityDb) ? pow(10.0, decibels * 0.05) : 0.0f;
	}

	/// <summary>A gain of 1.0 = 0 dB, and lower gains map onto negative decibel values.
	///	If the gain is 0 (or negative), then the method will return the value 
	/// provided as minusInfinityDb.</summary>
	/// <param name="gain">			  The gain.</param>
	/// <param name="minusInfinityDb">Min Decibel Limit to map to -infinity.</param>
	/// <returns>A Type.</returns>
	static float gainToDecibels(const float& gain, const float& minusInfinityDb = static_cast<float>(defaultMinusInfinitydB))
	{
		return (gain > 0.0f) ? (log10(gain) * 20.0f) : minusInfinityDb;
	}

	/// <summary>Converts input Decibel contained within specified range to a normalized 0-1 value</summary>
	/// <param name="decibels">Input decibels between -96 and maximumDecibels</param>
	/// <param name="maximumDecibels">The maximum decibel representation for the range</param>
	/// <param name="minusInfinityDb">Lowest decibel representation, defaults to -96</param>
	/// <returns>Normalized (0-1) gain value</returns>
	static float decibelRangeToGain(const float& decibels, const float& maximumDecibels, const float& minusInfinityDb = static_cast<float>(defaultMinusInfinitydB))
	{
		return (decibels > minusInfinityDb) ? pow(10.0, (decibels - maximumDecibels) * 0.05) : minusInfinityDb;
	}

	/// <summary>INCORRECTConverts a normalized (0.0-1.0) gain value to decibels in a given range</summary>
	/// <param name="gain">Input Gain value normalized between 0 and 1</param>
	/// <param name="maximumDecibels">Maximum Decibel value desired for range</param>
	/// <param name="minimumDecibels">Minimum Decibel value, below which -INF is returned</param>
	/// <returns>Decibel representation of the input value, between -96 and maximumDecibels</returns>
	static float linearToDecibelRange(const float& gain, const float& maximumDecibels, const float& minimumDecibels, const float& unityDecibels)
	{
		DBG("In DecibelConversions::gainToDecibelRange(): Method shouldn't be called, it's busted.");
		jassertfalse;
		return -9000.0f;
	}

	/// <summary>Map an input decibel value in a chosen finite range to a normalized, linear scaled Gain value such that decibelUnityGain maps to given normalizedMidpoint (ex: 0.0dB maps to 0.5 normalized in host)</summary>
	/// <param name="x">				 The input decibel value to be mapped (Between decibelMinimum and decibelMaximum)</param>
	/// <param name="normalizedMin">	 Minimum possible value of the normalized range (Generally always 0.0 for VST)</param>
	/// <param name="normalizedMax">	 Maximum possible value of the normalized range (Generally always 1.0 for VSTs)</param>
	/// <param name="normalizedMidpoint">Value in the range you want to use as the correlated midpoint (Generally 0.5 for Decibels due to automation)</param>
	/// <param name="decibelMinimum">	 Minimum possible value for the desired decibal range (ex: -96)</param>
	/// <param name="decibelMaximum">	 Maximum possible value for the desired decibal range (ex: 12)</param>
	/// <param name="decibelValueForMidpoint">Decimal value you want mapped to normalizedMidpoint (Generally 0.0 for Unity Gain Mapped to 0.5 in the host)</param>
	/// <returns>Decibel input normalized to value between 0 and 1.0 for VST host use</returns>
	static double mapDecibelsToProperNormalizedValue(const double& inDecibels, const double& decibelMinimum, const double& decibelMaximum, const double& decibelValueForMidpoint)
	{
		jassert(inDecibels >= decibelMinimum && inDecibels <= decibelMaximum && decibelValueForMidpoint >= decibelMinimum && decibelValueForMidpoint <= decibelMaximum);
		return ZenParamUtils::convertValueToWarpedLinearBasedOnMidpoint(inDecibels, decibelMinimum, decibelMaximum, decibelValueForMidpoint);
	}

	/// <summary>Map a normalized, linearly scaled input value between 0.0 and 1.0 to decibels in a given range (ex: -96 to 12)</summary>
	/// <param name="inValue">Input value (in 0to1 normalized form) to be converted to decibels.</param>
	/// <param name="decibelMinimum">Minimum possible value of the decibel range (ex. -96.0f)</param>
	/// <param name="decibelMaximum">Maximum possible value of the decibel range (ex. 18.0f)</param>
	/// <param name="dbValueToMapTo0pt5">	 Minimum possible value for the desired decibal range (ex: -96)</param>
	/// <returns>Decibel value of the input normalized value</returns>
	static double mapProperNormalizedValueToDecibels(float inValue, float decibelMinimum, float decibelMaximum, float dbValueToMapTo0pt5 = 0.0f)
	{
		inValue = getClamped(inValue, 0.0f, 1.0f);
		return ZenParamUtils::convertMidpointWarpedLinearNormalizedValueToRawRangeValue(inValue, decibelMinimum, decibelMaximum, dbValueToMapTo0pt5);
	}

	/// <summary>Takes a normalized gain value representing an arbitrary Decibel range and converts it to a raw decibel gain value where 1.0 = 0dB</summary>
	/// <param name="normGainValue">Value between 0 and 1.0 that represents a converted decibel from arbitrary range</param>
	/// <param name="maximumDecibels">The maximum decibel value of the arbitrary range</param>
	/// <param name="minimumDecibels">Any decibel value below this is returned as a 0</param>
	/// <returns>A de-normalized Gain value that can be used to process audio samples</returns>
	static double mapProperNormalizedValueToRawDecibelGain(double normGainValue, float minimumDecibels, float maximumDecibels, float mappedMidpointOfRange)
	{
		normGainValue = getClamped(normGainValue, 0.0f, 1.0f);
		//auto valueInDecibels = ZenParamUtils::convertMidpointWarpedLinearNormalizedValueToRawRangeValue(normGainValue, minimumDecibels, maximumDecibels, mappedMidpointOfRange);
		double valueInDecibels = mapProperNormalizedValueToDecibels(normGainValue, minimumDecibels, maximumDecibels, mappedMidpointOfRange);
		return decibelsToDBGain(valueInDecibels, minimumDecibels);
	}

	static double convertLinearToDecibels(const double& linear, const float minDecibels, const float maxDecibels)
	{
		return (linear * (maxDecibels - minDecibels)) + minDecibels;
	}

	static double convertDecibelsToLinear(const double& inDecibels, const float inMinDecibels, const float inMaxDecibels)
	{
		return (inDecibels - inMinDecibels) / (inMaxDecibels - inMinDecibels);
	}

private:
	//==============================================================================
	enum
	{
		defaultMinusInfinitydB = -96
	};
};

#endif   //DECIBEL_CONVERSIONS_H_INCLUDED

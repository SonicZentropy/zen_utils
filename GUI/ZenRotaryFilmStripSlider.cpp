/*==============================================================================
//  ZenRotaryFilmStripSlider.cpp
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 18 Apr 2016 5:51:37pm
//  Copyright (C) 2016 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Generic CPP File
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

//#include "ZenRotaryFilmStripSlider.h"
//#include "ZenRotaryEditorLabel.h"
//#include "ZenLookAndFeel.h"


ZenRotaryFilmStripSlider::ZenRotaryFilmStripSlider(const String& imgName, const int numFrames, const int knobWidth, const int knobHeight, TextEntryBoxPosition inPos, bool stripIsHorizontal)
	: Slider(imgName, RotaryHorizontalVerticalDrag, inPos) //Slider(imgName, RotaryHorizontalVerticalDrag, inPos)
	, numFrames(numFrames)
	, filmstripIsHorizontal(stripIsHorizontal)
{
	//setSliderStyle(RotaryHorizontalVerticalDrag);
	//setTextBoxStyle(Slider::TextBoxBelow, false, 80, 30);
	setColour(textBoxTextColourId, Colours::white);
	setColour(textBoxBackgroundColourId, Colour(0x00ffffff));
	setColour(textBoxHighlightColourId, Colour(0x001111ee));
	setColour(textBoxOutlineColourId, Colour(0x00808080));

	if (knobWidth > 0 && knobWidth < 48 && knobHeight > 0 && knobHeight < 48)
	{
		filmStrip = ImageCache::getFromMemory(ZenBinaryData::zenRotaryKnobNoGrates_png, (size_t)ZenBinaryData::zenRotaryKnobNoGrates_pngSize);
		isSmallKnob = true;
	} else
	{
		filmStrip = ImageCache::getFromMemory(ZenBinaryData::zenRotaryKnob_png, (size_t)ZenBinaryData::zenRotaryKnob_pngSize);
		isSmallKnob = false;
	}

	if (filmStrip.isValid())
	{
		//setTextBoxStyle(TextBoxCentered, 0, 80, 30);
		if (filmstripIsHorizontal) {
			frameHeight = filmStrip.getHeight();
			frameWidth = filmStrip.getWidth() / numFrames;
		} else {
			frameHeight = filmStrip.getHeight() / numFrames;
			frameWidth = filmStrip.getWidth();
		}
	}

	int compWidth = (knobWidth == -1) ? frameWidth : knobWidth;
	int	compHeight = (knobHeight == -1) ? frameHeight : knobHeight;
	
	setNumDecimalPlacesToDisplay(2);
	if (this->getTextBoxPosition() == Slider::TextBoxLeft || this->getTextBoxPosition() == Slider::TextBoxRight)
		setSize(compWidth + this->getTextBoxWidth(), compHeight);
	else if (this->getTextBoxPosition() == Slider::TextBoxAbove || this->getTextBoxPosition() == Slider::TextBoxBelow)
		setSize(compWidth, compHeight + this->getTextBoxHeight());
	else // Text box centered
		setSize(compWidth, compHeight);
}

ZenRotaryFilmStripSlider::~ZenRotaryFilmStripSlider() {};


void ZenRotaryFilmStripSlider::setTextBoxStyle(const TextEntryBoxPosition newPosition, const bool isReadOnly,
	const int textEntryBoxWidth, const int textEntryBoxHeight)
{
	TextEntryBoxPosition oldPos = this->getTextBoxPosition();
	Slider::setTextBoxStyle(newPosition, isReadOnly, textEntryBoxWidth, textEntryBoxHeight);
// 	switch (this->getTextBoxPosition())
// 	{
// 	case TextBoxBelow:
// 		DBG("below found");
// 
// 		break;
// 	case TextBoxCentered:
// 		DBG("Centered found");
// 		break;
// 	case TextBoxAbove:
// 		DBG("Above found");
// 		break;
// 	case TextBoxLeft:
// 		DBG("L found");
// 		if (oldPos != TextBoxLeft && oldPos != TextBoxRight)
// 			this->setSize(getWidth() + textEntryBoxWidth, getHeight());
// 		break;
// 	case TextBoxRight:
// 		DBG("R found");
// 		if (oldPos != TextBoxLeft && oldPos != TextBoxRight)
// 			this->setSize(getWidth() + textEntryBoxWidth, getHeight());
// 		break;
// 	default:
// 		DBG("DEFAULT");
// 		break;
// 	}
	
}


int ZenRotaryFilmStripSlider::getFrameWidth() const
{
	return filmStrip.isValid() ? frameWidth : 100;
}

int ZenRotaryFilmStripSlider::getFrameHeight() const
{
	return filmStrip.isValid() ? frameHeight : 24;
}

void ZenRotaryFilmStripSlider::setSize(int newWidth, int newHeight)
{
	if (isSmallKnob && (newWidth >= 48 || newHeight >= 48))
	{
		filmStrip = ImageCache::getFromMemory(ZenBinaryData::zenRotaryKnob_png, ZenBinaryData::zenRotaryKnob_pngSize);
		isSmallKnob = false;
	} else if (!isSmallKnob && (newWidth < 48 || newHeight < 48))
	{
		filmStrip = ImageCache::getFromMemory(ZenBinaryData::zenRotaryKnobNoGrates_png, ZenBinaryData::zenRotaryKnobNoGrates_pngSize);
		isSmallKnob = true;
		
	}

	if (isSmallKnob)
		dynamic_cast<ZenRotaryEditorLabel*>(this->getValueBox())->setTextHasShadow(false);
	else
		dynamic_cast<ZenRotaryEditorLabel*>(this->getValueBox())->setTextHasShadow(true);

	Component::setSize(newWidth, newHeight);
	if (getTextBoxPosition() == TextBoxCentered)
	{
		int textWidth = jmin(getTextBoxWidth(), newWidth - 20); //Make sure text box fits into knob
		setTextBoxStyle(getTextBoxPosition(), this->isTextBoxEditable(), textWidth, getTextBoxHeight());
	}
}





/*==============================================================================
//  ZenLabelDisplay.h
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 10 May 2016 6:19:48pm
//  Copyright (C) 2016 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Generic Header File
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

#ifndef ZENLABELDISPLAY_H_INCLUDED
#define ZENLABELDISPLAY_H_INCLUDED

//#include "JuceHeader.h"

/// ZenLabelDisplay: Creates a non-editable label display area.
/// This is for purposes of displaying relevant information from a plugin
/// with no chance of someone mistaking it for a field that can be 
/// manually changed.  Use by setting size, then simply changing
/// the displayed text with setText
/// <seealso cref="Label" />
class ZenLabelDisplay : public Label
{
public:
	explicit ZenLabelDisplay(const String& componentName = String::empty, const String& labelText = String::empty);
	~ZenLabelDisplay();

	//void setSize(int newWidth, int newHeight) override;

// 	Image getLabelImage() const { return labelImage; }
// 	void setLabelImage(Image inValue) { labelImage = inValue; }	
// 
// 	int getImageWidth() const { return labelImage.getWidth(); }
// 	int getImageHeight() const { return labelImage.getHeight(); }

	const Image& getLabelTLCornerImg() const { return labelTLCornerImage; }
	void setLabelTLCornerImg(Image inValue) { labelTLCornerImage = inValue; }

	const Image& getLabelTRCornerImage() const { return labelTRCornerImage; }
	void setLabelTRCornerImage(Image inValue) { labelTRCornerImage = inValue; }

	const Image& getLabelBLCornerImage() const { return labelBLCornerImage; }
	void setLabelBLCornerImage(Image inValue) { labelBLCornerImage = inValue; }

	const Image& getLabelBRCornerImage() const { return labelBRCornerImage; }
	void setLabelBRCornerImage(Image inValue) { labelBRCornerImage = inValue; }


	const Image& getLabelTopLineImg() const { return labelTopLineImg; }
	void setLabelTopLineImg(Image inValue) { labelTopLineImg = inValue; }

	const Image& getLabelBottomLineImg() const { return labelBottomLineImg; }
	void setLabelBottomLineImg(Image inValue) { labelBottomLineImg = inValue; }

	const Image& getLabelLeftLineImg() const { return labelLeftLineImg; }
	void setLabelLeftLineImg(Image inValue) { labelLeftLineImg = inValue; }

	const Image& getLabelRightLineImg() const { return labelRightLineImg; }
	void setLabelRightLineImg(Image inValue) { labelRightLineImg = inValue; }

	const Image& getLabelInteriorImg() const { return labelInteriorImg; }
	void setLabelInteriorImg(Image inValue) { labelInteriorImg = inValue; }
	//Image& getLabelImageCompositeFromSize(int inWidth, int inHeight);

protected:
	Image labelTLCornerImage, labelTRCornerImage, labelBLCornerImage, labelBRCornerImage;
	Image labelTopLineImg, labelBottomLineImg, labelLeftLineImg, labelRightLineImg;
	Image labelInteriorImg;


};



#endif  // ZENLABELDISPLAY_H_INCLUDED

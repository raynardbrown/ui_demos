////////////////////////////////////////////////////////////////////////////////
//
// File: LabelDemoGui.cpp
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#include <string>

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#include "graphics/Color.h"
#include "graphics/Font.h"
#include "graphics/FontFactory.h"

#include "ui/Label.h"
#include "ui/UiApplication.h"

#include "ui/event/CloseObserver.h"
#include "ui/event/UiEventObserver.h"

#include "ui/layout/RowLayout.h"
#include "ui/layout/UiComponentConstraints.h"

#include "LabelDemoGui.h"

static Color * getWhiteColor()
{
  return new Color(255,255,255,0);
}

static Color * getRedColor()
{
  return new Color(255,0,0,0);
}

static Color * getGreenColor()
{
  return new Color(0,128,0,0);
}

static Color * getBlueColor()
{
  return new Color(0,0,255,0);
}

static Color * getBrownColor()
{
  return new Color(165,42,42,0);
}

static Color * getYellowColor()
{
  return new Color(255,255,0,0);
}

class LabelDemoGui::LabelDemoGuiPrivate
{
  public:

    LabelDemoGuiPrivate()
    :labelLight(nullptr),
     labelRegular(nullptr),
     labelItalic(nullptr),
     labelBold(nullptr),
     labelDefaultPointSize(nullptr),
     label_12PointSize(nullptr),
     label_18PointSize(nullptr),
     label_24PointSize(nullptr),
     labelEnabled(nullptr),
     labelDisabled(nullptr),
     labelOpenAmpersandClose(nullptr),
     labelOpenFileAccelerator(nullptr),
     labelColorOne(nullptr),
     labelColorTwo(nullptr),
     labelColorThree(nullptr),
     labelColorFour(nullptr),
     mainRowLayout(nullptr)
    {
      colorPairs.push_back(std::pair<Color * (*)(), Color * (*)()>(::getWhiteColor, ::getRedColor));
      colorPairs.push_back(std::pair<Color * (*)(), Color * (*)()>(::getGreenColor, ::getWhiteColor));
      colorPairs.push_back(std::pair<Color * (*)(), Color * (*)()>(::getBlueColor, ::getWhiteColor));
      colorPairs.push_back(std::pair<Color * (*)(), Color * (*)()>(::getBrownColor, ::getYellowColor));
      colorPairs.push_back(std::pair<Color * (*)(), Color * (*)()>(::getRedColor, ::getWhiteColor));
    }

    ~LabelDemoGuiPrivate()
    {
      delete labelLight;
      labelLight = nullptr;

      delete labelRegular;
      labelRegular = nullptr;

      delete labelItalic;
      labelItalic = nullptr;

      delete labelBold;
      labelBold = nullptr;

      delete labelDefaultPointSize;
      labelDefaultPointSize = nullptr;

      delete label_12PointSize;
      label_12PointSize = nullptr;

      delete label_18PointSize;
      label_18PointSize = nullptr;

      delete label_24PointSize;
      label_24PointSize = nullptr;

      delete labelEnabled;
      labelEnabled = nullptr;

      delete labelDisabled;
      labelDisabled = nullptr;

      delete labelOpenAmpersandClose;
      labelOpenAmpersandClose = nullptr;

      delete labelOpenFileAccelerator;
      labelOpenFileAccelerator = nullptr;

      delete labelColorOne;
      labelColorOne = nullptr;

      delete labelColorTwo;
      labelColorTwo = nullptr;

      delete labelColorThree;
      labelColorThree = nullptr;

      delete labelColorFour;
      labelColorFour = nullptr;
    }

    void createAllUiComponents()
    {
      labelLight = new Label("Light",
                           Label::LeftAlignment,
                           Label::DisableAcceleratorInterpretation);

      labelRegular = new Label("Regular",
                           Label::LeftAlignment,
                           Label::DisableAcceleratorInterpretation);

      labelItalic = new Label("Italic",
                              Label::LeftAlignment,
                              Label::DisableAcceleratorInterpretation);

      labelBold = new Label("Bold",
                            Label::LeftAlignment,
                            Label::DisableAcceleratorInterpretation);

      labelDefaultPointSize = new Label("Default Point",
                                        Label::LeftAlignment,
                                        Label::DisableAcceleratorInterpretation);

      label_12PointSize = new Label("12 Point",
                                    Label::LeftAlignment,
                                    Label::DisableAcceleratorInterpretation);

      label_18PointSize = new Label("18 Point",
                                    Label::LeftAlignment,
                                    Label::DisableAcceleratorInterpretation);

      label_24PointSize = new Label("24 Point",
                                    Label::LeftAlignment,
                                    Label::DisableAcceleratorInterpretation);

      labelEnabled = new Label("Enabled",
                               Label::LeftAlignment,
                               Label::DisableAcceleratorInterpretation);

      labelDisabled = new Label("Disabled",
                                Label::LeftAlignment,
                                Label::DisableAcceleratorInterpretation);

      labelOpenAmpersandClose = new Label("Open & Close",
                                          Label::LeftAlignment,
                                          Label::DisableAcceleratorInterpretation);

      labelOpenFileAccelerator = new Label("&Open File",
                                           Label::LeftAlignment,
                                           Label::EnableAcceleratorInterpretation);

      labelColorOne = new Label("Colored Label",
                                Label::LeftAlignment,
                                Label::DisableAcceleratorInterpretation);

      labelColorTwo = new Label("Colored Label",
                                Label::LeftAlignment,
                                Label::DisableAcceleratorInterpretation);

      labelColorThree = new Label("Colored Label",
                                Label::LeftAlignment,
                                Label::DisableAcceleratorInterpretation);

      labelColorFour = new Label("Colored Label",
                                Label::LeftAlignment,
                                Label::DisableAcceleratorInterpretation);

      labelLight->setFont(FontFactory::createFont("Segoe UI", FontWeight::LightWeight, 9));
      labelRegular->setFont(FontFactory::createFont("Segoe UI", FontWeight::DefaultWeight, 9));
      labelItalic->setFont(FontFactory::createFont("Segoe UI", FontWeight::DefaultWeight, FontStyle::ItalicStyle, 9));
      labelBold->setFont(FontFactory::createFont("Segoe UI", FontWeight::BoldWeight, 9));

      label_12PointSize->setFont(FontFactory::createFont("Segoe UI", 12));
      label_18PointSize->setFont(FontFactory::createFont("Segoe UI", 18));
      label_24PointSize->setFont(FontFactory::createFont("Segoe UI", 24));

      labelDisabled->setEnabled(false);

      labelColorOne->setBackgroundColor(::getWhiteColor());
      labelColorOne->setForegroundColor(::getRedColor());

      labelColorTwo->setBackgroundColor(::getGreenColor());
      labelColorTwo->setForegroundColor(::getWhiteColor());

      labelColorThree->setBackgroundColor(::getBlueColor());
      labelColorThree->setForegroundColor(::getWhiteColor());

      labelColorFour->setBackgroundColor(::getBrownColor());
      labelColorFour->setForegroundColor(::getYellowColor());
    }

    Label * labelLight;
    Label * labelRegular;
    Label * labelItalic;
    Label * labelBold;

    Label * labelDefaultPointSize;
    Label * label_12PointSize;
    Label * label_18PointSize;
    Label * label_24PointSize;

    Label * labelEnabled;
    Label * labelDisabled;

    Label * labelOpenAmpersandClose;
    Label * labelOpenFileAccelerator;

    Label * labelColorOne;
    Label * labelColorTwo;
    Label * labelColorThree;
    Label * labelColorFour;

    RowLayout * mainRowLayout;

    boost::random::mt19937 gen;

    std::vector<std::pair<Color * (*)(), Color * (*)()> > colorPairs;
};

LabelDemoGui::LabelDemoGui()
:Window("Label Demo",
        800,
        600),
 d(std::auto_ptr<LabelDemoGuiPrivate>(new LabelDemoGuiPrivate()))
{
  d->mainRowLayout = new RowLayout(this);

  d->createAllUiComponents();
}

LabelDemoGui::~LabelDemoGui()
{

}

void LabelDemoGui::onClose()
{
  UiApplication::quit();
}

void LabelDemoGui::onLabelClick(UiComponent * uiComponent)
{
  // produce numbers in the range of 0 - 4
  boost::random::uniform_int_distribution<> dist(0, 4);

  int randomColorIndex = dist(d->gen);

  Color * foregroundColor = d->colorPairs[randomColorIndex].second();

  Color * backgroundColor = d->colorPairs[randomColorIndex].first();

  // This downcast is okay since I know it is a label that was clicked.
  // (See click observer registration below)
  Label * clickedLabel = static_cast<Label *>(uiComponent);

  clickedLabel->setBackgroundColor(backgroundColor);
  clickedLabel->setForegroundColor(foregroundColor);

  clickedLabel->redrawUiComponentLater();
}

void LabelDemoGui::create()
{
  CloseObserver<LabelDemoGui> * closeObserver  = new CloseObserver<LabelDemoGui>(this, &LabelDemoGui::onClose);

  addCloseObserver(closeObserver);

  UiEventObserver<LabelDemoGui> * clickObserverOne  = new UiEventObserver<LabelDemoGui>(this, &LabelDemoGui::onLabelClick);

  d->labelColorOne->setClickObserver(clickObserverOne);

  UiEventObserver<LabelDemoGui> * clickObserverTwo  = new UiEventObserver<LabelDemoGui>(this, &LabelDemoGui::onLabelClick);

  d->labelColorTwo->setClickObserver(clickObserverTwo);

  UiEventObserver<LabelDemoGui> * clickObserverThree  = new UiEventObserver<LabelDemoGui>(this, &LabelDemoGui::onLabelClick);

  d->labelColorThree->setClickObserver(clickObserverThree);

  UiEventObserver<LabelDemoGui> * clickObserverFour  = new UiEventObserver<LabelDemoGui>(this, &LabelDemoGui::onLabelClick);

  d->labelColorFour->setClickObserver(clickObserverFour);
}

void LabelDemoGui::postCreate()
{
  setTopPadding(11);
  setBottomPadding(11);
  setLeftPadding(11);
  setRightPadding(11);

  UiComponentConstraints uiComponentConstraints;

  ::initUiComponentConstraints(&uiComponentConstraints);

  d->mainRowLayout->addUiComponent(d->labelLight, 0, &uiComponentConstraints);
  d->mainRowLayout->addUiComponent(d->labelRegular, 0, &uiComponentConstraints);
  d->mainRowLayout->addUiComponent(d->labelItalic, 0, &uiComponentConstraints);
  d->mainRowLayout->addUiComponent(d->labelBold, 0, &uiComponentConstraints);

  // TODO: Add bottom/top row orientation to the RowLayout class
  d->mainRowLayout->addUiComponent(d->labelDefaultPointSize, 1, &uiComponentConstraints);
  d->mainRowLayout->addUiComponent(d->label_12PointSize, 1, &uiComponentConstraints);
  d->mainRowLayout->addUiComponent(d->label_18PointSize, 1, &uiComponentConstraints);
  d->mainRowLayout->addUiComponent(d->label_24PointSize, 1, &uiComponentConstraints);

  d->mainRowLayout->addUiComponent(d->labelEnabled, 2, &uiComponentConstraints);
  d->mainRowLayout->addUiComponent(d->labelDisabled, 2, &uiComponentConstraints);

  d->mainRowLayout->addUiComponent(d->labelOpenAmpersandClose, 3, &uiComponentConstraints);
  d->mainRowLayout->addUiComponent(d->labelOpenFileAccelerator, 3, &uiComponentConstraints);

  d->mainRowLayout->addUiComponent(d->labelColorOne, 4, &uiComponentConstraints);
  d->mainRowLayout->addUiComponent(d->labelColorTwo, 4, &uiComponentConstraints);
  d->mainRowLayout->addUiComponent(d->labelColorThree, 4, &uiComponentConstraints);
  d->mainRowLayout->addUiComponent(d->labelColorFour, 4, &uiComponentConstraints);
}

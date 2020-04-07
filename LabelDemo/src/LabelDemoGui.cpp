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

#include "ui/Label.h"
#include "ui/UiApplication.h"

#include "ui/event/CloseObserver.h"

#include "ui/layout/RowLayout.h"
#include "ui/layout/UiComponentConstraints.h"

#include "LabelDemoGui.h"

class LabelDemoGui::LabelDemoGuiPrivate
{
  public:

    LabelDemoGuiPrivate()
    :labelOne(nullptr),
     mainRowLayout(nullptr)
    {

    }

    ~LabelDemoGuiPrivate()
    {
      delete labelOne;
      labelOne = nullptr;
    }

    void createAllUiComponents()
    {
      labelOne = new Label("Label One",
                           Label::LeftAlignment,
                           Label::DisableAcceleratorInterpretation);
    }

    Label * labelOne;

    RowLayout * mainRowLayout;
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

void LabelDemoGui::create()
{
  CloseObserver<LabelDemoGui> * closeObserver  = new CloseObserver<LabelDemoGui>(this, &LabelDemoGui::onClose);

  addCloseObserver(closeObserver);
}

void LabelDemoGui::postCreate()
{
  setTopPadding(11);
  setBottomPadding(11);
  setLeftPadding(11);
  setRightPadding(11);

  UiComponentConstraints uiComponentConstraints;

  ::initUiComponentConstraints(&uiComponentConstraints);

  d->mainRowLayout->addUiComponent(d->labelOne, 0, &uiComponentConstraints);
}

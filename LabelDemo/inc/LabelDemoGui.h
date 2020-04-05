////////////////////////////////////////////////////////////////////////////////
//
// File: LabelDemoGui.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef LABELDEMOGUI_H_
#define LABELDEMOGUI_H_

#include "ui/Window.h"

class LabelDemoGui : public Window
{
  public:

    LabelDemoGui();

  protected:

    virtual void create();

    virtual void postCreate();
};
#endif /* LABELDEMOGUI_H_ */

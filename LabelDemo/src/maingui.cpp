////////////////////////////////////////////////////////////////////////////////
//
// File: maingui.cpp
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#include "ui/UiApplication.h"

#include "LabelDemoGui.h"

int main(int argc, char ** argv)
{
  UiApplication app(argc,  argv);

  int exitCode = 0;

  LabelDemoGui * labelDemoGui = new LabelDemoGui();

  labelDemoGui->showWindow();

  exitCode = app.run(labelDemoGui);

  return exitCode;
}

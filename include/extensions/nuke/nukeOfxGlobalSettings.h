#ifndef nukeOfxGlobalSettings_h
#define nukeOfxGlobalSettings_h

#include "ofxImageEffect.h"

/*
Software License :

Copyright (c) 2010, The Foundry Visionmongers Ltd. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.
    * Neither the name The Foundry Visionmongers Ltd, nor the names of its 
      contributors may be used to endorse or promote products derived from this
      software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/** @file nukeOfxGlobalSettings.h

This file defines a custom OFX extension to NUKE that allows plugins to 
access the values of parameters on the root settings.
*/

/** @brief string to identify the GlobalSettings suite, pass to OfxHost::fetchSuite */
#define kNukeOfxGlobalSettingsSuite "NukeOfxGlobalSettingsSuite"

typedef struct NukeOfxGlobalSettingsSuiteV1 {
  //! get the number of settings (knobs) available on the Root node.
  OfxStatus (*getSettingsCount) (OfxImageEffectHandle pluginHandle, int* settingsCount);

  //! get the name of a setting (knobs) available on the Root node.  String will be 
  //! owned by the plugin after this call and should be freed.
  OfxStatus (*getSettingsName) (OfxImageEffectHandle pluginHandle, int setting, char** settingsNames);

  //! get (if available) the double value of the /nth/ index on the setting called 'settingName'.
  OfxStatus (*getSettingDoubleValue) (OfxImageEffectHandle pluginHandle, const char* settingName, int dimension, double* value);

  //! get (if available) the string value of the /nth/ index on the setting called 'settingName'.  For
  //! non-string plugins will place NULL in *value.  String will be owned by the plugin after this call
  //! and should be freed.
  OfxStatus (*getSettingStringValue) (OfxImageEffectHandle pluginHandle, const char* settingName, char** value);

} NukeOfxGlobalSettingsSuiteV1;

#endif

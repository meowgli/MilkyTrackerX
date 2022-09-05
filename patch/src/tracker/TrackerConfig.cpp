/*
 *  tracker/TrackerConfig.cpp
 *
 *  Copyright 2009 Peter Barth
 *
 *  This file is part of Milkytracker.
 *
 *  Milkytracker is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Milkytracker is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Milkytracker.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "TrackerConfig.h"
#include "version.h"

const PPString TrackerConfig::stringButtonPlus("+");
const PPString TrackerConfig::stringButtonMinus("-");

const PPString TrackerConfig::stringButtonUp("\xfe");
const PPString TrackerConfig::stringButtonDown("\xfd");

const PPString TrackerConfig::stringButtonExtended("\xf0");
const PPString TrackerConfig::stringButtonCollapsed("=");

const PPPoint TrackerConfig::trackerExitBounds(4,4);

PPColor TrackerConfig::colorThemeMain(64, 96, 128);
PPColor TrackerConfig::colorRecordModeButtonText(255, 0, 0);

PPColor TrackerConfig::colorPatternEditorBackground(0,0,0);
PPColor TrackerConfig::colorPatternEditorCursor(64*2, 64*2, 128*2-1);
PPColor TrackerConfig::colorPatternEditorCursorLine(96, 32, 64);
PPColor TrackerConfig::colorPatternEditorCursorLineHighLight(128+32, 24, 48);
PPColor TrackerConfig::colorPatternEditorSelection(16,48,96);

PPColor TrackerConfig::colorPatternEditorNote(255, 255, 255);
PPColor TrackerConfig::colorPatternEditorInstrument(128, 224, 255);
PPColor TrackerConfig::colorPatternEditorVolume(128, 255, 128);
PPColor TrackerConfig::colorPatternEditorEffect(255, 128, 224);
PPColor TrackerConfig::colorPatternEditorOperand(255, 224, 128);

PPColor TrackerConfig::colorHighLight_1(255, 255, 0);
PPColor TrackerConfig::colorHighLight_2(255, 255, 128);
PPColor TrackerConfig::colorScopes(255, 255, 255);
PPColor TrackerConfig::colorScopesRecordIndicator(255, 0, 0);
PPColor TrackerConfig::colorPeakClipIndicator(255, 0, 0);
PPColor TrackerConfig::colorRowHighLight_1(32, 32, 32);
PPColor TrackerConfig::colorRowHighLight_2(16, 16, 16);

PPColor TrackerConfig::colorSampleEditorWaveform(255, 255, 128);

// how many open tabs are allowed
#ifndef __LOWRES__
pp_int32 TrackerConfig::numTabs = 32;
#else
pp_int32 TrackerConfig::numTabs = 1;
#endif

// How many channels possible in XM module? We take the standard here => 32 channels
pp_int32 TrackerConfig::numPlayerChannels = 32;
// How many channels allocated for instrument playback only? Doesn't cut notes
pp_int32 TrackerConfig::numVirtualChannels = 32;
// The final amount of channels to be mixed, add two for playing samples on seperate channels without having to cut notes
pp_int32 TrackerConfig::totalPlayerChannels = TrackerConfig::numPlayerChannels + TrackerConfig::numVirtualChannels + 2;
// This can't be changed later, it's the maximum of channels possible
const pp_int32 TrackerConfig::maximumPlayerChannels = MAXCHANNELS;

bool TrackerConfig::useVirtualChannels = false;

const pp_int32 TrackerConfig::numPredefinedEnvelopes = 10;
const pp_int32 TrackerConfig::numPredefinedColorPalettes = 6;

const PPString TrackerConfig::defaultPredefinedVolumeEnvelope("060203050700000000C000040100000800B0000E00200018005800200020");
const PPString TrackerConfig::defaultPredefinedPanningEnvelope("06020305000000000080000A00A0001E006000320080003C008000460080");

const PPString TrackerConfig::defaultProTrackerPanning("0000002000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00");

const PPString TrackerConfig::defaultColorPalette("2B" // Numkeys 
												  "FFFFFF" // ColorPatternNote // ColorPatternNote
												  "807F8C" // ColorPatternInstrument // ColorPatternInstrument
												  "A7C9F1" // ColorPatternVolume // ColorPatternVolume
												  "00A1FF" // ColorPatternEffect // ColorPatternEffect
												  "7F7F80" // ColorPatternOperand // ColorPatternOperand
												  "647278" // ColorCursor // ColorCursor
												  "202020" // ColorCursorLine // ColorCursorLine
												  "A01830" // ColorCursorLineHighlighted // ColorCursorLineHighlighted
												  "646B6B" // ColorTheme // ColorTheme
												  "C2C2C2" // ColorForegroundText // ColorForegroundText
												  "464949" // ColorButtons // ColorButtons
												  "B5AEAE" // ColorButtonText // ColorButtonText
												  "6B7286" // ColorSelection // ColorSelection
												  "2E2E2E" // ColorListBoxBackground // ColorListBoxBackground
												  "103060" // ColorPatternSelection // ColorPatternSelection
												  "6B7286" // Hilighted text // Hilighted text
												  "B5A7AE" // Scopes // Scopes
												  "FFFFFF" // Hilighted rows (secondary) // Hilighted rows (secondary)
												  "202120" // Row highlight background (primary) // Row highlight background (primary)
												  "101000" // Row highlight background (secondary) // Row highlight background (secondary)
												  "000000" // ColorScrollBarBackground // ColorScrollBarBackground
												  "FF0000" // ColorRecordModeButtonText // ColorRecordModeButtonText
												  "FF0000" // Scopes record indicator // Scopes record indicator
												  "FF0000" // Peak clip indicator // Peak clip indicator
												  "00A1FF" // Sample Editor Waveform
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0");

//"28"
//"FFFFFF"
//"807F8C"
//"A7C9F1"
//"FF57AE"
//"7F7F80"
//"8C5DFF"
//"001A14"
//"A01830"
//"646B6B"
//"C2C2C2"
//"464949"
//"B5AEAE"
//"8C8CD0"
//"2E2E2E"
//"103060"
//"BBAEFF"
//"B5A7AE"
//"FFFFFF"
//"202120"
//"101000"
//"000000"
//"FF0000"
//"FF0000"
//"FF0000"
//"00A1FF"
//"5B0040"
//"3B0040"
//"3B0040"
//"3B0040"

const char* TrackerConfig::predefinedColorPalettes[TrackerConfig::numPredefinedColorPalettes] =                // Current last color start in the line of this comment marker
{
// default
//"28FFFFFF807F8CA7C9F1FF57AE7F7F808C5DFF001A14A01830646B6BC2C2C2464949B5AEAE8C8CD02E2E2E103060BBAEFFB5A7AEFFFFFF202120101000000000FF0000FF0000FF000000A1FF5B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B0040"
"2BFFFFFF80E0FF80FF80FF80E0FFE0808080FF602040A01830406080FFFFFFC0C0C00000008080FF282849103060FFFF00FFFFFFFFFF80202020101010203040FF0000FF0000FF0000FFFF803B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B0040",
// bluish
"2BFFFFFF7FB5FFA7DDFF00B5FF7FFFFF0000593F5A7F8618C9405DA7FFFFFFC0C0C000000080B5FF18183A103060FFFF00FFFFFFFFFF8020202010101018183AFF0000FF0000FF0000FFFF805B00205B00205B00205B00205B00205B00205B00205B00205B00205B00205B00205B00205B00205B00205B00205B00205B00205B0020",
// nice one
"2BFFFFFFFFD6D6FFFFFFFFD6D6FFFFFF21140D6B5F57C2355D937F8CFFFFFFA6A6A6000000D6C2C92C242C605060FFFF00FFFFFFFFFF802020201010102C242CFF0000FF0000FF0000FFFF803B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B0040",
// rusty
"2BFFFFFFDDD0DDFFD0DDC9B5D0C2A7C22114217F647F785743403549FFFFFF7F737F000000937F8C202030403040FFFF00FFFFFFFFFF80202020101010202030FF0000FF0000FF0000FFFF809B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E0",
// greeny
"2B28D0E480E0FF80FF80FFB50078E080005D35506B2EA01830407843FFFFFFC0C0C000000035B56414281A106030FFFF00FFFFFFFFFF8020202010101014281AFF0000FF0000FF0000FFFF801B00601B00601B00601B00601B00601B00601B00601B00601B00601B00601B00601B00601B00601B00601B00601B00601B00601B0060",
// red one
"2BFFFFFFFF9393E45000FFA786FF5780350000602114A01830570028FFFFFFC0C0C00000007D0000200000500010FFFF00FFFFFFFFFF80202020101010200000FF0000FF0000FF0000FFFF809B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E0"
};


const PPSystemString TrackerConfig::untitledSong("Untitled");

const pp_int32 TrackerConfig::numMixFrequencies = 4;
const pp_int32 TrackerConfig::mixFrequencies[] = {22050, 32000, 44100, 48000};

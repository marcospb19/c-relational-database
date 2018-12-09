#ifndef COLORS_H
#define COLORS_H

// colors.c has functions that change the output font color, and background color


// Reset the font color and background, if changed
void colorReset();

// Regular and colored font
void colorBlack();	// Black
void colorRed();	// Red
void colorGreen();	// Green
void colorYellow();	// Yellow
void colorBlue();	// Blue
void colorPurple();	// Purple
void colorCyan();	// Cyan
void colorWhite();	// White

// Bold and colored font
void colorBoldBlack();	// Bold Black
void colorBoldRed();	// Bold Red
void colorBoldGreen();	// Bold Green
void colorBoldYellow();	// Bold Yellow
void colorBoldBlue();	// Bold Blue
void colorBoldPurple();	// Bold Purple
void colorBoldCyan();	// Bold Cyan
void colorBoldWhite();	// Bold White

// White font with colored background in terminal
void colorBackgroundBlack();	// Black Background
void colorBackgroundRed();		// Red Background
void colorBackgroundGreen();	// Green Background
void colorBackgroundYellow();	// Yellow Background
void colorBackgroundBlue();		// Blue Background
void colorBackgroundPurple();	// Purple Background
void colorBackgroundCyan();		// Cyan Background
void colorBackgroundWhite();	// White Background

#endif

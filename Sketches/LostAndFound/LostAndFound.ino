/*
  Lost And Found
  Version 1.0
  Created 2014-06-19 J.G. Wezensky
  MIT License
  
  Based on the "automatic typer" this sketch will attempt to start Notepad and then
  print out a pre-defined text document on the keyboard.  The program will wait 5 seconds after 
  being plugged in and then begin.  When it is finished, it will wait one minute, then repeat the cycle.
*/
#include "DigiKeyboard.h"
#include <avr/pgmspace.h>

const int max_line_length = 80;

const int line_count = 15;

prog_char line_0[] PROGMEM = "Hello.";
prog_char line_1[] PROGMEM = "Thank you for plugging me into a computer.";
prog_char line_2[] PROGMEM = " ";
prog_char line_3[] PROGMEM = "You have found the emergency information required to return these items.";
prog_char line_4[] PROGMEM = " ";
prog_char line_5[] PROGMEM = "Please contact Hannover at han@mail.com or (555)555-5555";
prog_char line_6[] PROGMEM = " ";
prog_char line_7[] PROGMEM = "Or please return to ";
prog_char line_8[] PROGMEM = " ";
prog_char line_9[] PROGMEM = "Hannover Woods";
prog_char line_10[] PROGMEM = "1234 Main Street";
prog_char line_11[] PROGMEM = "Fodrolrevo, Tx   77555";
prog_char line_12[] PROGMEM = " ";
prog_char line_13[] PROGMEM = "Thank you.";
prog_char line_14[] PROGMEM = "(Message will repeat in 60 seconds)";

PROGMEM const char *output_text[] = 
{
  line_0,
  line_1,
  line_2,
  line_3,
  line_4,
  line_5,
  line_6,
  line_7,
  line_8,
  line_9,
  line_10,
  line_11,
  line_12,
  line_13,
  line_14
};

char buffer[max_line_length + 1];

void setup() 
{
}

void loop() 
{  
  // five second delay
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(5000);

  // start notepad
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.println("notepad");
  DigiKeyboard.delay(1500);

  // type out the message
  int i;
  for (i=0; i<line_count; i++)
  {
    strcpy_P(buffer, (char *)pgm_read_word(&(output_text[i])));
    DigiKeyboard.println(buffer);
    DigiKeyboard.delay(1000);
  }  

  // 60 second delay
  DigiKeyboard.delay(60000);
}




// Pins for each of the faces
#define F_FACE_PIN 5
#define R_FACE_PIN 6
#define U_FACE_PIN 9
#define L_FACE_PIN 10
#define B_FACE_PIN 11
#define D_FACE_PIN 12

// Import libraries
// #include <Adafruit_NeoPXL8.h> Not using neopxl8
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>


Adafruit_NeoMatrix f = Adafruit_NeoMatrix(6, 6, 3, 3, F_FACE_PIN,  // 6x6 for each panel, 3x3 for each face
  NEO_MATRIX_TOP    +   NEO_MATRIX_RIGHT +          // First pixel is @ top right
  NEO_MATRIX_ROWS   +   NEO_MATRIX_PROGRESSIVE +    // Rows loop back around the back of the board
  NEO_TILE_TOP      +   NEO_TILE_RIGHT +            // First board is @ top right
  NEO_TILE_ROWS     +   NEO_TILE_PROGRESSIVE,       // Rows loop back around the back of the board
  NEO_GRB           +   NEO_KHZ800                  // Standard Neopixel wiring
);

Adafruit_NeoMatrix r = Adafruit_NeoMatrix(6, 6, 3, 3, R_FACE_PIN,  // 6x6 for each panel, 3x3 for each face
  NEO_MATRIX_TOP    +   NEO_MATRIX_RIGHT +          // First pixel is @ top right
  NEO_MATRIX_ROWS   +   NEO_MATRIX_PROGRESSIVE +    // Rows loop back around the back of the board
  NEO_TILE_TOP      +   NEO_TILE_RIGHT +            // First board is @ top right
  NEO_TILE_ROWS     +   NEO_TILE_PROGRESSIVE,       // Rows loop back around the back of the board
  NEO_GRB           +   NEO_KHZ800                  // Standard Neopixel wiring
);
Adafruit_NeoMatrix u = Adafruit_NeoMatrix(6, 6, 3, 3, U_FACE_PIN,  // 6x6 for each panel, 3x3 for each face
  NEO_MATRIX_TOP    +   NEO_MATRIX_RIGHT +          // First pixel is @ top right
  NEO_MATRIX_ROWS   +   NEO_MATRIX_PROGRESSIVE +    // Rows loop back around the back of the board
  NEO_TILE_TOP      +   NEO_TILE_RIGHT +            // First board is @ top right
  NEO_TILE_ROWS     +   NEO_TILE_PROGRESSIVE,       // Rows loop back around the back of the board
  NEO_GRB           +   NEO_KHZ800                  // Standard Neopixel wiring
);
Adafruit_NeoMatrix l = Adafruit_NeoMatrix(6, 6, 3, 3, L_FACE_PIN,  // 6x6 for each panel, 3x3 for each face
  NEO_MATRIX_TOP    +   NEO_MATRIX_RIGHT +          // First pixel is @ top right
  NEO_MATRIX_ROWS   +   NEO_MATRIX_PROGRESSIVE +    // Rows loop back around the back of the board
  NEO_TILE_TOP      +   NEO_TILE_RIGHT +            // First board is @ top right
  NEO_TILE_ROWS     +   NEO_TILE_PROGRESSIVE,       // Rows loop back around the back of the board
  NEO_GRB           +   NEO_KHZ800                  // Standard Neopixel wiring
);
Adafruit_NeoMatrix b = Adafruit_NeoMatrix(6, 6, 3, 3, B_FACE_PIN,  // 6x6 for each panel, 3x3 for each face
  NEO_MATRIX_TOP    +   NEO_MATRIX_RIGHT +          // First pixel is @ top right
  NEO_MATRIX_ROWS   +   NEO_MATRIX_PROGRESSIVE +    // Rows loop back around the back of the board
  NEO_TILE_TOP      +   NEO_TILE_RIGHT +            // First board is @ top right
  NEO_TILE_ROWS     +   NEO_TILE_PROGRESSIVE,       // Rows loop back around the back of the board
  NEO_GRB           +   NEO_KHZ800                  // Standard Neopixel wiring
);
Adafruit_NeoMatrix d = Adafruit_NeoMatrix(6, 6, 3, 3, D_FACE_PIN,  // 6x6 for each panel, 3x3 for each face
  NEO_MATRIX_TOP    +   NEO_MATRIX_RIGHT +          // First pixel is @ top right
  NEO_MATRIX_ROWS   +   NEO_MATRIX_PROGRESSIVE +    // Rows loop back around the back of the board
  NEO_TILE_TOP      +   NEO_TILE_RIGHT +            // First board is @ top right
  NEO_TILE_ROWS     +   NEO_TILE_PROGRESSIVE,       // Rows loop back around the back of the board
  NEO_GRB           +   NEO_KHZ800                  // Standard Neopixel wiring
);

long start;
long end_time;




// SETUP FUNCTION----------------------------------
void setup() {
	f.begin();
    r.begin();
    u.begin();
    l.begin();
    b.begin();
    d.begin();
	//strip.setBrightness(64); // 1/4 brightness
    Serial.begin(9600);
}
// END SETUP FUNCTION------------------------------






// LOOP FUNCTION-----------------------------------
void loop() {
	
    for (byte i=0;i<255;i++) {
        start = micros();
        f.fill(Wheel(i));
        r.fill(Wheel(i));
        u.fill(Wheel(i));
        l.fill(Wheel(i));
        b.fill(Wheel(i));
        d.fill(Wheel(i));
        f.show();
        r.show();
        u.show();
        l.show();
        b.show();
        d.show();
        end_time = micros();
        Serial.println(end_time - start);
    }

	
}
// END LOOP FUNCTION-------------------------------


// RESULTS: 6000 - 7000 microseconds per loop
// This translates to 6-7 milliseconds per loop, or 167 updates per second. Probably fine.




// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos)
{
    WheelPos = 255 - WheelPos;
    if(WheelPos < 85)
    {
        return f.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    }
    else if(WheelPos < 170)
    {
        WheelPos -= 85;
        return f.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
    else
    {
        WheelPos -= 170;
        return f.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
    }
}
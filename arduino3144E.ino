// 
// https://github.com/sunnybank101/BellTower
// 
// ===================================================
// BELL RINGING 3144E Hall Effect SENSOR MONITOR
// ===================================================

// how many bells is this device running?
#define BELLCOUNT 8

// handle electrical bounce - only process bell changes with more than 100ms separation
#define BELL_DEBOUNCE_TIME 100

// setup pins for each of the possible 8 bells


// Arduino Nano
#define BELL1_PIN 2
#define BELL2_PIN 3
#define BELL3_PIN 4
#define BELL4_PIN 5
#define BELL5_PIN 6
#define BELL6_PIN 7
#define BELL7_PIN 8
#define BELL8_PIN 9

/*
// ESP32
#define BELL1_PIN 13  // D G 13
#define BELL2_PIN 12  // D G 12
#define BELL3_PIN 14  // D G 14
#define BELL4_PIN 27  // D G 27
#define BELL5_PIN 26  // D G 26
#define BELL6_PIN 25  // D G 25
#define BELL7_PIN 33  // D G 33
#define BELL8_PIN 32  // D G 32
*/

// put the pins in an array for easy processing in a loop
short BELL_PIN[] = {BELL1_PIN, BELL2_PIN, BELL3_PIN, BELL4_PIN, BELL5_PIN, BELL6_PIN, BELL7_PIN, BELL8_PIN };

// new/current state of each bell
short BELL_state[] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};

// previous state of each bell - ready to look for changes
short BELL_oldstate[] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};

// time of the last state change for each bell - to debounce bell signals
long  BELL_ms[] = {0,0,0,0,0,0,0,0};

// ===================================================
// Called once at startup
// ===================================================
void setup()
{
  // standard bell sensors and ringing software use 2400 baud
  Serial.begin(2400);
  
  // setup each of the bell pins
  for( short b=0; b<BELLCOUNT; b++ )
    {
    // IR sensor as bell input
    pinMode(BELL_PIN[b], INPUT_PULLUP);
    }
  
  // let the pins settle
  delay( 200 );
  
  // setup each of the bell pins
  for( short b=0; b<BELLCOUNT; b++ )
    {
    // take an initial reading as a start point
    BELL_state[b] = digitalRead(BELL_PIN[b]);
    BELL_oldstate[b] = BELL_state[b];
    }
  
}

// ===================================================
// loop for ever..
// ===================================================
void loop()
{
  // loop thro the bells
  for( short b=0; b<BELLCOUNT; b++ )
    {
    // read each bell pin
    BELL_state[b] = digitalRead(BELL_PIN[b]);
    
    // is this a change of state?
    if( BELL_state[b] != BELL_oldstate[b] )
      {
      // check the debounce - is this too quick a change?
      if( (millis() - BELL_ms[b]) > BELL_DEBOUNCE_TIME )
        {
        // process this as a real bell state change
        // store the time now
        BELL_ms[b] = millis();
        // store the state as old ready for future comparisons
        BELL_oldstate[b] = BELL_state[b];
        
        // its a low pin meaning its time to pass on a bell ring msg
        if( BELL_state[b] == LOW ) 
          {
          // the bell msg is simply an ascii 1 digit number representing the bell number
          Serial.write('1'+b);
          }
        }
      }
    }
}

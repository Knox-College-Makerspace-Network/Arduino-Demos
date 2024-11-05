
class RGBLed {
  private:
    int redPin;
    int greenPin;
    int bluePin;

  public:
    // Constructor: Initialize the RGB LED pins
    RGBLed(int rPin, int gPin, int bPin) {
      redPin = rPin;
      greenPin = gPin;
      bluePin = bPin;
      
      // Set pin modes
      pinMode(redPin, OUTPUT);
      pinMode(greenPin, OUTPUT);
      pinMode(bluePin, OUTPUT);
    }

    // Method to set the color of the LED
    void setColor(int red, int green, int blue) {
      analogWrite(redPin, red);
      analogWrite(greenPin, green);
      analogWrite(bluePin, blue);
    }

    // Method to turn off the LED
    void off() {
      setColor(0, 0, 0);
    }
};





//setup leds on their respective pins

RGBLed led0(6,5,3);
RGBLed led1(11,10,9);
//holds the traffic state
int state = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);       // Start serial communication at 9600 baud rate

}

void loop() {
  // put your main code here, to run repeatedly:



  //checks if any new input is available
  if (Serial.available() > 0) {
      String command = Serial.readStringUntil('\n');  // Read input until newline
      command.trim();  // Remove any trailing newline or space characters
      if (command == "swap") {

        if (state == 1){
          state = 0;
          led1.setColor(255, 100, 0);
          delay(1000);

        }else if(state == 0){
          state = 1;
          led0.setColor(255,100, 0);
          delay(1000);

        }

        
      }
      

  }

  if (state == 0){
    led0.setColor(0,255,0);
    led1.setColor(255,0,0);
  }else if(state == 1){
    led0.setColor(255,0,0);
    led1.setColor(0,255,0);

  }
}


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


int r = 0;

RGBLed led0(6,5,3);
RGBLed led1(11,10,9);

void setup() {
  // put your setup code here, to run once:

}

void loop() {

  led0.setColor(r, 0, 0);
  led1.setColor(r, 0, 0);
  r +=1;
  if (r>=255){
    r=0;
  }
  delay(8);
  // put your main code here, to run repeatedly:

}

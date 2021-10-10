#include <iarduino_RTC.h>
#include <iarduino_RTC_DS3231.h>
#include <Adafruit_NeoPixel.h>
iarduino_RTC time(RTC_DS3231);

#define LED_PIN 6
#define NUMPIXELS 114
#define BRIGHTNESS 255

#define PIN_button_UP1 7
#define PIN_button_UP5 8
#define PIN_button_UP1H 9
#define PIN_button_Reset 10

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LED_PIN, NEO_GRBW + NEO_KHZ800);

// RGBW color
int red = 0;
int green = 0;
int blue = 0;
int white = 255;

bool l_m_status_1 = 0;
bool l_m_status_2 = 0;
bool l_m_status_3 = 0;
bool l_m_status_4 = 0;
bool l_m_status_5 = 0;
bool l_m_status_plus_5 = 0;
bool l_m_status_10 = 0;
bool l_m_status_15 = 0;
bool l_m_status_20 = 0;
bool l_m_status_30 = 0;
bool l_m_status_40 = 0;
bool l_m_status_50 = 0;

bool l_h_status_1 = 0;
bool l_h_status_2 = 0;
bool l_h_status_3 = 0;
bool l_h_status_4 = 0;
bool l_h_status_5 = 0;
bool l_h_status_6 = 0;
bool l_h_status_7 = 0;
bool l_h_status_8 = 0;
bool l_h_status_9 = 0;
bool l_h_status_10 = 0;
bool l_h_status_11 = 0;
bool l_h_status_12 = 0;

void setup()
{
  pinMode(PIN_button_UP1, OUTPUT);
  pinMode(PIN_button_UP5, OUTPUT);
  pinMode(PIN_button_UP1H, OUTPUT);
  pinMode(PIN_button_Reset, OUTPUT);

  pixels.begin();     
  Serial.begin(9600); 
  time.begin();
}

void loop()
{
  pixels.setBrightness(BRIGHTNESS);
  time.gettime("h:i:s");

  pixels.setPixelColor(0, pixels.Color(red, green, blue, white)); //с
  pixels.setPixelColor(1, pixels.Color(red, green, blue, white)); //е
  pixels.setPixelColor(2, pixels.Color(red, green, blue, white)); //й
  pixels.setPixelColor(3, pixels.Color(red, green, blue, white)); //ч
  pixels.setPixelColor(4, pixels.Color(red, green, blue, white)); //а
  pixels.setPixelColor(5, pixels.Color(red, green, blue, white)); //с

  int individualPixels[NUMPIXELS] =
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0};

  // one dotted light
  if ((time.minutes >= 1 && time.minutes <= 4) || (time.minutes >= 6 && time.minutes <= 9) ||
      (time.minutes >= 11 && time.minutes <= 14) || (time.minutes >= 16 && time.minutes <= 19) ||
      (time.minutes >= 21 && time.minutes <= 24) || (time.minutes >= 26 && time.minutes <= 29) ||
      (time.minutes >= 31 && time.minutes <= 34) || (time.minutes >= 36 && time.minutes <= 39) ||
      (time.minutes >= 41 && time.minutes <= 44) || (time.minutes >= 46 && time.minutes <= 49) ||
      (time.minutes >= 51 && time.minutes <= 54) || (time.minutes >= 56 && time.minutes <= 59))
  {
    OneDottedLedOn();
  }

  // two dotted light
  if ((time.minutes >= 2 && time.minutes <= 4) || (time.minutes >= 7 && time.minutes <= 9) ||
      (time.minutes >= 12 && time.minutes <= 14) || (time.minutes >= 17 && time.minutes <= 19) ||
      (time.minutes >= 22 && time.minutes <= 24) || (time.minutes >= 27 && time.minutes <= 29) ||
      (time.minutes >= 32 && time.minutes <= 34) || (time.minutes >= 37 && time.minutes <= 39) ||
      (time.minutes >= 42 && time.minutes <= 44) || (time.minutes >= 47 && time.minutes <= 49) ||
      (time.minutes >= 52 && time.minutes <= 54) || (time.minutes >= 57 && time.minutes <= 59))
  {
    TwoDottedLedOn();
  }

  // three dotted light
  if ((time.minutes >= 3 && time.minutes <= 4) || (time.minutes >= 8 && time.minutes <= 9) ||
      (time.minutes >= 13 && time.minutes <= 14) || (time.minutes >= 18 && time.minutes <= 19) ||
      (time.minutes >= 23 && time.minutes <= 24) || (time.minutes >= 28 && time.minutes <= 29) ||
      (time.minutes >= 33 && time.minutes <= 34) || (time.minutes >= 38 && time.minutes <= 39) ||
      (time.minutes >= 43 && time.minutes <= 44) || (time.minutes >= 48 && time.minutes <= 49) ||
      (time.minutes >= 53 && time.minutes <= 54) || (time.minutes >= 58 && time.minutes <= 59))
  {
    ThreeDottedLedOn();
  }

  // four dotted light
  if ((time.minutes >= 4 && time.minutes <= 4) || (time.minutes >= 9 && time.minutes <= 9) ||
      (time.minutes >= 14 && time.minutes <= 14) || (time.minutes >= 19 && time.minutes <= 19) ||
      (time.minutes >= 24 && time.minutes <= 24) || (time.minutes >= 29 && time.minutes <= 29) ||
      (time.minutes >= 34 && time.minutes <= 34) || (time.minutes >= 39 && time.minutes <= 39) ||
      (time.minutes >= 44 && time.minutes <= 44) || (time.minutes >= 49 && time.minutes <= 49) ||
      (time.minutes >= 54 && time.minutes <= 54) || (time.minutes >= 59 && time.minutes <= 59))
  {
    FourDottedLedOn();
  }
  else
  {
    FourDottedLedOff();
  }

  // five minut light
  if (time.minutes >= 5 && time.minutes <= 9)
  {
    FiveLedOn();
  }
  else
  {
    FiveLedOff();
  }

  // ten minut light
  if (time.minutes >= 10 && time.minutes <= 14)
  {
    TenLedOn();
  }
  else
  {
    TenLedOff();
  }

  // fifteen minut light
  if (time.minutes >= 15 && time.minutes <= 19)
  {
    FifteenLedOn();
  }
  else
  {
    FifteenLedOff();
  }

  //twenty minut light
  if (time.minutes >= 20 && time.minutes <= 29)
  {
    TwentyLedOn();
  }
  else
  {
    TwentyLedOff();
  }

  // thirty minut light
  if (time.minutes >= 30 && time.minutes <= 39)
  {
    ThirtyLedOn();
  }
  else
  {
    ThirtyLedOff();
  }
  // forty minut light
  if (time.minutes >= 40 && time.minutes <= 49)
  {
    FortyLedOn();
  }
  else
  {
    FortyLedOff();
  }

  // fifty minut light
  if (time.minutes >= 50 && time.minutes <= 59)
  {
    FiftyLedOn();
  }
  else
  {
    FiftyLedOff();
  }

  // +five minut light
  if ((time.minutes >= 25 && time.minutes <= 29) ||
      (time.minutes >= 35 && time.minutes <= 39) ||
      (time.minutes >= 45 && time.minutes <= 49) ||
      (time.minutes >= 55 && time.minutes <= 59))
  {

    PlusFiveLedOn();
  }


  if (time.hours == 1)
  {
    OneHourLedOn();
  }
  else
  {
    OneHourLedOff();
  }

  if (time.hours == 2)
  {
    TwoHourLedOn();
  }
  else
  {
    TwoHourLedOff();
  }

  if (time.hours == 3)
  {
    ThreeHourLedOn();
  }
  else
  {
    ThreeHourLedOff();
  }

  if (time.hours == 4)
  {
    FourHourLedOn();
  }
  else
  {
    FourHourLedOff();
  }

  if (time.hours == 5)
  {
    FiveHourLedOn();
  }
  else
  {
    FiveHourLedOff();
  }

  if (time.hours == 6)
  {
    SixHourLedOn();
  }
  else
  {
    SixHourLedOff();
  }

  if (time.hours == 7)
  {
    SevenHourLedOn();
  }
  else
  {
    SevenHourLedOff();
  }

  if (time.hours == 8)
  {
    EightHourLedOn();
  }
  else
  {
    EightHourLedOff();
  }

  if (time.hours == 9)
  {
    NineHourLedOn();
  }
  else
  {
    NineHourLedOff();
  }

  if (time.hours == 10)
  {
    TenHourLedOn();
  }
  else
  {
    TenHourLedOff();
  }

  if (time.hours == 11)
  {
    ElevenHourLedOn();
  }
  else
  {
    ElevenHourLedOff();
  }

  if (time.hours == 12)
  {
    TwelveHourLedOn();
  }
  else
  {
    TwelveHourLedOff();
  }

  Func_buttons_control();
}
void Func_buttons_control()
{

  if (digitalRead(PIN_button_UP1))
  {
    while (digitalRead(PIN_button_UP1))
    {
      delay(50);
    }

    time.settime(0, (time.minutes == 59 ? 0 : time.minutes + 1), -1, -1, -1, -1, -1);
  }

  if (digitalRead(PIN_button_UP5))
  {
    while (digitalRead(PIN_button_UP5))
    {
      delay(50);
    }

    time.settime(-1, (time.minutes == 60 ? 0 : time.minutes + 5), -1, -1, -1, -1, -1);
  }

  if (digitalRead(PIN_button_UP1H))
  {
    while (digitalRead(PIN_button_UP1H))
    {
      delay(50);
    }

    time.settime(-1, -1, (time.Hours == 23 ? 0 : time.Hours + 1), -1, -1, -1, -1);
  }

  if (digitalRead(PIN_button_Reset))
  {
    while (digitalRead(PIN_button_Reset))
    {
      delay(50);
    }

    time.settime(0, 0, 0, 0, 0, 0, 0);

    delay(5);
  }
}

void OneDottedLedOn()
{
  if (l_m_status_1 == 0)
  {
    for (int l = 0; l <= white; l += 1)
    {
      pixels.setPixelColor(110, pixels.Color(red, green, blue, l));
      pixels.show();
      l_m_status_1 = 1;
    }
  }
}

void TwoDottedLedOn()
{
  if (l_m_status_2 == 0)
  {
    for (int l = 0; l <= white; l += 1)
    {
      pixels.setPixelColor(111, pixels.Color(red, green, blue, l));
      pixels.show();
      l_m_status_2 = 1;
    }
  }
}

void ThreeDottedLedOn()
{
  if (l_m_status_3 == 0)
  {
    for (int l = 0; l <= white; l += 1)
    {
      pixels.setPixelColor(112, pixels.Color(red, green, blue, l));
      pixels.show();
      l_m_status_3 = 1;
    }
  }
}

void FourDottedLedOn()
{
  if (l_m_status_4 == 0)
  {
    for (int l = 0; l <= white; l += 1)
    {
      pixels.setPixelColor(113, pixels.Color(red, green, blue, l));
      pixels.show();
      l_m_status_4 = 1;
    }
  }
}

void FourDottedLedOff()
{
  if (l_m_status_4 == 1)
  {
    for (int l = white; l >= 0; l -= 1)
    {
      pixels.setPixelColor(110, pixels.Color(0, 0, 0, l));
      pixels.setPixelColor(111, pixels.Color(0, 0, 0, l));
      pixels.setPixelColor(112, pixels.Color(0, 0, 0, l));
      pixels.setPixelColor(113, pixels.Color(0, 0, 0, l));
      pixels.show();

      l_m_status_1 = 0;
      l_m_status_2 = 0;
      l_m_status_3 = 0;
      l_m_status_4 = 0;
    }
  }
}

void FiveLedOn()
{
  if (l_m_status_5 == 0)
  {
    delay(300);
    for (int l = 0; l <= white; l += 1)
    {

      pixels.setPixelColor(109, pixels.Color(red, green, blue, l)); //п
      pixels.setPixelColor(108, pixels.Color(red, green, blue, l)); //я
      pixels.setPixelColor(107, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(106, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(103, pixels.Color(red, green, blue, l)); //м
      pixels.setPixelColor(102, pixels.Color(red, green, blue, l)); //и
      pixels.setPixelColor(101, pixels.Color(red, green, blue, l)); //н
      pixels.setPixelColor(100, pixels.Color(red, green, blue, l)); //у
      pixels.setPixelColor(99, pixels.Color(red, green, blue, l));  //т
      l_m_status_5 = 1;
      pixels.show();
    }
  }
}

void FiveLedOff()
{
  if (l_m_status_5 == 1)
  {
    for (int l = white; l >= 0; l -= 1)
    {

      pixels.setPixelColor(109, pixels.Color(0, 0, 0, l)); //п
      pixels.setPixelColor(108, pixels.Color(0, 0, 0, l)); //я
      pixels.setPixelColor(107, pixels.Color(0, 0, 0, l)); //т
      pixels.setPixelColor(106, pixels.Color(0, 0, 0, l)); //ь

      pixels.setPixelColor(103, pixels.Color(0, 0, 0, l)); //м
      pixels.setPixelColor(102, pixels.Color(0, 0, 0, l)); //и
      pixels.setPixelColor(101, pixels.Color(0, 0, 0, l)); //н
      pixels.setPixelColor(100, pixels.Color(0, 0, 0, l)); //у
      pixels.setPixelColor(99, pixels.Color(0, 0, 0, l));  //т
      l_m_status_5 = 0;

      pixels.show();
    }
  }
}

void TenLedOn()
{
  if (l_m_status_10 == 0)
  {
    delay(100);
    for (int l = 0; l <= white; l += 1)
    {

      pixels.setPixelColor(89, pixels.Color(red, green, blue, l));  //д
      pixels.setPixelColor(90, pixels.Color(red, green, blue, l));  //е
      pixels.setPixelColor(91, pixels.Color(red, green, blue, l));  //с
      pixels.setPixelColor(108, pixels.Color(red, green, blue, l)); //я
      pixels.setPixelColor(107, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(106, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(103, pixels.Color(red, green, blue, l)); //м
      pixels.setPixelColor(102, pixels.Color(red, green, blue, l)); //и
      pixels.setPixelColor(101, pixels.Color(red, green, blue, l)); //н
      pixels.setPixelColor(100, pixels.Color(red, green, blue, l)); //у
      pixels.setPixelColor(99, pixels.Color(red, green, blue, l));  //т
      l_m_status_10 = 1;
      pixels.show();
    }
  }
}

void TenLedOff()
{
  if (l_m_status_10 == 1)
  {

    for (int l = white; l >= 0; l -= 1)
    {

      pixels.setPixelColor(89, pixels.Color(0, 0, 0, l));  //д
      pixels.setPixelColor(90, pixels.Color(0, 0, 0, l));  //е
      pixels.setPixelColor(91, pixels.Color(0, 0, 0, l));  //с
      pixels.setPixelColor(108, pixels.Color(0, 0, 0, l)); //я
      pixels.setPixelColor(107, pixels.Color(0, 0, 0, l)); //т
      pixels.setPixelColor(106, pixels.Color(0, 0, 0, l)); //ь

      pixels.setPixelColor(103, pixels.Color(0, 0, 0, l)); //м
      pixels.setPixelColor(102, pixels.Color(0, 0, 0, l)); //и
      pixels.setPixelColor(101, pixels.Color(0, 0, 0, l)); //н
      pixels.setPixelColor(100, pixels.Color(0, 0, 0, l)); //у
      pixels.setPixelColor(99, pixels.Color(0, 0, 0, l));  //т

      l_m_status_10 = 0;
      delay(1);
      pixels.show();
    }
  }
}

void FifteenLedOn()
{
  if (l_m_status_15 == 0)
  {
    delay(100);
    for (int l = 0; l <= white; l += 1)
    {
      pixels.setPixelColor(87, pixels.Color(red, green, blue, l)); //п
      pixels.setPixelColor(86, pixels.Color(red, green, blue, l)); //я
      pixels.setPixelColor(85, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(84, pixels.Color(red, green, blue, l)); //н
      pixels.setPixelColor(83, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(82, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(81, pixels.Color(red, green, blue, l)); //ц
      pixels.setPixelColor(80, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(79, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(78, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(103, pixels.Color(red, green, blue, l)); //м
      pixels.setPixelColor(102, pixels.Color(red, green, blue, l)); //и
      pixels.setPixelColor(101, pixels.Color(red, green, blue, l)); //н
      pixels.setPixelColor(100, pixels.Color(red, green, blue, l)); //у
      pixels.setPixelColor(99, pixels.Color(red, green, blue, l));  //т

      l_m_status_15 = 1;
      pixels.show();
    }
  }
}

void FifteenLedOff()
{
  if (l_m_status_15 == 1)
  {
    for (int l = white; l >= 0; l -= 1)
    {

      pixels.setPixelColor(87, pixels.Color(0, 0, 0, l)); //п
      pixels.setPixelColor(86, pixels.Color(0, 0, 0, l)); //я
      pixels.setPixelColor(85, pixels.Color(0, 0, 0, l)); //т
      pixels.setPixelColor(84, pixels.Color(0, 0, 0, l)); //н
      pixels.setPixelColor(83, pixels.Color(0, 0, 0, l)); //а
      pixels.setPixelColor(82, pixels.Color(0, 0, 0, l)); //д
      pixels.setPixelColor(81, pixels.Color(0, 0, 0, l)); //ц
      pixels.setPixelColor(80, pixels.Color(0, 0, 0, l)); //а
      pixels.setPixelColor(79, pixels.Color(0, 0, 0, l)); //т
      pixels.setPixelColor(78, pixels.Color(0, 0, 0, l)); //ь

      pixels.setPixelColor(103, pixels.Color(0, 0, 0, l)); //м
      pixels.setPixelColor(102, pixels.Color(0, 0, 0, l)); //и
      pixels.setPixelColor(101, pixels.Color(0, 0, 0, l)); //н
      pixels.setPixelColor(100, pixels.Color(0, 0, 0, l)); //у
      pixels.setPixelColor(99, pixels.Color(0, 0, 0, l));  //т
      l_m_status_15 = 0;
      pixels.show();
    }
  }
}

void TwentyLedOn()
{
  if (l_m_status_20 == 0)
  {
    delay(100);
    for (int l = 0; l <= white; l += 1)
    {
      pixels.setPixelColor(71, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(72, pixels.Color(red, green, blue, l)); //в
      pixels.setPixelColor(73, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(82, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(81, pixels.Color(red, green, blue, l)); //ц
      pixels.setPixelColor(80, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(79, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(78, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(103, pixels.Color(red, green, blue, l)); //м
      pixels.setPixelColor(102, pixels.Color(red, green, blue, l)); //и
      pixels.setPixelColor(101, pixels.Color(red, green, blue, l)); //н
      pixels.setPixelColor(100, pixels.Color(red, green, blue, l)); //у
      pixels.setPixelColor(99, pixels.Color(red, green, blue, l));  //т

      l_m_status_20 = 1;
      pixels.show();
    }
  }
}

void TwentyLedOff()
{
  if (l_m_status_20 == 1)
  {
    for (int l = white; l >= 0; l -= 1)
    {
      pixels.setPixelColor(71, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(72, pixels.Color(red, green, blue, l)); //в
      pixels.setPixelColor(73, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(82, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(81, pixels.Color(red, green, blue, l)); //ц
      pixels.setPixelColor(80, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(79, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(78, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(103, pixels.Color(0, 0, 0, l)); //м
      pixels.setPixelColor(102, pixels.Color(0, 0, 0, l)); //и
      pixels.setPixelColor(101, pixels.Color(0, 0, 0, l)); //н
      pixels.setPixelColor(100, pixels.Color(0, 0, 0, l)); //у
      pixels.setPixelColor(99, pixels.Color(0, 0, 0, l));  //т

      pixels.setPixelColor(109, pixels.Color(0, 0, 0, l)); //п
      pixels.setPixelColor(108, pixels.Color(0, 0, 0, l)); //я
      pixels.setPixelColor(107, pixels.Color(0, 0, 0, l)); //т
      pixels.setPixelColor(106, pixels.Color(0, 0, 0, l)); //ь

      l_m_status_plus_5 = 0;
      l_m_status_20 = 0;
      pixels.show();
    }
  }
}

void ThirtyLedOn()
{
  if (l_m_status_30 == 0)
  {
    delay(100);
    for (int l = 0; l <= white; l += 1)
    {
      pixels.setPixelColor(74, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(75, pixels.Color(red, green, blue, l)); //р
      pixels.setPixelColor(76, pixels.Color(red, green, blue, l)); //и
      pixels.setPixelColor(82, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(81, pixels.Color(red, green, blue, l)); //ц
      pixels.setPixelColor(80, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(79, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(78, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(103, pixels.Color(red, green, blue, l)); //м
      pixels.setPixelColor(102, pixels.Color(red, green, blue, l)); //и
      pixels.setPixelColor(101, pixels.Color(red, green, blue, l)); //н
      pixels.setPixelColor(100, pixels.Color(red, green, blue, l)); //у
      pixels.setPixelColor(99, pixels.Color(red, green, blue, l));  //т

      l_m_status_30 = 1;
      pixels.show();
    }
  }
}

void ThirtyLedOff()
{
  if (l_m_status_30 == 1)
  {
    for (int l = white; l >= 0; l -= 1)
    {
      pixels.setPixelColor(74, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(75, pixels.Color(red, green, blue, l)); //р
      pixels.setPixelColor(76, pixels.Color(red, green, blue, l)); //и
      pixels.setPixelColor(82, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(81, pixels.Color(red, green, blue, l)); //ц
      pixels.setPixelColor(80, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(79, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(78, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(103, pixels.Color(0, 0, 0, l)); //м
      pixels.setPixelColor(102, pixels.Color(0, 0, 0, l)); //и
      pixels.setPixelColor(101, pixels.Color(0, 0, 0, l)); //н
      pixels.setPixelColor(100, pixels.Color(0, 0, 0, l)); //у
      pixels.setPixelColor(99, pixels.Color(0, 0, 0, l));  //т

      pixels.setPixelColor(109, pixels.Color(0, 0, 0, l)); //п
      pixels.setPixelColor(108, pixels.Color(0, 0, 0, l)); //я
      pixels.setPixelColor(107, pixels.Color(0, 0, 0, l)); //т
      pixels.setPixelColor(106, pixels.Color(0, 0, 0, l)); //ь

      l_m_status_plus_5 = 0;

      l_m_status_30 = 0;
      pixels.show();
    }
  }
}

void FortyLedOn()
{
  if (l_m_status_40 == 0)
  {
    delay(100);
    for (int l = 0; l <= white; l += 1)
    {
      pixels.setPixelColor(94, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(95, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(96, pixels.Color(red, green, blue, l)); //р
      pixels.setPixelColor(97, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(98, pixels.Color(red, green, blue, l)); //к

      pixels.setPixelColor(103, pixels.Color(red, green, blue, l)); //м
      pixels.setPixelColor(102, pixels.Color(red, green, blue, l)); //и
      pixels.setPixelColor(101, pixels.Color(red, green, blue, l)); //н
      pixels.setPixelColor(100, pixels.Color(red, green, blue, l)); //у
      pixels.setPixelColor(99, pixels.Color(red, green, blue, l));  //т

      l_m_status_40 = 1;
      pixels.show();
    }
  }
}

void FortyLedOff()
{
  if (l_m_status_40 == 1)
  {
    for (int l = white; l >= 0; l -= 1)
    {
      pixels.setPixelColor(94, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(95, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(96, pixels.Color(red, green, blue, l)); //р
      pixels.setPixelColor(97, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(98, pixels.Color(red, green, blue, l)); //к

      pixels.setPixelColor(103, pixels.Color(0, 0, 0, l)); //м
      pixels.setPixelColor(102, pixels.Color(0, 0, 0, l)); //и
      pixels.setPixelColor(101, pixels.Color(0, 0, 0, l)); //н
      pixels.setPixelColor(100, pixels.Color(0, 0, 0, l)); //у
      pixels.setPixelColor(99, pixels.Color(0, 0, 0, l));  //т

      pixels.setPixelColor(109, pixels.Color(0, 0, 0, l)); //п
      pixels.setPixelColor(108, pixels.Color(0, 0, 0, l)); //я
      pixels.setPixelColor(107, pixels.Color(0, 0, 0, l)); //т
      pixels.setPixelColor(106, pixels.Color(0, 0, 0, l)); //ь

      l_m_status_plus_5 = 0;

      l_m_status_40 = 0;
      pixels.show();
    }
  }
}

void FiftyLedOn()
{
  if (l_m_status_50 == 0)
  {
    delay(100);
    for (int l = 0; l <= white; l += 1)
    {
      pixels.setPixelColor(87, pixels.Color(red, green, blue, l)); //п
      pixels.setPixelColor(86, pixels.Color(red, green, blue, l)); //я
      pixels.setPixelColor(85, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(88, pixels.Color(red, green, blue, l)); //ь
      pixels.setPixelColor(89, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(90, pixels.Color(red, green, blue, l)); //е
      pixels.setPixelColor(91, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(92, pixels.Color(red, green, blue, l)); //я
      pixels.setPixelColor(93, pixels.Color(red, green, blue, l)); //т

      pixels.setPixelColor(103, pixels.Color(red, green, blue, l)); //м
      pixels.setPixelColor(102, pixels.Color(red, green, blue, l)); //и
      pixels.setPixelColor(101, pixels.Color(red, green, blue, l)); //н
      pixels.setPixelColor(100, pixels.Color(red, green, blue, l)); //у
      pixels.setPixelColor(99, pixels.Color(red, green, blue, l));  //т

      l_m_status_50 = 1;
      pixels.show();
    }
  }
}

void FiftyLedOff()
{
  if (l_m_status_50 == 1)
  {
    for (int l = white; l >= 0; l -= 1)
    {
      pixels.setPixelColor(87, pixels.Color(red, green, blue, l)); //п
      pixels.setPixelColor(86, pixels.Color(red, green, blue, l)); //я
      pixels.setPixelColor(85, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(88, pixels.Color(red, green, blue, l)); //ь
      pixels.setPixelColor(89, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(90, pixels.Color(red, green, blue, l)); //е
      pixels.setPixelColor(91, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(92, pixels.Color(red, green, blue, l)); //я
      pixels.setPixelColor(93, pixels.Color(red, green, blue, l)); //т

      pixels.setPixelColor(103, pixels.Color(0, 0, 0, l)); //м
      pixels.setPixelColor(102, pixels.Color(0, 0, 0, l)); //и
      pixels.setPixelColor(101, pixels.Color(0, 0, 0, l)); //н
      pixels.setPixelColor(100, pixels.Color(0, 0, 0, l)); //у
      pixels.setPixelColor(99, pixels.Color(0, 0, 0, l));  //т

      pixels.setPixelColor(109, pixels.Color(0, 0, 0, l)); //п
      pixels.setPixelColor(108, pixels.Color(0, 0, 0, l)); //я
      pixels.setPixelColor(107, pixels.Color(0, 0, 0, l)); //т
      pixels.setPixelColor(106, pixels.Color(0, 0, 0, l)); //ь

      l_m_status_plus_5 = 0;

      l_m_status_50 = 0;
      pixels.show();
    }
  }
}

void PlusFiveLedOn()
{
  if (l_m_status_plus_5 == 0)
  {
    delay(250);
    for (int l = 0; l <= white; l += 1)
    {

      pixels.setPixelColor(109, pixels.Color(red, green, blue, l)); //п
      pixels.setPixelColor(108, pixels.Color(red, green, blue, l)); //я
      pixels.setPixelColor(107, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(106, pixels.Color(red, green, blue, l)); //ь

      l_m_status_plus_5 = 1;
      pixels.show();
    }
  }
}

void OneHourLedOn()
{
  if (l_h_status_1 == 0)
  {
    delay(100);
    for (int l = 0; l <= white; l += 1)
    {
      pixels.setPixelColor(22, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(23, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(24, pixels.Color(red, green, blue, l)); //и
      pixels.setPixelColor(25, pixels.Color(red, green, blue, l)); //н

      pixels.setPixelColor(66, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(67, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(68, pixels.Color(red, green, blue, l)); //с

      l_h_status_1 = 1;
      pixels.show();
    }
  }
}

void OneHourLedOff()
{
  if (l_h_status_1 == 1)
  {
    //    delay (100);
    for (int l = white; l >= 0; l -= 1)
    {
      pixels.setPixelColor(22, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(23, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(24, pixels.Color(red, green, blue, l)); //и
      pixels.setPixelColor(25, pixels.Color(red, green, blue, l)); //н

      pixels.setPixelColor(66, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(67, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(68, pixels.Color(red, green, blue, l)); //с

      l_h_status_1 = 0;
      pixels.show();
    }
  }
}

void TwoHourLedOn()
{
  if (l_h_status_2 == 0)
  {
    delay(100);
    for (int l = 0; l <= white; l += 1)
    {
      pixels.setPixelColor(7, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(8, pixels.Color(red, green, blue, l)); //в
      pixels.setPixelColor(9, pixels.Color(red, green, blue, l)); //а

      pixels.setPixelColor(66, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(67, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(68, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(69, pixels.Color(red, green, blue, l)); //а

      l_h_status_2 = 1;
      pixels.show();
    }
  }
}

void TwoHourLedOff()
{
  if (l_h_status_2 == 1)
  {
    //    delay (100);
    for (int l = white; l >= 0; l -= 1)
    {
      pixels.setPixelColor(7, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(8, pixels.Color(red, green, blue, l)); //в
      pixels.setPixelColor(9, pixels.Color(red, green, blue, l)); //а

      pixels.setPixelColor(66, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(67, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(68, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(69, pixels.Color(red, green, blue, l)); //а

      l_h_status_2 = 0;
      pixels.show();
    }
  }
}

void ThreeHourLedOn()
{
  if (l_h_status_3 == 0)
  {
    delay(100);
    for (int l = 0; l <= white; l += 1)
    {
      pixels.setPixelColor(43, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(42, pixels.Color(red, green, blue, l)); //р
      pixels.setPixelColor(41, pixels.Color(red, green, blue, l)); //и

      pixels.setPixelColor(66, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(67, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(68, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(69, pixels.Color(red, green, blue, l)); //а

      l_h_status_3 = 1;
      pixels.show();
    }
  }
}

void ThreeHourLedOff()
{
  if (l_h_status_3 == 1)
  {
    //    delay (100);
    for (int l = white; l >= 0; l -= 1)
    {
      pixels.setPixelColor(43, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(42, pixels.Color(red, green, blue, l)); //р
      pixels.setPixelColor(41, pixels.Color(red, green, blue, l)); //и

      pixels.setPixelColor(66, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(67, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(68, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(69, pixels.Color(red, green, blue, l)); //а

      l_h_status_3 = 0;
      pixels.show();
    }
  }
}

void FourHourLedOn()
{
  if (l_h_status_4 == 0)
  {
    delay(100);
    for (int l = 0; l <= white; l += 1)
    {
      pixels.setPixelColor(21, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(20, pixels.Color(red, green, blue, l)); //е
      pixels.setPixelColor(19, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(18, pixels.Color(red, green, blue, l)); //ы
      pixels.setPixelColor(17, pixels.Color(red, green, blue, l)); //р
      pixels.setPixelColor(16, pixels.Color(red, green, blue, l)); //е

      pixels.setPixelColor(66, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(67, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(68, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(69, pixels.Color(red, green, blue, l)); //а

      l_h_status_4 = 1;
      pixels.show();
    }
  }
}

void FourHourLedOff()
{
  if (l_h_status_4 == 1)
  {
    //    delay (100);
    for (int l = white; l >= 0; l -= 1)
    {
      pixels.setPixelColor(21, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(20, pixels.Color(red, green, blue, l)); //е
      pixels.setPixelColor(19, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(18, pixels.Color(red, green, blue, l)); //ы
      pixels.setPixelColor(17, pixels.Color(red, green, blue, l)); //р
      pixels.setPixelColor(16, pixels.Color(red, green, blue, l)); //е

      pixels.setPixelColor(66, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(67, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(68, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(69, pixels.Color(red, green, blue, l)); //а

      l_h_status_4 = 0;
      pixels.show();
    }
  }
}

void FiveHourLedOn()
{
  if (l_h_status_5 == 0)
  {
    delay(100);
    for (int l = 0; l <= white; l += 1)
    {
      pixels.setPixelColor(51, pixels.Color(red, green, blue, l)); //п
      pixels.setPixelColor(52, pixels.Color(red, green, blue, l)); //я
      pixels.setPixelColor(53, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(54, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(59, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(58, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(57, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(56, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(55, pixels.Color(red, green, blue, l)); //в

      l_h_status_5 = 1;
      pixels.show();
    }
  }
}

void FiveHourLedOff()
{
  if (l_h_status_5 == 1)
  {
    //    delay (100);
    for (int l = white; l >= 0; l -= 1)
    {
      pixels.setPixelColor(51, pixels.Color(red, green, blue, l)); //п
      pixels.setPixelColor(52, pixels.Color(red, green, blue, l)); //я
      pixels.setPixelColor(53, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(54, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(59, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(58, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(57, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(56, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(55, pixels.Color(red, green, blue, l)); //в

      l_h_status_5 = 0;
      pixels.show();
    }
  }
}

void SixHourLedOn()
{
  if (l_h_status_6 == 0)
  {
    delay(100);
    for (int l = 0; l <= white; l += 1)
    {
      pixels.setPixelColor(65, pixels.Color(red, green, blue, l)); //ш
      pixels.setPixelColor(64, pixels.Color(red, green, blue, l)); //е
      pixels.setPixelColor(63, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(62, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(61, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(59, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(58, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(57, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(56, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(55, pixels.Color(red, green, blue, l)); //в

      l_h_status_6 = 1;
      pixels.show();
    }
  }
}

void SixHourLedOff()
{
  if (l_h_status_6 == 1)
  {
    //    delay (100);
    for (int l = white; l >= 0; l -= 1)
    {
      pixels.setPixelColor(65, pixels.Color(red, green, blue, l)); //ш
      pixels.setPixelColor(64, pixels.Color(red, green, blue, l)); //е
      pixels.setPixelColor(63, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(62, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(61, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(59, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(58, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(57, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(56, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(55, pixels.Color(red, green, blue, l)); //в

      l_h_status_6 = 0;
      pixels.show();
    }
  }
}

void SevenHourLedOn()
{
  if (l_h_status_7 == 0)
  {
    delay(100);
    for (int l = 0; l <= white; l += 1)
    {
      pixels.setPixelColor(36, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(35, pixels.Color(red, green, blue, l)); //е
      pixels.setPixelColor(34, pixels.Color(red, green, blue, l)); //м
      pixels.setPixelColor(33, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(59, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(58, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(57, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(56, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(55, pixels.Color(red, green, blue, l)); //в

      l_h_status_7 = 1;
      pixels.show();
    }
  }
}

void SevenHourLedOff()
{
  if (l_h_status_7 == 1)
  {
    //    delay (100);
    for (int l = white; l >= 0; l -= 1)
    {
      pixels.setPixelColor(36, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(35, pixels.Color(red, green, blue, l)); //е
      pixels.setPixelColor(34, pixels.Color(red, green, blue, l)); //м
      pixels.setPixelColor(33, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(59, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(58, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(57, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(56, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(55, pixels.Color(red, green, blue, l)); //в

      l_h_status_7 = 0;
      pixels.show();
    }
  }
}

void EightHourLedOn()
{
  if (l_h_status_8 == 0)
  {
    delay(100);
    for (int l = 0; l <= white; l += 1)
    {
      pixels.setPixelColor(38, pixels.Color(red, green, blue, l)); //в
      pixels.setPixelColor(37, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(36, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(35, pixels.Color(red, green, blue, l)); //е
      pixels.setPixelColor(34, pixels.Color(red, green, blue, l)); //м
      pixels.setPixelColor(33, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(59, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(58, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(57, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(56, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(55, pixels.Color(red, green, blue, l)); //в

      l_h_status_8 = 1;
      pixels.show();
    }
  }
}

void EightHourLedOff()
{
  if (l_h_status_8 == 1)
  {
    //    delay (100);
    for (int l = white; l >= 0; l -= 1)
    {
      pixels.setPixelColor(38, pixels.Color(red, green, blue, l)); //в
      pixels.setPixelColor(37, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(36, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(35, pixels.Color(red, green, blue, l)); //е
      pixels.setPixelColor(34, pixels.Color(red, green, blue, l)); //м
      pixels.setPixelColor(33, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(59, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(58, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(57, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(56, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(55, pixels.Color(red, green, blue, l)); //в

      l_h_status_8 = 0;
      pixels.show();
    }
  }
}

void NineHourLedOn()
{
  if (l_h_status_9 == 0)
  {
    delay(100);
    for (int l = 0; l <= white; l += 1)
    {
      pixels.setPixelColor(40, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(39, pixels.Color(red, green, blue, l)); //е
      pixels.setPixelColor(38, pixels.Color(red, green, blue, l)); //в
      pixels.setPixelColor(47, pixels.Color(red, green, blue, l)); //я
      pixels.setPixelColor(48, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(49, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(59, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(58, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(57, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(56, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(55, pixels.Color(red, green, blue, l)); //в

      l_h_status_9 = 1;
      pixels.show();
    }
  }
}

void NineHourLedOff()
{
  if (l_h_status_9 == 1)
  {
    //    delay (100);
    for (int l = white; l >= 0; l -= 1)
    {
      pixels.setPixelColor(40, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(39, pixels.Color(red, green, blue, l)); //е
      pixels.setPixelColor(38, pixels.Color(red, green, blue, l)); //в
      pixels.setPixelColor(47, pixels.Color(red, green, blue, l)); //я
      pixels.setPixelColor(48, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(49, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(59, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(58, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(57, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(56, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(55, pixels.Color(red, green, blue, l)); //в

      l_h_status_9 = 0;
      pixels.show();
    }
  }
}

void TenHourLedOn()
{
  if (l_h_status_10 == 0)
  {
    delay(100);
    for (int l = 0; l <= white; l += 1)
    {
      pixels.setPixelColor(44, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(45, pixels.Color(red, green, blue, l)); //е
      pixels.setPixelColor(46, pixels.Color(red, green, blue, l)); //c
      pixels.setPixelColor(47, pixels.Color(red, green, blue, l)); //я
      pixels.setPixelColor(48, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(49, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(59, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(58, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(57, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(56, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(55, pixels.Color(red, green, blue, l)); //в

      l_h_status_10 = 1;
      pixels.show();
    }
  }
}

void TenHourLedOff()
{
  if (l_h_status_10 == 1)
  {
    //    delay (100);
    for (int l = white; l >= 0; l -= 1)
    {
      pixels.setPixelColor(44, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(45, pixels.Color(red, green, blue, l)); //е
      pixels.setPixelColor(46, pixels.Color(red, green, blue, l)); //c
      pixels.setPixelColor(47, pixels.Color(red, green, blue, l)); //я
      pixels.setPixelColor(48, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(49, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(59, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(58, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(57, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(56, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(55, pixels.Color(red, green, blue, l)); //в

      l_h_status_10 = 0;
      pixels.show();
    }
  }
}

void ElevenHourLedOn()
{
  if (l_h_status_11 == 0)
  {
    delay(100);
    for (int l = 0; l <= white; l += 1)
    {
      pixels.setPixelColor(22, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(23, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(24, pixels.Color(red, green, blue, l)); //и
      pixels.setPixelColor(25, pixels.Color(red, green, blue, l)); //н
      pixels.setPixelColor(26, pixels.Color(red, green, blue, l)); //н
      pixels.setPixelColor(27, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(28, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(29, pixels.Color(red, green, blue, l)); //ц
      pixels.setPixelColor(30, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(31, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(32, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(59, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(58, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(57, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(56, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(55, pixels.Color(red, green, blue, l)); //в
      l_h_status_11 = 1;
      pixels.show();
    }
  }
}

void ElevenHourLedOff()
{
  if (l_h_status_11 == 1)
  {
    //    delay (100);
    for (int l = white; l >= 0; l -= 1)
    {
      pixels.setPixelColor(22, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(23, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(24, pixels.Color(red, green, blue, l)); //и
      pixels.setPixelColor(25, pixels.Color(red, green, blue, l)); //н
      pixels.setPixelColor(26, pixels.Color(red, green, blue, l)); //н
      pixels.setPixelColor(27, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(28, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(29, pixels.Color(red, green, blue, l)); //ц
      pixels.setPixelColor(30, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(31, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(32, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(59, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(58, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(57, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(56, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(55, pixels.Color(red, green, blue, l)); //в

      l_h_status_11 = 0;
      pixels.show();
    }
  }
}

void TwelveHourLedOn()
{
  if (l_h_status_12 == 0)
  {
    delay(100);
    for (int l = 0; l <= white; l += 1)
    {
      pixels.setPixelColor(15, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(14, pixels.Color(red, green, blue, l)); //в
      pixels.setPixelColor(13, pixels.Color(red, green, blue, l)); //е
      pixels.setPixelColor(26, pixels.Color(red, green, blue, l)); //н
      pixels.setPixelColor(27, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(28, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(29, pixels.Color(red, green, blue, l)); //ц
      pixels.setPixelColor(30, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(31, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(32, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(59, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(58, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(57, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(56, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(55, pixels.Color(red, green, blue, l)); //в
      l_h_status_12 = 1;
      pixels.show();
    }
  }
}

void TwelveHourLedOff()
{
  if (l_h_status_12 == 1)
  {
    //    delay (100);
    for (int l = white; l >= 0; l -= 1)
    {
      pixels.setPixelColor(15, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(14, pixels.Color(red, green, blue, l)); //в
      pixels.setPixelColor(13, pixels.Color(red, green, blue, l)); //е
      pixels.setPixelColor(26, pixels.Color(red, green, blue, l)); //н
      pixels.setPixelColor(27, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(28, pixels.Color(red, green, blue, l)); //д
      pixels.setPixelColor(29, pixels.Color(red, green, blue, l)); //ц
      pixels.setPixelColor(30, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(31, pixels.Color(red, green, blue, l)); //т
      pixels.setPixelColor(32, pixels.Color(red, green, blue, l)); //ь

      pixels.setPixelColor(59, pixels.Color(red, green, blue, l)); //ч
      pixels.setPixelColor(58, pixels.Color(red, green, blue, l)); //а
      pixels.setPixelColor(57, pixels.Color(red, green, blue, l)); //с
      pixels.setPixelColor(56, pixels.Color(red, green, blue, l)); //о
      pixels.setPixelColor(55, pixels.Color(red, green, blue, l)); //в

      l_h_status_12 = 0;
      pixels.show();
    }
  }
}

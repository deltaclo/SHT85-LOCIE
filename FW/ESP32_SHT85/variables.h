#define TCAADDR1 0x70
#define TCAADDR2 0x71

//Network selection
char* network        = "NONE";
int NetworkSelect    = 0;

//Wifi
const char* ssid     = "SSID";
const char* password = "WIFIPWD";

// Static IP address
char* IP;
char* Passerel;
char* Masque;
char* MAC;

IPAddress local_IP;
IPAddress gateway;
IPAddress subnet;
byte macAdresse[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

WiFiServer server(80);
EthernetServer serverEth(80);

String boxName = "testBox";
String capteurType = "SHT85";
String versionFW = "  Version : 0.6b WIFI + ETH  ";

//SHT
SHTSensor sht[16](SHTSensor::SHT3X);
const int nbCapteur = 16;

String Capteur[16];
double Temperature[16];
double Humidity[16];
boolean initStatus[16];

double randomMes;

//Variables SD configfile
const int pinSelectSD = 15; // SD shield Chip Select pin.
const int pinSelectETH = 33; // SD shield Chip Select pin.
const char CONFIG_FILE[] = "/configuration.cfg";
const char SENSORS_FILE[] = "/sensors.cfg";

boolean didReadConfig;
boolean readConfiguration();

String ParsedIP[4];
String ParsedMAC[6];
int j = 0;


//Variables read SHT
unsigned long prevTime = 0;
unsigned long prevTimeSHT = 0;
unsigned long currTime = 0;
unsigned long SHTreadTime[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned long SensorReadTime[16][10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int k = 0;

boolean MUX = false;
int MUXDelay = 1000;
int ReadDelay = 32;
int initMUXDelay = 1000;
int initReadDelay = 1000;
int ReadDelayLoop = 1000;
int DatalogDelayLoop = 1;
unsigned long previousMillisSHT=0;
unsigned long previousMillisSD=0;

//Serial
String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

TaskHandle_t Task1, Task2;
SemaphoreHandle_t baton;

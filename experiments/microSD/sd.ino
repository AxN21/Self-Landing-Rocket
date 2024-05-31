#include <SPI.h>
#include <SD.h>


File myFile;
const int cs = 5;

void WriteFile(const char*path, const char*message) {
      // Open the filel, only one can be opened at a time
      myFile = SD.open(path, FILE_WRITE);
      // if the file opened, write to it
      if (myFile) {
          Serial.printf("Writing to %s", path);
          myFile.println(message);
          myFile.close(); // close the file
          Serial.println("Completed");
        }
      // if the file didn't open, print an error
      else {
          Serial.println("Error opening file");
          Serial.println(path);
        }
  }

void readFile(const char*path) {
      // open the file for reading
      myFile = SD.open(path);
      if (myFile) {
            Serial.printf("Reading file from %s/n", path);
            // read from the file until there is nothing left
            while (myFile.available()) {
                  Serial.write(myFile.read());
              }
            myFile.close(); // close the file
        }

      else {
            Serial.println("Error opening file text.txt");
        }
  }


void setup() {
      Serial.begin(9600);
      delay(500);
      while (!Serial) { ; }
      Serial.println("Initializing SD card...");
      
      if (!SD.begin(cs)) {
            Serial.println("Initialization failed");
            return;
        }
      Serial.println("Initialization done");

      WriteFile("/text.txt", "Code Space Labs");
      ReadFile("/text.txt");
  }


void loop() {
    
  }

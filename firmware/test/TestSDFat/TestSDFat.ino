#include <SPI.h>
#include <SdFat.h>

#define CS_PIN   4
#define MOSI_PIN 1
#define MISO_PIN 2
#define SCK_PIN  3


SPIClass spiSD(HSPI);
SdFat sd;

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Initialisation SPI...");
  spiSD.begin(SCK_PIN, MISO_PIN, MOSI_PIN, CS_PIN);

  Serial.println("Initialisation SD avec SdFat...");

  // ATTENTION : ordre des arguments corrigé !
  SdSpiConfig config(CS_PIN, DEDICATED_SPI, 4000000, &spiSD); 
  // 20 MHz = 20 000 000 Hz

  if (!sd.begin(config)) {
    Serial.println("❌ Échec init avec SdFat.");
    return;
  }

  Serial.println("✅ Carte SD détectée via SdFat.");

  File fichier = sd.open("test.txt", FILE_WRITE);
  if (fichier) {
    fichier.println("Test réussi via SdFat !");
    fichier.close();
    Serial.println("✅ Fichier écrit !");
  } else {
    Serial.println("❌ Impossible de créer le fichier !");
  }
}

void loop() {}
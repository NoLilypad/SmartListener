#include <SPI.h>
#include <SD.h>

// Nouvelles broches SPI
#define CS_PIN   4
#define MOSI_PIN 1
#define MISO_PIN 2
#define SCK_PIN  3

SPIClass spiSD(HSPI); // On utilise un bus SPI logiciel (HSPI)

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Initialisation SPI sur GPIO 0–3
  spiSD.begin(SCK_PIN, MISO_PIN, MOSI_PIN, CS_PIN);

  Serial.println("SPI initialisé, tentative SD...");

  if (!SD.begin(CS_PIN, spiSD)) {
    Serial.println("❌ Échec init carte SD !");
    return;
  }

  Serial.println("✅ Carte SD détectée !");

  File fichier = SD.open("/test.txt", FILE_WRITE);
  if (fichier) {
    fichier.println("Écriture OK depuis l’ESP32-C3 !");
    fichier.close();
    Serial.println("✅ Fichier écrit avec succès !");
  } else {
    Serial.println("❌ Erreur ouverture fichier !");
  }
}

void loop() {
  // Rien ici
}

const byte PIN_TRIG = 2;
const byte PIN_ECHO = 3;

const byte LED_L1 = 4;
const byte LED_L2 = 5;
const byte LED_L3 = 6;
const byte LED_L4 = 7;

const byte LED_INTERIEUR_ROUGE = 8;
const byte LED_INTERIEUR_VERT = 9;
const byte BOUTON = 10;
const byte POMPE = 11;

const float DISTANCE_L1 = 40.0;
const float DISTANCE_L2 = 30.0;
const float DISTANCE_L3 = 20.0;
const float DISTANCE_L4 = 10.0;

const unsigned long DEBOUNCE_MS = 50;
const unsigned long TEMPS_MAX_MESURE_MS = 40;
const unsigned long DELAI_MESURE_MS = 60;

bool systemeActif = false;
bool dernierEtatBouton = HIGH;
bool etatStableBouton = HIGH;
unsigned long dernierChangementBouton = 0;
unsigned long derniereMesure = 0;

float mesurerDistanceCm() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(3);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  unsigned long duree = pulseIn(PIN_ECHO, HIGH, TEMPS_MAX_MESURE_MS * 1000UL);

  if (duree == 0) {
    return -1.0;
  }

  return duree * 0.0343 / 2.0;
}

void reglerSorties(bool l1, bool l2, bool l3, bool l4, bool pompeActive) {
  digitalWrite(LED_L1, l1);
  digitalWrite(LED_L2, l2);
  digitalWrite(LED_L3, l3);
  digitalWrite(LED_L4, l4);
  digitalWrite(POMPE, pompeActive);
  digitalWrite(LED_INTERIEUR_ROUGE, !pompeActive);
  digitalWrite(LED_INTERIEUR_VERT, pompeActive);
}

void arreterSysteme() {
  reglerSorties(false, false, false, false, false);
}

void afficherProgression(float distance) {
  if (!systemeActif || distance < 0.0 || distance > DISTANCE_L1) {
    arreterSysteme();
    return;
  }

  bool l1 = distance <= DISTANCE_L1;
  bool l2 = distance <= DISTANCE_L2;
  bool l3 = distance <= DISTANCE_L3;
  bool l4 = distance <= DISTANCE_L4;
  bool pompeActive = l4;

  reglerSorties(l1, l2, l3, l4, pompeActive);
}

void gererBouton() {
  bool lecture = digitalRead(BOUTON);

  if (lecture != dernierEtatBouton) {
    dernierChangementBouton = millis();
    dernierEtatBouton = lecture;
  }

  if (millis() - dernierChangementBouton >= DEBOUNCE_MS) {
    if (lecture != etatStableBouton) {
      etatStableBouton = lecture;

      if (etatStableBouton == LOW) {
        systemeActif = !systemeActif;

        if (!systemeActif) {
          arreterSysteme();
        }
      }
    }
  }
}

void setup() {
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  pinMode(LED_L1, OUTPUT);
  pinMode(LED_L2, OUTPUT);
  pinMode(LED_L3, OUTPUT);
  pinMode(LED_L4, OUTPUT);

  pinMode(LED_INTERIEUR_ROUGE, OUTPUT);
  pinMode(LED_INTERIEUR_VERT, OUTPUT);
  pinMode(BOUTON, INPUT_PULLUP);
  pinMode(POMPE, OUTPUT);

  digitalWrite(PIN_TRIG, LOW);
  arreterSysteme();
}

void loop() {
  gererBouton();

  if (!systemeActif) {
    arreterSysteme();
    return;
  }

  if (millis() - derniereMesure >= DELAI_MESURE_MS) {
    derniereMesure = millis();
    float distance = mesurerDistanceCm();
    afficherProgression(distance);
  }
}

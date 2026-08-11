struct Configuration {

  byte trig;
  byte echo;

  byte leds[4];

  byte interieurRouge;
  byte interieurVert;

  byte bouton;
  byte relais;

  float distances[4];

  unsigned long debounce;
  unsigned long timeoutEcho;
  unsigned long intervalleMesure;
};


Configuration config = {

  2,
  3,

  {4, 5, 6, 7},

  8,
  9,

  10,
  11,

  {40.0, 30.0, 20.0, 10.0},

  50,
  40,
  60
};


struct Etat {

  bool actif;

  bool boutonDernier;
  bool boutonStable;

  unsigned long changementBouton;
  unsigned long derniereMesure;
};


Etat etat = {

  false,

  HIGH,
  HIGH,

  0,
  0
};


float mesurerDistance() {

  digitalWrite(config.trig, LOW);
  delayMicroseconds(3);

  digitalWrite(config.trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(config.trig, LOW);

  unsigned long duree = pulseIn(
    config.echo,
    HIGH,
    config.timeoutEcho * 1000UL
  );

  if (duree == 0) {
    return -1;
  }

  return duree * 0.0343 / 2.0;
}


void commanderPompe(bool active) {

  digitalWrite(
    config.relais,
    active ? HIGH : LOW
  );

  digitalWrite(
    config.interieurRouge,
    active ? LOW : HIGH
  );

  digitalWrite(
    config.interieurVert,
    active ? HIGH : LOW
  );
}


void eteindreLeds() {

  for (byte i = 0; i < 4; i++) {
    digitalWrite(config.leds[i], LOW);
  }
}


void progression(float distance) {

  eteindreLeds();

  if (
    !etat.actif ||
    distance < 0 ||
    distance > config.distances[0]
  ) {

    commanderPompe(false);
    return;
  }

  byte lignes = 0;

  for (byte i = 0; i < 4; i++) {

    if (distance <= config.distances[i]) {
      lignes = i + 1;
    }
  }

  for (byte i = 0; i < lignes; i++) {
    digitalWrite(config.leds[i], HIGH);
  }

  commanderPompe(lignes == 4);
}


void arreterSysteme() {

  eteindreLeds();

  commanderPompe(false);
}


void gererBouton() {

  bool lecture = digitalRead(config.bouton);

  if (lecture != etat.boutonDernier) {

    etat.changementBouton = millis();

    etat.boutonDernier = lecture;
  }

  if (
    millis() - etat.changementBouton >= config.debounce &&
    lecture != etat.boutonStable
  ) {

    etat.boutonStable = lecture;

    if (etat.boutonStable == LOW) {

      etat.actif = !etat.actif;

      if (!etat.actif) {
        arreterSysteme();
      }
    }
  }
}


void setup() {

  pinMode(config.trig, OUTPUT);
  pinMode(config.echo, INPUT);

  for (byte i = 0; i < 4; i++) {
    pinMode(config.leds[i], OUTPUT);
  }

  pinMode(config.interieurRouge, OUTPUT);
  pinMode(config.interieurVert, OUTPUT);

  pinMode(config.bouton, INPUT_PULLUP);

  pinMode(config.relais, OUTPUT);

  digitalWrite(config.trig, LOW);

  arreterSysteme();
}


void loop() {

  gererBouton();

  if (!etat.actif) {
    return;
  }

  if (
    millis() - etat.derniereMesure >=
    config.intervalleMesure
  ) {

    etat.derniereMesure = millis();

    float distance = mesurerDistance();

    progression(distance);
  }
}

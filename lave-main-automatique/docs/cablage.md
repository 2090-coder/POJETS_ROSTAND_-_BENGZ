# Câblage

## Arduino Nano

| Fonction | Broche Arduino Nano |
|---|---:|
| HC-SR04 TRIG | D2 |
| HC-SR04 ECHO | D3 |
| L1 Rouge | D4 |
| L2 Orange | D5 |
| L3 Jaune | D6 |
| L4 Vert | D7 |
| Éclairage intérieur rouge | D8 |
| Éclairage intérieur vert | D9 |
| Bouton poussoir | D10 |
| Commande relais pompe | D11 |

## HC-SR04

| HC-SR04 | Arduino Nano |
|---|---|
| VCC | 5 V |
| TRIG | D2 |
| ECHO | D3 |
| GND | GND |

## Bouton poussoir

Une borne du bouton est reliée à D10.

L'autre borne est reliée à GND.

Le programme utilise la résistance interne `INPUT_PULLUP` de l'Arduino Nano.

## LEDs de progression

Chaque ligne possède sa propre sortie de commande.

L1 rouge : D4

L2 orange : D5

L3 jaune : D6

L4 vert : D7

Pour plusieurs LEDs sur une même ligne, utiliser un étage de commande adapté et une résistance de limitation appropriée pour chaque branche lumineuse.

## Éclairage intérieur

LED rouge : D8

LED verte : D9

Les deux sorties doivent utiliser des résistances de limitation si les LEDs sont individuelles.

## Relais 5 V et pompe

La broche D11 commande la bobine du relais 5 V.

Broche 1 du relais : borne de la bobine

Broche 2 du relais : borne de la bobine

Broche 3 du relais : NC

Broche 4 du relais : NO

Broche 5 du relais : COM

Pour la pompe, utiliser COM et NO afin que la pompe soit arrêtée lorsque le relais est au repos.

Le circuit de commande de la bobine dépend du type de relais utilisé. Si le relais est un relais électromécanique nu, il ne faut pas connecter directement sa bobine à une broche Arduino. Utiliser un étage de commande adapté. Si le relais est un module 5 V prévu pour Arduino, connecter son entrée de commande conformément au module.

Circuit de puissance recommandé :

Alimentation pompe positive vers COM.

NO vers le positif de la pompe.

Négatif de la pompe vers le négatif de son alimentation.

La pompe doit recevoir une alimentation adaptée à sa tension nominale et à son courant de démarrage.

La broche D11 ne doit jamais alimenter directement la pompe.

## Circuit de niveau d'eau

Le circuit de niveau d'eau de Mirimo MUHINDO Rostand est indépendant du programme Arduino.

Les transistors et les LEDs de niveau sont alimentés par leur propre montage conformément au schéma électronique réalisé par Rostand.

Aucune broche Arduino n'est nécessaire pour la mesure du niveau d'eau dans cette version.

## Alimentation

L'Arduino Nano et les capteurs doivent recevoir une alimentation stable adaptée.

La pompe doit utiliser une alimentation capable de fournir son courant de démarrage.

Si une alimentation commune est utilisée, vérifier les tensions et les courants avant raccordement.

# Cahier des charges

## 1. Identification

Nom du projet : Lave-mains automatique

Équipe : TECHNOVA

Membres : Salomon BENGZ et Mirimo MUHINDO Rostand

Contrôleur principal : Arduino Nano

## 2. Objectif

Créer un lave-mains autonome capable de détecter la présence et la position des mains, d'indiquer la distance par quatre niveaux lumineux et de distribuer automatiquement l'eau lorsque la position correcte est atteinte.

## 3. Fonctions

### 3.1 Activation

Un bouton poussoir permet de basculer le système entre l'état actif et l'état inactif.

### 3.2 Détection

Un capteur HC-SR04 mesure la distance entre le capteur et les mains.

### 3.3 Guidage lumineux

La progression est représentée par quatre niveaux :

| Niveau | Couleur | Condition |
|---|---|---|
| L1 | Rouge | Distance inférieure ou égale à 40 cm |
| L2 | Orange | Distance inférieure ou égale à 30 cm |
| L3 | Jaune | Distance inférieure ou égale à 20 cm |
| L4 | Vert | Distance inférieure ou égale à 10 cm |

Les niveaux précédents restent allumés lorsque la main atteint un niveau supérieur.

### 3.4 Commande de la pompe

La pompe est activée uniquement lorsque la main atteint L4 et que le système est actif.

### 3.5 Éclairage intérieur

L'éclairage intérieur rouge indique l'attente.

L'éclairage intérieur vert indique que la position correcte est atteinte et que la pompe est active.

### 3.6 Niveau d'eau

Le niveau d'eau est géré par un montage électronique indépendant à transistors réalisé par Mirimo MUHINDO Rostand.

Aucune mesure du niveau d'eau n'est traitée par le programme Arduino.

## 4. Contraintes

La pompe doit être alimentée par une alimentation adaptée et commandée par une interface de puissance.

Les masses des différentes alimentations doivent être correctement référencées lorsque les circuits l'exigent.

Les parties en contact avec l'eau doivent être isolées des circuits électroniques.

Le boîtier doit permettre l'accès au réservoir, à la pompe et à l'électronique pour la maintenance.

## 5. Résultat attendu

Le système doit permettre à un utilisateur de placer progressivement ses mains dans la zone prévue, de suivre les quatre niveaux lumineux et d'obtenir automatiquement de l'eau lorsque le niveau vert est atteint.
